# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'checkRstTab.ui'
#
# Created by: PyQt5 UI code generator 5.10.1
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_rst(object):
    def setupUi(self, rst):
        rst.setObjectName("rst")
        rst.resize(1021, 656)
        self.gridLayout = QtWidgets.QGridLayout(rst)
        self.gridLayout.setObjectName("gridLayout")
        self.tabWidget = QtWidgets.QTabWidget(rst)
        self.tabWidget.setEnabled(True)
        font = QtGui.QFont()
        font.setFamily("微软雅黑")
        font.setPointSize(12)
        font.setBold(False)
        font.setItalic(False)
        font.setUnderline(False)
        font.setWeight(50)
        font.setStrikeOut(False)
        font.setKerning(True)
        self.tabWidget.setFont(font)
        self.tabWidget.setTabPosition(QtWidgets.QTabWidget.North)
        self.tabWidget.setTabShape(QtWidgets.QTabWidget.Triangular)
        self.tabWidget.setIconSize(QtCore.QSize(20, 20))
        self.tabWidget.setElideMode(QtCore.Qt.ElideLeft)
        self.tabWidget.setDocumentMode(True)
        self.tabWidget.setTabsClosable(False)
        self.tabWidget.setMovable(False)
        self.tabWidget.setTabBarAutoHide(False)
        self.tabWidget.setObjectName("tabWidget")
        self.tabTitleID = QtWidgets.QWidget()
        self.tabTitleID.setObjectName("tabTitleID")
        self.gridLayout_2 = QtWidgets.QGridLayout(self.tabTitleID)
        self.gridLayout_2.setObjectName("gridLayout_2")
        self.listViewTitleID = QtWidgets.QListView(self.tabTitleID)
        font = QtGui.QFont()
        font.setFamily("微软雅黑")
        font.setPointSize(12)
        font.setBold(False)
        font.setWeight(50)
        font.setStyleStrategy(QtGui.QFont.PreferAntialias)
        self.listViewTitleID.setFont(font)
        self.listViewTitleID.setObjectName("listViewTitleID")
        self.gridLayout_2.addWidget(self.listViewTitleID, 0, 0, 1, 1)
        self.tabWidget.addTab(self.tabTitleID, "")
        self.tabSo = QtWidgets.QWidget()
        self.tabSo.setObjectName("tabSo")
        self.gridLayout_3 = QtWidgets.QGridLayout(self.tabSo)
        self.gridLayout_3.setObjectName("gridLayout_3")
        self.listViewSo = QtWidgets.QListView(self.tabSo)
        font = QtGui.QFont()
        font.setFamily("微软雅黑")
        font.setPointSize(12)
        font.setBold(False)
        font.setWeight(50)
        self.listViewSo.setFont(font)
        self.listViewSo.setObjectName("listViewSo")
        self.gridLayout_3.addWidget(self.listViewSo, 0, 0, 1, 1)
        self.tabWidget.addTab(self.tabSo, "")
        self.tabTaborder = QtWidgets.QWidget()
        self.tabTaborder.setObjectName("tabTaborder")
        self.gridLayout_4 = QtWidgets.QGridLayout(self.tabTaborder)
        self.gridLayout_4.setObjectName("gridLayout_4")
        self.listViewTaborder = QtWidgets.QListView(self.tabTaborder)
        font = QtGui.QFont()
        font.setFamily("微软雅黑")
        font.setPointSize(12)
        font.setBold(False)
        font.setWeight(50)
        self.listViewTaborder.setFont(font)
        self.listViewTaborder.setObjectName("listViewTaborder")
        self.gridLayout_4.addWidget(self.listViewTaborder, 0, 0, 1, 1)
        self.tabWidget.addTab(self.tabTaborder, "")
        self.tabPwnd = QtWidgets.QWidget()
        self.tabPwnd.setObjectName("tabPwnd")
        self.gridLayout_5 = QtWidgets.QGridLayout(self.tabPwnd)
        self.gridLayout_5.setObjectName("gridLayout_5")
        self.listViewPwnd = QtWidgets.QListView(self.tabPwnd)
        font = QtGui.QFont()
        font.setFamily("微软雅黑")
        font.setPointSize(12)
        font.setBold(False)
        font.setWeight(50)
        self.listViewPwnd.setFont(font)
        self.listViewPwnd.setObjectName("listViewPwnd")
        self.gridLayout_5.addWidget(self.listViewPwnd, 0, 0, 1, 1)
        self.tabWidget.addTab(self.tabPwnd, "")
        self.tabDBID0 = QtWidgets.QWidget()
        self.tabDBID0.setObjectName("tabDBID0")
        self.gridLayout_6 = QtWidgets.QGridLayout(self.tabDBID0)
        self.gridLayout_6.setObjectName("gridLayout_6")
        self.tableWidgetDBID0 = QtWidgets.QTableWidget(self.tabDBID0)
        self.tableWidgetDBID0.setObjectName("tableWidgetDBID0")
        self.tableWidgetDBID0.setColumnCount(0)
        self.tableWidgetDBID0.setRowCount(0)
        self.gridLayout_6.addWidget(self.tableWidgetDBID0, 0, 0, 1, 1)
        self.tabWidget.addTab(self.tabDBID0, "")
        self.gridLayout.addWidget(self.tabWidget, 0, 0, 1, 1)

        self.retranslateUi(rst)
        self.tabWidget.setCurrentIndex(0)
        QtCore.QMetaObject.connectSlotsByName(rst)

    def retranslateUi(self, rst):
        _translate = QtCore.QCoreApplication.translate
        rst.setWindowTitle(_translate("rst", "验证结果"))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tabTitleID), _translate("rst", "titleID丢失"))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tabSo), _translate("rst", "so丢失"))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tabTaborder), _translate("rst", "taborder重复"))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tabPwnd), _translate("rst", "元件名重复"))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tabDBID0), _translate("rst", "dbid0重复"))

