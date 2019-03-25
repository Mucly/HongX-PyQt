# ！！旧版本的exe请从bak文件夹下搜寻

## 190315:
### 优化
- TMStudio生成的ui中，<strong>max、min、value、tickInterval</strong>元件的文本节点为double类型数据
所以本工具，ui转txt时，将上述元件的double文本变为int文本  

## 190319:
### 修正
- TMStudio生成的ui中，因原TMStudio的所有元件均以驼峰式命名，故本工具需特殊处理将tickInterval => tick-interval（<strong>property.ini</strong>是其映射表）

## 190321:
### 修正
- <刷新>按钮：从<strong>外部变更config.ini所指向的文件树</strong>【eg.新增文件】，当前工具窗口的文件列表中，该新增文件属性不对的问题修正

## 190322:
### 元件映射表更新
