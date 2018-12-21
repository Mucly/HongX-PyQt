# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'rstDialog.ui'
#
# Created by: PyQt5 UI code generator 5.10.1
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_Dialog(object):
    def setupUi(self, Dialog):
        Dialog.setObjectName("Dialog")
        Dialog.resize(1200, 820)
        self.listViewResult = QtWidgets.QListView(Dialog)
        self.listViewResult.setGeometry(QtCore.QRect(10, 10, 1180, 800))
        self.listViewResult.setObjectName("listViewResult")

        self.retranslateUi(Dialog)
        QtCore.QMetaObject.connectSlotsByName(Dialog)

    def retranslateUi(self, Dialog):
        _translate = QtCore.QCoreApplication.translate
        Dialog.setWindowTitle(_translate("Dialog", "Dialog"))

