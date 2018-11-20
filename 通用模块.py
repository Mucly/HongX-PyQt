'''
    将数据保存到注册表内
'''


class ClassName(object):
    """docstring for ClassName"""

    def __init__(self, arg):
        super(ClassName, self).__init__()

        # key为保存到注册表的名字，后面是元件
        self._cellMap = {
            "fold_path": self.ed_fold_path,
            "cell_type": self.ed_cell_type,
            "cell_key": self.ed_cell_key,
            "cell_val": self.ed_cell_val,
        }
        # 建立注册表映射关系
        self._settings = QSettings(
            "TechMation\\Chenly\\Qt-tools", "pwndRplc")

    # Chenly 2018-09-07 读取配置信息
    def readRegInfo(self):
        for key, value in self._cellMap.items():
            if self._settings.value(key) is not None:
                value.setText(self._settings.value(key))

    # Chenly 2018-09-07 保存配置信息
    def writeInfo2Reg(self):
        for key, value in self._cellMap.items():
            self._settings.setValue(key, QVariant(value.text()))
