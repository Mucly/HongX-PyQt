#ifndef CREATEQRCSETDLG_H
#define CREATEQRCSETDLG_H

#include <QDialog>

namespace Ui {
class CreateQrcSetDlg;
}

class CreateQrcSetDlg : public QDialog
{
    Q_OBJECT

public:
    explicit CreateQrcSetDlg(QWidget *parent = 0);
    ~CreateQrcSetDlg();

    bool GetQrcPara(QString &name, QStringList &dirNames);

private slots:
    void on_btnOK_clicked();
    void on_btnCancle_clicked();

private:
    Ui::CreateQrcSetDlg *ui;
};

#endif // CREATEQRCSETDLG_H
