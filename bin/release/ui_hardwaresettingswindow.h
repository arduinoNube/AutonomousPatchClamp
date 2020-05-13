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
    QLineEdit *lineEditAutopatcherCOM;
    QLabel *label_5;
    QLineEdit *lineEditHeadstageCOM;
    QLineEdit *lineEditMulticlampHeadstageNum;
    QLabel *label;
    QLabel *label_6;
    QLabel *label_9;
    QLineEdit *lineEditDAQDevName;
    QLabel *label_4;
    QLineEdit *lineEditMulticlampPath;
    QLineEdit *lineEditFillerCOM;
    QLabel *label_8;
    QLabel *label_2;
    QLineEdit *lineEditSCARACOM;
    QLineEdit *lineEditThorSerial;
    QLabel *label_3;
    QLabel *label_7;
    QLineEdit *lineEditVisualIP;
    QLabel *label_12;
    QLineEdit *lineEditVisualPort;
    QGroupBox *groupBox_2;
    QGroupBox *groupBox_3;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEditDAQSampRate;
    QLabel *label_13;
    QGroupBox *groupBox_4;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QLineEdit *lineEditLowP;
    QLineEdit *lineEditHighP;
    QLabel *label_14;
    QLabel *label_16;
    QLineEdit *lineEditHighV;
    QLabel *label_15;
    QLineEdit *lineEditLowV;
    QLabel *label_17;
    QGroupBox *groupBox_5;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox_6;
    QWidget *gridLayoutWidget_6;
    QGridLayout *gridLayout_6;
    QLineEdit *lineEditThorFastVel;
    QLabel *label_11;
    QLineEdit *lineEditThorSlowVel;
    QLabel *label_10;
    QGroupBox *groupBox_7;
    QWidget *gridLayoutWidget_8;
    QGridLayout *gridLayout_8;

    void setupUi(QWidget *HardwareSettingsWindow)
    {
        if (HardwareSettingsWindow->objectName().isEmpty())
            HardwareSettingsWindow->setObjectName(QStringLiteral("HardwareSettingsWindow"));
        HardwareSettingsWindow->resize(870, 537);
        pushButtonOk = new QPushButton(HardwareSettingsWindow);
        pushButtonOk->setObjectName(QStringLiteral("pushButtonOk"));
        pushButtonOk->setGeometry(QRect(690, 500, 75, 23));
        pushButtonCancel = new QPushButton(HardwareSettingsWindow);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        pushButtonCancel->setGeometry(QRect(780, 500, 75, 23));
        groupBox = new QGroupBox(HardwareSettingsWindow);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 451, 481));
        gridLayoutWidget = new QWidget(groupBox);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 30, 431, 361));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEditAutopatcherCOM = new QLineEdit(gridLayoutWidget);
        lineEditAutopatcherCOM->setObjectName(QStringLiteral("lineEditAutopatcherCOM"));

        gridLayout->addWidget(lineEditAutopatcherCOM, 0, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 4, 1, 1, 1);

        lineEditHeadstageCOM = new QLineEdit(gridLayoutWidget);
        lineEditHeadstageCOM->setObjectName(QStringLiteral("lineEditHeadstageCOM"));

        gridLayout->addWidget(lineEditHeadstageCOM, 3, 0, 1, 1);

        lineEditMulticlampHeadstageNum = new QLineEdit(gridLayoutWidget);
        lineEditMulticlampHeadstageNum->setObjectName(QStringLiteral("lineEditMulticlampHeadstageNum"));

        gridLayout->addWidget(lineEditMulticlampHeadstageNum, 4, 0, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 5, 1, 1, 1);

        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 7, 1, 1, 1);

        lineEditDAQDevName = new QLineEdit(gridLayoutWidget);
        lineEditDAQDevName->setObjectName(QStringLiteral("lineEditDAQDevName"));

        gridLayout->addWidget(lineEditDAQDevName, 6, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 1, 1, 1);

        lineEditMulticlampPath = new QLineEdit(gridLayoutWidget);
        lineEditMulticlampPath->setObjectName(QStringLiteral("lineEditMulticlampPath"));

        gridLayout->addWidget(lineEditMulticlampPath, 5, 0, 1, 1);

        lineEditFillerCOM = new QLineEdit(gridLayoutWidget);
        lineEditFillerCOM->setObjectName(QStringLiteral("lineEditFillerCOM"));

        gridLayout->addWidget(lineEditFillerCOM, 2, 0, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 6, 1, 1, 1);

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

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 10, 1, 1, 1);

        lineEditVisualIP = new QLineEdit(gridLayoutWidget);
        lineEditVisualIP->setObjectName(QStringLiteral("lineEditVisualIP"));

        gridLayout->addWidget(lineEditVisualIP, 10, 0, 1, 1);

        label_12 = new QLabel(gridLayoutWidget);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout->addWidget(label_12, 11, 1, 1, 1);

        lineEditVisualPort = new QLineEdit(gridLayoutWidget);
        lineEditVisualPort->setObjectName(QStringLiteral("lineEditVisualPort"));

        gridLayout->addWidget(lineEditVisualPort, 11, 0, 1, 1);

        groupBox_2 = new QGroupBox(HardwareSettingsWindow);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(470, 10, 391, 481));
        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 20, 371, 51));
        gridLayoutWidget_2 = new QWidget(groupBox_3);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 20, 351, 22));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEditDAQSampRate = new QLineEdit(gridLayoutWidget_2);
        lineEditDAQSampRate->setObjectName(QStringLiteral("lineEditDAQSampRate"));

        gridLayout_2->addWidget(lineEditDAQSampRate, 0, 1, 1, 1);

        label_13 = new QLabel(gridLayoutWidget_2);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_2->addWidget(label_13, 0, 2, 1, 1);

        groupBox_4 = new QGroupBox(groupBox_2);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 80, 371, 131));
        gridLayoutWidget_3 = new QWidget(groupBox_4);
        gridLayoutWidget_3->setObjectName(QStringLiteral("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(10, 20, 351, 100));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        lineEditLowP = new QLineEdit(gridLayoutWidget_3);
        lineEditLowP->setObjectName(QStringLiteral("lineEditLowP"));

        gridLayout_3->addWidget(lineEditLowP, 1, 0, 1, 1);

        lineEditHighP = new QLineEdit(gridLayoutWidget_3);
        lineEditHighP->setObjectName(QStringLiteral("lineEditHighP"));

        gridLayout_3->addWidget(lineEditHighP, 0, 0, 1, 1);

        label_14 = new QLabel(gridLayoutWidget_3);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout_3->addWidget(label_14, 0, 1, 1, 1);

        label_16 = new QLabel(gridLayoutWidget_3);
        label_16->setObjectName(QStringLiteral("label_16"));

        gridLayout_3->addWidget(label_16, 2, 1, 1, 1);

        lineEditHighV = new QLineEdit(gridLayoutWidget_3);
        lineEditHighV->setObjectName(QStringLiteral("lineEditHighV"));

        gridLayout_3->addWidget(lineEditHighV, 2, 0, 1, 1);

        label_15 = new QLabel(gridLayoutWidget_3);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout_3->addWidget(label_15, 1, 1, 1, 1);

        lineEditLowV = new QLineEdit(gridLayoutWidget_3);
        lineEditLowV->setObjectName(QStringLiteral("lineEditLowV"));

        gridLayout_3->addWidget(lineEditLowV, 3, 0, 1, 1);

        label_17 = new QLabel(gridLayoutWidget_3);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout_3->addWidget(label_17, 3, 1, 1, 1);

        groupBox_5 = new QGroupBox(groupBox_2);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 220, 371, 71));
        gridLayoutWidget_4 = new QWidget(groupBox_5);
        gridLayoutWidget_4->setObjectName(QStringLiteral("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(10, 20, 351, 41));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_4);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        groupBox_6 = new QGroupBox(groupBox_2);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(10, 300, 371, 80));
        gridLayoutWidget_6 = new QWidget(groupBox_6);
        gridLayoutWidget_6->setObjectName(QStringLiteral("gridLayoutWidget_6"));
        gridLayoutWidget_6->setGeometry(QRect(10, 20, 351, 51));
        gridLayout_6 = new QGridLayout(gridLayoutWidget_6);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        lineEditThorFastVel = new QLineEdit(gridLayoutWidget_6);
        lineEditThorFastVel->setObjectName(QStringLiteral("lineEditThorFastVel"));

        gridLayout_6->addWidget(lineEditThorFastVel, 1, 0, 1, 1);

        label_11 = new QLabel(gridLayoutWidget_6);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_6->addWidget(label_11, 1, 1, 1, 1);

        lineEditThorSlowVel = new QLineEdit(gridLayoutWidget_6);
        lineEditThorSlowVel->setObjectName(QStringLiteral("lineEditThorSlowVel"));

        gridLayout_6->addWidget(lineEditThorSlowVel, 0, 0, 1, 1);

        label_10 = new QLabel(gridLayoutWidget_6);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_6->addWidget(label_10, 0, 1, 1, 1);

        groupBox_7 = new QGroupBox(groupBox_2);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(10, 390, 371, 80));
        gridLayoutWidget_8 = new QWidget(groupBox_7);
        gridLayoutWidget_8->setObjectName(QStringLiteral("gridLayoutWidget_8"));
        gridLayoutWidget_8->setGeometry(QRect(10, 20, 351, 51));
        gridLayout_8 = new QGridLayout(gridLayoutWidget_8);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 0);

        retranslateUi(HardwareSettingsWindow);

        QMetaObject::connectSlotsByName(HardwareSettingsWindow);
    } // setupUi

    void retranslateUi(QWidget *HardwareSettingsWindow)
    {
        HardwareSettingsWindow->setWindowTitle(QApplication::translate("HardwareSettingsWindow", "Form", 0));
        pushButtonOk->setText(QApplication::translate("HardwareSettingsWindow", "Ok", 0));
        pushButtonCancel->setText(QApplication::translate("HardwareSettingsWindow", "Cancel", 0));
        groupBox->setTitle(QApplication::translate("HardwareSettingsWindow", "Hardware Connectino Settings", 0));
        lineEditAutopatcherCOM->setText(QApplication::translate("HardwareSettingsWindow", "COM17", 0));
        label_5->setText(QApplication::translate("HardwareSettingsWindow", "Multiclamp Amplifier headstage number", 0));
        lineEditHeadstageCOM->setText(QApplication::translate("HardwareSettingsWindow", "COM25", 0));
        lineEditMulticlampHeadstageNum->setText(QApplication::translate("HardwareSettingsWindow", "2", 0));
        label->setText(QApplication::translate("HardwareSettingsWindow", "Autopatcher control box serial COM port name. \n"
"(Look under Control Panel -> Hardware -> Device Manager -> Ports)  ", 0));
        label_6->setText(QApplication::translate("HardwareSettingsWindow", "Path to MC700B.exe (Multiclamp commander executable)", 0));
        label_9->setText(QApplication::translate("HardwareSettingsWindow", "ThorLabs motor serial number (i.e. 83840919)", 0));
        lineEditDAQDevName->setText(QApplication::translate("HardwareSettingsWindow", "Dev6", 0));
        label_4->setText(QApplication::translate("HardwareSettingsWindow", "Headstage Clamp serial COM port name. ", 0));
        lineEditMulticlampPath->setText(QApplication::translate("HardwareSettingsWindow", "C:\\Program Files (x86)\\Molecular Devices\\MultiClamp 700B Commander\\MC700B.exe", 0));
        lineEditFillerCOM->setText(QApplication::translate("HardwareSettingsWindow", "COM26", 0));
        label_8->setText(QApplication::translate("HardwareSettingsWindow", "DAQ Device Name (i.e. \"Dev1\")", 0));
        label_2->setText(QApplication::translate("HardwareSettingsWindow", "SCARA Robot serial COM port name. ", 0));
        lineEditSCARACOM->setText(QApplication::translate("HardwareSettingsWindow", "COM27", 0));
        lineEditThorSerial->setText(QApplication::translate("HardwareSettingsWindow", "83840919", 0));
        label_3->setText(QApplication::translate("HardwareSettingsWindow", "Filler Robot serial COM port name. ", 0));
        label_7->setText(QApplication::translate("HardwareSettingsWindow", "IP Address of visual stimulation computer running the server", 0));
        lineEditVisualIP->setText(QApplication::translate("HardwareSettingsWindow", "130.207.40.246", 0));
        label_12->setText(QApplication::translate("HardwareSettingsWindow", "Port the visual stimulation server is running on", 0));
        lineEditVisualPort->setText(QApplication::translate("HardwareSettingsWindow", "5296", 0));
        groupBox_2->setTitle(QApplication::translate("HardwareSettingsWindow", "Hardware Settings", 0));
        groupBox_3->setTitle(QApplication::translate("HardwareSettingsWindow", "DAQ", 0));
        lineEditDAQSampRate->setText(QApplication::translate("HardwareSettingsWindow", "20000", 0));
        label_13->setText(QApplication::translate("HardwareSettingsWindow", "(Hz) DAQ sampling rate", 0));
        groupBox_4->setTitle(QApplication::translate("HardwareSettingsWindow", "Pressure Control Box", 0));
        lineEditLowP->setText(QApplication::translate("HardwareSettingsWindow", "25", 0));
        lineEditHighP->setText(QApplication::translate("HardwareSettingsWindow", "999", 0));
        label_14->setText(QApplication::translate("HardwareSettingsWindow", "(mBar) Pressure used during decent to depth", 0));
        label_16->setText(QApplication::translate("HardwareSettingsWindow", "(mBar) Neagative pressure used to break in. (345 max)", 0));
        lineEditHighV->setText(QApplication::translate("HardwareSettingsWindow", "345", 0));
        label_15->setText(QApplication::translate("HardwareSettingsWindow", "(mBar) Pressure used during neuron hunting", 0));
        lineEditLowV->setText(QApplication::translate("HardwareSettingsWindow", "15", 0));
        label_17->setText(QApplication::translate("HardwareSettingsWindow", "(mBar) Negative pressure used to encourage gigasealing.", 0));
        groupBox_5->setTitle(QApplication::translate("HardwareSettingsWindow", "Robot Arm", 0));
        groupBox_6->setTitle(QApplication::translate("HardwareSettingsWindow", "Headstage Clamp, Wire Threader, and Thorlabs Motor", 0));
        lineEditThorFastVel->setText(QApplication::translate("HardwareSettingsWindow", "2", 0));
        label_11->setText(QApplication::translate("HardwareSettingsWindow", "ThorLabs motor rapid descent velocity (2) mm/s", 0));
        lineEditThorSlowVel->setText(QApplication::translate("HardwareSettingsWindow", "2", 0));
        label_10->setText(QApplication::translate("HardwareSettingsWindow", "ThorLabs motor hunting velocity (2) um/s", 0));
        groupBox_7->setTitle(QApplication::translate("HardwareSettingsWindow", "Pipette Filler", 0));
    } // retranslateUi

};

namespace Ui {
    class HardwareSettingsWindow: public Ui_HardwareSettingsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HARDWARESETTINGSWINDOW_H
