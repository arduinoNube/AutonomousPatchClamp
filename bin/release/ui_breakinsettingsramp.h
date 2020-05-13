/********************************************************************************
** Form generated from reading UI file 'breakinsettingsramp.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BREAKINSETTINGSRAMP_H
#define UI_BREAKINSETTINGSRAMP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BreakInSettingsRamp
{
public:
    QGroupBox *groupBox;
    QTableWidget *tableWidgetBreakIn;
    QPushButton *pushButtonAddRowBreakIn;
    QPushButton *pushButtonDeleteRowBreakIn;
    QPushButton *pushButtonOk;
    QPushButton *pushButtonCancel;

    void setupUi(QWidget *BreakInSettingsRamp)
    {
        if (BreakInSettingsRamp->objectName().isEmpty())
            BreakInSettingsRamp->setObjectName(QStringLiteral("BreakInSettingsRamp"));
        BreakInSettingsRamp->resize(520, 477);
        groupBox = new QGroupBox(BreakInSettingsRamp);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 461, 411));
        tableWidgetBreakIn = new QTableWidget(groupBox);
        if (tableWidgetBreakIn->columnCount() < 3)
            tableWidgetBreakIn->setColumnCount(3);
        QFont font;
        font.setPointSize(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem->setFont(font);
        tableWidgetBreakIn->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetBreakIn->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetBreakIn->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (tableWidgetBreakIn->rowCount() < 5)
            tableWidgetBreakIn->setRowCount(5);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidgetBreakIn->setItem(0, 0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidgetBreakIn->setItem(0, 1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidgetBreakIn->setItem(0, 2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidgetBreakIn->setItem(1, 0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidgetBreakIn->setItem(1, 1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidgetBreakIn->setItem(1, 2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidgetBreakIn->setItem(2, 0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidgetBreakIn->setItem(2, 1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidgetBreakIn->setItem(2, 2, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidgetBreakIn->setItem(3, 0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidgetBreakIn->setItem(3, 1, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidgetBreakIn->setItem(3, 2, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidgetBreakIn->setItem(4, 0, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidgetBreakIn->setItem(4, 1, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        __qtablewidgetitem17->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidgetBreakIn->setItem(4, 2, __qtablewidgetitem17);
        tableWidgetBreakIn->setObjectName(QStringLiteral("tableWidgetBreakIn"));
        tableWidgetBreakIn->setGeometry(QRect(30, 20, 411, 331));
        tableWidgetBreakIn->setFont(font);
        tableWidgetBreakIn->setInputMethodHints(Qt::ImhDigitsOnly);
        tableWidgetBreakIn->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidgetBreakIn->setWordWrap(false);
        tableWidgetBreakIn->setRowCount(5);
        tableWidgetBreakIn->setColumnCount(3);
        tableWidgetBreakIn->horizontalHeader()->setVisible(false);
        tableWidgetBreakIn->verticalHeader()->setVisible(false);
        pushButtonAddRowBreakIn = new QPushButton(groupBox);
        pushButtonAddRowBreakIn->setObjectName(QStringLiteral("pushButtonAddRowBreakIn"));
        pushButtonAddRowBreakIn->setGeometry(QRect(40, 370, 75, 23));
        pushButtonDeleteRowBreakIn = new QPushButton(groupBox);
        pushButtonDeleteRowBreakIn->setObjectName(QStringLiteral("pushButtonDeleteRowBreakIn"));
        pushButtonDeleteRowBreakIn->setGeometry(QRect(130, 370, 75, 23));
        pushButtonOk = new QPushButton(BreakInSettingsRamp);
        pushButtonOk->setObjectName(QStringLiteral("pushButtonOk"));
        pushButtonOk->setGeometry(QRect(310, 430, 75, 23));
        pushButtonCancel = new QPushButton(BreakInSettingsRamp);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        pushButtonCancel->setGeometry(QRect(400, 430, 75, 23));

        retranslateUi(BreakInSettingsRamp);

        QMetaObject::connectSlotsByName(BreakInSettingsRamp);
    } // setupUi

    void retranslateUi(QWidget *BreakInSettingsRamp)
    {
        BreakInSettingsRamp->setWindowTitle(QApplication::translate("BreakInSettingsRamp", "Form", 0));
        groupBox->setTitle(QApplication::translate("BreakInSettingsRamp", "Break In Settings", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetBreakIn->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("BreakInSettingsRamp", "Attempt #", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetBreakIn->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("BreakInSettingsRamp", "Max Pressure (mbar)", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetBreakIn->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("BreakInSettingsRamp", "Ramp Duration (ms)", 0));

        const bool __sortingEnabled = tableWidgetBreakIn->isSortingEnabled();
        tableWidgetBreakIn->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetBreakIn->item(0, 0);
        ___qtablewidgetitem3->setText(QApplication::translate("BreakInSettingsRamp", "1", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetBreakIn->item(0, 1);
        ___qtablewidgetitem4->setText(QApplication::translate("BreakInSettingsRamp", "150", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidgetBreakIn->item(0, 2);
        ___qtablewidgetitem5->setText(QApplication::translate("BreakInSettingsRamp", "2000", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidgetBreakIn->item(1, 0);
        ___qtablewidgetitem6->setText(QApplication::translate("BreakInSettingsRamp", "2", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidgetBreakIn->item(1, 1);
        ___qtablewidgetitem7->setText(QApplication::translate("BreakInSettingsRamp", "200", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidgetBreakIn->item(1, 2);
        ___qtablewidgetitem8->setText(QApplication::translate("BreakInSettingsRamp", "2500", 0));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidgetBreakIn->item(2, 0);
        ___qtablewidgetitem9->setText(QApplication::translate("BreakInSettingsRamp", "3", 0));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidgetBreakIn->item(2, 1);
        ___qtablewidgetitem10->setText(QApplication::translate("BreakInSettingsRamp", "250", 0));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidgetBreakIn->item(2, 2);
        ___qtablewidgetitem11->setText(QApplication::translate("BreakInSettingsRamp", "2500", 0));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidgetBreakIn->item(3, 0);
        ___qtablewidgetitem12->setText(QApplication::translate("BreakInSettingsRamp", "4", 0));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidgetBreakIn->item(3, 1);
        ___qtablewidgetitem13->setText(QApplication::translate("BreakInSettingsRamp", "300", 0));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidgetBreakIn->item(3, 2);
        ___qtablewidgetitem14->setText(QApplication::translate("BreakInSettingsRamp", "2500", 0));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidgetBreakIn->item(4, 0);
        ___qtablewidgetitem15->setText(QApplication::translate("BreakInSettingsRamp", "5", 0));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidgetBreakIn->item(4, 1);
        ___qtablewidgetitem16->setText(QApplication::translate("BreakInSettingsRamp", "345", 0));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidgetBreakIn->item(4, 2);
        ___qtablewidgetitem17->setText(QApplication::translate("BreakInSettingsRamp", "2500", 0));
        tableWidgetBreakIn->setSortingEnabled(__sortingEnabled);

        pushButtonAddRowBreakIn->setText(QApplication::translate("BreakInSettingsRamp", "Add Row", 0));
        pushButtonDeleteRowBreakIn->setText(QApplication::translate("BreakInSettingsRamp", "Delete Row", 0));
        pushButtonOk->setText(QApplication::translate("BreakInSettingsRamp", "Ok", 0));
        pushButtonCancel->setText(QApplication::translate("BreakInSettingsRamp", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class BreakInSettingsRamp: public Ui_BreakInSettingsRamp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BREAKINSETTINGSRAMP_H
