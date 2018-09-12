# codingLutf-8
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.QtCore import *
from MForm import Ui_MainWindow
from color import *
import os
import sys
import re
import datetime


class MainForm(QMainWindow, Ui_MainWindow):

    def __init__(self):
        super(MainForm, self).__init__()
        self.setupUi(self)
        self.initUi()
        self.initVariable()
        self.initMainWinSubComponent()
        self.initSlots()

    def initUi(self):
        #　居中显示，并固定窗口大小
        screen = QDesktopWidget().screenGeometry()  # 计算当前显示器的分辨率
        size = self.geometry()  # 该语句用来获取 QWidget 窗口的大小（size.width,size.height）
        self.move((screen.width() - size.width()) / 2,
                  (screen.height() - size.height()) / 2)  # 以左上角为基准，将窗口移动到屏幕的中间位置
        self.setFixedSize(self.width(), self.height())  # 窗口无法拖动

        self.actionHelp_doc.triggered.connect(self.helpMsg)

        self.status = self.statusBar()
        self.status.showMessage('仅用内部学习交流使用，Alt + h可查看帮助文档 -- Chenly')

    def initVariable(self):
        self.pe = QPalette()    # 创建QPalette实例
        self.btn_status_cnt = 0  # 判断按钮状态，用于按钮显示字串切换

        num_reg = QRegExp('[0-9a-fA-F]+[xX]?[0-9a-fA-F]+')
        self.num_validator = QRegExpValidator(self)
        self.num_validator.setRegExp(num_reg)

        self.color = ''
        self.RGB = ''

        # self.pe.setColor(QPalette.Window, QColor(16, 168, 224))  # just for test
        # self.lb_ShowColor.setPalette(self.pe)

    def initMainWinSubComponent(self):
        self.ed_RGB.setEnabled(False)
        self.btn_ShowColor.setText("确认（DEC）")

        # validator
        self.ed_565.setValidator(self.num_validator)
        self.ed_888.setValidator(self.num_validator)

        # 设置悬浮提示
        self.ed_565.setPlaceholderText("digital")
        self.ed_888.setPlaceholderText("digital")
        self.ed_RGB.setPlaceholderText('Show Only')

    def initSlots(self):
        self.btn_ShowColor.clicked.connect(self.showColor)
        self.actionClose.triggered.connect(self.close)

    def showNum1Str(self, edit, want_num_sys):
        if want_num_sys == show_hex:
            if edit.text() != '':
                if edit.text().isdecimal() == False:
                    edit.setText(dec2str(edit.text(), 16))
        else:
            if edit.text().isdecimal():
                edit.setText(hex2str_0x(edit.text()))

    def showColor(self):
        if self.ed_565.text() == '' and self.ed_888.text() == '':
            return 1

        # 按钮显示当前进制类型
        self.btn_status_cnt += 1
        # 十进制的处理
        if (self.btn_status_cnt % 2 == 0):
            self.btn_ShowColor.setText("确认（DEC）")

            if self.ed_565.text() != '':
                self.ed_888.setText(rgb565To888(self.ed_888.text()))
            elif self.ed_888.text() != '':
                self.ed_565.setText(rgb888To565(self.ed_888.text()))

            self.showNum1Str(self.ed_565, show_hex)
            self.showNum1Str(self.ed_888, show_hex)
            if self.ed_888.text() != '':
                self.color = re.sub('0x', '#', str(
                    hex(int(self.ed_888.text()))))

            self.RGB = str(hex(int(self.ed_888.text()))).replace('0x', '', 1)
        # 十六进制的处理
        else:
            self.btn_ShowColor.setText("确认（HEX）")

            if self.ed_565.text() != '' and self.ed_888.text() == '':
                self.ed_888.setText(rgb565To888(self.ed_565.text()))
            elif self.ed_888.text() != '' and self.ed_565.text() == '':
                self.ed_565.setText(rgb888To565(self.ed_888.text()))
            else:
                pass
            self.showNum1Str(self.ed_565, show_dec)
            self.showNum1Str(self.ed_888, show_dec)

            if self.ed_888.text() != '':
                self.color = re.sub('0x', '#', self.ed_888.text())
            self.RGB = self.ed_888.text().replace('0x', '')

        # print('before: ' +  self.RGB)
        self.RGB = self.RGB.rjust(6, '0')
        # print('after: ' +  self.RGB)
        self.ed_RGB.setText(hex2str(
            self.RGB[0:2]) + ', ' + hex2str(self.RGB[2:4]) + ', ' + hex2str(self.RGB[4:6]))

        self.pe.setColor(QPalette.Window, QColor(self.color))  # 以RGB888为准
        self.lb_ShowColor.setPalette(self.pe)

    def helpMsg(self):
        reply = QMessageBox.about(self, 'Help Doc',  '如何操作：\n\
    1、进制转换暂以按钮旁边的字串显示为准：DEC表示当前显示为十进制\n\
    2、暂未增加edit追踪功能，故每次使用前请先按下清除按钮\n\
    3、以RGB888为准显示颜色\n\
    5、按下Esc可快速结束此工具进程')


if __name__ == "__main__":
    app = QApplication(sys.argv)
    TestLogic1 = MainForm()
    TestLogic1.show()
    sys.exit(app.exec())
