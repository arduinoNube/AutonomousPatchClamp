/********************************************************************************
** Form generated from reading UI file 'hardwaresettingswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HARDWARESETTINGSWINDOW_H
#define UI_HARDWARESETTINGSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HardwareSettingsWindow
{
public:
    QPushButton *pushButtonOk;
    QPushButton *pushButtonCancel;
    QGroupBox *groupBox;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_6;
    QLabel *label;
    QLineEdit *lineEditMulticlampHeadstageNum;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEditHeadstageCOM;
    QLabel *label_9;
    QLineEdit *lineEditDAQDevName;
    QLineEdit *lineEditMulticlampPath;
    QLineEdit *lineEditFillerCOM;
    QLabel *label_8;
    QLineEdit *lineEditAutopatcherCOM;
    QLabel *label_2;
    QLineEdit *lineEditSCARACOM;
    QLineEdit *lineEditThorSerial;
    QLabel *label_3;
    QLineEdit *lineEditThorFastVel;
    QLineEdit *lineEditThorSlowVel;
    QLabel *label_10;
    QLabel *label_11;

    void setupUi(QWidget *HardwareSettingsWindow)
    {
        if (HardwareSettingsWindow->objectName().isEmpty())
            HardwareSettingsWindow->setObjectName(QStringLiteral("HardwareSettingsWindow"));
        HardwareSettingsWindow->resize(515, 537);
        pushButtonOk = new QPushButton(HardwareSettingsWindow);
        pushButtonOk->setObjectName(QStringLiteral("pushButtonOk"));
        pushButtonOk->setGeometry(QRect(330, 500, 75, 23));
        pushButtonCancel = new QPushButton(HardwareSettingsWindow);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        pushButtonCancel->setGeometry(QRect(420, 500, 75, 23));
        groupBox = new QGroupBox(HardwareSettingsWindow);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 491, 481));
        gridLayoutWidget = new QWidget(groupBox);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 30, 471, 361));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 5, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        lineEditMulticlampHeadstageNum = new QLineEdit(gridLayoutWidget);
        lineEditMulticlampHeadstageNum->setObjectName(QStringLiteral("lineEditMulticlampHeadstageNum"));

        gridLayout->addWidget(lineEditMulticlampHeadstageNum, 4, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 1, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 4, 1, 1, 1);

        lineEditHeadstageCOM = new QLineEdit(gridLayoutWidget);
        lineEditHeadstageCOM->setObjectName(QStringLiteral("lineEditHeadstageCOM"));

        gridLayout->addWidget(lineEditHeadstageCOM, 3, 0, 1, 1);

        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 7, 1, 1, 1);

        lineEditDAQDevName = new QLineEdit(gridLayoutWidget);
        lineEditDAQDevName->setObjectName(QStringLiteral("lineEditDAQDevName"));

        gridLayout->addWidget(lineEditDAQDevName, 6, 0, 1, 1);

        lineEditMulticlampPath = new QLineEdit(gridLayoutWidget);
        lineEditMulticlampPath->setObjectName(QStringLiteral("lineEditMulticlampPath"));

        gridLayout->addWidget(lineEditMulticlampPath, 5, 0, 1, 1);

        lineEditFillerCOM = new QLineEdit(gridLayoutWidget);
        lineEditFillerCOM->setObjectName(QStringLiteral("lineEditFillerCOM"));

        gridLayout->addWidget(lineEditFillerCOM, 2, 0, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 6, 1, 1, 1);

        lineEditAutopatcherCOM = new QLineEdit(gridLayoutWidget);
        lineEditAutopatcherCOM->setObjectName(QStringLiteral("lineEditAutopatcherCOM"));

        gridLayout->addWidget(lineEditAutopatcherCOM, 0, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        lineEditSCARACOM = new QLineEdit(gridLayoutWidget);
        lineEditSCARACOM->setObjectName(QStringLiteral("lineEditSCARACOM"));

        gridLayout->addWidget(lineEditSCARACOM, 1, 0, 1, 1);

        lineEditThorSerial = new QLineEdit(gridLayoutWidget);
        lineEditThorSerial->setObjectName(QStringLiteral("lineEditThorSerial"));

        gridLayout->addWidget(lineEditThorSerial, 7, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 1, 1, 1);

        lineEditThorFastVel = new QLineEdit(gridLayoutWidget);
        lineEditThorFastVel->setObjectName(QStringLiteral("lineEditThorFastVel"));

        gridLayout->addWidget(lineEditThorFastVel, 9, 0, 1, 1);

        lineEditThorSlowVel = new QLineEdit(gridLayoutWidget);
        lineEditThorSlowVel->setObjectName(QStringLiteral("lineEditThorSlowVel"));

        gridLayout->addWidget(lineEditThorSlowVel, 8, 0, 1, 1);

        label_10 = new QLabel(gridLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout->addWidget(label_10, 8, 1, 1, 1);

        label_11 = new QLabel(gridLayoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout->addWidget(label_11, 9, 1, 1, 1);


        retranslateUi(HardwareSettingsWindow);

        QMetaObject::connectSlotsByName(HardwareSettingsWindow);
    } // setupUi

    void retranslateUi(QWidget *HardwareSettingsWindow)
    {
        HardwareSettingsWindow->setWindowTitle(QApplication::translate("HardwareSettingsWindow", "Form", 0));
        pushButtonOk->setText(QApplication::translate("HardwareSettingsWindow", "Ok", 0));
        pushButtonCancel->setText(QApplication::translate("HardwareSettingsWindow", "Cancel", 0));
        groupBox->setTitle(QApplication::translate("HardwareSettingsWindow", "Hardware Settings", 0));
        label_6->setText(QApplication::translate("HardwareSettingsWindow", "Path to MC700B.exe (Multiclamp commander executable)", 0));
        label->setText(QApplication::translate("HardwareSettingsWindow", "Autopatcher control box serial COM port name. \n"
"(Look under Control Panel -> Hardware -> Device Manager -> Ports)  ", 0));
        lineEditMulticlampHeadstageNum->setText(QApplication::translate("HardwareSettingsWindow", "2", 0));
        label_4->setText(QApplication::translate("HardwareSettingsWindow", "Headstage Clamp serial COM port name. ", 0));
        label_5->setText(QApplication::translate("HardwareSettingsWindow", "Multiclamp Amplifier headstage number", 0));
        lineEditHeadstageCOM->setText(QApplication::translate("HardwareSettingsWindow", "COM25", 0));
        label_9->setText(QApplication::translate("HardwareSettingsWindow", "ThorLabs motor serial number (i.e. 83840919)", 0));
        lineEditDAQDevName->setText(QApplication::translate("HardwareSettingsWindow", "Dev6", 0));
        lineEditMulticlampPath->setText(QApplication::translate("HardwareSettingsWindow", "C:\\Axon\\MultiClamp 700B Commander\\MC700B.exe", 0));
        lineEditFillerCOM->setText(QApplication::translate("HardwareSettingsWindow", "COM26", 0));
        label_8->setText(QApplication::translate("HardwareSettingsWindow", "DAQ Device Name (i.e. \"Dev1\")", 0));
        lineEditAutopatcherCOM->setText(QApplication::translate("HardwareSettingsWindow", "COM17", 0));
        label_2->setText(QApplication::translate("HardwareSettingsWindow", "SCARA Robot serial COM port name. ", 0));
        lineEditSCARACOM->setText(QApplication::translate("HardwareSettingsWindow", "COM27", 0));
        lineEditThorSerial->setText(QApplication::translate("HardwareSettingsWindow", "83840919", 0));
        label_3->setText(QApplication::translate("HardwareSettingsWindow", "Filler Robot serial COM port name. ", 0));
        lineEditThorFastVel->setText(QApplication::translate("HardwareSettingsWindow", "2", 0));
        lineEditThorSlowVel->setText(QApplication::translate("HardwareSettingsWindow", "2", 0));
        label_10->setText(QApplication::translate("HardwareSettingsWindow", "ThorLabs motor hunting velocity (2) um/s", 0));
        label_11->setText(QApplication::translate("HardwareSettingsWindow", "ThorLabs motor rapid descent velocity (2) mm/s", 0));
    } // retranslateUi

};

namespace Ui {
    class HardwareSettingsWindow: public Ui_HardwareSettingsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HARDWARESETTINGSWINDOW_H
