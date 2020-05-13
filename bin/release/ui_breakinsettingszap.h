/********************************************************************************
** Form generated from reading UI file 'breakinsettingszap.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BREAKINSETTINGSZAP_H
#define UI_BREAKINSETTINGSZAP_H

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

class Ui_BreakInSettingsZap
{
public:
    QPushButton *pushButtonOk;
    QPushButton *pushButtonCancel;
    QGroupBox *groupBox;
    QTableWidget *tableWidgetBreakIn;
    QPushButton *pushButtonAddRowBreakIn;
    QPushButton *pushButtonDeleteRowBreakIn;

    void setupUi(QWidget *BreakInSettingsZap)
    {
        if (BreakInSettingsZap->objectName().isEmpty())
            BreakInSettingsZap->setObjectName(QStringLiteral("BreakInSettingsZap"));
        BreakInSettingsZap->resize(586, 480);
        pushButtonOk = new QPushButton(BreakInSettingsZap);
        pushButtonOk->setObjectName(QStringLiteral("pushButtonOk"));
        pushButtonOk->setGeometry(QRect(390, 430, 75, 23));
        pushButtonCancel = new QPushButton(BreakInSettingsZap);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        pushButtonCancel->setGeometry(QRect(480, 430, 75, 23));
        groupBox = new QGroupBox(BreakInSettingsZap);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 541, 411));
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
        if (tableWidgetBreakIn->rowCount() < 8)
            tableWidgetBreakIn->setRowCount(8);
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
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        __qtablewidgetitem18->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidgetBreakIn->setItem(5, 0, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        __qtablewidgetitem19->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidgetBreakIn->setItem(5, 1, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        __qtablewidgetitem20->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidgetBreakIn->setItem(5, 2, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        __qtablewidgetitem21->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidgetBreakIn->setItem(6, 0, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        __qtablewidgetitem22->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidgetBreakIn->setItem(6, 1, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        __qtablewidgetitem23->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidgetBreakIn->setItem(6, 2, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        __qtablewidgetitem24->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidgetBreakIn->setItem(7, 0, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        __qtablewidgetitem25->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidgetBreakIn->setItem(7, 1, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        __qtablewidgetitem26->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidgetBreakIn->setItem(7, 2, __qtablewidgetitem26);
        tableWidgetBreakIn->setObjectName(QStringLiteral("tableWidgetBreakIn"));
        tableWidgetBreakIn->setGeometry(QRect(30, 20, 411, 331));
        tableWidgetBreakIn->setFont(font);
        tableWidgetBreakIn->setInputMethodHints(Qt::ImhDigitsOnly);
        tableWidgetBreakIn->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidgetBreakIn->setWordWrap(false);
        tableWidgetBreakIn->setRowCount(8);
        tableWidgetBreakIn->setColumnCount(3);
        tableWidgetBreakIn->horizontalHeader()->setVisible(false);
        tableWidgetBreakIn->verticalHeader()->setVisible(false);
        pushButtonAddRowBreakIn = new QPushButton(groupBox);
        pushButtonAddRowBreakIn->setObjectName(QStringLiteral("pushButtonAddRowBreakIn"));
        pushButtonAddRowBreakIn->setGeometry(QRect(40, 370, 75, 23));
        pushButtonDeleteRowBreakIn = new QPushButton(groupBox);
        pushButtonDeleteRowBreakIn->setObjectName(QStringLiteral("pushButtonDeleteRowBreakIn"));
        pushButtonDeleteRowBreakIn->setGeometry(QRect(130, 370, 75, 23));

        retranslateUi(BreakInSettingsZap);

        QMetaObject::connectSlotsByName(BreakInSettingsZap);
    } // setupUi

    void retranslateUi(QWidget *BreakInSettingsZap)
    {
        BreakInSettingsZap->setWindowTitle(QApplication::translate("BreakInSettingsZap", "Form", 0));
        pushButtonOk->setText(QApplication::translate("BreakInSettingsZap", "Ok", 0));
        pushButtonCancel->setText(QApplication::translate("BreakInSettingsZap", "Cancel", 0));
        groupBox->setTitle(QApplication::translate("BreakInSettingsZap", "Break In Settings", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetBreakIn->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("BreakInSettingsZap", "Attempt #", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetBreakIn->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("BreakInSettingsZap", "Zap Duration (\302\265s)", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetBreakIn->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("BreakInSettingsZap", "Number of Pulses", 0));

        const bool __sortingEnabled = tableWidgetBreakIn->isSortingEnabled();
        tableWidgetBreakIn->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetBreakIn->item(0, 0);
        ___qtablewidgetitem3->setText(QApplication::translate("BreakInSettingsZap", "1", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetBreakIn->item(0, 1);
        ___qtablewidgetitem4->setText(QApplication::translate("BreakInSettingsZap", "25", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidgetBreakIn->item(0, 2);
        ___qtablewidgetitem5->setText(QApplication::translate("BreakInSettingsZap", "1", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidgetBreakIn->item(1, 0);
        ___qtablewidgetitem6->setText(QApplication::translate("BreakInSettingsZap", "2", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidgetBreakIn->item(1, 1);
        ___qtablewidgetitem7->setText(QApplication::translate("BreakInSettingsZap", "50", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidgetBreakIn->item(1, 2);
        ___qtablewidgetitem8->setText(QApplication::translate("BreakInSettingsZap", "1", 0));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidgetBreakIn->item(2, 0);
        ___qtablewidgetitem9->setText(QApplication::translate("BreakInSettingsZap", "3", 0));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidgetBreakIn->item(2, 1);
        ___qtablewidgetitem10->setText(QApplication::translate("BreakInSettingsZap", "100", 0));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidgetBreakIn->item(2, 2);
        ___qtablewidgetitem11->setText(QApplication::translate("BreakInSettingsZap", "1", 0));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidgetBreakIn->item(3, 0);
        ___qtablewidgetitem12->setText(QApplication::translate("BreakInSettingsZap", "4", 0));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidgetBreakIn->item(3, 1);
        ___qtablewidgetitem13->setText(QApplication::translate("BreakInSettingsZap", "200", 0));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidgetBreakIn->item(3, 2);
        ___qtablewidgetitem14->setText(QApplication::translate("BreakInSettingsZap", "1", 0));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidgetBreakIn->item(4, 0);
        ___qtablewidgetitem15->setText(QApplication::translate("BreakInSettingsZap", "5", 0));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidgetBreakIn->item(4, 1);
        ___qtablewidgetitem16->setText(QApplication::translate("BreakInSettingsZap", "500", 0));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidgetBreakIn->item(4, 2);
        ___qtablewidgetitem17->setText(QApplication::translate("BreakInSettingsZap", "1", 0));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidgetBreakIn->item(5, 0);
        ___qtablewidgetitem18->setText(QApplication::translate("BreakInSettingsZap", "6", 0));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidgetBreakIn->item(5, 1);
        ___qtablewidgetitem19->setText(QApplication::translate("BreakInSettingsZap", "1000", 0));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidgetBreakIn->item(5, 2);
        ___qtablewidgetitem20->setText(QApplication::translate("BreakInSettingsZap", "1", 0));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidgetBreakIn->item(6, 0);
        ___qtablewidgetitem21->setText(QApplication::translate("BreakInSettingsZap", "7", 0));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidgetBreakIn->item(6, 1);
        ___qtablewidgetitem22->setText(QApplication::translate("BreakInSettingsZap", "1000", 0));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidgetBreakIn->item(6, 2);
        ___qtablewidgetitem23->setText(QApplication::translate("BreakInSettingsZap", "3", 0));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidgetBreakIn->item(7, 0);
        ___qtablewidgetitem24->setText(QApplication::translate("BreakInSettingsZap", "8", 0));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidgetBreakIn->item(7, 1);
        ___qtablewidgetitem25->setText(QApplication::translate("BreakInSettingsZap", "5000", 0));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidgetBreakIn->item(7, 2);
        ___qtablewidgetitem26->setText(QApplication::translate("BreakInSettingsZap", "3", 0));
        tableWidgetBreakIn->setSortingEnabled(__sortingEnabled);

        pushButtonAddRowBreakIn->setText(QApplication::translate("BreakInSettingsZap", "Add Row", 0));
        pushButtonDeleteRowBreakIn->setText(QApplication::translate("BreakInSettingsZap", "Delete Row", 0));
    } // retranslateUi

};

namespace Ui {
    class BreakInSettingsZap: public Ui_BreakInSettingsZap {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BREAKINSETTINGSZAP_H
