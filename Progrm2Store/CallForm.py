# coding:utf-8
# version:python 3.6
# Author:Chenly

from PyQt5.QtWidgets import *
from PyQt5.QtCore import *
from PyQt5.QtGui import *
from MainForm import Ui_MainWindow
from getDeskPath_win import getDesktop
import sys
import os
import shutil
import time
# import shutil

# # TODO : 4.112 V:\updateMMI\program -> Z:\NEWPROGRAM\7HT(海天)\3354\完整版 or 配置版
# # TODO : W:\updateMMI\program -> Z:\NEWPROGRAM\7HT(海天)\270_M12M\完整版 or 配置版
# # TODO : W:\updateMMI\program -> Z:\NEWPROGRAM\7HT(海天)\270_M12M_5528\完整版 or 配置版

# shutil.copy(r'V:\updateMMI\7HT_TF75LOCT_185M_update.rar', r'Z:\NEWPROGRAM\7HT(海天)')


class CallMainForm(Ui_MainWindow, QMainWindow):

    def __init__(self):
        super(CallMainForm, self).__init__()

        # dispaly
        self.setupUi(self)
        self.initVariate()
        self.initUi()
        self.initCell()
        self.initMenu()

        # slots and emit
        self.initSlots()

    def initVariate(self):
        # create a temp fold in desktop for save programs temporary
        self.desktop = getDesktop()
        self.temp_dir = os.path.join(self.desktop, 'prgm temp')

        self.vm_path_M12 = 'W:\updateMMI'
        self.vm_path_3354 = 'V:\updateMMI'

        self.localtime = time.time()
        print (time.strftime("%a %b %d %H:%M:%S %Y", self.localtime.localtime()))

    def initCell(self):
        # statusbar
        self.status = self.statusBar()
        self.status.setLayoutDirection(Qt.LeftToRight)
        self.status.showMessage("按Esc直接退出，仅做内部交流使用 -- Chenly")

    def initSlots(self):
        self.btn_Prgm2Storage.clicked.connect(self.prgm2Storage)

    def initUi(self):
        # setWindows AlignCenter
        screen = QDesktopWidget().screenGeometry()
        size = self.geometry()
        self.move((screen.width() - size.width()) / 2,
                  (screen.height() - size.height()) / 2)

    def initMenu(self):
        self.WindowsCloseAction.triggered.connect(self.close)

    # 提示信息
    def delMsg(self):
        reply = QMessageBox.question(self, 'Information', '是否删除桌面生成的Prgm Temp文件夹?',
                                     QMessageBox.Yes | QMessageBox.Cancel, QMessageBox.Cancel)
        if reply == QMessageBox.Yes:
            os.removedirs(self.temp_dir)

    def prgm2Storage(self):
        if not os.path.exists(self.temp_dir):
            os.mkdir(self.temp_dir)
            self.delMsg()

        self.prgm_list = []
        self.prgm_zip_list = []

        for file in os.path.listdir(self.vm_path_M12):
            if file.

if __name__ == '__main__':
    app = QApplication(sys.argv)
    MainWin = CallMainForm()
    MainWin.show()
    sys.exit(app.exec())
