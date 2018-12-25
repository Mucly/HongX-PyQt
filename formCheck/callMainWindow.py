# -*- coding:utf-8 -*-
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.QtCore import *
from formCheck import Ui_MainWindow
from checkRstTab import Ui_rst
from copy import deepcopy

import os
import sys
import time


class RstForm(QWidget, Ui_rst):

    def __init__(self):
        super().__init__()
        self.setupUi(self)
        self.initUi()
        self.initVar()

    def initUi(self):
        pass
        # self.setFixedSize(self.width(), self.height())

    def initVar(self):
        self.__txt_dirpath = ""  # form画面所在的目录路径

    # listView元件内的列表文件，双击后可调用默认软件打开该文件
    def listViewClink(self, QModelIndex):
        file, _, _ = QModelIndex.data().partition(" ----- ")  # 这个partition里的参数需按照列表里的来
        file = file.strip()
        if os.path.exists(file):
            time.sleep(0.5)  # 为防止列表当前行焦点丢失，故需要在文件打开前加入sleep
            os.startfile(file)

    def tabWidgetClink(self, item):
        file = self.__txt_dirpath + os.sep + item.text()
        if os.path.exists(file):
            time.sleep(0.5)  # 为防止列表当前行焦点丢失，故需要在文件打开前加入sleep
            os.startfile(file)

    # 设置title标签页内容
    def setTitleTab(self, content_list):
        tmp_list = []
        if not content_list:
            tmp_list = ["恭喜，该项未验证到问题"]
        else:
            tmp_list = deepcopy(content_list)  # 必须要deepcopy，防止元数据被改动
        slm = QStringListModel(tmp_list)  # TODO same

        self.listViewTitleID.setModel(slm)  # TODO same
        self.listViewTitleID.doubleClicked.connect(self.listViewClink)

    # 设置so标签页内容
    def setSoTab(self, content_list):
        tmp_list = []
        if not content_list:
            tmp_list = ["恭喜，该项未验证到问题"]
        else:
            tmp_list = deepcopy(content_list)
        slm = QStringListModel(tmp_list)

        self.listViewSo.setModel(slm)
        self.listViewSo.doubleClicked.connect(self.listViewClink)

    # 设置taborder标签页内容
    def setTaborderTab(self, content_list):
        tmp_list = []
        if not content_list:
            tmp_list = ["恭喜，该项未验证到问题"]
        else:
            tmp_list = deepcopy(content_list)
        slm = QStringListModel(tmp_list)

        self.listViewTaborder.setModel(slm)
        self.listViewTaborder.doubleClicked.connect(self.listViewClink)

    # 设置pwnd标签页内容
    def setPwndTab(self, content_list):
        tmp_list = []
        if not content_list:
            tmp_list = ["恭喜，该项未验证到问题"]
        else:
            tmp_list = deepcopy(content_list)
        slm = QStringListModel(tmp_list)

        self.listViewPwnd.setModel(slm)
        self.listViewPwnd.doubleClicked.connect(self.listViewClink)

    def setDBID0Tab(self, d):
        tmp_dict = {}
        if not d:
            tmp_dict = {"恭喜，该项未验证到问题": "恭喜，该项未验证到问题"}
        else:
            tmp_dict = deepcopy(d)
        self.tableWidgetDBID0.clear()
        cols = 3  # 初始化列数，重复的数据最起码有三列
        rows = 0  # 初始化行数
        for k, v in tmp_dict.items():
            cnt = len(v) + 1  # 生成的col必须额外加一列DBID0的数据，所以取得的v还要加个1
            if cnt > 2:
                # 设置最大列数
                if cnt > cols:
                    cols = cnt
                # 设置总行数
                rows += 1

        # 必须先设置行、列数，不然数据无法显示
        self.tableWidgetDBID0.setColumnCount(cols)
        self.tableWidgetDBID0.setRowCount(rows)
        # 设置table title
        tb_title = ["DBID0"] + ["file"] * cols
        for i in range(len(tb_title)):
            if i > 0:
                tb_title[i] += str(i)
        self.tableWidgetDBID0.setHorizontalHeaderLabels(tb_title)
        # 设置table data
        rowx = 0
        for k, v in tmp_dict.items():
            cnt = len(v)  # 生成的col必须额外加一列DBID0的数据，所以取得的v还要加个1
            colx = 0
            if cnt > 1:
                self.tableWidgetDBID0.setItem(rowx, colx, QTableWidgetItem(k))
                # 获取txt画面脚本所在路径
                if (self.__txt_dirpath != os.path.dirname(v[0])):
                    self.__txt_dirpath = os.path.dirname(v[0])
                for i in range(cnt):
                    colx += 1
                    td = os.path.basename(v[i])  # td = os.path.split(v[i])[-1]
                    self.tableWidgetDBID0.setItem(rowx, colx, QTableWidgetItem(td))
                rowx += 1
        # table 自适应行列宽高
        self.tableWidgetDBID0.resizeRowsToContents()
        self.tableWidgetDBID0.resizeColumnsToContents()
        self.tableWidgetDBID0.itemDoubleClicked.connect(self.tabWidgetClink)


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
        self.status.showMessage('仅供内部学习交流使用 -- Muc v1.0.0')
        # self.setFixedSize(self.width(), self.height())

    # 通过注册表获取桌面路径
    def getDeskTop(self):
        key = winreg.OpenKey(winreg.HKEY_CURRENT_USER, r'Software\Microsoft\Windows\CurrentVersion\Explorer\Shell Folders')
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

    def wrPwndLog(self, file, pwnd):
        self.pwnd_log.append(f"{file} ----- {pwnd}")

    # 初始化变量内容
    def initVar(self):
        # log日志
        self.tabLog = ["----------如下文件，taborder重复----------\n"]
        self.soLog = ["----------如下文件，so文件丢失----------\n"]
        self.titleLog = ["----------如下文件，titleID丢失----------\n"]
        self.pwnd_log = ["----------如下文件，元件重复----------\n"]

        # 全局
        self.__so_list = []
        self.dbid0_dict = {}  # {DBID0_CONTENT : [View1.txt, View2.txt, ...]}

        # 文件路径
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

        __pwnd_list = []  # 元件名列表
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
                                if (so not in self.__so_list):
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
                        pwnd, _, _ = line.partition(":")
                        if pwnd not in __pwnd_list:
                            __pwnd_list.append(pwnd)
                        else:
                            self.wrPwndLog(file, pwnd)
                    elif "dbid0" in line:
                        _, _, dbid0 = line.partition("=")
                        # 创建全局dbid0字典，假使key不存在则以数组的形式创建
                        if not self.dbid0_dict.get(dbid0):
                            self.dbid0_dict[dbid0] = []
                        self.dbid0_dict[dbid0].append(file)

        if not get_title:
            self.wrTitleLog(file)

    # 设置config文件路径
    def setCfgEdit(self):
        explorer = "./"
        cfg_path = self.edCfg.text()
        if (os.path.exists(cfg_path)):
            explorer = cfg_path

        tmp = QFileDialog.getOpenFileName(
            self, "选择config配置文件", explorer, "config*.ini")[0]  # 这里返回的是个tuple，前者是路径，后者是fileFilter
        if tmp:
            self.edCfg.setText(tmp)

    # 设置config文件的上级路径
    def setBasePath(self, cfg_path):
        inx = cfg_path.find("config")
        self.base_path = cfg_path[0: inx - 1]  # 减1是因为config前面还有个'/'特殊符号

    # 注册表信息读取
    def rdReg(self):
        for k, v in self.cell_map.items():
            v.setText(self.settings.value(k))

    # 注册表信息保存
    def wr2Reg(self):
        for k, v in self.cell_map.items():
            self.settings.setValue(k, QVariant(v.text()))

        # 根据所有信息，遍历form下的文件并判断文件内容
    def trvFolder(self):
        cfg_path = self.edCfg.text()
        self.initVar()

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
                        self.__so_list.append(file.replace(".so", ""))
                # 遍历form文件夹及判断操作
                for file in os.listdir(self.form_path):
                    if file.endswith(".txt"):
                        self.trvTxtFold(file)
            except Exception as e:
                QMessageBox.critical(
                    self, "错误 #2", f"路径丢失或错误，请检查所选的config文件中，FormPath和FormlibPath的内容\n{e}")
            else:
                self.wr2Reg()
                # 呈现校验结果窗口
                rst_ui.setTitleTab(self.titleLog)
                rst_ui.setSoTab(self.soLog)
                rst_ui.setTaborderTab(self.tabLog)
                rst_ui.setPwndTab(self.pwnd_log)
                rst_ui.setDBID0Tab(self.dbid0_dict)
                rst_ui.show()
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

if __name__ == "__main__":
    app = QApplication(sys.argv)
    # 实例化主窗口
    main_ui = MainForm()
    main_ui.show()

    # 实例化子窗口
    rst_ui = RstForm()

    sys.exit(app.exec())
