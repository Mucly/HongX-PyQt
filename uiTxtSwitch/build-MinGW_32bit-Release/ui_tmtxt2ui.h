/********************************************************************************
** Form generated from reading UI file 'tmtxt2ui.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TMTXT2UI_H
#define UI_TMTXT2UI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TMTxt2UI
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QTableView *tableWgt;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_4;
    QTableView *tableWgt3;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QTableView *tableWgt2;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_5;
    QTableView *tableWgt4;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *tbtnSetPath;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *checkBox;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnSelect;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btnDoIt;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *TMTxt2UI)
    {
        if (TMTxt2UI->objectName().isEmpty())
            TMTxt2UI->setObjectName(QStringLiteral("TMTxt2UI"));
        TMTxt2UI->setWindowModality(Qt::ApplicationModal);
        TMTxt2UI->resize(845, 444);
        TMTxt2UI->setStyleSheet(QLatin1String("QDialog{\n"
"                border: 1px solid blue;\n"
"                }\n"
"                QPushButton{\n"
"                border-radius: 5px;\n"
"                border: 1px solid gray;\n"
"                color: rgb(85, 170, 0);\n"
"                }\n"
"                QAbstractItemView::item{\n"
"                selection-background-color:qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0 rgba(94, 126, 165, 255), stop:1 rgba(159, 191, 230, 255));\n"
"                /* selection-color:black;*/\n"
"                }\n"
"                QTabWidget::pane{\n"
"                border:1px solid gray;\n"
"                }\n"
"                QTabWidget::tab-bar{\n"
"                alignment:left;\n"
"                margin-left: 10px;\n"
"                }\n"
"                QTabBar::tab:hover{\n"
"                color: blue; font-size: 15px; /* background-color: blue; */\n"
"                }\n"
"                QTabBar::tab { min-width: 120px; min-height: 30px; }\n"
"                QTabBar::ta"
                        "b:!selected {}\n"
"                QTabBar::tab:selected {color: blue; font: 15px bold;}"));
        verticalLayout = new QVBoxLayout(TMTxt2UI);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(7, 7, 7, 7);
        tabWidget = new QTabWidget(TMTxt2UI);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setTabShape(QTabWidget::Triangular);
        tabWidget->setElideMode(Qt::ElideNone);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(7, 7, 7, 7);
        tableWgt = new QTableView(tab);
        tableWgt->setObjectName(QStringLiteral("tableWgt"));
        tableWgt->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWgt->setAlternatingRowColors(true);
        tableWgt->setSelectionMode(QAbstractItemView::ExtendedSelection);
        tableWgt->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWgt->setCornerButtonEnabled(false);
        tableWgt->horizontalHeader()->setDefaultSectionSize(115);
        tableWgt->horizontalHeader()->setHighlightSections(false);
        tableWgt->horizontalHeader()->setStretchLastSection(true);
        tableWgt->verticalHeader()->setDefaultSectionSize(26);
        tableWgt->verticalHeader()->setHighlightSections(false);

        verticalLayout_2->addWidget(tableWgt);

        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        verticalLayout_4 = new QVBoxLayout(tab_3);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(7, 7, 7, 7);
        tableWgt3 = new QTableView(tab_3);
        tableWgt3->setObjectName(QStringLiteral("tableWgt3"));
        tableWgt3->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWgt3->setAlternatingRowColors(true);
        tableWgt3->setSelectionMode(QAbstractItemView::ExtendedSelection);
        tableWgt3->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWgt3->horizontalHeader()->setDefaultSectionSize(115);
        tableWgt3->horizontalHeader()->setHighlightSections(false);
        tableWgt3->horizontalHeader()->setStretchLastSection(true);
        tableWgt3->verticalHeader()->setDefaultSectionSize(26);
        tableWgt3->verticalHeader()->setHighlightSections(false);

        verticalLayout_4->addWidget(tableWgt3);

        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(7, 7, 7, 7);
        tableWgt2 = new QTableView(tab_2);
        tableWgt2->setObjectName(QStringLiteral("tableWgt2"));
        tableWgt2->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWgt2->setAlternatingRowColors(true);
        tableWgt2->setSelectionMode(QAbstractItemView::ExtendedSelection);
        tableWgt2->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWgt2->horizontalHeader()->setDefaultSectionSize(115);
        tableWgt2->horizontalHeader()->setHighlightSections(false);
        tableWgt2->horizontalHeader()->setStretchLastSection(true);
        tableWgt2->verticalHeader()->setDefaultSectionSize(26);
        tableWgt2->verticalHeader()->setHighlightSections(false);

        verticalLayout_3->addWidget(tableWgt2);

        tabWidget->addTab(tab_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        verticalLayout_5 = new QVBoxLayout(tab_4);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(7, 7, 7, 7);
        tableWgt4 = new QTableView(tab_4);
        tableWgt4->setObjectName(QStringLiteral("tableWgt4"));
        tableWgt4->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWgt4->setAlternatingRowColors(true);
        tableWgt4->setSelectionMode(QAbstractItemView::ExtendedSelection);
        tableWgt4->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWgt4->horizontalHeader()->setDefaultSectionSize(115);
        tableWgt4->horizontalHeader()->setHighlightSections(false);
        tableWgt4->horizontalHeader()->setStretchLastSection(true);
        tableWgt4->verticalHeader()->setDefaultSectionSize(26);
        tableWgt4->verticalHeader()->setHighlightSections(false);

        verticalLayout_5->addWidget(tableWgt4);

        tabWidget->addTab(tab_4, QString());

        verticalLayout->addWidget(tabWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(TMTxt2UI);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(TMTxt2UI);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);
        lineEdit->setMinimumSize(QSize(200, 25));
        lineEdit->setStyleSheet(QStringLiteral("color: rgb(255, 112, 46);"));

        horizontalLayout->addWidget(lineEdit);

        tbtnSetPath = new QPushButton(TMTxt2UI);
        tbtnSetPath->setObjectName(QStringLiteral("tbtnSetPath"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tbtnSetPath->sizePolicy().hasHeightForWidth());
        tbtnSetPath->setSizePolicy(sizePolicy1);
        tbtnSetPath->setMinimumSize(QSize(50, 30));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        tbtnSetPath->setFont(font);
        tbtnSetPath->setStyleSheet(QStringLiteral("color: rgb(44, 171, 22);"));

        horizontalLayout->addWidget(tbtnSetPath);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        checkBox = new QCheckBox(TMTxt2UI);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(checkBox->sizePolicy().hasHeightForWidth());
        checkBox->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(checkBox);

        comboBox = new QComboBox(TMTxt2UI);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout->addWidget(comboBox);

        horizontalSpacer_2 = new QSpacerItem(25, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btnSelect = new QPushButton(TMTxt2UI);
        btnSelect->setObjectName(QStringLiteral("btnSelect"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(btnSelect->sizePolicy().hasHeightForWidth());
        btnSelect->setSizePolicy(sizePolicy3);
        btnSelect->setMinimumSize(QSize(70, 35));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        btnSelect->setFont(font1);
        btnSelect->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(btnSelect);

        horizontalSpacer_4 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        btnDoIt = new QPushButton(TMTxt2UI);
        btnDoIt->setObjectName(QStringLiteral("btnDoIt"));
        sizePolicy3.setHeightForWidth(btnDoIt->sizePolicy().hasHeightForWidth());
        btnDoIt->setSizePolicy(sizePolicy3);
        btnDoIt->setMinimumSize(QSize(80, 35));
        btnDoIt->setFont(font1);
        btnDoIt->setStyleSheet(QStringLiteral("color: rgb(85, 170, 0);"));

        horizontalLayout->addWidget(btnDoIt);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(TMTxt2UI);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(TMTxt2UI);
    } // setupUi

    void retranslateUi(QDialog *TMTxt2UI)
    {
        TMTxt2UI->setWindowTitle(QApplication::translate("TMTxt2UI", "\346\226\207\344\273\266\350\275\254\346\215\242\345\231\250\357\274\210txt\344\270\216ui\346\226\207\344\273\266\344\272\222\350\275\254 ver190319\357\274\211", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("TMTxt2UI", "TXT\346\226\207\344\273\266(form)", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("TMTxt2UI", "TXT\346\226\207\344\273\266(toolbar)", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("TMTxt2UI", "UI\346\226\207\344\273\266(form)", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("TMTxt2UI", "UI\346\226\207\344\273\266(toolbar)", Q_NULLPTR));
        label->setText(QApplication::translate("TMTxt2UI", "\351\241\271\347\233\256\357\274\232", Q_NULLPTR));
        lineEdit->setText(QApplication::translate("TMTxt2UI", "/UI/Form/form", Q_NULLPTR));
        tbtnSetPath->setText(QApplication::translate("TMTxt2UI", "...", Q_NULLPTR));
        checkBox->setText(QString());
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("TMTxt2UI", "\345\205\250\351\200\211", Q_NULLPTR)
         << QApplication::translate("TMTxt2UI", "\351\200\211\346\213\251\345\275\223\345\211\215\351\241\265", Q_NULLPTR)
        );
        btnSelect->setText(QApplication::translate("TMTxt2UI", "\345\210\267\346\226\260", Q_NULLPTR));
        btnDoIt->setText(QApplication::translate("TMTxt2UI", "\345\274\200\345\247\213\350\275\254\346\215\242", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TMTxt2UI: public Ui_TMTxt2UI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TMTXT2UI_H
