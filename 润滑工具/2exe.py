# coding:utf-8
import os
import os.path

# Ui文件所在路径
dir = './'

def code2exe(pyfile):
	cmd = 'pyinstaller -F -w {pyfile}'.format(pyfile = pyfile)  # -i gen.ico 设置图标， -D 创建一个目录,
	os.system(cmd)

if __name__ == "__main__":
	code2exe('callMainForm.py')
