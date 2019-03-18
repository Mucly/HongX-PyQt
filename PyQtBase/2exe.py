# coding:utf-8
import os
import os.path

# Ui文件所在路径
dir = './'


def code2exe(pyfile):
    # cmd = 'pyinstaller -F -w {pyfile}'.format(pyfile=pyfile) # 隐藏CMD
    cmd = 'pyinstaller -F --icon=myIco.ico {pyfile}'.format(pyfile=pyfile)
    os.system(cmd)

if __name__ == "__main__":
    code2exe('run.py')
