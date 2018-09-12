# coding:utf-8
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.QtCore import *
from MainForm import Ui_MainWindow
from getDeskPath import getDesktop
import os
import sys
import shutil


class MainForm(QMainWindow, Ui_MainWindow):

    def __init__(self):
        super(MainForm, self).__init__()
        # pass
        self.setupUi(self)
        self.setWindowTitle("字体自动替换工具 -- Muc")
        self.setWindowIcon(QIcon('../images/doge.jpg'))
        """ global variable """
        # button_54_clicked    = 0    # 后续以flag区分，缩短代码量，增加可读性
        self.jpn_B16 = 'xFontjpn.B16'
        self.chn_B16 = 'xFontchn.B16'

        self.jpn_B20 = 'xFontjpn.B20'
        self.chn_B20 = 'xFontchn.B20'

        self.fontFiles = 'String_20'
        self.Desktop = getDesktop()

        """ slot """
        self.pushButton_54.clicked.connect(self.font54_repl)
        self.pushButton_55_270.clicked.connect(self.font55_270_repl)
        self.pushButton_55_3354.clicked.connect(self.font55_3354_repl)

    def showMsg(self):
        QMessageBox.warning(self, "aha？",
                            self.tr("请将出货的字串文件夹放至桌面!"))

    def font54_repl(self):
        self.label_Prompt.setText("处理中，请稍后！")
        font_type = '.txt'
        dst = self.lineEdit_54.text()
        String_path = None
        # 获取桌面String文件夹名
        for search_files in os.listdir(self.Desktop):
            if self.fontFiles in search_files:
                String_path = search_files
                break
        if String_path == None:
            self.showMsg()
            # pixmap = QPixmap("../images/catchDog.jpg")
            # self.label_images.setPixmap(pixmap)
            return 0

        # 将String文件夹内的font.txt和.B16/20文件复制到目标路径
        String_filelist = os.listdir(self.Desktop + os.sep + String_path)
        for cp_files in String_filelist:
            if font_type in cp_files:
                shutil.copy(self.Desktop + os.sep +
                            String_path + os.sep + cp_files, dst)
            elif self.jpn_B16 in cp_files:
                shutil.copy(self.Desktop + os.sep + String_path +
                            os.sep + cp_files, dst + self.chn_B16)
            elif self.jpn_B20 in cp_files:
                shutil.copy(self.Desktop + os.sep + String_path +
                            os.sep + cp_files, dst + self.chn_B20)

        self.label_Prompt.setText("已处理！请手动删除桌面上的font文件")
        # self.label_images.setPixmap(QPixmap("../images/husky.jpg"))
        # shutil.rmtree(Desktop() + String_path)

    def font55_270_repl(self):
        font_type = '.txt'
        dst = self.lineEdit_55_270.text()
        String_path = None
        # 获取桌面String文件夹名
        for search_files in os.listdir(self.Desktop):
            if self.fontFiles in search_files:
                String_path = search_files
                break
        if String_path == None:
            self.showMsg()
            # self.label_images.setPixmap(QPixmap("../images/catchDog.jpg"))
            return 0
        # 将String文件夹内的font.txt和.B16/20文件复制到目标路径
        String_filelist = os.listdir(self.Desktop + os.sep + String_path)
        for cp_files in String_filelist:
            if font_type in cp_files:
                shutil.copy(self.Desktop + os.sep +
                            String_path + os.sep + cp_files, dst)
            elif self.jpn_B16 in cp_files:
                shutil.copy(self.Desktop + os.sep + String_path +
                            os.sep + cp_files, dst + self.chn_B16)
            elif self.jpn_B20 in cp_files:
                shutil.copy(self.Desktop + os.sep + String_path +
                            os.sep + cp_files, dst + self.chn_B20)

        self.label_Prompt.setText("已处理！请手动删除桌面上的font文件")
        # self.label_images.setPixmap(QPixmap("../images/husky.jpg"))
        # shutil.rmtree(Desktop() + String_path)

    def font55_3354_repl(self):
        font_type = '.xml'
        dst = self.lineEdit_55_3354.text()
        String_path = None
        # 获取桌面String文件夹名
        for search_files in os.listdir(self.Desktop):
            if self.fontFiles in search_files:
                String_path = search_files
                break
        if String_path == None:
            self.showMsg()
            # self.label_images.setPixmap(QPixmap("../images/catchDog.jpg"))
            return 0
        # 将String文件夹内的font.txt和.B16/20文件复制到目标路径
        String_filelist = os.listdir(self.Desktop + os.sep + String_path)
        for cp_files in String_filelist:
            if font_type in cp_files:
                shutil.copy(self.Desktop + os.sep +
                            String_path + os.sep + cp_files, dst)

        self.label_Prompt.setText("已处理！请手动删除桌面上的font文件")
        # self.label_images.setPixmap(QPixmap("../images/husky.jpg"))


if __name__ == "__main__":
    app = QApplication(sys.argv)
    form = MainForm()
    form.show()
    sys.exit(app.exec())
