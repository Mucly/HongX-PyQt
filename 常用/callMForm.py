from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.QtCore import *
from MForm import Ui_MainWindow
import os
import sys


class MainForm(QMainWindow, Ui_MainWindow):

    def __init__(self):
        super(MainForm, self).__init__()
        self.setupUi(self)
        self.initUi()
        self.initVar()
        self.initWidgets()
        self.initSlots()

    def initUi(self):
        #　居中显示，并固定窗口大小
        screen = QDesktopWidget().screenGeometry()  # 计算当前显示器的分辨率
        size = self.geometry()  # 该语句用来获取 QWidget 窗口的大小（size.width,size.height）
        self.move((screen.width() - size.width()) / 2,
                  (screen.height() - size.height()) / 2)  # 以左上角为基准，将窗口移动到屏幕的中间位置
        self.setFixedSize(self.width(), self.height())  # 窗口无法拖动

        # 设置气泡提示
        QToolTip.setFont(QFont('hack', 10))
        self.setToolTip('气泡提示内容，支持html格式')

        # 底部提示
        self.status = self.statusBar()
        self.statusBar.showMessage('仅用内部学习交流使用 -- Chenly')

    # Chenly 2018-09-07 读取配置信息
    def rdReg(self):  # #1 PART3
        for key, value in self.cellMap.items():
            value.setText(self.settings.value(key))

    # Chenly 2018-09-07 保存配置信息
    def wr2Reg(self):  # #1 PART4
        for key, value in self.cellMap.items():
            self.settings.setValue(key, QVariant(value.text()))

    # 通过注册表获取桌面路径
    def getDeskTop(self):
        key = winreg.OpenKey(winreg.HKEY_CURRENT_USER,
                             r'Software\Microsoft\Windows\CurrentVersion\Explorer\Shell Folders')
        return winreg.QueryValueEx(key, "Desktop")[0]

    # Chenly 2018-09-07 提示信息
    def Msg(self):
        reply = QMessageBox.warning(
            self, "版本确认", "程式版本日期是否已做修改？", QMessageBox.Yes | QMessageBox.No, QMessageBox.No)
        if reply == QMessageBox.No:
            QMessageBox.about(
                self, "???", "Cancel")

    def initVar(self):
        # 注册表#1 PART1
        self.settings = QSettings(
            "TechMation\\Muc\\tools", "undefined")

        # 映射表 #1 PART2
        self.cellMap = {
            "firm": self.firm,
            "vers": self.vers,
            "progm_store": self.progm_store,
            "HMI_ip": self.HMI_ip,
            "HMI_account": self.HMI_account,
            "HMI_passwd": self.HMI_passwd,
            "HMI_port": self.HMI_port,
        }

    def initWidgets(self):
        pass

    def fileAndFolder(self):
        folderVar = QFileDialog.getExistingDirectory(
            self, "选取文件夹", "./")  # 起始路径

        fileVar = QFileDialog.getOpenFileName(
            self, "Open File Dialog", "/", "Python files(*.py);;Text files(*.txt)")  # 两个分号是换行效果，同时表示可选前后两种类型文件，括号里限制类型，返回一个tuple(path，fileFilter)

    # 根据当前系统日期设置时间 A-10， B-11， C-12 ...
    def setCurDate(self):
        tmp = time.strftime("%y%m%d")
        if int(tmp[2:4]) > 9:
            month = chr(int(tmp[2:4]) + 55)
        else:
            month = tmp[3]

        if int(tmp[4:]) > 9:
            day = chr(int(tmp[4:]) + 55)
        else:
            day = tmp[5]

        cur_date = tmp[0:2] + month + day
        # self.date.setText(cur_date)

    def initSlots(self):
        # self.btnName.clicked.connect(self.fnName)

if __name__ == "__main__":
    app = QApplication(sys.argv)
    TestLogic1 = MainForm()
    TestLogic1.show()
    sys.exit(app.exec())
