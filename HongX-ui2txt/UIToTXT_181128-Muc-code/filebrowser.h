#ifndef FILEBROWSER_H
#define FILEBROWSER_H

#include <QMap>
#include <QDialog>
#include <QKeyEvent>

#include "./myhighlighter.h"

namespace Ui {
class FileBrowser;
}

class FileBrowser : public QDialog
{
    Q_OBJECT

public:
    explicit FileBrowser(QWidget *parent = 0);
    ~FileBrowser();

    void Show(QString &path);

protected:
    void keyPressEvent(QKeyEvent *event);

private slots:
    void slotFindRes(bool ok);
    void on_pushButton_2_clicked();
    void on_tbtn1_clicked();
    void on_tbtn2_clicked();
    void on_tbtnSearch_clicked();

private:
    QString search_text;
    int nCurMaxCount;
    int nCurPos;
    int nCurCount;
    QMap<int, int> mapPos;

    MyHighLighter *mHighLighter;
    Ui::FileBrowser *ui;
};

#endif // FILEBROWSER_H
