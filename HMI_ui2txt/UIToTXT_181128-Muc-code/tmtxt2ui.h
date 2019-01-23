#ifndef TMTXT2UI_H
#define TMTXT2UI_H

#include <QMap>
#include <QDialog>
#include <QFileInfo>
#include <QFileSystemModel>
#include <QProgressBar>
#include <QTextStream>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QAbstractItemModel>

#include "./toolbarsetdlg.h"
#include "./proinisetdlg.h"
#include "./filebrowser.h"

namespace Ui {
class TMTxt2UI;
}

class TMTxt2UI : public QDialog
{
    Q_OBJECT

public:

    enum SWITCH_MODE{
        MODE_TXT2UI,
        MODE_UI2TXT
    };

    explicit TMTxt2UI(QWidget *parent = 0);
    ~TMTxt2UI();

protected:
    void Init();
    void InitModel();
    void InitForm();
    void InitPropertyType();

    void DoTask();
    void UpdateTableWgt();
    void ClearAllTableSelections();
    bool CheckPropertyName(QString &temp);
    bool CheckPropertyName2(QString &temp);
    void Ui2Txt_Fun(const QString &path1, const QString &path2);
    void Txt2Ui_Fun(const QString &path1, const QString &path2);
    bool Ui2Txt_rWgt(QXmlStreamReader &reader, QString &stmTxt);
    bool Txt2Ui_wWgt(QXmlStreamWriter &writer, const QString &strLine, const QString &filter);
    void BrowserFile(QFileSystemModel *tempmodel, const QModelIndex &index, QString &rootPath);

signals:
    void sglUpdateProgBar(int nval);

private slots:

    void slotUpdateProgressBar(int nval);

    void on_btnSelect_clicked();
    void on_btnDoIt_clicked();

    void on_checkBox_clicked(bool checked);
    void on_tabWidget_currentChanged(int index);

    void on_tableWgt_clicked(const QModelIndex &index);
    void on_tableWgt3_clicked(const QModelIndex &index);
    void on_tableWgt2_clicked(const QModelIndex &index);
    void on_tableWgt4_clicked(const QModelIndex &index);

    void on_tbtnSetPath_clicked();
    void on_comboBox_currentIndexChanged(int index);

    void on_tableWgt_doubleClicked(const QModelIndex &index);
    void on_tableWgt3_doubleClicked(const QModelIndex &index);
    void on_tableWgt2_doubleClicked(const QModelIndex &index);
    void on_tableWgt4_doubleClicked(const QModelIndex &index);


private:
    int mRows;
    QString mProRoot; // 项目根路径
    QString mProQrcDir; // 项目资源路径
    QString mProQrcName; // 项目资源名称
    QString mUIDirPath; // ui文件夹路径--form
    QString mUIDirPath2; // ui文件夹路径--toolbar
    QString mTXTDirPath; // txt文件夹路径--form
    QString mTXTDirPath2;// txt文件夹路径--toolbar

    QString mCurTxtClass;// 当前节点类

    bool mFlagWType; // 是否有wtype属性出现
    bool mSwitchMode; // 0: txt->ui;  1: ui->txt;
    bool mFlagColorChange, mFlagFileChange; // 色值转换开启；文件表示转换开启
    int mTBWidth, mTBHeight, mSTBWidth, mSTBHeight; // toolbar,subtoolbar的宽高

    QStringList ltNames;

    QMap<QString, int> mapProperty; // 属性对应类型表
    QMap<QString, QString> mapProperty2; // 属性转换表
    QMap<QString, QString> mapSystem; // 系统参数map表

    QStringList ltNewClss; // 新WND类

    QFileSystemModel *model; // txt文件系统--form
    QFileSystemModel *model2;// txt文件系统--toolbar
    QFileSystemModel *model3;// ui文件系统--form
    QFileSystemModel *model4;// ui文件系统--toolbar

    int mPercent; // 进度条均分数
    int mProbarValue; // 进度条值
    QProgressBar *mBar; // 进度条

    FileBrowser *mBrowser; // 文件浏览器
    ToolBarSetDlg *mSetTBWH; // txt转ui时的设置弹窗
    ProIniSetDlg *mSetProPath; // 项目配置弹窗

    Ui::TMTxt2UI *ui; // 界面
};

#endif // TMTXT2UI_H
