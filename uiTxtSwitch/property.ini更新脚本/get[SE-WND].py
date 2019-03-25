# 根据property.cv 映射表，获取property.ini [SE-WND] 的映射内容
import re

type_map = {
    "tmBYTE": 0,
    "tmSHORT": 1,
    "tmINT": 2,
    "tmWORD": 3,
    "tmDWORD": 4,
    "tmLONG": 5,
    "tmFLOAT": 6,
    "tmINT64": 7,
    "tmDOUBLE": 8,
    "tmENUM": 9,
    "tmSTRUCT": 10,
    "tmSTR": 11,
    "tmUSTR": 12,
    "tmCHAR": 13,
    "tmBOOL": 14,
    "tmCLASS": 15,
    "tmPROCEDURE": 16,
    "tmFontStream": 17,
    "tmUnknown": 18,
}

with open('./res/wnd_typenum.txt') as fd:
    with open('./[SE-WND].txt', 'w') as fout:
        fout.write('[SE-WND]\n')
        for line in fd.readlines():
            line = line.replace('\n', '')
            wnd, h_type = line.split(',')
            real_inx = type_map.get(h_type, 11)  # 缺省：tmSTR

            content = wnd + "=" + str(real_inx) + "\n"
            fout.write(content)
