# coding:utf-8
import os
import os.path

# Ui文件所在路径
dir = './'

# 列出目录下所有的ui文件


def listUiFile():
    list = []
    files = os.listdir(dir)
    for filename in files:
        if os.path.splitext(filename)[1] == '.ui':
            list.append(filename)
    return list

# 把后缀为.ui的文件改为.py


def transPyFile(filename):
    return os.path.splitext(filename)[0] + '.py'


def runMain():
    for uifile in listUiFile():
        pyfile = transPyFile(uifile)
        # cmd = 'pyuic5.exe {uifile} -o {pyfile}'.format(uifile = uifile, pyfile = pyfile)
        cmd = f'pyuic5.exe {uifile} -o {pyfile}'
        os.system(cmd)

if __name__ == "__main__":
    runMain()
