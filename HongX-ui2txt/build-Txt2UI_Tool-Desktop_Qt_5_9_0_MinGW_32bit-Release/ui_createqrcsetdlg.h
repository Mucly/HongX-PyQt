/********************************************************************************
** Form generated from reading UI file 'createqrcsetdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEQRCSETDLG_H
#define UI_CREATEQRCSETDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CreateQrcSetDlg
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOK;
    QPushButton *btnCancle;

    void setupUi(QDialog *CreateQrcSetDlg)
    {
        if (CreateQrcSetDlg->objectName().isEmpty())
            CreateQrcSetDlg->setObjectName(QStringLiteral("CreateQrcSetDlg"));
        CreateQrcSetDlg->resize(387, 137);
        CreateQrcSetDlg->setFocusPolicy(Qt::NoFocus);
        verticalLayout = new QVBoxLayout(CreateQrcSetDlg);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(7, 7, 7, 7);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, 40, -1);
        label = new QLabel(CreateQrcSetDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(70, 0));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(CreateQrcSetDlg);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        label_2 = new QLabel(CreateQrcSetDlg);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout);

        label_3 = new QLabel(CreateQrcSetDlg);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(70, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        checkBox = new QCheckBox(CreateQrcSetDlg);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setChecked(true);

        horizontalLayout_3->addWidget(checkBox);

        checkBox_2 = new QCheckBox(CreateQrcSetDlg);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setChecked(true);

        horizontalLayout_3->addWidget(checkBox_2);

        checkBox_3 = new QCheckBox(CreateQrcSetDlg);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));

        horizontalLayout_3->addWidget(checkBox_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btnOK = new QPushButton(CreateQrcSetDlg);
        btnOK->setObjectName(QStringLiteral("btnOK"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnOK->sizePolicy().hasHeightForWidth());
        btnOK->setSizePolicy(sizePolicy);
        btnOK->setMinimumSize(QSize(80, 35));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        btnOK->setFont(font);

        horizontalLayout_2->addWidget(btnOK);

        btnCancle = new QPushButton(CreateQrcSetDlg);
        btnCancle->setObjectName(QStringLiteral("btnCancle"));
        sizePolicy.setHeightForWidth(btnCancle->sizePolicy().hasHeightForWidth());
        btnCancle->setSizePolicy(sizePolicy);
        btnCancle->setMinimumSize(QSize(80, 35));
        btnCancle->setFont(font);
        btnCancle->setStyleSheet(QStringLiteral("color:red;"));

        horizontalLayout_2->addWidget(btnCancle);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(CreateQrcSetDlg);

        QMetaObject::connectSlotsByName(CreateQrcSetDlg);
    } // setupUi

    void retranslateUi(QDialog *CreateQrcSetDlg)
    {
        CreateQrcSetDlg->setWindowTitle(QApplication::translate("CreateQrcSetDlg", "\347\224\237\346\210\220QRC\350\256\276\347\275\256", Q_NULLPTR));
        label->setText(QApplication::translate("CreateQrcSetDlg", "\346\226\207\344\273\266\345\220\215\357\274\232", Q_NULLPTR));
        lineEdit->setText(QApplication::translate("CreateQrcSetDlg", "pro_res", Q_NULLPTR));
        label_2->setText(QApplication::translate("CreateQrcSetDlg", ".qrc", Q_NULLPTR));
        label_3->setText(QApplication::translate("CreateQrcSetDlg", "\350\265\204\346\272\220\346\226\207\344\273\266\357\274\232", Q_NULLPTR));
        checkBox->setText(QApplication::translate("CreateQrcSetDlg", "image", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("CreateQrcSetDlg", "toolbarBG", Q_NULLPTR));
        checkBox_3->setText(QApplication::translate("CreateQrcSetDlg", "screen", Q_NULLPTR));
        btnOK->setText(QApplication::translate("CreateQrcSetDlg", "\347\241\256\350\256\244", Q_NULLPTR));
        btnCancle->setText(QApplication::translate("CreateQrcSetDlg", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CreateQrcSetDlg: public Ui_CreateQrcSetDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEQRCSETDLG_H
