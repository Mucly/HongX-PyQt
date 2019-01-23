#ifndef TOOLBARSETDLG_H
#define TOOLBARSETDLG_H

#include <QDialog>

namespace Ui {
class ToolBarSetDlg;
}

class ToolBarSetDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ToolBarSetDlg(QWidget *parent = 0);
    ~ToolBarSetDlg();

    int Show(QString &path, QString &qrcName, QList<int> &ltPara);
    //int Show(QString &path, QString &qrcName, int &nw1, int &nh1, int &nw2, int &nh2);

private slots:
    void on_btnOK_clicked();
    void on_btnCancle_clicked();

private:
    Ui::ToolBarSetDlg *ui;
};

#endif // TOOLBARSETDLG_H
