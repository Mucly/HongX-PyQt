# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'MainForm.ui'
#
# Created by: PyQt5 UI code generator 5.9.1
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(521, 389)
        MainWindow.setLayoutDirection(QtCore.Qt.LeftToRight)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.btn_Prgm2Storage = QtWidgets.QPushButton(self.centralwidget)
        self.btn_Prgm2Storage.setGeometry(QtCore.QRect(30, 80, 161, 41))
        self.btn_Prgm2Storage.setObjectName("btn_Prgm2Storage")
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 521, 26))
        self.menubar.setObjectName("menubar")
        self.menu = QtWidgets.QMenu(self.menubar)
        self.menu.setObjectName("menu")
        self.menu_F = QtWidgets.QMenu(self.menubar)
        self.menu_F.setObjectName("menu_F")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setLayoutDirection(QtCore.Qt.RightToLeft)
        self.statusbar.setAutoFillBackground(True)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)
        self.WindowsCloseAction = QtWidgets.QAction(MainWindow)
        self.WindowsCloseAction.setObjectName("WindowsCloseAction")
        self.actionNone = QtWidgets.QAction(MainWindow)
        self.actionNone.setObjectName("actionNone")
        self.menu.addAction(self.WindowsCloseAction)
        self.menu_F.addAction(self.actionNone)
        self.menubar.addAction(self.menu_F.menuAction())
        self.menubar.addAction(self.menu.menuAction())

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.btn_Prgm2Storage.setText(_translate("MainWindow", "程式自动入库"))
        self.menu.setTitle(_translate("MainWindow", "Other(O)"))
        self.menu_F.setTitle(_translate("MainWindow", "File(F)"))
        self.WindowsCloseAction.setText(_translate("MainWindow", "Close"))
        self.WindowsCloseAction.setShortcut(_translate("MainWindow", "Esc"))
        self.actionNone.setText(_translate("MainWindow", "None"))

