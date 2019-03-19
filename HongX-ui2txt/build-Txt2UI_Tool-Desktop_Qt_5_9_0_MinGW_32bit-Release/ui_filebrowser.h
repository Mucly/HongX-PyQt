/********************************************************************************
** Form generated from reading UI file 'filebrowser.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEBROWSER_H
#define UI_FILEBROWSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FileBrowser
{
public:
    QVBoxLayout *verticalLayout;
    QTextEdit *pTextEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QToolButton *tbtnSearch;
    QToolButton *tbtn1;
    QLabel *labIndex;
    QToolButton *tbtn2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnSave;
    QPushButton *pushButton_2;

    void setupUi(QDialog *FileBrowser)
    {
        if (FileBrowser->objectName().isEmpty())
            FileBrowser->setObjectName(QStringLiteral("FileBrowser"));
        FileBrowser->resize(800, 600);
        FileBrowser->setFocusPolicy(Qt::NoFocus);
        verticalLayout = new QVBoxLayout(FileBrowser);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(7, 7, 7, 7);
        pTextEdit = new QTextEdit(FileBrowser);
        pTextEdit->setObjectName(QStringLiteral("pTextEdit"));
        QFont font;
        font.setPointSize(11);
        pTextEdit->setFont(font);
        pTextEdit->setFocusPolicy(Qt::NoFocus);
        pTextEdit->setStyleSheet(QStringLiteral("background-color: rgb(237, 255, 253);"));

        verticalLayout->addWidget(pTextEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, 7, -1);
        label = new QLabel(FileBrowser);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(FileBrowser);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(28, 28));

        horizontalLayout->addWidget(lineEdit);

        tbtnSearch = new QToolButton(FileBrowser);
        tbtnSearch->setObjectName(QStringLiteral("tbtnSearch"));
        tbtnSearch->setMinimumSize(QSize(0, 30));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        tbtnSearch->setFont(font1);
        tbtnSearch->setStyleSheet(QStringLiteral("color: rgb(59, 150, 52);"));

        horizontalLayout->addWidget(tbtnSearch);

        tbtn1 = new QToolButton(FileBrowser);
        tbtn1->setObjectName(QStringLiteral("tbtn1"));
        tbtn1->setArrowType(Qt::UpArrow);

        horizontalLayout->addWidget(tbtn1);

        labIndex = new QLabel(FileBrowser);
        labIndex->setObjectName(QStringLiteral("labIndex"));
        labIndex->setMinimumSize(QSize(45, 0));
        labIndex->setFont(font);
        labIndex->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(labIndex);

        tbtn2 = new QToolButton(FileBrowser);
        tbtn2->setObjectName(QStringLiteral("tbtn2"));
        tbtn2->setArrowType(Qt::DownArrow);

        horizontalLayout->addWidget(tbtn2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnSave = new QPushButton(FileBrowser);
        btnSave->setObjectName(QStringLiteral("btnSave"));
        btnSave->setMinimumSize(QSize(80, 35));
        btnSave->setFont(font1);

        horizontalLayout->addWidget(btnSave);

        pushButton_2 = new QPushButton(FileBrowser);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(80, 35));
        pushButton_2->setFont(font1);
        pushButton_2->setStyleSheet(QStringLiteral("color:red;"));

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);

        QWidget::setTabOrder(pTextEdit, btnSave);
        QWidget::setTabOrder(btnSave, pushButton_2);
        QWidget::setTabOrder(pushButton_2, lineEdit);
        QWidget::setTabOrder(lineEdit, tbtnSearch);
        QWidget::setTabOrder(tbtnSearch, tbtn1);
        QWidget::setTabOrder(tbtn1, tbtn2);

        retranslateUi(FileBrowser);

        QMetaObject::connectSlotsByName(FileBrowser);
    } // setupUi

    void retranslateUi(QDialog *FileBrowser)
    {
        FileBrowser->setWindowTitle(QApplication::translate("FileBrowser", "\346\226\207\344\273\266\346\265\217\350\247\210\345\231\250", Q_NULLPTR));
        label->setText(QApplication::translate("FileBrowser", "\345\205\263\351\224\256\345\255\227\357\274\232", Q_NULLPTR));
        tbtnSearch->setText(QApplication::translate("FileBrowser", "\346\237\245\346\211\276", Q_NULLPTR));
        tbtn1->setText(QString());
        labIndex->setText(QApplication::translate("FileBrowser", "0/0", Q_NULLPTR));
        tbtn2->setText(QApplication::translate("FileBrowser", "...", Q_NULLPTR));
        btnSave->setText(QApplication::translate("FileBrowser", "\344\277\235\345\255\230", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("FileBrowser", "\345\205\263\351\227\255", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FileBrowser: public Ui_FileBrowser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEBROWSER_H
