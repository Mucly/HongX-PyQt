#-------------------------------------------------
#
# Project created by QtCreator 2018-03-15T14:00:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Txt2UI_Tool
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    tmtxt2ui.cpp \
    toolbarsetdlg.cpp \
    proinisetdlg.cpp \
    createqrcsetdlg.cpp \
    filebrowser.cpp \
    myhighlighter.cpp

HEADERS += \
        mainwindow.h \
    tmtxt2ui.h \
    toolbarsetdlg.h \
    proinisetdlg.h \
    globalvalue.h \
    createqrcsetdlg.h \
    filebrowser.h \
    myhighlighter.h

FORMS += \
        mainwindow.ui \
    tmtxt2ui.ui \
    toolbarsetdlg.ui \
    proinisetdlg.ui \
    createqrcsetdlg.ui \
    filebrowser.ui

unix:{
DISTFILES   += appico.rc    # 就是前面说的文本文件
}
win32:{
RC_FILE     += appico.rc
}
