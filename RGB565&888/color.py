global show_hex, show_dec
show_hex = 1
show_dec = 2


def rgb565To888(ed_text):
    print(ed_text)
    try:
        ed_text = int(ed_text)
        print ('1', ed_text)
    except:
        ed_text = int(ed_text, base=16)
        print ('2', ed_text)
    finally:
        return str((((ed_text >> 11) & 0x1F) << 19) | (((ed_text >> 5) & 0x3F) << 10) | ((ed_text & 0x1F) << 3))


def rgb888To565(ed_text):
    try:
        ed_text = int(ed_text)
    except:
        ed_text = int(ed_text, base=16)
    finally:
        return str((((ed_text & 0xff0000) >> 19) << 11) | (((ed_text & 0xff00) >> 10) << 5) | ((ed_text & 0xff) >> 3))


def dec2str(num, base):
    return str(int(num, base))


def hex2str_0x(num):
    return str(hex(int(num)))


def hex2str(num, base=16):
    num = '0x' + num
    return str(int(num, base=16)).replace('0x', '', 1)
