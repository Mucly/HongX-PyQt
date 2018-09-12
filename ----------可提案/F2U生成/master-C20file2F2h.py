# coding:utf-8
import os
import sys
import winreg
import re

def getDesktop():
    key = winreg.OpenKey(winreg.HKEY_CURRENT_USER, r'Software\Microsoft\Windows\CurrentVersion\Explorer\Shell Folders')
    return winreg.QueryValueEx(key, "Desktop")[0]

desk_path = getDesktop()
C20_file_bigest = ''

for desk_files in os.listdir(desk_path):
	if ('.C20' in os.path.splitext(desk_files)[1]):
		C20_file_bigest = desk_files

jpnC20_file = open(C20_file_bigest, 'r')
f2u_file = open(desk_path + os.sep + 'F2U.c', 'w')

HOF = '#include "F2U.h"\n\
FONT2UNICODE	Font2Unicode[]=\n\
{\n'

EOF = '};'

chines_pattern = re.compile(r'((0x5[0-5][0-9A-F]{2})(\s)(0x\w{4}))')
f2u_file.write(HOF)
for c20line in jpnC20_file.readlines():
	if (re.search(chines_pattern, c20line)):
		temp = '	{' + re.search(chines_pattern, c20line).group(2) + ',' + re.search(chines_pattern, c20line).group(4) + '}' + ',' + '\n'
		f2u_file.write(temp)
f2u_file.write(EOF)

jpnC20_file.close()
f2u_file.close()