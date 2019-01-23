# -*- coding: utf-8 -*-
#! /usr/bin
import paramiko
import shutil
import os
import winreg
import shutil
import time

# host_ip = '192.168.4.112' # zjw PLC
host_ip = '192.168.4.247'
port = 22
usrname = 'root'
pswd = '123456'
usr_path = 'usr'
plc_firm = '7KK'
plc_vers = 'PLC'
plc_date = '188V'
sep = r'\\'

plc_progm = f'{plc_firm} {plc_vers} {plc_date}'


def getDesktop():
    key = winreg.OpenKey(winreg.HKEY_CURRENT_USER,
                         r'Software\Microsoft\Windows\CurrentVersion\Explorer\Shell Folders')
    return winreg.QueryValueEx(key, "Desktop")[0]


def cp_del_plc(dsktop, rsc, plc_prgm):
    file_list = os.listdir(rsc)
    for file in file_list:
        if file == plc_prgm:
            os.chdir(rsc)
            if os.path.exists(f'{dsktop}{os.sep}{file}.SYS'):
                shutil.rmtree(f'{dsktop}{os.sep}{file}.SYS')
            shutil.copytree(file, f'{dsktop}{os.sep}{file}.SYS')
            return 0


def callSSH(hostname, port, username, passwd, **shell):
    # try:
    result = {}
    ssh = paramiko.SSHClient()
    rsc = f'{sep}{host_ip}{os.sep}{usr_path}'
    plc_prgm = f'{plc_firm}_{plc_vers}_{plc_date}_update'

    # 用于允许连接不在known_hosts名单中的主机
    ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
    ssh.connect(hostname=hostname, port=port,
                username=username, password=passwd)

    for key in shell:
        stdin, stdout, stderr = ssh.exec_command(shell[key])
        result[key] = stdout.read(), stderr.read()

        cp_del_plc(getDesktop(), rsc, plc_prgm)

    # Chenly 2018-09-05 删除面板/usr路径下生产的PLC程序
    cmd_del_plc = f"cd /usr && rm -rf {plc_prgm}"
    ssh.exec_command(cmd_del_plc)

    ssh.close()  # Chenly 2018-09-05 关闭ssh通道

    return result
    # except:
    #     result = u"无"
    #     return result


# callSSH(host_ip, port, usrname, pswd,
#         SHEEL1='cd /usr/ && ls -l')   # TODO : for Test
# # SHELL1=f'cd /usr/ && ./new_pack_PLC.sh {plc_progm}')
