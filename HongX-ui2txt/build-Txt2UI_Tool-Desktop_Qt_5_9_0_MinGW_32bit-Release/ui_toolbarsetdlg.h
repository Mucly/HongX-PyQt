/********************************************************************************
** Form generated from reading UI file 'toolbarsetdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLBARSETDLG_H
#define UI_TOOLBARSETDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ToolBarSetDlg
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_6;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_3;
    QSpinBox *spinBox_3;
    QLabel *label;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox_4;
    QLabel *label_7;
    QComboBox *cbxRGBChange;
    QComboBox *cbxTxtChange;
    QLabel *label_5;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOK;
    QPushButton *btnCancle;

    void setupUi(QDialog *ToolBarSetDlg)
    {
        if (ToolBarSetDlg->objectName().isEmpty())
            ToolBarSetDlg->setObjectName(QStringLiteral("ToolBarSetDlg"));
        ToolBarSetDlg->resize(353, 259);
        verticalLayout = new QVBoxLayout(ToolBarSetDlg);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(7, 7, 7, 7);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(7);
        gridLayout->setVerticalSpacing(2);
        gridLayout->setContentsMargins(5, -1, 7, -1);
        label_6 = new QLabel(ToolBarSetDlg);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        label_2 = new QLabel(ToolBarSetDlg);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label_4 = new QLabel(ToolBarSetDlg);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        label_3 = new QLabel(ToolBarSetDlg);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        spinBox_3 = new QSpinBox(ToolBarSetDlg);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));
        QFont font;
        font.setPointSize(10);
        spinBox_3->setFont(font);
        spinBox_3->setAlignment(Qt::AlignCenter);
        spinBox_3->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_3->setMaximum(99999);

        gridLayout->addWidget(spinBox_3, 3, 1, 1, 1);

        label = new QLabel(ToolBarSetDlg);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        spinBox = new QSpinBox(ToolBarSetDlg);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setFont(font);
        spinBox->setAlignment(Qt::AlignCenter);
        spinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox->setMaximum(99999);

        gridLayout->addWidget(spinBox, 1, 1, 1, 1);

        spinBox_2 = new QSpinBox(ToolBarSetDlg);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setFont(font);
        spinBox_2->setAlignment(Qt::AlignCenter);
        spinBox_2->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_2->setMaximum(99999);

        gridLayout->addWidget(spinBox_2, 2, 1, 1, 1);

        spinBox_4 = new QSpinBox(ToolBarSetDlg);
        spinBox_4->setObjectName(QStringLiteral("spinBox_4"));
        spinBox_4->setFont(font);
        spinBox_4->setAlignment(Qt::AlignCenter);
        spinBox_4->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_4->setMaximum(99999);

        gridLayout->addWidget(spinBox_4, 4, 1, 1, 1);

        label_7 = new QLabel(ToolBarSetDlg);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 6, 0, 1, 1);

        cbxRGBChange = new QComboBox(ToolBarSetDlg);
        cbxRGBChange->setObjectName(QStringLiteral("cbxRGBChange"));
        cbxRGBChange->setMinimumSize(QSize(0, 26));

        gridLayout->addWidget(cbxRGBChange, 5, 1, 1, 1);

        cbxTxtChange = new QComboBox(ToolBarSetDlg);
        cbxTxtChange->setObjectName(QStringLiteral("cbxTxtChange"));
        cbxTxtChange->setMinimumSize(QSize(0, 26));

        gridLayout->addWidget(cbxTxtChange, 6, 1, 1, 1);

        label_5 = new QLabel(ToolBarSetDlg);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 7, 0, 1, 1);

        comboBox = new QComboBox(ToolBarSetDlg);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMinimumSize(QSize(0, 26));

        gridLayout->addWidget(comboBox, 7, 1, 1, 1);

        gridLayout->setColumnStretch(0, 2);
        gridLayout->setColumnStretch(1, 3);
        gridLayout->setColumnMinimumWidth(0, 3);
        gridLayout->setColumnMinimumWidth(1, 2);

        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnOK = new QPushButton(ToolBarSetDlg);
        btnOK->setObjectName(QStringLiteral("btnOK"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnOK->sizePolicy().hasHeightForWidth());
        btnOK->setSizePolicy(sizePolicy);
        btnOK->setMinimumSize(QSize(65, 35));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        btnOK->setFont(font1);

        horizontalLayout->addWidget(btnOK);

        btnCancle = new QPushButton(ToolBarSetDlg);
        btnCancle->setObjectName(QStringLiteral("btnCancle"));
        sizePolicy.setHeightForWidth(btnCancle->sizePolicy().hasHeightForWidth());
        btnCancle->setSizePolicy(sizePolicy);
        btnCancle->setMinimumSize(QSize(65, 35));
        btnCancle->setFont(font1);

        horizontalLayout->addWidget(btnCancle);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 5);
        verticalLayout->setStretch(1, 1);
        QWidget::setTabOrder(spinBox, spinBox_2);
        QWidget::setTabOrder(spinBox_2, spinBox_3);
        QWidget::setTabOrder(spinBox_3, spinBox_4);
        QWidget::setTabOrder(spinBox_4, cbxRGBChange);
        QWidget::setTabOrder(cbxRGBChange, cbxTxtChange);
        QWidget::setTabOrder(cbxTxtChange, comboBox);
        QWidget::setTabOrder(comboBox, btnOK);
        QWidget::setTabOrder(btnOK, btnCancle);

        retranslateUi(ToolBarSetDlg);

        cbxRGBChange->setCurrentIndex(1);
        cbxTxtChange->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(ToolBarSetDlg);
    } // setupUi

    void retranslateUi(QDialog *ToolBarSetDlg)
    {
        ToolBarSetDlg->setWindowTitle(QApplication::translate("ToolBarSetDlg", "\347\233\270\345\205\263\350\256\276\347\275\256\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("ToolBarSetDlg", "\350\211\262\345\200\274RGB565\350\275\254RGB888:", Q_NULLPTR));
        label_2->setText(QApplication::translate("ToolBarSetDlg", "toolbar\351\253\230\345\272\246\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("ToolBarSetDlg", "subtoolbar\351\253\230\345\272\246\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("ToolBarSetDlg", "subtoolbar\345\256\275\345\272\246\357\274\232", Q_NULLPTR));
        label->setText(QApplication::translate("ToolBarSetDlg", "toolbar\345\256\275\345\272\246\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("ToolBarSetDlg", "\346\226\207\344\273\266\347\264\242\345\274\225.txt\346\224\271\346\210\220.ui\357\274\232", Q_NULLPTR));
        cbxRGBChange->clear();
        cbxRGBChange->insertItems(0, QStringList()
         << QApplication::translate("ToolBarSetDlg", "\345\205\263\351\227\255", Q_NULLPTR)
         << QApplication::translate("ToolBarSetDlg", "\345\274\200\345\220\257", Q_NULLPTR)
        );
        cbxTxtChange->clear();
        cbxTxtChange->insertItems(0, QStringList()
         << QApplication::translate("ToolBarSetDlg", "\345\205\263\351\227\255", Q_NULLPTR)
         << QApplication::translate("ToolBarSetDlg", "\345\274\200\345\220\257", Q_NULLPTR)
        );
        label_5->setText(QApplication::translate("ToolBarSetDlg", "\345\233\276\347\211\207\345\205\263\350\201\224\350\265\204\346\272\220qrc\346\226\207\344\273\266\357\274\232", Q_NULLPTR));
        btnOK->setText(QApplication::translate("ToolBarSetDlg", "\347\241\256\350\256\244", Q_NULLPTR));
        btnCancle->setText(QApplication::translate("ToolBarSetDlg", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ToolBarSetDlg: public Ui_ToolBarSetDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLBARSETDLG_H
