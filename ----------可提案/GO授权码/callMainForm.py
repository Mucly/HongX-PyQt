from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.QtCore import *
from MainWindows import Ui_Form
import sys


class MainForm(QWidget, Ui_Form):

    def __init__(self):
        super(MainForm, self).__init__()
        self.setupUi(self)
        self.initWidgets()
        self.initSlots()

    def initWidgets(self):
        # 特征码
        hexreg = QRegExp('[0-9a-fA-F]+')
        hex_validator = QRegExpValidator(self)
        hex_validator.setRegExp(hexreg)
        self.lineEdit_FeatureCode.setValidator(hex_validator)

        # 月份
        month_validator = QIntValidator(self)
        month_validator.setRange(1, 12)
        self.lineEdit_Month.setValidator(month_validator)

        # 日
        day_validator = QIntValidator(self)
        day_validator.setRange(1, 31)
        self.lineEdit_Day.setValidator(day_validator)

        # 年
        year_validator = QIntValidator(self)
        year_validator.setRange(2018, 9999)
        self.lineEdit_Year.setValidator(year_validator)

    def initSlots(self):
        self.pushButton_AuthorizedCode.clicked.connect(self.calcAuthorized)

    def calcAuthorized(self):           # 00C792504375
        open_day = int(self.lineEdit_Day.text())
        open_month = int(self.lineEdit_Month.text())
        open_year = int(self.lineEdit_Year.text())

        FeatureCode_sorted = self.lineEdit_FeatureCode.text()[::-1]

        if (len(FeatureCode_sorted) == 12):
            part1 = (int(str(FeatureCode_sorted[0:4]), 16)) ^ (
                open_day + 0x1234)
            part2 = (int(str(FeatureCode_sorted[4:8]), 16)) ^ (
                open_month + 0x5612)
            part3 = (int(str(FeatureCode_sorted[8:]), 16)) ^ (
                3 * open_year + 0x3456)
            authorizedCode = str("%04X " % part1) + \
                str("%04X " % part2) + str("%04X " % part3)
            self.lineEdit_AuthorizedCode.setText(authorizedCode)
            # print(authorizedCode)
        else:
            self.lineEdit_AuthorizedCode.setText("请输入正确的特征码")

if __name__ == "__main__":
    app = QApplication(sys.argv)
    TestLogic1 = MainForm()
    TestLogic1.show()
    sys.exit(app.exec())
