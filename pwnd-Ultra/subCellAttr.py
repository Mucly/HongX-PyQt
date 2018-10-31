# -*- coding:utf-8 -*-
# 提供资源文件夹路径，自动替换文件夹内txt画面脚本，指定元件的指定属性，并生成在桌面
import os
import re
import winreg


def get_desktop():  # 获得桌面路径
    key = winreg.OpenKey(winreg.HKEY_CURRENT_USER,
                         r'Software\Microsoft\Windows\CurrentVersion\Explorer\Shell Folders')  # 利用系统的链表
    return winreg.QueryValueEx(key, "Desktop")[0]  # 返回的是Unicode类型数据


# 此处 key = value，对应画面内元件的属性与值
def rplcCell(form_path, cell, key, value, code_in='utf-8', code_out='utf-8'):
    global dst_path
    # variable
    key = key
    # value = '=' + value + '\n'
    attr_pat = re.compile(key + '.*' + '\n')
    attr_rlpc = key + ' ' + '=' + value + '\n'
    # flag
    cellfound_flag = False  # 　将txt内的元件看做一个区块，用以识别需要替换的元件块
    cellhave_flag = False  # 用以标记txt内是否存在目标元件，不存在则删除

    dst_path = get_desktop() + os.sep + 'form'
    if not os.path.exists(dst_path):
        os.mkdir(dst_path)

    os.chdir(form_path)

    for root, folders, files in os.walk(form_path):
        for file in files:
            if '.txt' == os.path.splitext(file)[1]:  # 只修改txt画面脚本
                linesBuff = ""
                dst_file = dst_path + os.sep + file
                f_read = open(file, encoding=code_in, errors='ignore')
                f_write = open(dst_file, 'w', encoding=code_out,
                               errors='ignore')

                for line in f_read.readlines():
                    if cell in line:
                        cellfound_flag = True

                    if True == cellfound_flag:
                        cellhave_flag = True
                        if re.search(attr_pat, line):
                            if value == '':
                                cellfound_flag = False
                                continue
                            else:
                                line = re.sub(attr_pat, attr_rlpc, line)
                                cellfound_flag = False

                    # linesBuff += line + '\r'
                    f_write.write(line)

                f_read.close()
                f_write.close()

                if False == cellhave_flag:
                    os.remove(dst_file)
                else:
                    cellhave_flag = False
                    print(dst_file + ' create!')


# if __name__ == '__main__':
#     cwd = os.getcwd()
#     dst_path = get_desktop() + os.sep + 'form'
#     if not os.path.exists(dst_path):
#         os.mkdir(dst_path)

#     rplcCellAttr(r'V:\pxammi\7HT_3354_M12InjCur-nk\res_tm640\form',
#                     'CtmToolButton', 'wtype', '0x27')
