#ifndef PROINISETDLG_H
#define PROINISETDLG_H

#include <QDialog>
#include <QMap>

namespace Ui {
class ProIniSetDlg;
}

class ProIniSetDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ProIniSetDlg(QWidget *parent = 0);
    ~ProIniSetDlg();

    bool UpdatePath(QMap<QString, QString> &map);

private slots:
    void on_btnSetIni_clicked();
    void on_btnSetUi1_clicked();
    void on_btnSetUi2_clicked();
    void on_btnOK_clicked();
    void on_btnCancle_clicked();
    void on_btnCreateQrc_clicked();

private:
    QString mRootPath;
    QString mProQrcPath;
    QString mProQrcName;
    Ui::ProIniSetDlg *ui;
};

QStringList GetFilesOfDir(QString &dirPath, QStringList &filters, QString removeString="");
bool WriteQrcFile(QString path, QStringList &flNames);

#endif // PROINISETDLG_H
