#include "createqrcsetdlg.h"
#include "ui_createqrcsetdlg.h"

#include <QMessageBox>

CreateQrcSetDlg::CreateQrcSetDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateQrcSetDlg)
{
    ui->setupUi(this);
}

CreateQrcSetDlg::~CreateQrcSetDlg()
{
    delete ui;
}

/*
 * 获取qrc文件名name,资源文件夹列表dirNames
 */
bool CreateQrcSetDlg::GetQrcPara(QString &name, QStringList &dirNames)
{
    int nres = exec();
    if(nres==1){
        name = ui->lineEdit->text() + ".qrc";

        dirNames.clear();
        if(ui->checkBox->isChecked()){
            dirNames << ui->checkBox->text();
        }
        if(ui->checkBox_2->isChecked()){
            dirNames << ui->checkBox_2->text();
        }
        if(ui->checkBox_3->isChecked()){
            dirNames << ui->checkBox_3->text();
        }

        return true;
    }
    return false;
}

void CreateQrcSetDlg::on_btnOK_clicked()
{
    if(ui->lineEdit->text().isEmpty()){
        QMessageBox::critical(NULL, tr("错误！"), tr("文件名不能为空！"));
        return;
    }
    if(!ui->checkBox->isChecked() &&
            !ui->checkBox_2->isChecked() &&
            !ui->checkBox_3->isChecked()){
        QMessageBox::critical(NULL, tr("错误！"), tr("资源路径不能为空！"));
        return;
    }
    done(1);
    close();
}

void CreateQrcSetDlg::on_btnCancle_clicked()
{
    done(0);
    close();
}
