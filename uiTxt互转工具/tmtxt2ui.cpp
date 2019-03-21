#include "tmtxt2ui.h"
#include "ui_tmtxt2ui.h"

#include <QDir>
#include <QFile>
#include <QTimer>
#include <QDebug>
#include <QFileDialog>
#include <QTableWidget>
#include <QMessageBox>
#include <QTextDocument>
#include <QSettings>
#include <QItemSelectionModel>
#include <QTableWidgetItem>

#include "./globalvalue.h"

#define  TXT_SPACE4     "    "
#define  TXT_SPACE8     "         "
#define  TXT_SPACE12    "             "
#define  TXT_SPACE16    "                  "

#define RGB565TORGB888(c) ((((c)>>8)&0xf8 | (((c)>>11)&0x7))<<16 | (((c)>>3)&0xfc | (((c)>>5)&0x3))<<8 | ((c)<<3)&0xf8 | ((c)&0x7) )

const QString spaceTxt[] = {"", TXT_SPACE4, TXT_SPACE8,
                            TXT_SPACE12, TXT_SPACE16, "  ", "  "
                           };

QMap<QString, QString> mapRect;// = {{"x", "left"}, {"y", "top"}, {"width", "right"}, {"height", "bottom"}};

TMTxt2UI::TMTxt2UI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TMTxt2UI)
{
    mapRect.insert("x", "left");
    mapRect.insert("y", "top");
    mapRect.insert("width", "right");
    mapRect.insert("height", "bottom");
    ui->setupUi(this);

    Init();
}

TMTxt2UI::~TMTxt2UI()
{
    delete ui;
}

void TMTxt2UI::Init()
{
    mUIDirPath = "";
    mTXTDirPath = "";
    ltNames.clear();
    mTBWidth = 767;
    mTBHeight = 40;
    mSTBWidth = 767;
    mSTBHeight = 45;
    mFlagWType = false;
    mSwitchMode = MODE_TXT2UI;
    mFlagColorChange = true;
    mFlagFileChange = true;

    setWindowFlags(Qt::Window);

    mBar = new QProgressBar(this);
    mBar->hide();
    mBar->resize(400, 40);
    mBar->setStyleSheet("color:red;font: 26px bold;");
    mBar->move(this->width() / 2 - 200, this->height() / 2 - 40);

    mSetTBWH = new ToolBarSetDlg(this);
    mSetProPath = new ProIniSetDlg(this);
    mBrowser = new FileBrowser(this);

    InitPropertyType();
    InitModel();
    InitForm();

    connect(this, &TMTxt2UI::sglUpdateProgBar, this, &TMTxt2UI::slotUpdateProgressBar);
}

/*
 * 初始化model
 */
void TMTxt2UI::InitModel()
{
    model = new QFileSystemModel(this);
    model->setNameFilters(QStringList() << "*.txt");
    model->setNameFilterDisables(false);
    model->setFilter(QDir::Files); // 只显示文件

    model2 = new QFileSystemModel(this);
    model2->setNameFilters(QStringList() << "*.ui");
    model2->setNameFilterDisables(false);
    model2->setFilter(QDir::Files); // 只显示文件

    model3 = new QFileSystemModel(this);
    model3->setNameFilters(QStringList() << "*.txt");
    model3->setNameFilterDisables(false);
    model3->setFilter(QDir::Files); // 只显示文件

    model4 = new QFileSystemModel(this);
    model4->setNameFilters(QStringList() << "*.ui");
    model4->setNameFilterDisables(false);
    model4->setFilter(QDir::Files); // 只显示文件

    model->setRootPath(mTXTDirPath);
    model2->setRootPath(mUIDirPath);
    model3->setRootPath(mTXTDirPath2);
    model4->setRootPath(mUIDirPath2);
}

/*
 * 初始化form
 */
void TMTxt2UI::InitForm()
{
    UpdateTableWgt();

    ui->tableWgt->setColumnWidth(0, 220);
    ui->tableWgt2->setColumnWidth(0, 220);
    ui->tableWgt3->setColumnWidth(0, 220);
    ui->tableWgt4->setColumnWidth(0, 220);

    ui->lineEdit->setText(mProRoot);
    ui->tabWidget->setCurrentIndex(0);
}

/*
 * 初始化各map及list
 */
void TMTxt2UI::InitPropertyType()
{
    QSettings *pConf = new QSettings(PropertyINI, QSettings::IniFormat);
    if (pConf) {
        ltNewClss.clear();
        mapProperty.clear();
        QStringList ltKey = pConf->allKeys();
        foreach (QString key, ltKey) {
            if (key.contains(INI_ELE_WND))
                mapProperty.insert(key.remove(INI_ELE_WND), pConf->value(key, "11").toInt());
            else if (key.contains(INI_ELE_SYS))
                mapSystem.insert(key.remove(INI_ELE_SYS), pConf->value(key, "").toString());
            else if (key.contains(INI_ELE_S2Q))
                mapProperty2.insert(key.remove(INI_ELE_S2Q), pConf->value(key, key).toString());
            else if (key.contains(INI_ELE_NEW))
                ltNewClss.append(pConf->value(key, "").toString());
        }

        //qDebug() << "********* Init mapProperty ok: count =" << mapProperty;
        //qDebug() << "********* Init mapProperty2 ok: count =" << mapProperty2;
        //qDebug() << "********* Init mapSystem ok: count =" << mapSystem;
        //qDebug() << "********** Init ltNewClass ok: =" << ltNewClss;
        delete pConf;
        pConf = NULL;

        // @ update path
        mProRoot = mapSystem.value(INI_KEY_PRO_ROOT);
        mUIDirPath = mapSystem.value(INI_KEY_UI_FORM);
        mUIDirPath2 = mapSystem.value(INI_KEY_UI_TOOLBAR);
        mTXTDirPath = mapSystem.value(INI_KEY_TXT_FORM);
        mTXTDirPath2 = mapSystem.value(INI_KEY_TXT_TOOLBAR);
    }
}

/*
 * FUN: 获取文件名
 * path: 路径
 * delForm: 是否删除文件后缀.txt (true删除，false不删）
 */
QString GetFileName(const QString &path, bool delForm = false)
{
    QString name = "";
    int ndex = 0;
    ndex = path.lastIndexOf("/");
    name = path.right(path.length() - ndex - 1 );

    if (delForm) name = name.remove(".txt");
    return name;
}

/*
 * 根据类型ntype获取对应子串
 */
QString GetTypeNmae(int ntype)
{
    if (ntype == tmBOOL) return "bool";
    else if (ntype == tmCHAR) return "char";
    else if (ntype == tmFLOAT || ntype == tmDOUBLE) return "double";
    else if (ntype == tmSHORT || ntype == tmINT) return "number";
    else if (ntype == tmLONG || ntype == tmINT64) return "longlong";
    else if (ntype == tmBYTE || ntype == tmWORD || ntype == tmDWORD) return "UInt";
    else return "string";
}

/*
 * 从子串中解析出数字值
 */
int GetXYFromStr(const QString &temp) {
    if (temp.contains("+") || temp.contains("-") || temp.contains("*")) {
        static QStringList ltTxt;
        static QString temp1 = "";
        static QString temp2 = "";

        ltTxt.clear();
        if (temp.contains("+"))
            ltTxt = temp.split("+");
        else if (temp.contains("-"))
            ltTxt = temp.split("-");
        else
            ltTxt = temp.split("*");

        temp1 = ltTxt.at(0);
        temp2 = ltTxt.at(1);
        temp1 = temp1.trimmed();
        temp2 = temp2.trimmed();

        if (temp.contains("+"))
            return temp1.toInt() + temp2.toInt();
        else if (temp.contains("-"))
            return temp1.toInt() - temp2.toInt();
        else
            return temp1.toInt() * temp2.toInt();
    } else return temp.trimmed().toInt();
}

/*
 * 从子串中解析出宽,高值
 * wh为left或top值
 */
int GetWHFromStr(const QString &temp, int wh)
{
    // "91 * 2"
    // "100 - 23"
    // "100 + 23"
    // "1720 + left";

    static QStringList ltTxt;
    static QString temp1 = "";
    static QString temp2 = "";

    ltTxt.clear();

    if (temp.contains("-")) {
        ltTxt = temp.split("-");
        temp1 = ltTxt.at(0);
        temp2 = ltTxt.at(1);
        temp1 = temp1.trimmed();
        temp2 = temp2.trimmed();
        // return temp1.toInt() - temp2.toInt() - wh + 1; // Muc 2018-11-28 mark，原上海写法，加了1就有Bug了
        return temp1.toInt() - temp2.toInt() - wh;
    } else if (temp.contains("*")) {
        ltTxt = temp.split("*");
        temp1 = ltTxt.at(0);
        temp2 = ltTxt.at(1);
        temp1 = temp1.trimmed();
        temp2 = temp2.trimmed();
        // return temp1.toInt() * temp2.toInt() - wh + 1; // Muc 2018-11-28 mark，原上海写法，加了1就有Bug了
        return temp1.toInt() * temp2.toInt() - wh;
    } else if (temp.contains("+")) {
        ltTxt = temp.split("+");
        temp1 = ltTxt.at(0);
        temp2 = ltTxt.at(1);
        temp1 = temp1.trimmed();
        temp2 = temp2.trimmed();
        if (temp1 == "left" || temp1 == "top") {
            // return temp2.toInt() + 1;    // Muc 2018-11-28 mark，原上海写法，加了1就有Bug了
            return temp2.toInt();
        } else if (temp2 == "left" || temp2 == "top") {
            // return temp1.toInt() + 1;    // Muc 2018-11-28 mark，原上海写法，加了1就有Bug了
            return temp1.toInt();
        } else
            // return temp1.toInt() + temp2.toInt() - wh + 1;    // Muc 2018-11-28 mark，原上海写法，加了1就有Bug了
            return temp1.toInt() + temp2.toInt() - wh;    // Muc 2018-11-28 mark，原上海写法，加了1就有Bug了
    } else {
        // return temp.trimmed().toInt() - wh + 1;    // Muc 2018-11-28 mark，原上海写法，加了1就有Bug了
        return temp.trimmed().toInt() - wh;
    }
}

/*
 * txt到Ui属性名称转换
 * false: 不需转换； true： 需要转换
 */
bool TMTxt2UI::CheckPropertyName(QString &temp) {
    if (temp.isEmpty()) return false;
    QString tmp = mapProperty2.value(temp, "");
    if (tmp.isEmpty()) return false;
    temp = tmp;
    return true;
}

/*
 * ui到txt属性名称转换
 * false: 不需转换； true： 需要转换
 */
bool TMTxt2UI::CheckPropertyName2(QString &temp) {
    if (temp.isEmpty()) return false;
    QString tmp = mapProperty2.key(temp, "");
    if (tmp.isEmpty()) return false;
    temp = tmp;
    return true;
}

/*
 * 处理pixmap属性的value值
 */
bool HandleProperty_Pixmap(QString &value) {
//    int ndex = value.indexOf("/");
//    value.remove(0, ndex);
    value = ":/" + value;
    return true;
}

/*
 * FUN: 根据类型type处理属性的value值
 */
bool HandlePropertyValue(QString &type, QString &value) {

    if (type == "bool") { // 处理bool类型值
        value = value.toLower(); // 变小写
    } else if (type == "bytearry" || type == "number" || type == "int" || type == "UInt" || type == "longlong") {
        if (value.contains("0x")) { // 处理16进制数
            bool ok = true;
            uint nval = value.toUInt(&ok, 16);
            value = QString::number(nval);
        } else if (value.contains("+") || value.contains("-") || value.contains("*")) {
            value = QString::number(GetXYFromStr(value));
        }
    }
    return true;
}

/*
 * FUN: 以filter为分隔符，获取temp左右子串
 * temp: 被解析的子串
 * filter: 分隔符":"或"="
 * temp1: 左边的子串1
 * temp2: 右边的子串2
 * return: true获取成功; false获取失败
 */
bool HandleStrHelper(const QString &temp, const QString &filter,
                     QString &temp1, QString &temp2)
{
    if (temp.isEmpty() || filter.isEmpty()) return false;
    if (!temp.contains(filter)) return false;

    if (filter == ":" || filter == "=") {
        QStringList ltTxt;
        ltTxt.clear();
        ltTxt = temp.split(filter);

        if (ltTxt.count() != 2) return false;
        temp1 = ltTxt.at(0);
        temp2 = ltTxt.at(1);
        temp1 = temp1.trimmed();
        temp2 = temp2.trimmed();

        if (temp1.isEmpty()) return false;

    } else {
        return false;
    }

    return true;
}

/*
 * 开始文件转换业务
 */
void TMTxt2UI::DoTask()
{
    if (mUIDirPath.isEmpty()) return;
    if (ltNames.isEmpty()) {
        QMessageBox::critical(NULL, tr("警告！"), tr("请先选择文件！"));
        return;
    }

    QString path2 = "";
    QString uiPath, txtPath;
    static QList<int> ltPara = QList<int> () << mTBWidth << mTBHeight << mSTBWidth
                               << mSTBHeight << mFlagColorChange << mFlagFileChange;

    mProQrcDir = mapSystem.value(INI_KEY_PRO_IMAGE);

    // txt转ui模式需要进行参数设置
    if (mSwitchMode == MODE_TXT2UI) {

        if (1 != mSetTBWH->Show(mProQrcDir, mProQrcName, ltPara)) return;
        mTBWidth = ltPara.at(0);
        mTBHeight = ltPara.at(1);
        mSTBWidth = ltPara.at(2);
        mSTBHeight = ltPara.at(3);
        mFlagColorChange = ltPara.at(4);
        mFlagFileChange = ltPara.at(5);
    }

    // @ Show Progressbar
    mBar->show();
    mProbarValue = 0;
    mBar->setValue(0);
    mBar->move(this->width() / 2 - 200, this->height() / 2 - 40);
    qApp->processEvents();

    mPercent = 1000 / ltNames.count();

    // @ Do Task
    foreach (QString path1, ltNames) {
        //qDebug() <<"path1 =" <<path1 << ", mUIDirPath2="<<mUIDirPath2 << ", mTXTDirPath2=" <<mTXTDirPath2;

        path2 = path1;
        if (mSwitchMode == MODE_TXT2UI) path2.replace(".txt", ".ui");
        else path2.replace(".ui", ".txt");

        // @ 判断脚本归属form还是toolbar
        if (path1.contains("toolbar")) { // toolbar
            uiPath = mUIDirPath2;
            txtPath = mTXTDirPath2;
        } else {
            uiPath = mUIDirPath;
            txtPath = mTXTDirPath;
        }

        // @ 移除最后的"/"
        if (uiPath.right(1) == "/") uiPath.remove(uiPath.length() - 1, 1);
        if (txtPath.right(1) == "/") txtPath.remove(txtPath.length() - 1, 1);

        // @ 组合完整的文件路径
        if (mSwitchMode == MODE_TXT2UI) {
            path2 = uiPath + "/" + path2;
            path1 = txtPath + "/" + path1;
        } else {
            path1 = uiPath + "/" + path1;
            path2 = txtPath + "/" + path2;
        }

        // @ 真正的转换开始了
        if (mSwitchMode == MODE_TXT2UI) Txt2Ui_Fun(path1, path2);
        else Ui2Txt_Fun(path1, path2);

        //qDebug() << "***** TMTxt2UI::DoTask: path1 =" << path1 << ", path2=" << path2;

        // @ 进度条刷新下
        mProbarValue += mPercent;
        if (mProbarValue / 10 > 0) {
            mBar->setValue(mProbarValue / 10);
            qApp->processEvents();
        }
    }

    mBar->setValue(100);
    QTimer::singleShot(800, mBar, SLOT(close()));

    // @ 转换完，更新下界面
    InitModel();
    UpdateTableWgt();
}

/*
 * 更新下界面
 */
void TMTxt2UI::UpdateTableWgt()
{
    ui->tableWgt->setModel(model);
    ui->tableWgt->setRootIndex(model->index(mTXTDirPath));

    ui->tableWgt2->setModel(model2);
    ui->tableWgt2->setRootIndex(model2->index(mUIDirPath));

    ui->tableWgt3->setModel(model3);
    ui->tableWgt3->setRootIndex(model3->index(mTXTDirPath2));

    ui->tableWgt4->setModel(model4);
    ui->tableWgt4->setRootIndex(model4->index(mUIDirPath2));

    ClearAllTableSelections();

    ui->checkBox->setChecked(false);

//    QModelIndex index = model->index(1, 3, model->index(mTXTDirPath));
//    qDebug() << "***** index =" << index.data().toString();
}

/*
 * 清除所有选择
 */
void TMTxt2UI::ClearAllTableSelections()
{
    ui->tableWgt->clearSelection();
    ui->tableWgt2->clearSelection();
    ui->tableWgt3->clearSelection();
    ui->tableWgt4->clearSelection();
}

/*
 * 写入wtype属性节点
 */
void WriteEle_Wtype(QXmlStreamWriter &writer) {
    writer.writeStartElement("property");
    writer.writeAttribute("name", "wtype");
    writer.writeTextElement("UInt", "48"); // "0x30"
    writer.writeEndElement();
}

/*
 * FUN： ui转txt
 * path1: ui路径
 * path2: txt路径
 */
void TMTxt2UI::Ui2Txt_Fun(const QString &path1, const QString &path2)
{
    if (path1.isEmpty() || path2.isEmpty()) {
        return;
    }
    //qDebug() << "************ Ui2Txt_Fun : path1 =" << path1 << ", path2 =" << path2;

    // @ open ui file
    QFile fl1(path1);
    if (!fl1.open(QFile::ReadOnly)) {
        QMessageBox::warning(NULL, "Warnning!", tr("打开%1文件失败!").arg(path1));
        return;
    }

    // @ open txt file
    QFile fl2(path2);
    if (!fl2.open(QFile::WriteOnly | QFile::Text | QFile::Truncate)) {
        //QMessageBox::warning(NULL, "Warnning!", tr("保存txt文件失败!"));
        return;
    }

    QString txt = "";
    QTextStream stm(&fl2);
    QXmlStreamReader reader(&fl1);

    while (!reader.atEnd()) {
        // @ 分行获取信息
        Ui2Txt_rWgt(reader, txt);
    }
    //qDebug() << "***** txt =" << txt;

    stm << txt;
    fl1.close();
    fl2.close();
}

/*
 * FUN： txt转ui
 * path1: txt路径
 * path2: ui路径
 */
void TMTxt2UI::Txt2Ui_Fun(const QString &path1, const QString &path2)
{
    if (path1.isEmpty() || path2.isEmpty()) {
        return;
    }
    //qDebug() << "************ Txt2Ui_Fun : path1 =" << path1 << ", path2 =" << path2;

    // @
    QFile fl1(path1);
    if (!fl1.open(QFile::ReadOnly)) {
        return;
    }

    // @ open file
    QFile fl2(path2);
    if (!fl2.open(QFile::WriteOnly | QFile::Text | QFile::Truncate)) {
        //QMessageBox::warning(NULL, "Warnning!", tr("保存xml文件失败!"));
        return;
    }

    bool Flag_Root = false; // 根节点开始标志(即所有widget的根节点)
    bool Flag_Window = false; // 窗口节点开始标志(只是记录root节点属性范围)
    bool Flag_Widget = false; // widget节点开始标志
    bool Flag_Widget2  = false; // 子widget节点开始标志
    bool Flag_Widget3  = false; // 孙子widget节点开始标志
    QString strLine = "";
    QByteArray arrLine = "";
    QString temp1, temp2;

    // @ get file name
    int ndex = path1.lastIndexOf("/");
    QString path1Name = path1.right(path1.length() - ndex - 1).remove(".txt");

    // @ begin write
    QXmlStreamWriter writer(&fl2);
    writer.setAutoFormatting(true);
    writer.writeStartDocument();

    // @ ele root: ui
    writer.writeStartElement("ui");
    writer.writeAttribute("version", "4.0");

    // @ ele body

    // @ 对toolbar进行特殊处理：加上头节点widget
    if (path1Name.contains("toolbar") || path1Name.contains("subtoolbar")) {
        Flag_Root = true;
        Flag_Window = true;
        mFlagWType = false;
        writer.writeTextElement("class", path1Name);
        writer.writeStartElement("widget");
        bool flag_subtoolbar = path1Name.contains("subtoolbar");
        writer.writeAttribute("class", flag_subtoolbar ? "CtmSubToolBar" : "CtmToolBar");
        writer.writeAttribute("name", path1Name);
        writer.writeStartElement("property");
        writer.writeAttribute("name", "geometry");
        writer.writeStartElement("rect");
        writer.writeTextElement("x", "0");
        writer.writeTextElement("y", "0");
        if (flag_subtoolbar) {
            writer.writeTextElement("width", QString::number(mSTBWidth));
            writer.writeTextElement("height", QString::number(mSTBHeight));
        } else {
            writer.writeTextElement("width", QString::number(mTBWidth));
            writer.writeTextElement("height", QString::number(mTBHeight));
        }
        writer.writeEndElement();
        writer.writeEndElement();
        //WriteEle_Wtype(writer);
    }
    // @ 开始转换
    while (!fl1.atEnd()) {
        arrLine = fl1.readLine();
        strLine = QString(arrLine);
        strLine = strLine.trimmed();

        if (strLine.isEmpty()) continue;
        if (strLine.left(2) == "//") continue;

        if (!Flag_Root) { // 首先查找根节点root
            if (strLine.contains(":")) {
                if (HandleStrHelper(strLine, ":", temp1, temp2)) {
                    // @ class name
                    //if(temp2!="CtmFormView") continue;
                    writer.writeTextElement("class", temp1);

                    // @ widget -- window
                    writer.writeStartElement("widget");
                    writer.writeAttribute("class", temp2);;
                    writer.writeAttribute("name", temp1);

                    // @ set flag
                    Flag_Root = true;
                    Flag_Window = true;
                    mFlagWType = false;
                }
            }
        } else {
            if (Flag_Window) { //窗口节点内容开始标志
                if (strLine.contains("=")) {
                    Txt2Ui_wWgt(writer, strLine, "=");
                }
                // @ start widget
                else if (strLine.contains(":")) { //第一级widget开始
                    if (!mFlagWType) WriteEle_Wtype(writer);
                    if (Txt2Ui_wWgt(writer, strLine, ":")) {
                        Flag_Widget = true;
                        Flag_Window = false;
                        mFlagWType = false;
                    }
                }
            } else {
                if (Flag_Widget) { //处理第一级widget
                    if (Flag_Widget2) { //处理第二级widget
                        if (Flag_Widget3) { //处理第三级widget
                            if (strLine == "end") {
                                Flag_Widget3 = false;
                                if (!mFlagWType) WriteEle_Wtype(writer);
                                mFlagWType = true;
                                writer.writeEndElement();// ---end widget3
                            } else if (strLine.contains("=")) {
                                Txt2Ui_wWgt(writer, strLine, "=");
                            } else if (strLine.contains(":")) {
                                if (Txt2Ui_wWgt(writer, strLine, ":")) {
//                                        Flag_Widget4 = true;
                                    qDebug() << "****** over the range: Flag_Widget4 = true";
                                }
                            }
                        } else {
                            if (strLine == "end") {
                                Flag_Widget2 = false;
                                writer.writeEndElement(); // ---end widget2
                            } else if (strLine.contains("=")) {
                                Txt2Ui_wWgt(writer, strLine, "=");
                            } else if (strLine.contains(":")) {
                                //第三级widget开始
                                if (!mFlagWType) WriteEle_Wtype(writer);
                                if (Txt2Ui_wWgt(writer, strLine, ":")) {
                                    Flag_Widget3 = true;
                                    mFlagWType = false;
                                }
                            }
                        }
                    } else {

                        if (strLine == "end") {
                            Flag_Widget = false;
                            writer.writeEndElement(); // ---end widget
                        } else if (strLine.contains("=")) {
                            Txt2Ui_wWgt(writer, strLine, "=");
                        } else if (strLine.contains(":")) {
                            if (!mFlagWType) WriteEle_Wtype(writer);
                            if (Txt2Ui_wWgt(writer, strLine, ":")) {
                                //第二级widget开始
                                Flag_Widget2 = true;
                                mFlagWType = false;
                            }
                        }
                    }

                } else {
                    if (strLine == "end") {
                        writer.writeEndElement();// end widget -- window
                    } else if (strLine.contains(":")) {
                        if (Txt2Ui_wWgt(writer, strLine, ":")) {
                            Flag_Widget = true;
                            mFlagWType = false;
                        }
                    }
                }
            }
        }
    }
    if (path1Name.contains("toolbar") || path1Name.contains("subtoolbar")) {
        writer.writeEndElement(); // end window -- toolbar
    }
    writer.writeEndElement(); // end root -- ui
    writer.writeEndDocument(); // end document

    fl1.close();
    fl2.close();
}

/*
 * FUN: ui转txt 对xml语句进行解析，一次解析一行
 * reader: 读xml文件句柄
 * stmTxt: 解析转换后的子串流
 */
bool TMTxt2UI::Ui2Txt_rWgt(QXmlStreamReader &reader, QString &stmTxt)
{
    static int ndex = 0;
    static bool rootEle = false;
    static bool isToolbar = false;
    static bool eleCustomWgt = false;
    static QString eleName = "";
    static QString propertyName = "";
    static QString txt_value = "";

    if (reader.atEnd()) return true;
    QXmlStreamReader::TokenType type = reader.readNext();//读取下一行

    if (type == QXmlStreamReader::StartDocument) { //文档开始
        rootEle = false;
        eleCustomWgt = false;
        //qDebug() << reader.documentEncoding() << reader.documentVersion();
    } else if (type == QXmlStreamReader::EndDocument) { //文档结束
        //qDebug() << "********** end document";
        return true;
    } else if (!eleCustomWgt) {
        if (type == QXmlStreamReader::StartElement) { //节点开始
            eleName = reader.name().toString();
            //qDebug() << "start eleName =" << eleName;
            if (eleName == "class") { // class节点
                ndex = 0;
                stmTxt = "";
                if (!reader.readElementText().contains("toolbar")) {
                    rootEle = true;
                    isToolbar = false;
                } else {
                    isToolbar = true;
                }
            } else if (eleName == "customwidget") { // qcreator自动给ui文件添加的部分
                eleCustomWgt = true;
            } else if (eleName == "widget") { // widget节点 代表元件
                if (rootEle) {
                    stmTxt += QString("%1%2:%3\n").arg(spaceTxt[ndex])
                              .arg(reader.attributes().value("name").toString())
                              .arg(reader.attributes().value("class").toString());
                } else {
                    if (isToolbar && ndex == 1) {
                        ndex = 0;
                        rootEle = true;
                        stmTxt += QString("%1%2:%3\n").arg(spaceTxt[ndex])
                                  .arg(reader.attributes().value("name").toString())
                                  .arg(reader.attributes().value("class").toString());
                    }
                }
                ndex++;
            } else if (rootEle) {
                if (eleName == "property") { // property节点 代表当前元件的属性，例 stmTxt= "    max ="
                    // Muc 2019-03-19 这里的propertyName要根据property.ini来
                    propertyName = reader.attributes().value("name").toString();
                    if (propertyName != "geometry") {
                        // @ switch first
                        QString newName = propertyName;
                        if (CheckPropertyName2(newName)) propertyName = newName;
                        stmTxt +=  QString("%1%2 =").arg(spaceTxt[ndex]).arg(propertyName);
                    }
                } else if (eleName == "x" || eleName == "y" || eleName == "width" || eleName == "height") {
                    //坐标节点
                    propertyName = mapRect.value(eleName);
                    stmTxt += QString("%1%2 =").arg(spaceTxt[ndex]).arg(propertyName);
                }
            }
        } else if (rootEle) {
            if (type == QXmlStreamReader::EndElement) { //节点结束
                eleName = reader.name().toString();
                if (eleName == "widget") {
                    if (ndex > 0) stmTxt += QString("%1end\n").arg(spaceTxt[ndex - 1]);
                    ndex--;
                    return true;
                }
            } else if (type == QXmlStreamReader::Characters && !reader.isWhitespace()) {
                //节点值
                txt_value = reader.text().toString();

                if (propertyName == "right") { // 宽
                    // txt_value = QString::number(txt_value.toInt() - 1);
                    txt_value = QString::number(txt_value.toInt());
                    txt_value += "+left";
                } else if (propertyName == "bottom") { // 高
                    // txt_value = QString::number(txt_value.toInt() - 1);
                    txt_value = QString::number(txt_value.toInt());
                    txt_value += "+top";
                } else if (propertyName == "imagepath" || propertyName == "upbitmap" || propertyName == "downbitmap") { // 图片
//                    QString dirName = mProQrcDir;
//                    dirName.remove(mProRoot);
//                    dirName.remove("/");
//                    txt_value.replace(":", dirName);
                    txt_value.remove(":/");
                }
                else if ((propertyName == "max") || (propertyName == "min")
                         || (propertyName == "tick-interval") || (propertyName == "value"))
                {
                    // Muc 2019-03-15 TMStudio生成的ui，上述属性，文本节点为double类型数据，故需做特殊处理
                    txt_value = QString::number(int(txt_value.toDouble()));
                }

                // Muc 2019-03-15 txt里，true和false要大写
                if (txt_value == "true" || txt_value == "false")
                    txt_value = txt_value.toUpper();
                if (txt_value.contains(".ui"))
                    txt_value.replace(".ui", ".txt");

                stmTxt += txt_value + "\n";
                //qDebug() << "Characters = " << reader.text().toString();
            }
        }
    }

    // 读取出错
    if (reader.hasError()) {
        qDebug() << "ReadXmlFile: error =" << reader.errorString();
    }

    return Ui2Txt_rWgt(reader, stmTxt); // 递归循环
}

/*
 * FUN: txt转ui 每次转换一行，并写入xml
 * writer: 写xml句柄
 * strLine: 需要转换的一行txt子串
 * filter: 分割符号“=”或“:”
 * return: true转换成功；false转换失败
 */
bool TMTxt2UI::Txt2Ui_wWgt(QXmlStreamWriter &writer, const QString &strLine, const QString &filter)
{
    static int nx = 0;
    static int ny = 0;
    static int nw = 0;
    static int nh = 0;
    static QString temp1 = "";
    static QString temp2 = "";

    if (HandleStrHelper(strLine, "=", temp1, temp2)) {
        // @ property: geometry
        if (temp1 == "left") {
            nx = GetXYFromStr(temp2);
            writer.writeStartElement("property");
            writer.writeAttribute("name", "geometry");
            writer.writeStartElement("rect");
            writer.writeTextElement("x", QString::number(nx));
        } else if (temp1 == "top") {
            ny = GetXYFromStr(temp2);
            writer.writeTextElement("y", QString::number(ny));
        } else if (temp1 == "right") {
            nw = GetWHFromStr(temp2, nx);
            writer.writeTextElement("width", QString::number(nw));
        } else if (temp1 == "bottom") {
            nh = GetWHFromStr(temp2, ny);
            writer.writeTextElement("height", QString::number(nh));
            writer.writeEndElement();
            writer.writeEndElement();
        }
        // @ property: other
        else {
            if (temp1 == "wtype") mFlagWType = true;

            // @ get text lable
            QString stype = GetTypeNmae(mapProperty.value(temp1, 11));

            // @ handle temp1 -- attribute
            CheckPropertyName(temp1);

            // @ handle temp2 -- text value
            if ((temp1 == "imagepath") || (temp1 == "upbitmap") || (temp1 == "downbitmap")) {
                HandleProperty_Pixmap(temp2);
            } else {
                HandlePropertyValue(stype, temp2);

                // 替换子串中的.txt
                if (mFlagFileChange && temp2.contains(".txt")) {
                    temp2.replace(".txt", ".ui");
                }

                // 色值转换 RGB565 TO RGB888
                if (mFlagColorChange && !ltNewClss.contains(mCurTxtClass)) {
                    if (temp1 == "bgc" || temp1 == "fgc" || temp1.endsWith("color", Qt::CaseInsensitive)) {
                        uint ncol = temp2.toUInt();
                        ncol = RGB565TORGB888(ncol);
                        temp2 = QString::number(ncol);
                    }
                }
            }

            writer.writeStartElement("property");
            writer.writeAttribute("name", temp1);

            if ((temp1 == "imagepath") || (temp1 == "upbitmap") || (temp1 == "downbitmap")) { // bmpuppath bmpdownpath bmpbackpath logopath
                writer.writeStartElement("pixmap");
                writer.writeAttribute("resource", "../" + mProQrcName);
                writer.writeCharacters(temp2);

                //writer.writeAttribute("resource", "./"+mProQrcDir+"/"+mProQrcName);
                //writer.writeCharacters(temp2);
                writer.writeEndElement();
            } else {
                writer.writeTextElement(stype, temp2);
            }
            writer.writeEndElement();
        }

        return true;
    } else if (HandleStrHelper(strLine, ":", temp1, temp2)) {

        // @ widget
        writer.writeStartElement("widget");
        writer.writeAttribute("class", temp2);;
        writer.writeAttribute("name", temp1);

        mCurTxtClass = temp2;
        return true;
    }

    return false;
}

/*
 * FUN: 更新进度条
 * nval: 数值
 */
void TMTxt2UI::slotUpdateProgressBar(int nval)
{
    mBar->setValue(nval);

    qDebug() << "*********** slotUpdateProgressBar nval =" << nval;

    if (nval == 0) mBar->show();
    else if (nval >= 100) {
        QTimer::singleShot(10 * 5000, mBar, SLOT(close()));
    }
}

/*
 * 刷新按钮的槽函数
 */
void TMTxt2UI::on_btnSelect_clicked()
{
    InitPropertyType();

    UpdateTableWgt();

    QMessageBox::information(NULL, tr("提示！"), tr("刷新完成！"));
}

/*
 * 开始转换按钮的槽函数
 */
void TMTxt2UI::on_btnDoIt_clicked()
{
    //mUIDirPath = QFileDialog::getExistingDirectory(this, tr("文件保存"), "./");

    QModelIndexList selected;
    QItemSelectionModel *selections = NULL;
    int ndex = ui->tabWidget->currentIndex();
    if (ndex < 2) mSwitchMode = MODE_TXT2UI;
    else mSwitchMode = MODE_UI2TXT;

    selected.clear();
    if (ui->checkBox->isChecked() && ui->comboBox->currentIndex() == 0) {
        if (ndex < 2) { // MODE_TXT2UI
            selections = ui->tableWgt->selectionModel();
            selected.append(selections->selectedIndexes());
            selections = ui->tableWgt3->selectionModel();
            selected.append(selections->selectedIndexes());
        } else { // MODE_UI2TXT
            selections = ui->tableWgt2->selectionModel();
            selected.append(selections->selectedIndexes());
            selections = ui->tableWgt4->selectionModel();
            selected.append(selections->selectedIndexes());
        }
    } else {
        if (ndex == 0) {
            selections = ui->tableWgt->selectionModel();
        } else if (ndex == 1) {
            selections = ui->tableWgt3->selectionModel();
        } else if (ndex == 2) {
            selections = ui->tableWgt2->selectionModel();
        } else if (ndex == 3) {
            selections = ui->tableWgt4->selectionModel();
        }
        selected = selections->selectedIndexes();
    }

    ltNames.clear();
    // 获取选择的文件名
    foreach (const QModelIndex index, selected) {
        if (index.column() == 0) {
            ltNames.append(index.data().toString());
            //qDebug() << "file name =" << index.data().toString();
        }
    }

//    int ncount = model->rowCount(model->index(mTXTDirPath));
//    int ncount2 = model2->rowCount(model2->index(mUIDirPath));
//    qDebug() << "ncount =" << ncount << ", 2 =" << ncount2;

    // 开始转换操作
    DoTask();
}

/*
 * 复选框点击槽函数
 */
void TMTxt2UI::on_checkBox_clicked(bool checked)
{
    int ndex0 = ui->tabWidget->currentIndex();
    int ndex1 = ui->comboBox->currentIndex();
    if (ndex1 == 0) { // 全选
        if (checked) {
            //if(ndex0<2){
            ui->tableWgt->selectAll();
            ui->tableWgt3->selectAll();
            //}else{
            ui->tableWgt2->selectAll();
            ui->tableWgt4->selectAll();
            //}
        } else {
            //if(ndex0<2){
            ui->tableWgt->clearSelection();
            ui->tableWgt3->clearSelection();
            //}else{
            ui->tableWgt2->clearSelection();
            ui->tableWgt4->clearSelection();
            //}
        }
    } else { // 只对当前页进行全选
        if (ndex0 == 0) {
            if (checked)
                ui->tableWgt->selectAll();
            else
                ui->tableWgt->clearSelection();
        } else if (ndex0 == 1) {
            if (checked)
                ui->tableWgt3->selectAll();
            else
                ui->tableWgt3->clearSelection();
        } else if (ndex0 == 2) {
            if (checked)
                ui->tableWgt2->selectAll();
            else
                ui->tableWgt2->clearSelection();
        } else if (ndex0 == 3) {
            if (checked)
                ui->tableWgt4->selectAll();
            else
                ui->tableWgt4->clearSelection();
        }
    }
}

/*
 * tabWidget切换槽函数
 */
void TMTxt2UI::on_tabWidget_currentChanged(int index)
{
    if (1 == ui->comboBox->currentIndex()) {
        ui->checkBox->setChecked(false);
        ui->tableWgt->clearSelection();
        ui->tableWgt2->clearSelection();
        ui->tableWgt3->clearSelection();
        ui->tableWgt4->clearSelection();
    }
}

/*
 * tableWgt点击槽函数
 */
void TMTxt2UI::on_tableWgt_clicked(const QModelIndex &index)
{
    ui->checkBox->setChecked(false);
    ui->tableWgt2->clearSelection();
    ui->tableWgt3->clearSelection();
    ui->tableWgt4->clearSelection();
}

/*
 * tableWgt3点击槽函数
 */
void TMTxt2UI::on_tableWgt3_clicked(const QModelIndex &index)
{
    ui->checkBox->setChecked(false);
    ui->tableWgt->clearSelection();
    ui->tableWgt2->clearSelection();
    ui->tableWgt4->clearSelection();
}

/*
 * tableWgt2点击槽函数
 */
void TMTxt2UI::on_tableWgt2_clicked(const QModelIndex &index)
{
    ui->checkBox->setChecked(false);
    ui->tableWgt->clearSelection();
    ui->tableWgt3->clearSelection();
    ui->tableWgt4->clearSelection();
}

/*
 * tableWgt4点击槽函数
 */
void TMTxt2UI::on_tableWgt4_clicked(const QModelIndex &index)
{
    ui->checkBox->setChecked(false);
    ui->tableWgt2->clearSelection();
    ui->tableWgt3->clearSelection();
    ui->tableWgt->clearSelection();
}

/*
 * 按钮tbtnSetPath点击槽函数：加载项目ini窗口
 */
void TMTxt2UI::on_tbtnSetPath_clicked()
{
    if (!mSetProPath->UpdatePath(mapSystem)) return;

    QSettings *pConf = new QSettings(PropertyINI, QSettings::IniFormat);
    if (pConf == NULL || !pConf->isWritable()) {
        QMessageBox::critical(NULL, tr("警告！"), tr("保存配置文件失败property.ini！"));
        return;
    }

    // @ compare and save to ini
    QString temp = "";
    temp = mapSystem.value(INI_KEY_PRO_ROOT, "");
    if (temp.isEmpty()) QMessageBox::critical(NULL,
                tr("警告！"), tr("项目配置文件config.ini为空或未找到！"));
    else if (mProRoot != temp) { // root path exchange
        mProRoot = temp;
        mTXTDirPath = mapSystem.value(INI_KEY_TXT_FORM);
        mTXTDirPath2 = mapSystem.value(INI_KEY_TXT_TOOLBAR);

        pConf->setValue(QString("%1%2").arg(INI_ELE_SYS).arg(INI_KEY_PRO_ROOT), temp);
        pConf->setValue(QString("%1%2").arg(INI_ELE_SYS).arg(INI_KEY_PRO_INI), mapSystem.value(INI_KEY_PRO_INI));
        pConf->setValue(QString("%1%2").arg(INI_ELE_SYS).arg(INI_KEY_TXT_FORM), mTXTDirPath);
        pConf->setValue(QString("%1%2").arg(INI_ELE_SYS).arg(INI_KEY_TXT_TOOLBAR), mTXTDirPath2);
        pConf->setValue(QString("%1%2").arg(INI_ELE_SYS).arg(INI_KEY_PRO_IMAGE), mapSystem.value(INI_KEY_PRO_IMAGE));

        ui->lineEdit->setText(mProRoot);
        //qDebug() << "********* mapSystem =" << mapSystem;
    }

    // @ compare form ui and save to ini
    temp = mapSystem.value(INI_KEY_UI_FORM, "");
    if (temp.isEmpty()) QMessageBox::critical(NULL,
                tr("警告！"), tr("form_ui路径不能为空！"));
    else if (mUIDirPath != temp) {
        mUIDirPath = temp;
        pConf->setValue(QString("%1%2").arg(INI_ELE_SYS).arg(INI_KEY_UI_FORM), mUIDirPath);

    }

    // @ compare toolbar ui and save to ini
    temp = mapSystem.value(INI_KEY_UI_TOOLBAR, "");
    if (temp.isEmpty()) QMessageBox::critical(NULL,
                tr("警告！"), tr("toolbar_ui路径不能为空！"));
    else if (mUIDirPath2 != temp) {
        mUIDirPath2 = temp;
        pConf->setValue(QString("%1%2").arg(INI_ELE_SYS).arg(INI_KEY_UI_TOOLBAR), mUIDirPath2);

    }

    delete pConf;
    pConf = NULL;

    // @ Update table
    UpdateTableWgt();
}

/*
 * comboBox槽函数
 */
void TMTxt2UI::on_comboBox_currentIndexChanged(int index)
{
    if (ui->checkBox->isChecked()) {
        if (index == 0) {
            ui->tableWgt->selectAll();
            ui->tableWgt3->selectAll();
            ui->tableWgt2->selectAll();
            ui->tableWgt4->selectAll();
        } else {
            index = ui->tabWidget->currentIndex();
            ClearAllTableSelections();
            if (index == 0) {
                ui->tableWgt->selectAll();
            } else if (index == 1) {
                ui->tableWgt3->selectAll();
            } else if (index == 2) {
                ui->tableWgt2->selectAll();
            } else if (index == 3) {
                ui->tableWgt4->selectAll();
            }
        }
    }
}

/*
 * FUN：文件浏览
 * tempmodel：当前文件系统
 * index：文件index
 * rootPath：根路径
 */
void TMTxt2UI::BrowserFile(QFileSystemModel *tempmodel, const QModelIndex &index, QString &rootPath)
{
    if (index.isValid()) {
        QString name = "";
        int ncol = index.column();

        if (ncol == 0) {
            name = index.data().toString();
        } else {
            int nrow = index.row();
            name = tempmodel->index(nrow, 0, tempmodel->index(rootPath)).data().toString();
        }
        name = rootPath + name;
        mBrowser->Show(name);
    }
}

// @ model
void TMTxt2UI::on_tableWgt_doubleClicked(const QModelIndex &index)
{
    BrowserFile(model, index, mTXTDirPath);
}

// @ model3
void TMTxt2UI::on_tableWgt3_doubleClicked(const QModelIndex &index)
{
    BrowserFile(model3, index, mTXTDirPath2);
}

// @ model2
void TMTxt2UI::on_tableWgt2_doubleClicked(const QModelIndex &index)
{
    BrowserFile(model2, index, mUIDirPath);
}

// @ model4
void TMTxt2UI::on_tableWgt4_doubleClicked(const QModelIndex &index)
{
    BrowserFile(model4, index, mUIDirPath2);
}
