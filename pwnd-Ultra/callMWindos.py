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
        self.initVariable()
        self.initWidgets()
        self.initSlots()

    def initUi(self):
        QToolTip.setFont(QFont('hack', 12))
        self.status = self.statusBar()
        self.status.setLayoutDirection(Qt.RightToLeft)
        self.status.showMessage('仅供内部学习交流使用 -- Chenly')
        self.setToolTip("功能介绍：\n\
  1、替换\删除指定form下所有的txt画面脚本的元件属性\n\
  2、输入合适的参数后按下Go按钮，将在桌面生成替换\删除后的txt画面脚本\n\
  3、按下Esc可快速结束该工具进程\n\
  4、暂未加入进度提示功能")
        self.setFixedSize(self.width(), self.height())

    def initVariable(self):
        self.code_list = ['utf-8', 'big5']

    def initWidgets(self):
        self.btn_chosefile.setEnabled(False)
        self.btn_chosefile.setToolTip('暂未加入此功能')

        self.cb_orig_code.addItems(self.code_list)
        self.cb_orig_code.setToolTip('最原始文档一般为big5，选择错误的编码会导致注释乱码')

        self.cb_exp_code.addItems(self.code_list)
        self.cb_exp_code.setToolTip('No prompt')

    def rplCellAttr(self):
        if (os.path.exists(self.lineEdit_rsc.text()) and self.lineEdit_CellType.text() != ''
                and self.lineEdit_CellKey.text() != ''):
            self.btn_Go.setEnabled(False)
            rplcCell(self.lineEdit_rsc.text(), self.lineEdit_CellType.text(),
                     self.lineEdit_CellKey.text(), self.lineEdit_CellValue.text(),
                     self.cb_orig_code.currentText(), self.cb_exp_code.currentText())
            QMessageBox.about(self, '提示', '已在桌面生成form文件夹！')
            self.btn_Go.setEnabled(True)
        else:
            QMessageBox.about(self, 'about', '请输入正确的数据')

    def initSlots(self):
        # self.lineEdit_rsc.setText(
        # r'V:\pxammi\7HT_3354_M12InjCur-nk\res_tm640\form')  #　just for test
        self.actionClose_Esc.triggered.connect(self.close)
        self.btn_Go.clicked.connect(self.rplCellAttr)


if __name__ == "__main__":
    app = QApplication(sys.argv)
    TestLogic1 = MainForm()
    TestLogic1.show()
    sys.exit(app.exec())
