# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'dbid0Widget.ui'
#
# Created by: PyQt5 UI code generator 5.10.1
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_dbid0(object):
    def setupUi(self, dbid0):
        dbid0.setObjectName("dbid0")
        dbid0.resize(1200, 820)
        font = QtGui.QFont()
        font.setFamily("Hack")
        font.setPointSize(12)
        font.setBold(False)
        font.setWeight(50)
        dbid0.setFont(font)
        self.TabDbid0 = QtWidgets.QTableWidget(dbid0)
        self.TabDbid0.setGeometry(QtCore.QRect(10, 10, 1180, 800))
        self.TabDbid0.setObjectName("TabDbid0")
        self.TabDbid0.setColumnCount(0)
        self.TabDbid0.setRowCount(0)

        self.retranslateUi(dbid0)
        QtCore.QMetaObject.connectSlotsByName(dbid0)

    def retranslateUi(self, dbid0):
        _translate = QtCore.QCoreApplication.translate
        dbid0.setWindowTitle(_translate("dbid0", "验证结果 #2 dbid0"))

