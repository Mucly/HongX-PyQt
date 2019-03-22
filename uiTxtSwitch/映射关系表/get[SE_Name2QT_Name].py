# 根据property.cv 映射表，获取property.ini [SE_Name2QT_Name] 的映射内容
import re

dict_pat = r'<property name="(.*)">\s+<convert>(.*)</convert>\s+</property>'

with open('./res/property.xml', encoding='utf-8') as fd:
    with open('./[SE_Name2QT_Name]', 'w') as fout:
        fout.write('[SE_Name2QT_Name]\n')
        cv_content = fd.read()
        cell_map = re.findall(dict_pat, cv_content)

        for k, v in cell_map:
            content = v + "=" + k + '\n'
            fout.write(content)
