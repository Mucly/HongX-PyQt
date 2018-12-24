# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'rstWidget.ui'
#
# Created by: PyQt5 UI code generator 5.10.1
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_rst(object):
    def setupUi(self, rst):
        rst.setObjectName("rst")
        rst.resize(1200, 820)
        font = QtGui.QFont()
        font.setFamily("Hack")
        font.setPointSize(10)
        font.setBold(True)
        font.setWeight(75)
        rst.setFont(font)
        self.listViewRst = QtWidgets.QListView(rst)
        self.listViewRst.setGeometry(QtCore.QRect(10, 10, 1180, 800))
        font = QtGui.QFont()
        font.setFamily("Hack")
        font.setPointSize(12)
        font.setBold(False)
        font.setWeight(50)
        self.listViewRst.setFont(font)
        self.listViewRst.setObjectName("listViewRst")

        self.retranslateUi(rst)
        QtCore.QMetaObject.connectSlotsByName(rst)

    def retranslateUi(self, rst):
        _translate = QtCore.QCoreApplication.translate
        rst.setWindowTitle(_translate("rst", "验证结果 #1"))

