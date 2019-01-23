# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'MainForm.ui'
#
# Created by: PyQt5 UI code generator 5.10.1
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_MainForm(object):
    def setupUi(self, MainForm):
        MainForm.setObjectName("MainForm")
        MainForm.resize(472, 319)
        self.btn_F2U = QtWidgets.QPushButton(MainForm)
        self.btn_F2U.setGeometry(QtCore.QRect(140, 40, 201, 101))
        font = QtGui.QFont()
        font.setFamily("Hack")
        font.setPointSize(23)
        self.btn_F2U.setFont(font)
        self.btn_F2U.setObjectName("btn_F2U")
        self.label = QtWidgets.QLabel(MainForm)
        self.label.setGeometry(QtCore.QRect(10, 140, 461, 101))
        font = QtGui.QFont()
        font.setFamily("Hack")
        font.setPointSize(10)
        self.label.setFont(font)
        self.label.setObjectName("label")
        self.label_2 = QtWidgets.QLabel(MainForm)
        self.label_2.setGeometry(QtCore.QRect(130, 280, 341, 21))
        font = QtGui.QFont()
        font.setFamily("Hack")
        font.setPointSize(15)
        self.label_2.setFont(font)
        self.label_2.setObjectName("label_2")

        self.retranslateUi(MainForm)
        QtCore.QMetaObject.connectSlotsByName(MainForm)

    def retranslateUi(self, MainForm):
        _translate = QtCore.QCoreApplication.translate
        MainForm.setWindowTitle(_translate("MainForm", "Form"))
        self.btn_F2U.setText(_translate("MainForm", "生成F2U.c\n"
                                        "（需0.5-3s）"))
        self.label.setText(_translate(
            "MainForm", "<html><head/><body><p><span style=\" font-size:16pt; color:#d8006c;\">使用前</span>请将出货的字串文件夹中占用空间最大的C20文件放至桌面！</p><p>例：将String_20180416145339（字串文件夹名字）中的xFontjpn.C20</p><p>（注：所有C20文件中占用空间最大）放至桌面</p></body></html>"))
        self.label_2.setText(_translate("MainForm", "仅供内部交流使用 -- Chenly"))
