#include "filebrowser.h"
#include "ui_filebrowser.h"

#include <QFile>
#include <QDebug>
#include <QRegExp>
#include <QTextStream>
#include <QMessageBox>
#include <QInputDialog>

FileBrowser::FileBrowser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FileBrowser)
{
    ui->setupUi(this);

    setModal(false);
    //setWindowFlags(Qt::Widget | Qt::WindowStaysOnTopHint);
    this->hide();

    ui->btnSave->hide();

    ui->label->hide();
    ui->lineEdit->hide();
    ui->tbtn1->hide();
    ui->tbtn2->hide();
    ui->tbtnSearch->hide();
    ui->labIndex->hide();

    mHighLighter = new MyHighLighter(ui->pTextEdit->document());
    //connect(mHighLighter, &MyHighLighter::searchRes, this, &FileBrowser::slotFindRes);
}

FileBrowser::~FileBrowser()
{
    delete ui;
}

/*
 * 文件浏览界面显示
 */
void FileBrowser::Show(QString &path)
{
    ui->pTextEdit->clear();
    //ui->pTextEdit->setForegroundRole(Qt::black);
    //ui->pTextEdit->setBackgroundRole(Qt::lightGray);
    if (path.isEmpty()) {
        QMessageBox::critical(NULL, tr("错误！"), tr("打开失败：文件名为空！"));
        return;
    }

    QFile fl(path);
    if (!fl.open(QFile::ReadWrite)) {
        QMessageBox::critical(NULL, tr("警告！"), tr("打开文件失败！"));
        return ;
    }

    QTextStream stm(&fl);
    QString txt = stm.readAll();

    fl.close();

    // @
    this->setWindowTitle(tr("文件浏览 -- %1").arg(path));
    ui->pTextEdit->setText(txt);

    //this->exec();
    this->show();
}

void FileBrowser::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_F && (event->modifiers() == (Qt::ControlModifier))) {
        //QString search_text = QInputDialog::getText(NULL, tr("查找"), tr("查找内容："));
//        if(!search_text.isEmpty()){
//            mHighLighter->findTxt(search_text);
//            ui->pTextEdit->setTextCursor(ui->pTextEdit->document()->find(search_text, 0));
//        }
    }
}

void FileBrowser::slotFindRes(bool ok)
{
    if (!ok) {
        QMessageBox::information(this, tr("Word not found"),
                                 tr("Sorry,the word cannot be found."));
    }
}

void FileBrowser::on_pushButton_2_clicked()
{
    //close();
    hide();
}

// up
void FileBrowser::on_tbtn1_clicked()
{
    if (nCurCount <= 1) return;
    nCurCount--;
    nCurPos = mapPos.value(nCurCount);
    QTextCursor mycursor =  ui->pTextEdit->document()->find(search_text, nCurPos - 1);
    ui->labIndex->setText(QString("%1/%2").arg(nCurCount).arg(nCurMaxCount));
    ui->pTextEdit->setTextCursor(mycursor);
}

// down
void FileBrowser::on_tbtn2_clicked()
{
    if (nCurCount >= nCurMaxCount) return;
    nCurCount++;
    nCurPos = mapPos.value(nCurCount);
    QTextCursor mycursor =  ui->pTextEdit->document()->find(search_text, nCurPos - 1);
    ui->labIndex->setText(QString("%1/%2").arg(nCurCount).arg(nCurMaxCount));
    ui->pTextEdit->setTextCursor(mycursor);
}

void FileBrowser::on_tbtnSearch_clicked()
{
    search_text = ui->lineEdit->text();
    if (search_text.isEmpty()) {
        QMessageBox::critical(NULL, tr("错误！"), tr("关键字不能为空！"));
        return;
    }

    nCurPos = 0;
    nCurMaxCount = 0;
    int nlen = search_text.length();
    QTextCursor mycursor;
    QTextDocument *mydoc = ui->pTextEdit->document();
    ui->labIndex->setText("0/0");
    mapPos.clear();

    while (true) {
        mycursor =  mydoc->find(search_text, nCurPos);
        if (mycursor.isNull()) break;

        nCurMaxCount++;
        mapPos.insert(nCurMaxCount, mycursor.position());
        nCurPos = mycursor.position() + nlen - 1;
    }
    qDebug() << "mapPos =" << mapPos;

    if (nCurMaxCount > 0) {
        //
        mHighLighter->findTxt(search_text);

        //
        nCurCount = 1;
        nCurPos = mapPos.value(nCurCount);
        qDebug() << "********** nCurpos =" << nCurPos;
        mycursor =  mydoc->find(search_text, nCurPos - 1);
        ui->labIndex->setText(QString("%1/%2").arg(nCurCount).arg(nCurMaxCount));
        ui->pTextEdit->setTextCursor(mycursor);
    }
}
