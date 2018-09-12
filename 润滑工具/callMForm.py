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
        self.initVariable()
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

    def initVariable(self):
        pass

    def initWidgets(self):
        pass

    def initSlots(self):
        pass

if __name__ == "__main__":
    app = QApplication(sys.argv)
    TestLogic1 = MainForm()
    TestLogic1.show()
    sys.exit(app.exec())
