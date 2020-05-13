/********************************************************************************
** Form generated from reading UI file 'breakinsettingssuction.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BREAKINSETTINGSSUCTION_H
#define UI_BREAKINSETTINGSSUCTION_H

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

class Ui_BreakInSettingsSuction
{
public:
    QGroupBox *groupBox;
    QTableWidget *tableWidgetBreakIn;
    QPushButton *pushButtonAddRowBreakIn;
    QPushButton *pushButtonDeleteRowBreakIn;
    QPushButton *pushButtonOk;
    QPushButton *pushButtonCancel;

    void setupUi(QWidget *BreakInSettingsSuction)
    {
        if (BreakInSettingsSuction->objectName().isEmpty())
            BreakInSettingsSuction->setObjectName(QStringLiteral("BreakInSettingsSuction"));
        BreakInSettingsSuction->resize(507, 491);
        groupBox = new QGroupBox(BreakInSettingsSuction);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 461, 411));
        tableWidgetBreakIn = new QTableWidget(groupBox);
        if (tableWidgetBreakIn->columnCount() < 4)
            tableWidgetBreakIn->setColumnCount(4);
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
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetBreakIn->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (tableWidgetBreakIn->rowCount() < 5)
            tableWidgetBreakIn->setRowCount(5);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidgetBreakIn->setItem(0, 0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidgetBreakIn->setItem(0, 1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidgetBreakIn->setItem(0, 2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidgetBreakIn->setItem(0, 3, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidgetBreakIn->setItem(1, 0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidgetBreakIn->setItem(1, 1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidgetBreakIn->setItem(1, 2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidgetBreakIn->setItem(1, 3, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidgetBreakIn->setItem(2, 0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidgetBreakIn->setItem(2, 1, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidgetBreakIn->setItem(2, 2, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidgetBreakIn->setItem(2, 3, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidgetBreakIn->setItem(3, 0, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        __qtablewidgetitem17->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidgetBreakIn->setItem(3, 1, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        __qtablewidgetitem18->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidgetBreakIn->setItem(3, 2, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        __qtablewidgetitem19->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidgetBreakIn->setItem(3, 3, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        __qtablewidgetitem20->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidgetBreakIn->setItem(4, 0, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        __qtablewidgetitem21->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidgetBreakIn->setItem(4, 1, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        __qtablewidgetitem22->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidgetBreakIn->setItem(4, 2, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        __qtablewidgetitem23->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidgetBreakIn->setItem(4, 3, __qtablewidgetitem23);
        tableWidgetBreakIn->setObjectName(QStringLiteral("tableWidgetBreakIn"));
        tableWidgetBreakIn->setGeometry(QRect(30, 20, 411, 331));
        tableWidgetBreakIn->setFont(font);
        tableWidgetBreakIn->setInputMethodHints(Qt::ImhDigitsOnly);
        tableWidgetBreakIn->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidgetBreakIn->setWordWrap(false);
        tableWidgetBreakIn->setRowCount(5);
        tableWidgetBreakIn->setColumnCount(4);
        tableWidgetBreakIn->horizontalHeader()->setVisible(false);
        tableWidgetBreakIn->verticalHeader()->setVisible(false);
        pushButtonAddRowBreakIn = new QPushButton(groupBox);
        pushButtonAddRowBreakIn->setObjectName(QStringLiteral("pushButtonAddRowBreakIn"));
        pushButtonAddRowBreakIn->setGeometry(QRect(40, 370, 75, 23));
        pushButtonDeleteRowBreakIn = new QPushButton(groupBox);
        pushButtonDeleteRowBreakIn->setObjectName(QStringLiteral("pushButtonDeleteRowBreakIn"));
        pushButtonDeleteRowBreakIn->setGeometry(QRect(130, 370, 75, 23));
        pushButtonOk = new QPushButton(BreakInSettingsSuction);
        pushButtonOk->setObjectName(QStringLiteral("pushButtonOk"));
        pushButtonOk->setGeometry(QRect(310, 440, 75, 23));
        pushButtonCancel = new QPushButton(BreakInSettingsSuction);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        pushButtonCancel->setGeometry(QRect(400, 440, 75, 23));

        retranslateUi(BreakInSettingsSuction);

        QMetaObject::connectSlotsByName(BreakInSettingsSuction);
    } // setupUi

    void retranslateUi(QWidget *BreakInSettingsSuction)
    {
        BreakInSettingsSuction->setWindowTitle(QApplication::translate("BreakInSettingsSuction", "Form", 0));
        groupBox->setTitle(QApplication::translate("BreakInSettingsSuction", "Break In Settings", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetBreakIn->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("BreakInSettingsSuction", "Attempt #", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetBreakIn->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("BreakInSettingsSuction", "Pressure (mbar)", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetBreakIn->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("BreakInSettingsSuction", "Duration (ms)", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetBreakIn->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("BreakInSettingsSuction", "Number of Pulses", 0));

        const bool __sortingEnabled = tableWidgetBreakIn->isSortingEnabled();
        tableWidgetBreakIn->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetBreakIn->item(0, 0);
        ___qtablewidgetitem4->setText(QApplication::translate("BreakInSettingsSuction", "1", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidgetBreakIn->item(0, 1);
        ___qtablewidgetitem5->setText(QApplication::translate("BreakInSettingsSuction", "150", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidgetBreakIn->item(0, 2);
        ___qtablewidgetitem6->setText(QApplication::translate("BreakInSettingsSuction", "150", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidgetBreakIn->item(0, 3);
        ___qtablewidgetitem7->setText(QApplication::translate("BreakInSettingsSuction", "1", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidgetBreakIn->item(1, 0);
        ___qtablewidgetitem8->setText(QApplication::translate("BreakInSettingsSuction", "2", 0));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidgetBreakIn->item(1, 1);
        ___qtablewidgetitem9->setText(QApplication::translate("BreakInSettingsSuction", "200", 0));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidgetBreakIn->item(1, 2);
        ___qtablewidgetitem10->setText(QApplication::translate("BreakInSettingsSuction", "250", 0));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidgetBreakIn->item(1, 3);
        ___qtablewidgetitem11->setText(QApplication::translate("BreakInSettingsSuction", "1", 0));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidgetBreakIn->item(2, 0);
        ___qtablewidgetitem12->setText(QApplication::translate("BreakInSettingsSuction", "3", 0));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidgetBreakIn->item(2, 1);
        ___qtablewidgetitem13->setText(QApplication::translate("BreakInSettingsSuction", "250", 0));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidgetBreakIn->item(2, 2);
        ___qtablewidgetitem14->setText(QApplication::translate("BreakInSettingsSuction", "300", 0));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidgetBreakIn->item(2, 3);
        ___qtablewidgetitem15->setText(QApplication::translate("BreakInSettingsSuction", "1", 0));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidgetBreakIn->item(3, 0);
        ___qtablewidgetitem16->setText(QApplication::translate("BreakInSettingsSuction", "4", 0));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidgetBreakIn->item(3, 1);
        ___qtablewidgetitem17->setText(QApplication::translate("BreakInSettingsSuction", "300", 0));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidgetBreakIn->item(3, 2);
        ___qtablewidgetitem18->setText(QApplication::translate("BreakInSettingsSuction", "450", 0));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidgetBreakIn->item(3, 3);
        ___qtablewidgetitem19->setText(QApplication::translate("BreakInSettingsSuction", "1", 0));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidgetBreakIn->item(4, 0);
        ___qtablewidgetitem20->setText(QApplication::translate("BreakInSettingsSuction", "5", 0));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidgetBreakIn->item(4, 1);
        ___qtablewidgetitem21->setText(QApplication::translate("BreakInSettingsSuction", "345", 0));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidgetBreakIn->item(4, 2);
        ___qtablewidgetitem22->setText(QApplication::translate("BreakInSettingsSuction", "500", 0));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidgetBreakIn->item(4, 3);
        ___qtablewidgetitem23->setText(QApplication::translate("BreakInSettingsSuction", "1", 0));
        tableWidgetBreakIn->setSortingEnabled(__sortingEnabled);

        pushButtonAddRowBreakIn->setText(QApplication::translate("BreakInSettingsSuction", "Add Row", 0));
        pushButtonDeleteRowBreakIn->setText(QApplication::translate("BreakInSettingsSuction", "Delete Row", 0));
        pushButtonOk->setText(QApplication::translate("BreakInSettingsSuction", "Ok", 0));
        pushButtonCancel->setText(QApplication::translate("BreakInSettingsSuction", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class BreakInSettingsSuction: public Ui_BreakInSettingsSuction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BREAKINSETTINGSSUCTION_H
