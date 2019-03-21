#include "mainwindow.h"
#include <QApplication>

#include "./tmtxt2ui.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    a.setStyle("windows");

    TMTxt2UI *mw = new TMTxt2UI;
    mw->show();
    //qDebug() << "********************* exit0";

    int nres = a.exec();
    delete mw;
    mw = NULL;
    //qDebug() << "********************* exit1";

    return nres;
}
