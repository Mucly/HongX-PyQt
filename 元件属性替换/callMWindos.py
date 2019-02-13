from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.QtCore import *
from Mwindos import Ui_MainWindow
from subCellAttr import rplcCell, get_desktop
import os
import sys
import time


class MainForm(QMainWindow, Ui_MainWindow):

    def __init__(self):
        super(MainForm, self).__init__()
        self.setupUi(self)

        self.initUi()
        self.initVar()
        self.initWidgets()
        self.initSlots()

    def initUi(self):
        QToolTip.setFont(QFont('hack', 12))
        self.status = self.statusBar()
        self.status.setLayoutDirection(Qt.RightToLeft)
        self.status.showMessage('仅供内部学习交流使用 v1.0.0 -- Chenly')
        self.setToolTip("功能介绍：\n\
  1、替换\删除指定form下所有的txt画面脚本的元件属性\n\
  2、输入合适的参数后按下Go按钮，将在桌面生成替换\删除后的txt画面脚本文件夹，范例： form 02-13 [16;28;46]\n\
  3、按下Esc可快速结束该工具进程\n\
  4、暂未加入进度提示功能")
        self.setFixedSize(self.width(), self.height())

    def initVar(self):
        self._cellMap = {
            "fold_path": self.ed_fold_path,  # key为保存到注册表的名字，后面是元件
            "cell_type": self.ed_cell_type,
            "cell_key": self.ed_cell_key,
            "cell_val": self.ed_cell_val,
        }

        self.code_list = ['utf-8', 'big5']
        self.folderPath = ""
        self._settings = QSettings(
            "TechMation\\Chenly\\Qt-tools", "pwndRplc")

        self.readRegInfo()

    def initWidgets(self):
        self.cb_orig_code.addItems(self.code_list)
        self.cb_orig_code.setToolTip('最原始文档一般为big5，选择错误的编码会导致注释乱码')

        self.cb_exp_code.addItems(self.code_list)
        self.cb_exp_code.setToolTip('No prompt')

    def rplCellAttr(self):
        if (os.path.exists(self.ed_fold_path.text())
            and self.ed_cell_type.text() != ''
                and self.ed_cell_key.text() != ''):
            # 执行替换函数
            rplcCell(self.ed_fold_path.text(), self.ed_cell_type.text(),
                     self.ed_cell_key.text(), self.ed_cell_val.text(),
                     self.cb_orig_code.currentText(),
                     self.cb_exp_code.currentText())
            QMessageBox.about(self, '提示', '已在桌面生成form x-x [x;x;x]文件夹！')
            self.writeInfo2Reg()
        else:
            QMessageBox.about(self, 'about', '请输入/选择正确的数据')

    def getFolder(self):
        self.folderPath = QFileDialog.getExistingDirectory(
            self, "选取文件夹", "./")  # 起始路径
        self.ed_fold_path.setText(self.folderPath)

    def readRegInfo(self):  # Chenly 2018-09-07 读取配置信息
        for key, value in self._cellMap.items():
            if self._settings.value(key) is not None:
                value.setText(self._settings.value(key))

    def writeInfo2Reg(self):   # Chenly 2018-09-07 保存配置信息
        for key, value in self._cellMap.items():
            self._settings.setValue(key, QVariant(value.text()))

    def initSlots(self):
        self.actionClose_Esc.triggered.connect(self.close)
        self.btn_Go.clicked.connect(self.rplCellAttr)
        self.btn_fold.clicked.connect(self.getFolder)


if __name__ == "__main__":
    app = QApplication(sys.argv)
    TestLogic1 = MainForm()
    TestLogic1.show()
    sys.exit(app.exec())
