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
#include <QtWidgets/QCheckBox>
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
    QLineEdit *lineEditAdvMaxVar;
    QLabel *label_37;
    QLabel *label_39;
    QLineEdit *lineEditAdvDetectNSamps;
    QLabel *label_21;
    QLabel *label_38;
    QLineEdit *lineEditNumSampsToWaitReleasePress;
    QLabel *label_23;
    QLabel *label_19;
    QLineEdit *lineEditAdvClogThresh;
    QLineEdit *lineEditAdvMaxR;
    QLabel *label_20;
    QLineEdit *lineEditSkipExtraStep;
    QLineEdit *lineEditGigasealRetract;
    QLabel *label_40;
    QLineEdit *lineEditAdvNeuronDetectThresh;
    QLabel *label_22;
    QLineEdit *lineEditAdvMinR;
    QLineEdit *lineEditAdvReturnToHuntThresh;
    QLabel *label_18;
    QLineEdit *lineEditDelayAfterDescent;
    QLabel *label_41;
    QLabel *label_42;
    QLineEdit *lineEditWaitForRecordingStabilize;
    QLabel *label_16;
    QLineEdit *lineEditNumVisualStims;
    QLabel *label_43;
    QLineEdit *lineEditSlowRetractSize;
    QLineEdit *lineEditNumBACCurrentInjRepeats;
    QLabel *label_44;
    QGroupBox *groupBox;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEditBasicStartDepth;
    QLineEdit *lineEditBasicStopDepth;
    QLabel *label_15;
    QLineEdit *lineEditBasicNSamples;
    QLabel *label_14;
    QLineEdit *lineEditStartPipetteNum;
    QLabel *label_25;
    QLabel *label_13;
    QLineEdit *lineEditHeadstageChannelNum;
    QLabel *label_36;
    QLineEdit *lineEditVStimScreenNumber;
    QLabel *label;
    QLineEdit *lineEditNumCurrentStepRepeats;
    QLabel *label_2;
    QLineEdit *lineEditBrainSurfaceAbsPos;
    QLabel *label_3;
    QCheckBox *checkBoxSlowRetract;
    QGroupBox *groupBox_3;
    QRadioButton *radioButtonRampFeedback;
    QRadioButton *radioButtonRamp;
    QRadioButton *radioButtonZap;
    QRadioButton *radioButtonSuction;
    QLabel *label_4;

    void setupUi(QWidget *AutopatcherSettingsWindow)
    {
        if (AutopatcherSettingsWindow->objectName().isEmpty())
            AutopatcherSettingsWindow->setObjectName(QStringLiteral("AutopatcherSettingsWindow"));
        AutopatcherSettingsWindow->resize(781, 472);
        pushButtonOk = new QPushButton(AutopatcherSettingsWindow);
        pushButtonOk->setObjectName(QStringLiteral("pushButtonOk"));
        pushButtonOk->setGeometry(QRect(600, 430, 75, 23));
        pushButtonCancel = new QPushButton(AutopatcherSettingsWindow);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        pushButtonCancel->setGeometry(QRect(690, 430, 75, 23));
        groupBox_2 = new QGroupBox(AutopatcherSettingsWindow);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(280, 10, 491, 411));
        gridLayoutWidget_2 = new QWidget(groupBox_2);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 20, 451, 386));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEditAdvMaxVar = new QLineEdit(gridLayoutWidget_2);
        lineEditAdvMaxVar->setObjectName(QStringLiteral("lineEditAdvMaxVar"));
        lineEditAdvMaxVar->setAutoFillBackground(false);
        lineEditAdvMaxVar->setStyleSheet(QStringLiteral("background:white"));
        lineEditAdvMaxVar->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEditAdvMaxVar, 2, 0, 1, 1);

        label_37 = new QLabel(gridLayoutWidget_2);
        label_37->setObjectName(QStringLiteral("label_37"));

        gridLayout_2->addWidget(label_37, 8, 1, 1, 1);

        label_39 = new QLabel(gridLayoutWidget_2);
        label_39->setObjectName(QStringLiteral("label_39"));

        gridLayout_2->addWidget(label_39, 10, 1, 1, 1);

        lineEditAdvDetectNSamps = new QLineEdit(gridLayoutWidget_2);
        lineEditAdvDetectNSamps->setObjectName(QStringLiteral("lineEditAdvDetectNSamps"));
        lineEditAdvDetectNSamps->setAutoFillBackground(false);
        lineEditAdvDetectNSamps->setStyleSheet(QStringLiteral("background:white"));
        lineEditAdvDetectNSamps->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEditAdvDetectNSamps, 6, 0, 1, 1);

        label_21 = new QLabel(gridLayoutWidget_2);
        label_21->setObjectName(QStringLiteral("label_21"));

        gridLayout_2->addWidget(label_21, 4, 1, 1, 1);

        label_38 = new QLabel(gridLayoutWidget_2);
        label_38->setObjectName(QStringLiteral("label_38"));

        gridLayout_2->addWidget(label_38, 9, 1, 1, 1);

        lineEditNumSampsToWaitReleasePress = new QLineEdit(gridLayoutWidget_2);
        lineEditNumSampsToWaitReleasePress->setObjectName(QStringLiteral("lineEditNumSampsToWaitReleasePress"));
        lineEditNumSampsToWaitReleasePress->setAutoFillBackground(false);
        lineEditNumSampsToWaitReleasePress->setStyleSheet(QStringLiteral("background:white"));
        lineEditNumSampsToWaitReleasePress->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEditNumSampsToWaitReleasePress, 9, 0, 1, 1);

        label_23 = new QLabel(gridLayoutWidget_2);
        label_23->setObjectName(QStringLiteral("label_23"));

        gridLayout_2->addWidget(label_23, 7, 1, 1, 1);

        label_19 = new QLabel(gridLayoutWidget_2);
        label_19->setObjectName(QStringLiteral("label_19"));

        gridLayout_2->addWidget(label_19, 1, 1, 1, 1);

        lineEditAdvClogThresh = new QLineEdit(gridLayoutWidget_2);
        lineEditAdvClogThresh->setObjectName(QStringLiteral("lineEditAdvClogThresh"));
        lineEditAdvClogThresh->setAutoFillBackground(false);
        lineEditAdvClogThresh->setStyleSheet(QStringLiteral("background:white"));
        lineEditAdvClogThresh->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEditAdvClogThresh, 4, 0, 1, 1);

        lineEditAdvMaxR = new QLineEdit(gridLayoutWidget_2);
        lineEditAdvMaxR->setObjectName(QStringLiteral("lineEditAdvMaxR"));
        lineEditAdvMaxR->setAutoFillBackground(false);
        lineEditAdvMaxR->setStyleSheet(QStringLiteral("background:white"));
        lineEditAdvMaxR->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEditAdvMaxR, 1, 0, 1, 1);

        label_20 = new QLabel(gridLayoutWidget_2);
        label_20->setObjectName(QStringLiteral("label_20"));

        gridLayout_2->addWidget(label_20, 2, 1, 1, 1);

        lineEditSkipExtraStep = new QLineEdit(gridLayoutWidget_2);
        lineEditSkipExtraStep->setObjectName(QStringLiteral("lineEditSkipExtraStep"));
        lineEditSkipExtraStep->setAutoFillBackground(false);
        lineEditSkipExtraStep->setStyleSheet(QStringLiteral("background:white"));
        lineEditSkipExtraStep->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEditSkipExtraStep, 8, 0, 1, 1);

        lineEditGigasealRetract = new QLineEdit(gridLayoutWidget_2);
        lineEditGigasealRetract->setObjectName(QStringLiteral("lineEditGigasealRetract"));
        lineEditGigasealRetract->setEnabled(false);
        lineEditGigasealRetract->setAutoFillBackground(false);
        lineEditGigasealRetract->setStyleSheet(QStringLiteral("background:white"));
        lineEditGigasealRetract->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEditGigasealRetract, 12, 0, 1, 1);

        label_40 = new QLabel(gridLayoutWidget_2);
        label_40->setObjectName(QStringLiteral("label_40"));
        label_40->setEnabled(false);

        gridLayout_2->addWidget(label_40, 12, 1, 1, 1);

        lineEditAdvNeuronDetectThresh = new QLineEdit(gridLayoutWidget_2);
        lineEditAdvNeuronDetectThresh->setObjectName(QStringLiteral("lineEditAdvNeuronDetectThresh"));
        QFont font;
        font.setPointSize(8);
        lineEditAdvNeuronDetectThresh->setFont(font);
        lineEditAdvNeuronDetectThresh->setAutoFillBackground(false);
        lineEditAdvNeuronDetectThresh->setStyleSheet(QStringLiteral("background:white"));
        lineEditAdvNeuronDetectThresh->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEditAdvNeuronDetectThresh, 5, 0, 1, 1);

        label_22 = new QLabel(gridLayoutWidget_2);
        label_22->setObjectName(QStringLiteral("label_22"));

        gridLayout_2->addWidget(label_22, 6, 1, 1, 1);

        lineEditAdvMinR = new QLineEdit(gridLayoutWidget_2);
        lineEditAdvMinR->setObjectName(QStringLiteral("lineEditAdvMinR"));
        lineEditAdvMinR->setAutoFillBackground(false);
        lineEditAdvMinR->setStyleSheet(QStringLiteral("background:white"));
        lineEditAdvMinR->setInputMethodHints(Qt::ImhDigitsOnly);
        lineEditAdvMinR->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEditAdvMinR, 0, 0, 1, 1);

        lineEditAdvReturnToHuntThresh = new QLineEdit(gridLayoutWidget_2);
        lineEditAdvReturnToHuntThresh->setObjectName(QStringLiteral("lineEditAdvReturnToHuntThresh"));
        lineEditAdvReturnToHuntThresh->setAutoFillBackground(false);
        lineEditAdvReturnToHuntThresh->setStyleSheet(QStringLiteral("background:white"));
        lineEditAdvReturnToHuntThresh->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEditAdvReturnToHuntThresh, 7, 0, 1, 1);

        label_18 = new QLabel(gridLayoutWidget_2);
        label_18->setObjectName(QStringLiteral("label_18"));

        gridLayout_2->addWidget(label_18, 0, 1, 1, 1);

        lineEditDelayAfterDescent = new QLineEdit(gridLayoutWidget_2);
        lineEditDelayAfterDescent->setObjectName(QStringLiteral("lineEditDelayAfterDescent"));
        lineEditDelayAfterDescent->setAutoFillBackground(false);
        lineEditDelayAfterDescent->setStyleSheet(QStringLiteral("background:white"));
        lineEditDelayAfterDescent->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEditDelayAfterDescent, 3, 0, 1, 1);

        label_41 = new QLabel(gridLayoutWidget_2);
        label_41->setObjectName(QStringLiteral("label_41"));
        label_41->setFont(font);

        gridLayout_2->addWidget(label_41, 3, 1, 1, 1);

        label_42 = new QLabel(gridLayoutWidget_2);
        label_42->setObjectName(QStringLiteral("label_42"));

        gridLayout_2->addWidget(label_42, 11, 1, 1, 1);

        lineEditWaitForRecordingStabilize = new QLineEdit(gridLayoutWidget_2);
        lineEditWaitForRecordingStabilize->setObjectName(QStringLiteral("lineEditWaitForRecordingStabilize"));
        lineEditWaitForRecordingStabilize->setAutoFillBackground(false);
        lineEditWaitForRecordingStabilize->setStyleSheet(QStringLiteral("background:white"));
        lineEditWaitForRecordingStabilize->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEditWaitForRecordingStabilize, 11, 0, 1, 1);

        label_16 = new QLabel(gridLayoutWidget_2);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setFont(font);

        gridLayout_2->addWidget(label_16, 5, 1, 1, 1);

        lineEditNumVisualStims = new QLineEdit(gridLayoutWidget_2);
        lineEditNumVisualStims->setObjectName(QStringLiteral("lineEditNumVisualStims"));
        lineEditNumVisualStims->setAutoFillBackground(false);
        lineEditNumVisualStims->setStyleSheet(QStringLiteral("background:white"));
        lineEditNumVisualStims->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEditNumVisualStims, 13, 0, 1, 1);

        label_43 = new QLabel(gridLayoutWidget_2);
        label_43->setObjectName(QStringLiteral("label_43"));

        gridLayout_2->addWidget(label_43, 13, 1, 1, 1);

        lineEditSlowRetractSize = new QLineEdit(gridLayoutWidget_2);
        lineEditSlowRetractSize->setObjectName(QStringLiteral("lineEditSlowRetractSize"));
        lineEditSlowRetractSize->setAutoFillBackground(false);
        lineEditSlowRetractSize->setStyleSheet(QStringLiteral("background:white"));
        lineEditSlowRetractSize->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEditSlowRetractSize, 10, 0, 1, 1);

        lineEditNumBACCurrentInjRepeats = new QLineEdit(gridLayoutWidget_2);
        lineEditNumBACCurrentInjRepeats->setObjectName(QStringLiteral("lineEditNumBACCurrentInjRepeats"));
        lineEditNumBACCurrentInjRepeats->setAutoFillBackground(false);
        lineEditNumBACCurrentInjRepeats->setStyleSheet(QStringLiteral("background:white"));
        lineEditNumBACCurrentInjRepeats->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEditNumBACCurrentInjRepeats, 14, 0, 1, 1);

        label_44 = new QLabel(gridLayoutWidget_2);
        label_44->setObjectName(QStringLiteral("label_44"));

        gridLayout_2->addWidget(label_44, 14, 1, 1, 1);

        groupBox = new QGroupBox(AutopatcherSettingsWindow);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 261, 391));
        gridLayoutWidget = new QWidget(groupBox);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 20, 241, 221));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEditBasicStartDepth = new QLineEdit(gridLayoutWidget);
        lineEditBasicStartDepth->setObjectName(QStringLiteral("lineEditBasicStartDepth"));
        lineEditBasicStartDepth->setFont(font);
        lineEditBasicStartDepth->setAutoFillBackground(false);
        lineEditBasicStartDepth->setStyleSheet(QStringLiteral("background:white"));
        lineEditBasicStartDepth->setInputMethodHints(Qt::ImhPreferNumbers);
        lineEditBasicStartDepth->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEditBasicStartDepth, 0, 0, 1, 1);

        lineEditBasicStopDepth = new QLineEdit(gridLayoutWidget);
        lineEditBasicStopDepth->setObjectName(QStringLiteral("lineEditBasicStopDepth"));
        lineEditBasicStopDepth->setAutoFillBackground(false);
        lineEditBasicStopDepth->setStyleSheet(QStringLiteral("background:white"));
        lineEditBasicStopDepth->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEditBasicStopDepth, 1, 0, 1, 1);

        label_15 = new QLabel(gridLayoutWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setFont(font);

        gridLayout->addWidget(label_15, 1, 2, 1, 1);

        lineEditBasicNSamples = new QLineEdit(gridLayoutWidget);
        lineEditBasicNSamples->setObjectName(QStringLiteral("lineEditBasicNSamples"));
        lineEditBasicNSamples->setFont(font);
        lineEditBasicNSamples->setAutoFillBackground(false);
        lineEditBasicNSamples->setStyleSheet(QStringLiteral("background:white"));
        lineEditBasicNSamples->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEditBasicNSamples, 2, 0, 1, 1);

        label_14 = new QLabel(gridLayoutWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setFont(font);

        gridLayout->addWidget(label_14, 2, 2, 1, 1);

        lineEditStartPipetteNum = new QLineEdit(gridLayoutWidget);
        lineEditStartPipetteNum->setObjectName(QStringLiteral("lineEditStartPipetteNum"));
        lineEditStartPipetteNum->setFont(font);
        lineEditStartPipetteNum->setAutoFillBackground(false);
        lineEditStartPipetteNum->setStyleSheet(QStringLiteral("background:white"));
        lineEditStartPipetteNum->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEditStartPipetteNum, 3, 0, 1, 1);

        label_25 = new QLabel(gridLayoutWidget);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setFont(font);

        gridLayout->addWidget(label_25, 3, 2, 1, 1);

        label_13 = new QLabel(gridLayoutWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font);

        gridLayout->addWidget(label_13, 0, 2, 1, 1);

        lineEditHeadstageChannelNum = new QLineEdit(gridLayoutWidget);
        lineEditHeadstageChannelNum->setObjectName(QStringLiteral("lineEditHeadstageChannelNum"));
        lineEditHeadstageChannelNum->setFont(font);
        lineEditHeadstageChannelNum->setAutoFillBackground(false);
        lineEditHeadstageChannelNum->setStyleSheet(QStringLiteral("background:white"));
        lineEditHeadstageChannelNum->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEditHeadstageChannelNum, 4, 0, 1, 1);

        label_36 = new QLabel(gridLayoutWidget);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setFont(font);

        gridLayout->addWidget(label_36, 4, 2, 1, 1);

        lineEditVStimScreenNumber = new QLineEdit(gridLayoutWidget);
        lineEditVStimScreenNumber->setObjectName(QStringLiteral("lineEditVStimScreenNumber"));
        lineEditVStimScreenNumber->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEditVStimScreenNumber, 5, 0, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 5, 2, 1, 1);

        lineEditNumCurrentStepRepeats = new QLineEdit(gridLayoutWidget);
        lineEditNumCurrentStepRepeats->setObjectName(QStringLiteral("lineEditNumCurrentStepRepeats"));
        lineEditNumCurrentStepRepeats->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEditNumCurrentStepRepeats, 6, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 6, 2, 1, 1);

        lineEditBrainSurfaceAbsPos = new QLineEdit(gridLayoutWidget);
        lineEditBrainSurfaceAbsPos->setObjectName(QStringLiteral("lineEditBrainSurfaceAbsPos"));
        lineEditBrainSurfaceAbsPos->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEditBrainSurfaceAbsPos, 7, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 7, 2, 1, 1);

        checkBoxSlowRetract = new QCheckBox(groupBox);
        checkBoxSlowRetract->setObjectName(QStringLiteral("checkBoxSlowRetract"));
        checkBoxSlowRetract->setGeometry(QRect(10, 360, 161, 17));
        checkBoxSlowRetract->setChecked(true);
        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 250, 201, 101));
        radioButtonRampFeedback = new QRadioButton(groupBox_3);
        radioButtonRampFeedback->setObjectName(QStringLiteral("radioButtonRampFeedback"));
        radioButtonRampFeedback->setGeometry(QRect(20, 80, 161, 17));
        radioButtonRampFeedback->setChecked(true);
        radioButtonRamp = new QRadioButton(groupBox_3);
        radioButtonRamp->setObjectName(QStringLiteral("radioButtonRamp"));
        radioButtonRamp->setGeometry(QRect(20, 60, 131, 21));
        radioButtonRamp->setChecked(false);
        radioButtonZap = new QRadioButton(groupBox_3);
        radioButtonZap->setObjectName(QStringLiteral("radioButtonZap"));
        radioButtonZap->setGeometry(QRect(20, 20, 91, 21));
        radioButtonSuction = new QRadioButton(groupBox_3);
        radioButtonSuction->setObjectName(QStringLiteral("radioButtonSuction"));
        radioButtonSuction->setGeometry(QRect(20, 40, 131, 21));
        radioButtonSuction->setChecked(false);
        label_4 = new QLabel(AutopatcherSettingsWindow);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 430, 581, 31));
        label_4->setWordWrap(true);
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
        QWidget::setTabOrder(lineEditSkipExtraStep, lineEditNumSampsToWaitReleasePress);
        QWidget::setTabOrder(lineEditNumSampsToWaitReleasePress, lineEditSlowRetractSize);
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
        lineEditAdvMaxVar->setText(QApplication::translate("AutopatcherSettingsWindow", "0.5", 0));
        label_37->setText(QApplication::translate("AutopatcherSettingsWindow", "(MOhms) Hit Threshold to Skip the Extra Step", 0));
        label_39->setText(QApplication::translate("AutopatcherSettingsWindow", "(\302\265m) Slow retraction step size", 0));
        lineEditAdvDetectNSamps->setText(QApplication::translate("AutopatcherSettingsWindow", "3", 0));
        label_21->setText(QApplication::translate("AutopatcherSettingsWindow", "(MOhms) Maximum Clog Check R Increase", 0));
        label_38->setText(QApplication::translate("AutopatcherSettingsWindow", "(int) Number of samples to gather after dection before releasing positive pressure", 0));
        lineEditNumSampsToWaitReleasePress->setText(QApplication::translate("AutopatcherSettingsWindow", "10", 0));
        label_23->setText(QApplication::translate("AutopatcherSettingsWindow", "(MOhms) Threshold to Return to Neuron Hunt", 0));
        label_19->setText(QApplication::translate("AutopatcherSettingsWindow", "(MOhms) Maximum Acceptable Pipette Resistance", 0));
        lineEditAdvClogThresh->setText(QApplication::translate("AutopatcherSettingsWindow", "0.4", 0));
        lineEditAdvMaxR->setText(QApplication::translate("AutopatcherSettingsWindow", "9", 0));
        label_20->setText(QApplication::translate("AutopatcherSettingsWindow", "(MOhms) Maximum Acceptable Pipette Variation", 0));
        lineEditSkipExtraStep->setText(QApplication::translate("AutopatcherSettingsWindow", "1", 0));
        lineEditGigasealRetract->setText(QApplication::translate("AutopatcherSettingsWindow", "6", 0));
        label_40->setText(QApplication::translate("AutopatcherSettingsWindow", "(um) Retraction distance on gigaseal", 0));
        lineEditAdvNeuronDetectThresh->setText(QApplication::translate("AutopatcherSettingsWindow", "0.35", 0));
        label_22->setText(QApplication::translate("AutopatcherSettingsWindow", "(N) of Samples to Detect Neuron", 0));
        lineEditAdvMinR->setText(QApplication::translate("AutopatcherSettingsWindow", "3", 0));
        lineEditAdvReturnToHuntThresh->setText(QApplication::translate("AutopatcherSettingsWindow", "1", 0));
        label_18->setText(QApplication::translate("AutopatcherSettingsWindow", "(MOhms) Minimum Acceptable Pipette Resistance", 0));
        lineEditDelayAfterDescent->setText(QApplication::translate("AutopatcherSettingsWindow", "8", 0));
        label_41->setText(QApplication::translate("AutopatcherSettingsWindow", "(sec)  Delay After Descent to Start Depth", 0));
        label_42->setText(QApplication::translate("AutopatcherSettingsWindow", "(sec) Time to wait for the recording to stabilize after break in (3 min default)", 0));
        lineEditWaitForRecordingStabilize->setText(QApplication::translate("AutopatcherSettingsWindow", "120", 0));
        label_16->setText(QApplication::translate("AutopatcherSettingsWindow", "(kOhms) Neuron Detection Threshold ", 0));
        lineEditNumVisualStims->setText(QApplication::translate("AutopatcherSettingsWindow", "2", 0));
        label_43->setText(QApplication::translate("AutopatcherSettingsWindow", "Maximuim number of visual stimulation repeats", 0));
        lineEditSlowRetractSize->setText(QApplication::translate("AutopatcherSettingsWindow", "3", 0));
        lineEditNumBACCurrentInjRepeats->setText(QApplication::translate("AutopatcherSettingsWindow", "2", 0));
        label_44->setText(QApplication::translate("AutopatcherSettingsWindow", "Number of BAC firing current injection sweep (20 to 200 Hz) repeats", 0));
        groupBox->setTitle(QApplication::translate("AutopatcherSettingsWindow", "Basic Settings", 0));
        lineEditBasicStartDepth->setText(QApplication::translate("AutopatcherSettingsWindow", "560", 0));
        lineEditBasicStopDepth->setText(QApplication::translate("AutopatcherSettingsWindow", "850", 0));
        label_15->setText(QApplication::translate("AutopatcherSettingsWindow", "(\302\265m)  Stop Depth ", 0));
        lineEditBasicNSamples->setText(QApplication::translate("AutopatcherSettingsWindow", "7", 0));
        label_14->setText(QApplication::translate("AutopatcherSettingsWindow", "(N)  of Samples to Average", 0));
        lineEditStartPipetteNum->setText(QApplication::translate("AutopatcherSettingsWindow", "1", 0));
        label_25->setText(QApplication::translate("AutopatcherSettingsWindow", "(N) Starting Pipette Number", 0));
        label_13->setText(QApplication::translate("AutopatcherSettingsWindow", "(\302\265m)  Start Depth ", 0));
        lineEditHeadstageChannelNum->setText(QApplication::translate("AutopatcherSettingsWindow", "2", 0));
        label_36->setText(QApplication::translate("AutopatcherSettingsWindow", "Headstage Channel Num.", 0));
        lineEditVStimScreenNumber->setText(QApplication::translate("AutopatcherSettingsWindow", "1", 0));
        label->setText(QApplication::translate("AutopatcherSettingsWindow", "Screen Number for Visual Stim", 0));
        lineEditNumCurrentStepRepeats->setText(QApplication::translate("AutopatcherSettingsWindow", "3", 0));
        label_2->setText(QApplication::translate("AutopatcherSettingsWindow", "Number of current step repeats", 0));
        lineEditBrainSurfaceAbsPos->setText(QApplication::translate("AutopatcherSettingsWindow", "0", 0));
        label_3->setText(QApplication::translate("AutopatcherSettingsWindow", "(mm) Brain surface absolute position ", 0));
        checkBoxSlowRetract->setText(QApplication::translate("AutopatcherSettingsWindow", "Slow retract after recording", 0));
        groupBox_3->setTitle(QApplication::translate("AutopatcherSettingsWindow", "Break-In Algorithm Type", 0));
        radioButtonRampFeedback->setText(QApplication::translate("AutopatcherSettingsWindow", "Suction Ramp With Feedback", 0));
        radioButtonRamp->setText(QApplication::translate("AutopatcherSettingsWindow", "Suction Ramp Break In", 0));
        radioButtonZap->setText(QApplication::translate("AutopatcherSettingsWindow", "Zap break in", 0));
        radioButtonSuction->setText(QApplication::translate("AutopatcherSettingsWindow", "Suction break in", 0));
        label_4->setText(QApplication::translate("AutopatcherSettingsWindow", "By editing these values, any data logged by the current state will be lost.  Try to only adjust settings during the non-data-logging states (i.e. Aquiring Pipette, Removing Pipette).  This is a bug.  For now, just be careful or you'll lose data.", 0));
    } // retranslateUi

};

namespace Ui {
    class AutopatcherSettingsWindow: public Ui_AutopatcherSettingsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTOPATCHERSETTINGSWINDOW_H
