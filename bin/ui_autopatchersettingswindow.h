/********************************************************************************
** Form generated from reading UI file 'autopatchersettingswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTOPATCHERSETTINGSWINDOW_H
#define UI_AUTOPATCHERSETTINGSWINDOW_H

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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AutopatcherSettingsWindow
{
public:
    QPushButton *pushButtonOk;
    QPushButton *pushButtonCancel;
    QGroupBox *groupBox_2;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *label_16;
    QLineEdit *lineEditSlowRetractSize;
    QLabel *label_39;
    QLineEdit *lineEditAdvDetectNSamps;
    QLabel *label_21;
    QLabel *label_38;
    QLineEdit *lineEditPReleaseWait;
    QLabel *label_23;
    QLabel *label_19;
    QLineEdit *lineEditAdvClogThresh;
    QLineEdit *lineEditAdvMaxR;
    QLabel *label_20;
    QLineEdit *lineEditAdvMaxVar;
    QLineEdit *lineEditSkipExtraStep;
    QLabel *label_37;
    QLineEdit *lineEditGigasealRetract;
    QLabel *label_40;
    QLineEdit *lineEditAdvNeuronDetectThresh;
    QLabel *label_22;
    QLineEdit *lineEditAdvMinR;
    QLineEdit *lineEditAdvReturnToHuntThresh;
    QLabel *label_18;
    QLineEdit *lineEditDelayAfterDescent;
    QLabel *label_41;
    QGroupBox *groupBox;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_13;
    QLineEdit *lineEditBasicStartDepth;
    QLineEdit *lineEditBasicStopDepth;
    QLabel *label_15;
    QLineEdit *lineEditBasicNSamples;
    QLabel *label_14;
    QLineEdit *lineEditStartPipetteNum;
    QLabel *label_25;
    QLineEdit *lineEditHeadstageChannelNum;
    QLabel *label_36;
    QRadioButton *radioButtonRamp;
    QRadioButton *radioButtonZap;
    QRadioButton *radioButtonSuction;

    void setupUi(QWidget *AutopatcherSettingsWindow)
    {
        if (AutopatcherSettingsWindow->objectName().isEmpty())
            AutopatcherSettingsWindow->setObjectName(QStringLiteral("AutopatcherSettingsWindow"));
        AutopatcherSettingsWindow->resize(659, 447);
        pushButtonOk = new QPushButton(AutopatcherSettingsWindow);
        pushButtonOk->setObjectName(QStringLiteral("pushButtonOk"));
        pushButtonOk->setGeometry(QRect(480, 410, 75, 23));
        pushButtonCancel = new QPushButton(AutopatcherSettingsWindow);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        pushButtonCancel->setGeometry(QRect(570, 410, 75, 23));
        groupBox_2 = new QGroupBox(AutopatcherSettingsWindow);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(250, 10, 401, 371));
        gridLayoutWidget_2 = new QWidget(groupBox_2);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 20, 378, 341));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_16 = new QLabel(gridLayoutWidget_2);
        label_16->setObjectName(QStringLiteral("label_16"));
        QFont font;
        font.setPointSize(8);
        label_16->setFont(font);

        gridLayout_2->addWidget(label_16, 5, 1, 1, 1);

        lineEditSlowRetractSize = new QLineEdit(gridLayoutWidget_2);
        lineEditSlowRetractSize->setObjectName(QStringLiteral("lineEditSlowRetractSize"));
        lineEditSlowRetractSize->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEditSlowRetractSize, 10, 0, 1, 1);

        label_39 = new QLabel(gridLayoutWidget_2);
        label_39->setObjectName(QStringLiteral("label_39"));

        gridLayout_2->addWidget(label_39, 10, 1, 1, 1);

        lineEditAdvDetectNSamps = new QLineEdit(gridLayoutWidget_2);
        lineEditAdvDetectNSamps->setObjectName(QStringLiteral("lineEditAdvDetectNSamps"));
        lineEditAdvDetectNSamps->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEditAdvDetectNSamps, 6, 0, 1, 1);

        label_21 = new QLabel(gridLayoutWidget_2);
        label_21->setObjectName(QStringLiteral("label_21"));

        gridLayout_2->addWidget(label_21, 4, 1, 1, 1);

        label_38 = new QLabel(gridLayoutWidget_2);
        label_38->setObjectName(QStringLiteral("label_38"));

        gridLayout_2->addWidget(label_38, 9, 1, 1, 1);

        lineEditPReleaseWait = new QLineEdit(gridLayoutWidget_2);
        lineEditPReleaseWait->setObjectName(QStringLiteral("lineEditPReleaseWait"));
        lineEditPReleaseWait->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEditPReleaseWait, 9, 0, 1, 1);

        label_23 = new QLabel(gridLayoutWidget_2);
        label_23->setObjectName(QStringLiteral("label_23"));

        gridLayout_2->addWidget(label_23, 7, 1, 1, 1);

        label_19 = new QLabel(gridLayoutWidget_2);
        label_19->setObjectName(QStringLiteral("label_19"));

        gridLayout_2->addWidget(label_19, 1, 1, 1, 1);

        lineEditAdvClogThresh = new QLineEdit(gridLayoutWidget_2);
        lineEditAdvClogThresh->setObjectName(QStringLiteral("lineEditAdvClogThresh"));
        lineEditAdvClogThresh->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEditAdvClogThresh, 4, 0, 1, 1);

        lineEditAdvMaxR = new QLineEdit(gridLayoutWidget_2);
        lineEditAdvMaxR->setObjectName(QStringLiteral("lineEditAdvMaxR"));
        lineEditAdvMaxR->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEditAdvMaxR, 1, 0, 1, 1);

        label_20 = new QLabel(gridLayoutWidget_2);
        label_20->setObjectName(QStringLiteral("label_20"));

        gridLayout_2->addWidget(label_20, 2, 1, 1, 1);

        lineEditAdvMaxVar = new QLineEdit(gridLayoutWidget_2);
        lineEditAdvMaxVar->setObjectName(QStringLiteral("lineEditAdvMaxVar"));
        lineEditAdvMaxVar->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEditAdvMaxVar, 2, 0, 1, 1);

        lineEditSkipExtraStep = new QLineEdit(gridLayoutWidget_2);
        lineEditSkipExtraStep->setObjectName(QStringLiteral("lineEditSkipExtraStep"));
        lineEditSkipExtraStep->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEditSkipExtraStep, 8, 0, 1, 1);

        label_37 = new QLabel(gridLayoutWidget_2);
        label_37->setObjectName(QStringLiteral("label_37"));

        gridLayout_2->addWidget(label_37, 8, 1, 1, 1);

        lineEditGigasealRetract = new QLineEdit(gridLayoutWidget_2);
        lineEditGigasealRetract->setObjectName(QStringLiteral("lineEditGigasealRetract"));
        lineEditGigasealRetract->setEnabled(false);
        lineEditGigasealRetract->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEditGigasealRetract, 11, 0, 1, 1);

        label_40 = new QLabel(gridLayoutWidget_2);
        label_40->setObjectName(QStringLiteral("label_40"));
        label_40->setEnabled(false);

        gridLayout_2->addWidget(label_40, 11, 1, 1, 1);

        lineEditAdvNeuronDetectThresh = new QLineEdit(gridLayoutWidget_2);
        lineEditAdvNeuronDetectThresh->setObjectName(QStringLiteral("lineEditAdvNeuronDetectThresh"));
        lineEditAdvNeuronDetectThresh->setFont(font);
        lineEditAdvNeuronDetectThresh->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEditAdvNeuronDetectThresh, 5, 0, 1, 1);

        label_22 = new QLabel(gridLayoutWidget_2);
        label_22->setObjectName(QStringLiteral("label_22"));

        gridLayout_2->addWidget(label_22, 6, 1, 1, 1);

        lineEditAdvMinR = new QLineEdit(gridLayoutWidget_2);
        lineEditAdvMinR->setObjectName(QStringLiteral("lineEditAdvMinR"));
        lineEditAdvMinR->setInputMethodHints(Qt::ImhDigitsOnly);
        lineEditAdvMinR->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEditAdvMinR, 0, 0, 1, 1);

        lineEditAdvReturnToHuntThresh = new QLineEdit(gridLayoutWidget_2);
        lineEditAdvReturnToHuntThresh->setObjectName(QStringLiteral("lineEditAdvReturnToHuntThresh"));
        lineEditAdvReturnToHuntThresh->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEditAdvReturnToHuntThresh, 7, 0, 1, 1);

        label_18 = new QLabel(gridLayoutWidget_2);
        label_18->setObjectName(QStringLiteral("label_18"));

        gridLayout_2->addWidget(label_18, 0, 1, 1, 1);

        lineEditDelayAfterDescent = new QLineEdit(gridLayoutWidget_2);
        lineEditDelayAfterDescent->setObjectName(QStringLiteral("lineEditDelayAfterDescent"));
        lineEditDelayAfterDescent->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEditDelayAfterDescent, 3, 0, 1, 1);

        label_41 = new QLabel(gridLayoutWidget_2);
        label_41->setObjectName(QStringLiteral("label_41"));
        label_41->setFont(font);

        gridLayout_2->addWidget(label_41, 3, 1, 1, 1);

        groupBox = new QGroupBox(AutopatcherSettingsWindow);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 231, 371));
        gridLayoutWidget = new QWidget(groupBox);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 20, 221, 151));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(gridLayoutWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font);

        gridLayout->addWidget(label_13, 0, 2, 1, 1);

        lineEditBasicStartDepth = new QLineEdit(gridLayoutWidget);
        lineEditBasicStartDepth->setObjectName(QStringLiteral("lineEditBasicStartDepth"));
        lineEditBasicStartDepth->setFont(font);
        lineEditBasicStartDepth->setInputMethodHints(Qt::ImhPreferNumbers);
        lineEditBasicStartDepth->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEditBasicStartDepth, 0, 0, 1, 1);

        lineEditBasicStopDepth = new QLineEdit(gridLayoutWidget);
        lineEditBasicStopDepth->setObjectName(QStringLiteral("lineEditBasicStopDepth"));
        lineEditBasicStopDepth->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEditBasicStopDepth, 1, 0, 1, 1);

        label_15 = new QLabel(gridLayoutWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setFont(font);

        gridLayout->addWidget(label_15, 1, 2, 1, 1);

        lineEditBasicNSamples = new QLineEdit(gridLayoutWidget);
        lineEditBasicNSamples->setObjectName(QStringLiteral("lineEditBasicNSamples"));
        lineEditBasicNSamples->setFont(font);
        lineEditBasicNSamples->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEditBasicNSamples, 2, 0, 1, 1);

        label_14 = new QLabel(gridLayoutWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setFont(font);

        gridLayout->addWidget(label_14, 2, 2, 1, 1);

        lineEditStartPipetteNum = new QLineEdit(gridLayoutWidget);
        lineEditStartPipetteNum->setObjectName(QStringLiteral("lineEditStartPipetteNum"));
        lineEditStartPipetteNum->setFont(font);
        lineEditStartPipetteNum->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEditStartPipetteNum, 3, 0, 1, 1);

        label_25 = new QLabel(gridLayoutWidget);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setFont(font);

        gridLayout->addWidget(label_25, 3, 2, 1, 1);

        lineEditHeadstageChannelNum = new QLineEdit(gridLayoutWidget);
        lineEditHeadstageChannelNum->setObjectName(QStringLiteral("lineEditHeadstageChannelNum"));
        lineEditHeadstageChannelNum->setFont(font);
        lineEditHeadstageChannelNum->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEditHeadstageChannelNum, 4, 0, 1, 1);

        label_36 = new QLabel(gridLayoutWidget);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setFont(font);

        gridLayout->addWidget(label_36, 4, 2, 1, 1);

        radioButtonRamp = new QRadioButton(groupBox);
        radioButtonRamp->setObjectName(QStringLiteral("radioButtonRamp"));
        radioButtonRamp->setGeometry(QRect(10, 260, 131, 21));
        radioButtonRamp->setChecked(true);
        radioButtonZap = new QRadioButton(groupBox);
        radioButtonZap->setObjectName(QStringLiteral("radioButtonZap"));
        radioButtonZap->setGeometry(QRect(10, 220, 91, 21));
        radioButtonSuction = new QRadioButton(groupBox);
        radioButtonSuction->setObjectName(QStringLiteral("radioButtonSuction"));
        radioButtonSuction->setGeometry(QRect(10, 240, 131, 21));
        radioButtonSuction->setChecked(false);
        QWidget::setTabOrder(pushButtonOk, pushButtonCancel);
        QWidget::setTabOrder(pushButtonCancel, lineEditBasicStartDepth);
        QWidget::setTabOrder(lineEditBasicStartDepth, lineEditBasicStopDepth);
        QWidget::setTabOrder(lineEditBasicStopDepth, lineEditBasicNSamples);
        QWidget::setTabOrder(lineEditBasicNSamples, lineEditStartPipetteNum);
        QWidget::setTabOrder(lineEditStartPipetteNum, lineEditHeadstageChannelNum);
        QWidget::setTabOrder(lineEditHeadstageChannelNum, radioButtonZap);
        QWidget::setTabOrder(radioButtonZap, radioButtonSuction);
        QWidget::setTabOrder(radioButtonSuction, radioButtonRamp);
        QWidget::setTabOrder(radioButtonRamp, lineEditAdvMinR);
        QWidget::setTabOrder(lineEditAdvMinR, lineEditAdvMaxR);
        QWidget::setTabOrder(lineEditAdvMaxR, lineEditAdvMaxVar);
        QWidget::setTabOrder(lineEditAdvMaxVar, lineEditDelayAfterDescent);
        QWidget::setTabOrder(lineEditDelayAfterDescent, lineEditAdvClogThresh);
        QWidget::setTabOrder(lineEditAdvClogThresh, lineEditAdvNeuronDetectThresh);
        QWidget::setTabOrder(lineEditAdvNeuronDetectThresh, lineEditAdvDetectNSamps);
        QWidget::setTabOrder(lineEditAdvDetectNSamps, lineEditAdvReturnToHuntThresh);
        QWidget::setTabOrder(lineEditAdvReturnToHuntThresh, lineEditSkipExtraStep);
        QWidget::setTabOrder(lineEditSkipExtraStep, lineEditPReleaseWait);
        QWidget::setTabOrder(lineEditPReleaseWait, lineEditSlowRetractSize);
        QWidget::setTabOrder(lineEditSlowRetractSize, lineEditGigasealRetract);

        retranslateUi(AutopatcherSettingsWindow);

        QMetaObject::connectSlotsByName(AutopatcherSettingsWindow);
    } // setupUi

    void retranslateUi(QWidget *AutopatcherSettingsWindow)
    {
        AutopatcherSettingsWindow->setWindowTitle(QApplication::translate("AutopatcherSettingsWindow", "Autopatcher Settings", 0));
        pushButtonOk->setText(QApplication::translate("AutopatcherSettingsWindow", "Ok", 0));
        pushButtonCancel->setText(QApplication::translate("AutopatcherSettingsWindow", "Cancel", 0));
        groupBox_2->setTitle(QApplication::translate("AutopatcherSettingsWindow", "Advanced Settings", 0));
        label_16->setText(QApplication::translate("AutopatcherSettingsWindow", "(kOhms) Neuron Detection Threshold ", 0));
        lineEditSlowRetractSize->setText(QApplication::translate("AutopatcherSettingsWindow", "4", 0));
        label_39->setText(QApplication::translate("AutopatcherSettingsWindow", "(\302\265m) Slow retraction step size", 0));
        lineEditAdvDetectNSamps->setText(QApplication::translate("AutopatcherSettingsWindow", "3", 0));
        label_21->setText(QApplication::translate("AutopatcherSettingsWindow", "(MOhms) Maximum Clog Check R Increase", 0));
        label_38->setText(QApplication::translate("AutopatcherSettingsWindow", "(sec) Time to wait after dection before releasing positive pressure", 0));
        lineEditPReleaseWait->setText(QApplication::translate("AutopatcherSettingsWindow", "0", 0));
        label_23->setText(QApplication::translate("AutopatcherSettingsWindow", "(MOhms) Threshold to Return to Neuron Hunt", 0));
        label_19->setText(QApplication::translate("AutopatcherSettingsWindow", "(MOhms) Maximum Acceptable Resistance", 0));
        lineEditAdvClogThresh->setText(QApplication::translate("AutopatcherSettingsWindow", "0.25", 0));
        lineEditAdvMaxR->setText(QApplication::translate("AutopatcherSettingsWindow", "9", 0));
        label_20->setText(QApplication::translate("AutopatcherSettingsWindow", "(MOhms) Maximum Acceptable Variation", 0));
        lineEditAdvMaxVar->setText(QApplication::translate("AutopatcherSettingsWindow", "0.5", 0));
        lineEditSkipExtraStep->setText(QApplication::translate("AutopatcherSettingsWindow", "1", 0));
        label_37->setText(QApplication::translate("AutopatcherSettingsWindow", "(MOhms) Hit Threshold to Skip the Extra Step", 0));
        lineEditGigasealRetract->setText(QApplication::translate("AutopatcherSettingsWindow", "6", 0));
        label_40->setText(QApplication::translate("AutopatcherSettingsWindow", "(um) Retraction distance on gigaseal", 0));
        lineEditAdvNeuronDetectThresh->setText(QApplication::translate("AutopatcherSettingsWindow", "0.6", 0));
        label_22->setText(QApplication::translate("AutopatcherSettingsWindow", "(N) of Samples to Detect Neuron", 0));
        lineEditAdvMinR->setText(QApplication::translate("AutopatcherSettingsWindow", "3", 0));
        lineEditAdvReturnToHuntThresh->setText(QApplication::translate("AutopatcherSettingsWindow", "0.25", 0));
        label_18->setText(QApplication::translate("AutopatcherSettingsWindow", "(MOhms) Minimum Acceptable Resistance", 0));
        lineEditDelayAfterDescent->setText(QApplication::translate("AutopatcherSettingsWindow", "5", 0));
        label_41->setText(QApplication::translate("AutopatcherSettingsWindow", "(sec)  Delay After Descent to Start Depth", 0));
        groupBox->setTitle(QApplication::translate("AutopatcherSettingsWindow", "Basic Settings", 0));
        label_13->setText(QApplication::translate("AutopatcherSettingsWindow", "(\302\265m)  Start Depth ", 0));
        lineEditBasicStartDepth->setText(QApplication::translate("AutopatcherSettingsWindow", "400", 0));
        lineEditBasicStopDepth->setText(QApplication::translate("AutopatcherSettingsWindow", "1000", 0));
        label_15->setText(QApplication::translate("AutopatcherSettingsWindow", "(\302\265m)  Stop Depth ", 0));
        lineEditBasicNSamples->setText(QApplication::translate("AutopatcherSettingsWindow", "7", 0));
        label_14->setText(QApplication::translate("AutopatcherSettingsWindow", "(N)  of Samples to Average", 0));
        lineEditStartPipetteNum->setText(QApplication::translate("AutopatcherSettingsWindow", "20", 0));
        label_25->setText(QApplication::translate("AutopatcherSettingsWindow", "(N) Starting Pipette Number", 0));
        lineEditHeadstageChannelNum->setText(QApplication::translate("AutopatcherSettingsWindow", "2", 0));
        label_36->setText(QApplication::translate("AutopatcherSettingsWindow", "Headstage Channel Num.", 0));
        radioButtonRamp->setText(QApplication::translate("AutopatcherSettingsWindow", "Suction Ramp Break In", 0));
        radioButtonZap->setText(QApplication::translate("AutopatcherSettingsWindow", "Zap break in", 0));
        radioButtonSuction->setText(QApplication::translate("AutopatcherSettingsWindow", "Suction break in", 0));
    } // retranslateUi

};

namespace Ui {
    class AutopatcherSettingsWindow: public Ui_AutopatcherSettingsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTOPATCHERSETTINGSWINDOW_H
