#include "toolbarsetdlg.h"
#include "ui_toolbarsetdlg.h"

#include <QDir>
#include <QFileInfo>

ToolBarSetDlg::ToolBarSetDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ToolBarSetDlg)
{
    ui->setupUi(this);
}

ToolBarSetDlg::~ToolBarSetDlg()
{
    delete ui;
}

/*
 * txt转换Ui时，弹出设置窗口
 */
int ToolBarSetDlg::Show(QString &path, QString &qrcName, QList<int> &ltPara)
//int ToolBarSetDlg::Show(QString &path, QString &qrcName, int &nw1, int &nh1, int &nw2, int &nh2)
{
    // @
    ui->comboBox->clear();
    QDir dir(path);
    if(dir.exists()){
        dir.setNameFilters(QStringList()<<"*.qrc");
        dir.setFilter(QDir::Files | QDir::NoSymLinks);
        QFileInfoList list = dir.entryInfoList();

        QStringList ltNames;
        ltNames.clear();
        foreach (QFileInfo info, list) {
            ltNames.append(info.fileName());
        }
        ui->comboBox->addItems(ltNames);
    }

    // @
    if(path.right(1)=="/") path = path.left(path.length()-1);
    int ndex = path.lastIndexOf("/");
    path.remove(0, ndex+1);

    // @
    ui->spinBox->setValue(ltPara.value(0, 0));
    ui->spinBox_2->setValue(ltPara.value(1, 0));
    ui->spinBox_3->setValue(ltPara.value(2, 0));
    ui->spinBox_4->setValue(ltPara.value(3, 0));
    ui->cbxRGBChange->setCurrentIndex(ltPara.value(4, 0));
    ui->cbxTxtChange->setCurrentIndex(ltPara.value(5, 0));

    int nres = this->exec();
    if(nres==1){
        ltPara.replace(0, ui->spinBox->value());
        ltPara.replace(1, ui->spinBox_2->value());
        ltPara.replace(2, ui->spinBox_3->value());
        ltPara.replace(3, ui->spinBox_4->value());
        ltPara.replace(4, ui->cbxRGBChange->currentIndex());
        ltPara.replace(5, ui->cbxTxtChange->currentIndex());

        qrcName = ui->comboBox->currentText();
    }

    return nres;
}



void ToolBarSetDlg::on_btnOK_clicked()
{
    done(1);
    this->close();
}

void ToolBarSetDlg::on_btnCancle_clicked()
{
    done(0);
    this->close();
}
