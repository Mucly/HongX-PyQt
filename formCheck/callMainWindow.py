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
        self.status.showMessage('仅供内部学习交流使用 -- Muc')
        self.setFixedSize(self.width(), self.height())

    # 通过注册表获取桌面路径
    def getDeskTop(self):
        key = winreg.OpenKey(winreg.HKEY_CURRENT_USER,
                             r'Software\Microsoft\Windows\CurrentVersion\Explorer\Shell Folders')
        return winreg.QueryValueEx(key, "Desktop")[0]

    # write tab log
    def wrTabLog(self, file, line):
        self.tabLog.append(f"{file} : {line}")

    # write so log
    def wrSoLog(self, file, line):
        self.soLog.append(f"{file} : {line}")

    # write titleID log
    def wrTitleLog(self, file):
        self.titleLog.append(f"{file}")

    def initVar(self):
        self.tabLog = ['\n----------如下画面文件内的taborder重复，请处理----------\n']
        self.soLog = ['\n\n----------如下画面文件所映射的so文件丢失，请核实----------\n']
        self.titleLog = ["\n\n----------如下画面文件titleID丢失，请核实----------\n"]

        self.so_list = []
        self.dbid0_map = {}

        self.so_path = ""  # formlib文件夹路径
        self.form_path = ""  # form文件夹路径
        self.cfg_path = ""  # config.ini文件路径

        self.settings = QSettings("TechMation\\Muc\\tools", "HMIFormCheck")

        # 注册表的映射表 #1
        self.el_map = {
            "cfg_path": self.edCfg,
        }

    def initWidgets(self):
        self.rdReg()

    # 判断当前form画面脚本是否存在taborder重复的情况
    def trvTxtFold(self, file):
        file = os.path.join(self.form_path, file)  # 绝对路径
        file = file.replace('\\', '/')

        el_list = []  # 元件名列表
        order_list = []  # 画面内，所有taborder的值的集合
        so_val_list = ["CtmFormView", "CtmMainFrame",
                       "CtmWndSplash"]     # 画面脚本内，画面so对应的值

        first_line = False
        get_title = False

        with open(file, errors='ignore') as fd:
            for line in fd.readlines():
                line = line.strip()
                # 判断画面so是否存在
                if (not first_line):
                    if (":" in line):
                        so, _, val = line.partition(":")
                        if (val in so_val_list):
                            if (so not in self.so_list):
                                self.wrSoLog(file, line)
                        else:
                            self.wrSoLog(file, line)
                    else:  # 如果画面第一行不是逻辑内容行
                        self.wrSoLog(file, "缺失第一行内容")
                    first_line = True
                # 判断taborder是否有重复的
                elif "taborder" in line:
                    if "//" not in line:
                        _, _, val = line.partition("=")
                        # 因为有taborder = 5+1这种骚写法，故须做eval处理
                        if (int(eval(val)) >= 0):
                            if not(val in order_list):
                                order_list.append(val)
                            else:
                                self.wrTabLog(file, line)
                elif not get_title:
                    if "titleID" in line:
                        get_title = True

        if not get_title:
            self.wrTitleLog(file)

    # --- 设置edit元件内容 ---
    def setCfgEdit(self):
        tmp = QFileDialog.getOpenFileName(
            self, "选择config配置文件", "./", "config*.ini")[0]  # 这里返回的是个tuple，前者是路径，后者是fileFilter
        if tmp:
            self.edCfg.setText(tmp)

    def setBasePath(self, cfg_path):
        inx = cfg_path.find("config")
        self.base_path = cfg_path[0: inx - 1]  # 减1是因为config前面还有个特殊符号

    # 注册表信息读取
    def rdReg(self):
        for key, value in self.el_map.items():
            value.setText(self.settings.value(key))

    # 注册表信息保存
    def wr2Reg(self):
        for key, value in self.el_map.items():
            self.settings.setValue(key, QVariant(value.text()))

    def showResult(self):
        rst_ui.qList = self.tabLog + self.soLog + self.titleLog
        slm = QStringListModel(rst_ui.qList)

        rst_ui.listViewResult.setModel(slm)
        rst_ui.listViewResult.clicked.connect(rst_ui.rstClicked)
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
                    self, "错误 #2", "路径丢失或错误，请检查所选的config文件中，FormPath和FormlibPath内容")
            else:
                self.wr2Reg()
                self.showResult()  # 如果一切正常，展示测试结果
            finally:
                pass
        else:
            QMessageBox.critical(
                self, "错误 #1", "请先选择config配置文件")

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

    def rstClicked(self, QModelIndex):
        file, _, _ = self.qList[QModelIndex.row()].partition(" : ")
        file = file.strip()
        if os.path.exists(file):
            os.startfile(file)

if __name__ == "__main__":
    app = QApplication(sys.argv)
    # 实例化主窗口
    main_ui = MainForm()
    main_ui.show()
    # 实例化子窗口
    rst_ui = RstForm()

    sys.exit(app.exec())
