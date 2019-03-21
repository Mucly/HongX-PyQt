/********************************************************************************
** Form generated from reading UI file 'proinisetdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROINISETDLG_H
#define UI_PROINISETDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ProIniSetDlg
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_5;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label_5;
    QLineEdit *lineEdit_4;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QPushButton *btnSetUi1;
    QPushButton *btnSetUi2;
    QPushButton *btnSetIni;
    QLabel *label_6;
    QLineEdit *lineEdit_6;
    QPushButton *btnCreateQrc;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOK;
    QPushButton *btnCancle;

    void setupUi(QDialog *ProIniSetDlg)
    {
        if (ProIniSetDlg->objectName().isEmpty())
            ProIniSetDlg->setObjectName(QStringLiteral("ProIniSetDlg"));
        ProIniSetDlg->resize(513, 248);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ProIniSetDlg->sizePolicy().hasHeightForWidth());
        ProIniSetDlg->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(ProIniSetDlg);
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(7, 7, 7, 4);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setVerticalSpacing(5);
        gridLayout->setContentsMargins(-1, -1, 7, -1);
        lineEdit = new QLineEdit(ProIniSetDlg);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setEnabled(false);
        lineEdit->setMinimumSize(QSize(0, 25));
        lineEdit->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        lineEdit_5 = new QLineEdit(ProIniSetDlg);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setEnabled(false);
        lineEdit_5->setMinimumSize(QSize(0, 25));
        lineEdit_5->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));

        gridLayout->addWidget(lineEdit_5, 4, 1, 1, 1);

        label_4 = new QLabel(ProIniSetDlg);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_2 = new QLabel(ProIniSetDlg);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_5 = new QLabel(ProIniSetDlg);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        lineEdit_4 = new QLineEdit(ProIniSetDlg);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setEnabled(false);
        lineEdit_4->setMinimumSize(QSize(0, 25));
        lineEdit_4->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));

        gridLayout->addWidget(lineEdit_4, 3, 1, 1, 1);

        label = new QLabel(ProIniSetDlg);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_2 = new QLineEdit(ProIniSetDlg);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setEnabled(false);
        lineEdit_2->setMinimumSize(QSize(0, 25));
        lineEdit_2->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));

        gridLayout->addWidget(lineEdit_2, 1, 1, 1, 1);

        label_3 = new QLabel(ProIniSetDlg);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        lineEdit_3 = new QLineEdit(ProIniSetDlg);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setEnabled(false);
        lineEdit_3->setMinimumSize(QSize(0, 25));
        lineEdit_3->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));

        gridLayout->addWidget(lineEdit_3, 2, 1, 1, 1);

        btnSetUi1 = new QPushButton(ProIniSetDlg);
        btnSetUi1->setObjectName(QStringLiteral("btnSetUi1"));
        sizePolicy.setHeightForWidth(btnSetUi1->sizePolicy().hasHeightForWidth());
        btnSetUi1->setSizePolicy(sizePolicy);
        btnSetUi1->setMinimumSize(QSize(60, 0));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        btnSetUi1->setFont(font);

        gridLayout->addWidget(btnSetUi1, 3, 2, 1, 1);

        btnSetUi2 = new QPushButton(ProIniSetDlg);
        btnSetUi2->setObjectName(QStringLiteral("btnSetUi2"));
        sizePolicy.setHeightForWidth(btnSetUi2->sizePolicy().hasHeightForWidth());
        btnSetUi2->setSizePolicy(sizePolicy);
        btnSetUi2->setMinimumSize(QSize(60, 0));
        btnSetUi2->setFont(font);

        gridLayout->addWidget(btnSetUi2, 4, 2, 1, 1);

        btnSetIni = new QPushButton(ProIniSetDlg);
        btnSetIni->setObjectName(QStringLiteral("btnSetIni"));
        sizePolicy.setHeightForWidth(btnSetIni->sizePolicy().hasHeightForWidth());
        btnSetIni->setSizePolicy(sizePolicy);
        btnSetIni->setMinimumSize(QSize(60, 0));
        btnSetIni->setFont(font);

        gridLayout->addWidget(btnSetIni, 0, 2, 1, 1);

        label_6 = new QLabel(ProIniSetDlg);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        lineEdit_6 = new QLineEdit(ProIniSetDlg);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setEnabled(false);
        lineEdit_6->setMinimumSize(QSize(0, 25));
        lineEdit_6->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));

        gridLayout->addWidget(lineEdit_6, 5, 1, 1, 1);

        btnCreateQrc = new QPushButton(ProIniSetDlg);
        btnCreateQrc->setObjectName(QStringLiteral("btnCreateQrc"));
        sizePolicy.setHeightForWidth(btnCreateQrc->sizePolicy().hasHeightForWidth());
        btnCreateQrc->setSizePolicy(sizePolicy);
        btnCreateQrc->setMinimumSize(QSize(60, 0));

        gridLayout->addWidget(btnCreateQrc, 5, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, -1, -1, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnOK = new QPushButton(ProIniSetDlg);
        btnOK->setObjectName(QStringLiteral("btnOK"));
        btnOK->setMinimumSize(QSize(86, 35));

        horizontalLayout->addWidget(btnOK);

        btnCancle = new QPushButton(ProIniSetDlg);
        btnCancle->setObjectName(QStringLiteral("btnCancle"));
        btnCancle->setMinimumSize(QSize(86, 35));
        btnCancle->setStyleSheet(QStringLiteral("color: red;"));

        horizontalLayout->addWidget(btnCancle);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 6);
        verticalLayout->setStretch(1, 1);

        retranslateUi(ProIniSetDlg);

        QMetaObject::connectSlotsByName(ProIniSetDlg);
    } // setupUi

    void retranslateUi(QDialog *ProIniSetDlg)
    {
        ProIniSetDlg->setWindowTitle(QApplication::translate("ProIniSetDlg", "\345\212\240\350\275\275\351\241\271\347\233\256", Q_NULLPTR));
        label_4->setText(QApplication::translate("ProIniSetDlg", "form\350\267\257\345\276\204(ui)\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("ProIniSetDlg", "form\350\267\257\345\276\204(txt)\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("ProIniSetDlg", "toolbar\350\267\257\345\276\204(ui)\357\274\232", Q_NULLPTR));
        label->setText(QApplication::translate("ProIniSetDlg", "\351\241\271\347\233\256\351\205\215\347\275\256(ini)\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("ProIniSetDlg", "toolbar\350\267\257\345\276\204(txt)\357\274\232", Q_NULLPTR));
        btnSetUi1->setText(QApplication::translate("ProIniSetDlg", "...", Q_NULLPTR));
        btnSetUi2->setText(QApplication::translate("ProIniSetDlg", "...", Q_NULLPTR));
        btnSetIni->setText(QApplication::translate("ProIniSetDlg", "...", Q_NULLPTR));
        label_6->setText(QApplication::translate("ProIniSetDlg", "\350\207\252\345\212\250\347\224\237\346\210\220qrc\350\267\257\345\276\204\357\274\232", Q_NULLPTR));
        btnCreateQrc->setText(QApplication::translate("ProIniSetDlg", "\347\224\237\346\210\220", Q_NULLPTR));
        btnOK->setText(QApplication::translate("ProIniSetDlg", "\347\241\256\350\256\244", Q_NULLPTR));
        btnCancle->setText(QApplication::translate("ProIniSetDlg", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ProIniSetDlg: public Ui_ProIniSetDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROINISETDLG_H
