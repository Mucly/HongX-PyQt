#!/usr/bin/
# coding:utf-8
# version:python 3.6
# Author:Chenly

# 待加入内容：
# 1、进度条
# 2、连线状态

from PyQt5.QtWidgets import *
from PyQt5.QtCore import *
from PyQt5.QtGui import *
from MainForm import Ui_MainWindow
import sys
import os
import shutil
import time
import paramiko
import winreg
import time


class MainForm(Ui_MainWindow, QMainWindow):

    def __init__(self):
        super(Ui_MainWindow, self).__init__()

        # display
        self.setupUi(self)
        self.initUi()
        self.initVar()
        self.initMenu()

        # slots and emit
        self.initSlots()

    def getPingResult(self):
        # ping_result = False # Chenly 2018-09-10 mark，pyinstaller后无法用ping命令
        # ping_cmd = f"ping -n 1 {self.HMI_ip.text()}"
        try:
            #     r = os.popen(ping_cmd)
            #     info = r.read()

            #     if f"无法访问" in info:
            #         QMessageBox.critical(
            #             self, 'err', '无法与指定ip地址进行网络通讯', QMessageBox.Abort)
            #     else:
            self.callSSH()
        except:
            self.btnMsg(False, "#1")
        finally:
            self.pBar.setValue(0)
            self.pBar.setVisible(False)
            self.btn_to_pack.setVisible(True)

    def cellMap(self):    # Chenly 2018-09-07 创建画面元件与其值的映射表关系
        self._cellMap = {
            "firm": self.firm,
            "vers": self.vers,
            # "date": self.date,
            "progm_store": self.progm_store,
            "HMI_ip": self.HMI_ip,
            "HMI_account": self.HMI_account,
            "HMI_passwd": self.HMI_passwd,
            "HMI_port": self.HMI_port,
        }

    def initWhenClick(self):
        # Chenly 2018-09-05 来源路径
        self._res = f'{self._sep}{self.HMI_ip.text()}{os.sep}{self._usr_path}'

        # Chenly 2018-09-07 7KK_PLC_188V_update
        self._plc_prefix = f"{self.firm.text()} {self.vers.text()} {self.date.text()}"
        self._plc_progm = self._plc_prefix.replace(' ', '_')

        # Chenly 2018-09-07 通过SSH进入面板后执行的shell
        self._shell_list = [
            # Chenly 2018-09-07 打包PLC程式
            f'cd /usr/ && ./{self._pack_sh} {self._plc_prefix}',
            f'cd /usr/local/samba/sbin/ && ./nmbd && ./smbd',  # Chenly 2018-09-07 开启samba服务
        ]

    def getDskTop(self):    # Chenly 2018-09-07 通过注册表获取桌面路径
        key = winreg.OpenKey(winreg.HKEY_CURRENT_USER,
                             r'Software\Microsoft\Windows\CurrentVersion\Explorer\Shell Folders')
        return winreg.QueryValueEx(key, "Desktop")[0]

    def move_plc(self, res, dst, plc_progm):
        file_list = os.listdir(res)
        for file in file_list:
            if file == plc_progm:
                os.chdir(res)
                plc_ultra = f'{dst}{os.sep}{file}.SYS'
                # Chenly 2018-09-07 桌面上假设已有同名程序则先删除
                if os.path.exists(plc_ultra):
                    shutil.rmtree(plc_ultra)
                shutil.copytree(file, plc_ultra)
                return 0

    # Chenly 2018-09-07 TODO 改为传参的方式
    def callSSH(self):
        self.initWhenClick()

        # Chenly 2018-09-10 版本日期确认
        reply = QMessageBox.warning(
            self, "版本确认", "程式版本日期是否已做修改？", QMessageBox.Yes | QMessageBox.No, QMessageBox.No)
        if reply == QMessageBox.No:
            QMessageBox.about(
                self, "???", "Cancel")
            return -1

        self.pBar.setVisible(True)
        # self.pBar.setText("处理中")
        self.pBar.setValue(20)

        result = {}
        ssh = paramiko.SSHClient()
        # 用于允许连接不在known_hosts名单中的主机
        ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
        try:
            time_out_flag = True
            tmp = ssh.connect(hostname=self.HMI_ip.text(), port=self.HMI_port.text(),
                              username=self.HMI_account.text(), password=self.HMI_passwd.text(), timeout=3)
            # for key in shell:
            #     stdin, stdout, stderr = ssh.exec_command(shell[key])
            #     result[key] = stdout.read(), stderr.read()

            # self.pBar_step = self.pBar_step + 10
            self.pBar.setValue(60)
            for shell in self._shell_list:
                ssh.exec_command(shell)

            if os.path.exists(self.progm_store.text()):
                self.move_plc(self._res, self.progm_store.text(),
                              self._plc_progm)

                # Chenly 2018-09-14 删除HMI/usr路径下生成的程式，以减少空间占用
                self.pBar.setValue(80)
                cmd_del_plc = f"cd /usr && rm -rf {self._plc_progm}"
                ssh.exec_command(cmd_del_plc)
                self.pBar.setValue(100)
                time_out_flag = False
                self.btnMsg(self.MsgSucced)
            else:
                self.btnMsg(self.MsgFalse, "#2")
        except Exception as e:
            # Chenly 2018-09-07 TODO 改为判断return结果
            # print('err: ' + e)
            if (time_out_flag is True):
                QMessageBox.critical(
                    self, 'err', '无法与指定ip地址进行网络通讯', QMessageBox.Cancel)
            else:
                self.btnMsg(self.MsgFalse, "#3")
        finally:
            ssh.close()
            self.write2Ini()   # Chenly 2018-09-05 写入配置信息
            return result

    def setCurDate(self):   # Chenly 2018-09-10 自动根据当前系统日期设置时间
        tmp = time.strftime("%y%m%d")
        if int(tmp[2:4]) > 9:
            month = chr(int(tmp[2:4]) + 55)
        else:
            month = tmp[3]

        if int(tmp[4:]) > 9:
            day = chr(int(tmp[4:]) + 55)
        else:
            day = tmp[5]

        cur_date = tmp[0:2] + month + day
        self.date.setText(cur_date)

    def readFrIni(self):  # Chenly 2018-09-07 读取配置信息
        for key, value in self._cellMap.items():
            if self._settings.value(key) is None:
                self.progm_store.setText(self.getDskTop())
            else:
                value.setText(self._settings.value(key))
            # self.progm_store.setEnabled(False)
            # print(self._settings.value(key))

        self.setCurDate()

    def write2Ini(self):   # Chenly 2018-09-07 保存配置信息
        for key, value in self._cellMap.items():
            self._settings.setValue(key, QVariant(value.text()))

    def btnMsg(self, status, t=''):    # Chenly 2018-09-07 提示信息
        if status is self.MsgSucced:
            QMessageBox.information(self, "Succeed!",
                                    self.tr(f"打包成功\nPLC程序已存放在 路径: {self.progm_store.text()}下"))
        else:
            QMessageBox.critical(self, "Warning!",
                                 self.tr("填写内容有误，请检查!" + t))

    def initVar(self):
        self.pBar_step = 0
        self._settings = QSettings(
            "TechMation\\Chenly\\Qt-tools", "PLC_Pack")

        self.cellMap()
        self.initCell()
        # Chenly 2018-09-05 读取配置信息
        self._sep = r'\\'
        self._usr_path = 'usr'

        self._pack_sh = "PLC_PackByTool.sh"

        self.MsgSucced = True
        self.MsgFalse = False

    def initUi(self):
        # 底部提示信息
        self.status = self.statusBar()
        self.status.setLayoutDirection(Qt.RightToLeft)
        self.status.showMessage('仅供内部学习交流使用 -- Chenly')

        # 设置当前tab
        self.tabWidget.setCurrentIndex(0)

        screen = QDesktopWidget().screenGeometry()  # 计算当前显示器的分辨率
        size = self.geometry()  # 该语句用来获取 QWidget 窗口的大小（size.width,size.height）
        self.move((screen.width() - size.width()) / 2,
                  (screen.height() - size.height()) / 2)  # 以左上角为基准，将窗口移动到屏幕的中间位置
        self.setFixedSize(self.width(), self.height())  # 窗口无法拖动

    def initCell(self):
        self.pBar.setVisible(False)

        self.readFrIni()

    def initMenu(self):
        pass

    def initSlots(self):
        self.btn_to_pack.clicked.connect(self.getPingResult)


if __name__ == "__main__":
    app = QApplication(sys.argv)
    MForm = MainForm()
    MForm.show()
    sys.exit(app.exec())
