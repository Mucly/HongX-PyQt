#include "proinisetdlg.h"
#include "ui_proinisetdlg.h"

#include <QDebug>
#include <QSettings>
#include <QFileDialog>
#include <QDir>
#include <QDirIterator>
#include <QFileInfo>
#include <QMessageBox>
#include <QXmlStreamWriter>

#include "./globalvalue.h"
#include "createqrcsetdlg.h"

ProIniSetDlg::ProIniSetDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProIniSetDlg)
{
    ui->setupUi(this);
}

ProIniSetDlg::~ProIniSetDlg()
{
    delete ui;
}

bool ProIniSetDlg::UpdatePath(QMap<QString, QString> &map)
{
    mRootPath = map.value(INI_KEY_PRO_ROOT);
    mProQrcPath = map.value(INI_KEY_PRO_IMAGE);
    ui->lineEdit->setText(map.value(INI_KEY_PRO_INI));
    ui->lineEdit_2->setText(map.value(INI_KEY_TXT_FORM));
    ui->lineEdit_3->setText(map.value(INI_KEY_TXT_TOOLBAR));
    ui->lineEdit_4->setText(map.value(INI_KEY_UI_FORM));
    ui->lineEdit_5->setText(map.value(INI_KEY_UI_TOOLBAR));
    ui->lineEdit_6->setText(map.value(INI_KEY_PRO_IMAGE));

    int res = exec();
    if(res==1){
        map.insert(INI_KEY_PRO_ROOT, mRootPath);
        map.insert(INI_KEY_PRO_INI, ui->lineEdit->text());
        map.insert(INI_KEY_TXT_FORM, ui->lineEdit_2->text());
        map.insert(INI_KEY_TXT_TOOLBAR, ui->lineEdit_3->text());
        map.insert(INI_KEY_UI_FORM, ui->lineEdit_4->text());
        map.insert(INI_KEY_UI_TOOLBAR, ui->lineEdit_5->text());
        map.insert(INI_KEY_PRO_IMAGE, ui->lineEdit_6->text());
        return true;
    }
    return false;
}

/*
 * 获取项目config.ini
 */
void ProIniSetDlg::on_btnSetIni_clicked()
{
     QString flPath = QFileDialog::getOpenFileName(this, tr("加载项目配置ini"), "./", "config.ini");
     if(flPath.isEmpty()) return;
     if(flPath.right(11) != "/config.ini") return;
     ui->lineEdit->setText(flPath);

     // @ get project root path
     mRootPath = flPath;
     mRootPath.remove("config.ini");

     // @ update other
     QSettings *pConf = new QSettings(flPath, QSettings::IniFormat);
     if(pConf){
         QString temp = pConf->value(SEINI_KEY_FORM).toString();
         //qDebug() << "****** temp1 =" << flPath;
         temp = temp.remove("./");
         ui->lineEdit_2->setText(mRootPath+temp);
         ui->lineEdit_4->setText(mRootPath+temp);

         temp = pConf->value(SEINI_KEY_TOOLBAR).toString();
         //qDebug() << "****** temp2 =" << temp;
         temp = temp.remove("./");
         ui->lineEdit_3->setText(mRootPath+temp);
         ui->lineEdit_5->setText(mRootPath+temp);

         //mProQrcPath = mRootPath;

         temp = pConf->value(SEINI_KEY_IMAGE).toString();
         //qDebug() << "****** temp2 =" << temp;
         temp.remove("./");
         temp.remove("image/");
         mProQrcPath = mRootPath+temp;
         ui->lineEdit_6->setText(mProQrcPath);

         delete pConf;
         pConf = NULL;
     }
}

void ProIniSetDlg::on_btnSetUi1_clicked()
{
    QString dirPath = QFileDialog::getExistingDirectory(this, tr("form的ui路径设置"), "./");
    if(dirPath.isEmpty()) return;
    ui->lineEdit_4->setText(dirPath);
}

void ProIniSetDlg::on_btnSetUi2_clicked()
{
    QString dirPath = QFileDialog::getExistingDirectory(this, tr("toolbar的ui路径设置"), "./");
    if(dirPath.isEmpty()) return;
    ui->lineEdit_5->setText(dirPath);
}

void ProIniSetDlg::on_btnOK_clicked()
{
    done(1);
    close();
}

void ProIniSetDlg::on_btnCancle_clicked()
{
    done(0);
    close();
}

// @ image
void ProIniSetDlg::on_btnCreateQrc_clicked()
{   
//    qDebug() << "******* mProQrcPath =" <<mProQrcPath;

    QStringList filters, listNames, ltDirNames;
    filters << "*.png"<<"*.bmp"<<"*.jpg"<<"*.jpeg"<<"*.gif"
            <<"*.PNG"<<"*.BMP"<<"*.JPG";//设置过滤类型
    listNames.clear();
    ltDirNames.clear();

    // @ get para
    CreateQrcSetDlg dlg;
    if(!dlg.GetQrcPara(mProQrcName, ltDirNames)) return;
//    qDebug() << "**********list Name =" << ltDirNames
//             << ", mProQrcName =" << mProQrcName;

    // @ get files
    foreach (QString path, ltDirNames) {
        path = mProQrcPath + path;
        listNames.append(GetFilesOfDir(path, filters, mProQrcPath));
    }

    if(listNames.isEmpty()) return;

//    qDebug() << "**********list Name =" << listNames;
//    return;

    // @ write qrc
    if(WriteQrcFile(mProQrcPath+mProQrcName, listNames))
        QMessageBox::information(NULL, tr("提示："), tr("生成qrc成功！"));
}

/*
 * FUN: 获取文件夹下的所有文件
 * dirPath: 文件夹路径
 * filters: 过滤因子
 * removeString: 对结果进行移除的部分子串
 */
QStringList GetFilesOfDir(QString &dirPath, QStringList &filters, QString removeString)
{
    QDir dir(dirPath);
    if(!dir.exists()){
        qDebug() << dirPath << "not exist!";
        return QStringList();
    }

    QStringList ltNames;
    ltNames.clear();
    QDirIterator dir_iterator(dirPath,
            filters,
            QDir::Files | QDir::NoSymLinks,
            QDirIterator::Subdirectories);

    while(dir_iterator.hasNext())
    {
        dir_iterator.next();
        QFileInfo file_info = dir_iterator.fileInfo();
        QString file_path = file_info.absoluteFilePath();
        if(!removeString.isEmpty())
            file_path.remove(removeString);
        ltNames.append(file_path);
    }
    return ltNames;
}

/*
 * FUN：写资源文件
 * path: qrc路径
 * flNames: 资源文件列表
 */
bool WriteQrcFile(QString path, QStringList &flNames)
{
    QFile fl(path);
    if(!fl.open(QFile::WriteOnly | QFile::Truncate | QFile::Text)){
        return false;
    }

    qDebug() << "********** WriteQrcFile: path =" << path;

    QXmlStreamWriter writer(&fl);
    writer.setAutoFormatting(true);
    writer.writeStartDocument();
    writer.writeStartElement("RCC");
    writer.writeStartElement("qresource");
    writer.writeAttribute("prefix", "/");

    foreach (QString name, flNames) {
        //qDebug() << "****** name =" << name;
        writer.writeTextElement("file", name);
    }

    writer.writeEndElement();
    writer.writeEndElement();
    writer.writeEndDocument();

    fl.close();

    return true;
}
