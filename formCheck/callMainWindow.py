# -*- coding:utf-8 -*-
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.QtCore import *
from formCheck import Ui_MainWindow
from rstDialog import Ui_Dialog
import os
import sys
import time
import re


class MainForm(QMainWindow, Ui_MainWindow):

    def __init__(self):
        super(MainForm, self).__init__()
        self.setupUi(self)

        self.initUi()
        self.initVar()
        self.initWidgets()
        self.initSlots()

    def initUi(self):
        self.status = self.statusBar()
        self.status.setLayoutDirection(Qt.RightToLeft)
        self.status.showMessage('仅供内部学习交流使用 -- Muc v0.0.2')
        self.setFixedSize(self.width(), self.height())

    # 通过注册表获取桌面路径
    def getDeskTop(self):
        key = winreg.OpenKey(winreg.HKEY_CURRENT_USER,
                             r'Software\Microsoft\Windows\CurrentVersion\Explorer\Shell Folders')
        return winreg.QueryValueEx(key, "Desktop")[0]

    # write tab log
    def wrTabLog(self, file, line):
        self.tabLog.append(f"{file} ----- {line}")

    # write so log
    def wrSoLog(self, file, line):
        self.soLog.append(f"{file} ----- {line}")

    # write titleID log
    def wrTitleLog(self, file):
        self.titleLog.append(f"{file}")

    def wrEleLog(self, file, el):
        self.ele_log.append(f"{file} ----- {el}")

    def initVar(self):
        self.tabLog = ['\n----------如下文件，taborder重复，请核实处理----------\n']
        self.soLog = ['\n\n----------如下文件，所映射的so文件丢失，请核实处理----------\n']
        self.titleLog = ["\n\n----------如下文件，titleID丢失，请核实处理----------\n"]
        self.ele_log = ["\n\n----------如下文件，元件名重复，请核实处理----------\n"]

        self.so_list = []
        self.dbid0_map = {}

        self.so_path = ""  # formlib文件夹路径
        self.form_path = ""  # form文件夹路径
        self.cfg_path = ""  # config.ini文件路径

        self.settings = QSettings("TechMation\\Muc\\tools", "HMIFormCheck")

        # 工具画面内的元件映射表 #1
        self.cell_map = {
            "cfg_path": self.edCfg,
        }

    def initWidgets(self):
        self.rdReg()

    # 判断当前form画面脚本是否存在taborder重复的情况
    def trvTxtFold(self, file):
        file = os.path.join(self.form_path, file)  # 绝对路径
        file = file.replace('\\', '/')

        ele_list = []  # 元件名列表
        order_list = []  # 画面内，所有taborder的值的集合
        so_val_list = ["CtmFormView", "CtmMainFrame",
                       "CtmWndSplash"]     # 画面脚本内，画面so对应的值

        get_fline = False  # first line
        get_title = False  # titleID

        with open(file, errors='ignore') as fd:
            for line in fd.readlines():
                # 仅需对未注释的内容进行处理
                if "//" not in line:
                    line = line.strip()
                    # 判断画面so是否存在
                    if (not get_fline):
                        if (":" in line):
                            so, _, val = line.partition(":")
                            if (val in so_val_list):
                                if (so not in self.so_list):
                                    self.wrSoLog(file, line)
                            else:
                                self.wrSoLog(file, line)
                        else:  # 如果画面第一行不是逻辑内容行
                            self.wrSoLog(file, "缺失第一行内容")
                        get_fline = True
                    elif not get_title:
                        if "titleID" in line:
                            get_title = True
                    # 判断taborder是否有重复的
                    elif "taborder" in line:
                        _, _, val = line.partition("=")
                        # 因为有taborder = 5+1这种骚写法，故须做eval处理
                        if (int(eval(val)) >= 0):  # taborder为负数代表不可编辑，所以不用加判断
                            if not(val in order_list):
                                order_list.append(val)
                            else:
                                self.wrTabLog(file, line)
                    elif ":" in line:
                        el, _, _ = line.partition(":")
                        if el not in ele_list:
                            ele_list.append(el)
                        else:
                            self.wrEleLog(file, el)

        if not get_title:
            self.wrTitleLog(file)

    # --- 设置edit元件内容 ---
    def setCfgEdit(self):
        explorer = "./"
        cfg_path = self.edCfg.text()
        if (os.path.exists(cfg_path)):
            explorer = cfg_path

        tmp = QFileDialog.getOpenFileName(
            self, "选择config配置文件", explorer, "config*.ini")[0]  # 这里返回的是个tuple，前者是路径，后者是fileFilter
        if tmp:
            self.edCfg.setText(tmp)

    def setBasePath(self, cfg_path):
        inx = cfg_path.find("config")
        self.base_path = cfg_path[0: inx - 1]  # 减1是因为config前面还有个'/'特殊符号

    # 注册表信息读取
    def rdReg(self):
        for key, value in self.cell_map.items():
            value.setText(self.settings.value(key))

    # 注册表信息保存
    def wr2Reg(self):
        for key, value in self.cell_map.items():
            self.settings.setValue(key, QVariant(value.text()))

    def showResult(self):
        rst_ui.qList = self.tabLog + self.soLog + self.titleLog + self.ele_log
        slm = QStringListModel(rst_ui.qList)

        rst_ui.listViewResult.setModel(slm)
        rst_ui.listViewResult.doubleClicked.connect(rst_ui.fileLinkClicked)
        rst_ui.show()

    # 主要操作，遍历form下的文件并判断文件内容
    def trvFolder(self):
        cfg_path = self.edCfg.text()
        if (os.path.exists(cfg_path)):
            # 设置base路径，用于定位form和formlib文件夹
            self.setBasePath(cfg_path)
            with open(cfg_path) as fd:
                for line in fd.readlines():
                    if "FormPath" in line:
                        _, _, v = line.partition("=.")
                        # v.replace(r"\\", "/")
                        v = v.rstrip(' \n/')  # 去除尾部多余内容
                        self.form_path = self.base_path + v
                    elif "FormlibPath" in line:
                        _, _, v = line.partition("=.")
                        # v.replace(r"\\", "/")
                        v = v.rstrip(' \n/')
                        self.so_path = self.base_path + v
            try:
                # 根据formlib文件夹下的so文件，建立so列表
                for file in os.listdir(self.so_path):
                    if file.endswith(".so"):
                        self.so_list.append(file.replace(".so", ""))
                # 遍历form文件夹及判断操作
                for file in os.listdir(self.form_path):
                    if file.endswith(".txt"):
                        self.trvTxtFold(file)
            except Exception as e:
                QMessageBox.critical(
                    self, "错误 #2", f"路径丢失或错误，请检查所选的config文件中，FormPath和FormlibPath的内容\n{e}")
            else:
                self.wr2Reg()
                self.showResult()  # 如果一切正常，展示测试结果
            finally:
                pass
        else:
            QMessageBox.critical(
                self, "错误 #1", "config.ini文件路径无效，请选择或确认路径是否有效")

    def initSlots(self):
        # shotcut
        self.actionClose.triggered.connect(self.close)

        # event
        self.pbtCfg.clicked.connect(self.setCfgEdit)  # 点击config按钮
        self.pbtCheck.clicked.connect(self.trvFolder)  # 点击check按钮


class RstForm(QDialog, Ui_Dialog):

    def __init__(self):
        super().__init__()
        self.setupUi(self)

    def fileLinkClicked(self, QModelIndex):
        file, _, _ = self.qList[QModelIndex.row()].partition(
            " ----- ")  # 这个partition里的参数需按照列表里的来
        file = file.strip()
        if os.path.exists(file):
            time.sleep(0.5)  # 为防止列表当前行焦点丢失，故需要在文件打开前加入sleep
            os.startfile(file)

    def foo(self):
        pass

if __name__ == "__main__":
    app = QApplication(sys.argv)
    # 实例化主窗口
    main_ui = MainForm()
    main_ui.show()
    # 实例化子窗口
    rst_ui = RstForm()

    sys.exit(app.exec())
