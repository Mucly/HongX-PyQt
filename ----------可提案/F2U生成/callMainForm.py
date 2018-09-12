from MainForm import Ui_MainForm
from PyQt5.QtGui import *
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
import sys
import os
import winreg
import re


def getDesktop():
    key = winreg.OpenKey(
        winreg.HKEY_CURRENT_USER, r'Software\Microsoft\Windows\CurrentVersion\Explorer\Shell Folders')
    return winreg.QueryValueEx(key, "Desktop")[0]


class MainWindos(QWidget, Ui_MainForm):

    def __init__(self):
        super(MainWindos, self).__init__()
        self.setupUi(self)
        QToolTip.setFont(QFont('hack', 18))
        self.setToolTip(
            '以后有时间优化项目： \n1、自动判断String文件夹中最大的C20文件\n2、进度提示\n3、弹出路径or自动放至剪贴板内')
        self.initSlot()

    def initSlot(self):
        self.btn_F2U.clicked.connect(self.createF2U)

    def createF2U(self):
        desk_path = getDesktop()
        C20_file_bigest = ''

        for desk_files in os.listdir(desk_path):
            if ('.C20' in os.path.splitext(desk_files)[1]):
                C20_file_bigest = desk_path + os.sep + desk_files
                break

        if C20_file_bigest == '':
            self.promptMessage()
        else:
            jpnC20_file = open(C20_file_bigest, 'r')
            f2u_file = open(desk_path + os.sep + 'F2U.c', 'w+')

            HOF = '#include "F2U.h"\nFONT2UNICODE	Font2Unicode[]=\n{\n'

            EOF = '};'

            chines_pattern = re.compile(
                r'((0x5[0-5][0-9A-F]{2})(\s)(0x\w{4}))')
            f2u_file.write(HOF)
            for c20line in jpnC20_file.readlines():
                if (re.search(chines_pattern, c20line)):
                    temp = '	{' + re.search(chines_pattern, c20line).group(2) + ',' + re.search(
                        chines_pattern, c20line).group(4) + '}' + ',' + '\n'
                    f2u_file.write(temp)
            f2u_file.write(EOF)

            jpnC20_file.close()
            f2u_file.close()
            self.msgDone()

    def promptMessage(self):
        QMessageBox.information(self, "Warning",
                                self.tr("请将最大的C20文件放至桌面!"))

    def msgDone(self):
        reply = QMessageBox.information(self, "prompt",
                                        self.tr("F2U.c已在桌面生成!"), QMessageBox.Yes)
        if reply == QMessageBox.Yes:
            self.close()

if __name__ == '__main__':

    app = QApplication(sys.argv)
    MainWin = MainWindos()
    MainWin.show()
    sys.exit(app.exec_())
