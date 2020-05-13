#include "autopatchersettingswindow.h"
#include "ui_autopatchersettingswindow.h"
#include <QKeyEvent>
#include <QDebug>
#include <QDoubleValidator>
#include <QIntValidator>
#include <MyValidator.h>

AutopatcherSettingsWindow::AutopatcherSettingsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AutopatcherSettingsWindow)
{
    ui->setupUi(this);
    ui->lineEditAdvClogThresh->         setValidator(new MyValidator(0,999,2,this));
    ui->lineEditAdvDetectNSamps->       setValidator(new QIntValidator(0,9,this));
    ui->lineEditAdvMaxR->               setValidator(new MyValidator(0,999,2,this));
    ui->lineEditAdvMaxVar->             setValidator(new MyValidator(0,999,2,this));
    ui->lineEditAdvMinR->               setValidator(new MyValidator(0,999,2,this));
    ui->lineEditDelayAfterDescent->     setValidator(new QDoubleValidator(0,30,2,this));
    ui->lineEditAdvNeuronDetectThresh-> setValidator(new MyValidator(0,999,2,this));
    ui->lineEditAdvReturnToHuntThresh-> setValidator(new MyValidator(0,999,2,this));
    ui->lineEditBasicNSamples->         setValidator(new QIntValidator(0,16,this));
    ui->lineEditBasicStartDepth->       setValidator(new QIntValidator(0,9999,this));
    ui->lineEditBasicStopDepth->        setValidator(new QIntValidator(0,9999,this));
    ui->lineEditHeadstageChannelNum->   setValidator(new QIntValidator(0,16,this));
    ui->lineEditVStimScreenNumber->     setValidator(new QIntValidator(1,2,this));
    ui->lineEditNumCurrentStepRepeats-> setValidator(new QIntValidator(1,999,this));
    ui->lineEditNumBACCurrentInjRepeats-> setValidator(new QIntValidator(0,999,this));
    ui->lineEditNumSampsToWaitReleasePress->setValidator(new QIntValidator(0,999,this));  // Minimum value of 8 unless the user wants to skip the check
    ui->lineEditSkipExtraStep->         setValidator(new MyValidator(0,999,2,this));
    ui->lineEditStartPipetteNum->       setValidator(new QIntValidator(1,40,this));
    ui->lineEditSlowRetractSize->       setValidator(new MyValidator(0,999,2,this));
    ui->lineEditBrainSurfaceAbsPos->    setValidator(new MyValidator(-25,0,3,this));
    ui->lineEditWaitForRecordingStabilize->setValidator(new QIntValidator(0,3600,this));
    ui->lineEditNumVisualStims->        setValidator(new QIntValidator(0,100,this));
    registerGuiValues();
}

AutopatcherSettingsWindow::~AutopatcherSettingsWindow()
{
    delete ui;
}

void AutopatcherSettingsWindow::setVals(AutopatcherSettings vals)
{
        ui->lineEditBasicStartDepth->setText(QString::number(vals.startDepth));
        ui->lineEditBasicStopDepth->setText(QString::number(vals.stopDepth));
        ui->lineEditBasicNSamples->setText(QString::number(vals.nPeriods));
        ui->lineEditAdvMaxR->setText(QString::number(vals.maxR));
        ui->lineEditAdvMinR->setText(QString::number(vals.minR));
        ui->lineEditAdvMaxVar->setText(QString::number(vals.maxVar));
        ui->lineEditDelayAfterDescent->setText(QString::number(vals.delayAfterDescent));
        ui->lineEditAdvClogThresh->setText(QString::number(vals.clogThresh));
        ui->lineEditAdvNeuronDetectThresh->setText(QString::number(vals.neuronThresh));
        ui->lineEditSkipExtraStep->setText(QString::number(vals.hitNoStepThresh));
        ui->lineEditAdvDetectNSamps->setText(QString::number(vals.nDetectSamps));
        ui->lineEditAdvReturnToHuntThresh->setText(QString::number(vals.returnThresh));
        ui->lineEditStartPipetteNum->setText(QString::number(vals.startingPipetteNumber));
        ui->lineEditHeadstageChannelNum->setText(QString::number(vals.headstageNum));
        ui->lineEditVStimScreenNumber->setText(QString::number(vals.screenNumber));
        ui->lineEditNumCurrentStepRepeats->setText(QString::number(vals.numCurrentStepRepeats));
        ui->lineEditNumBACCurrentInjRepeats->setText(QString::number(vals.numBACCurrentInjRepeats));
        ui->lineEditNumSampsToWaitReleasePress->setText(QString::number(vals.numSampsToWaitToReleasePress));
        ui->lineEditSlowRetractSize->setText(QString::number(vals.slowRetractStepSize));
        ui->lineEditBrainSurfaceAbsPos->setText(QString::number(vals.brainHeight));
        ui->lineEditWaitForRecordingStabilize->setText(QString::number(vals.waitForRecordingStabilization));
        ui->lineEditNumVisualStims->setText(QString::number(vals.numVisualStims));

        qWarning() << vals.breakInType;
        switch(vals.breakInType)
        {
        case 0:  // Zap Break In
            ui->radioButtonZap->setChecked(true);
            break;

        case 1:  // Suction Break In
            ui->radioButtonSuction->setChecked(true);
            break;

        case 2:  // Ramp Break In
            ui->radioButtonRamp->setChecked(true);
            break;
        }
        ap_data = vals;
}

bool AutopatcherSettingsWindow::registerGuiValues()
{
    int flag(0);
    bool err(1);
    AutopatcherSettings ap_tmp = ap_data;

    ap_tmp.brainHeight             = ui->lineEditBrainSurfaceAbsPos->text().toFloat(&err);
    if(err==0){ errs.push_back("Brain Surface Pos."); err = 0; flag = 1;};
    ap_tmp.startDepth              = ui->lineEditBasicStartDepth->text().toFloat(&err);
    if(err==0){ errs.push_back("Start Depth"); err = 0; flag = 1;};
    ap_tmp.stopDepth               = ui->lineEditBasicStopDepth->text().toFloat(&err);
    if(err==0){ errs.push_back("Stop Depth"); err = 0; flag = 1;};
    ap_tmp.nPeriods                = ui->lineEditBasicNSamples->text().toInt(&err);
    if(err==0){ errs.push_back("N Samples to Average"); err = 0; flag = 1;};
    ap_tmp.maxR                    = ui->lineEditAdvMaxR->text().toDouble(&err);
    if(err==0){ errs.push_back("Maximum Acceptable Resistance"); err = 0; flag = 1;};
    ap_tmp.minR                    = ui->lineEditAdvMinR->text().toDouble(&err);
    if(err==0){ errs.push_back("Minimum Acceptable Resistance"); err = 0; flag = 1;};
    ap_tmp.maxVar                  = ui->lineEditAdvMaxVar->text().toDouble(&err);
    if(err==0){ errs.push_back("Maximum Acceptable Variation"); err = 0; flag = 1;};
    ap_tmp.delayAfterDescent       = ui->lineEditDelayAfterDescent->text().toDouble(&err);
    if(err==0){ errs.push_back("Delay After Descent to Start Depth"); err = 0; flag = 1;};
    ap_tmp.clogThresh              = ui->lineEditAdvClogThresh->text().toDouble(&err);
    if(err==0){ errs.push_back("Maximum Clog Check Threshold"); err = 0; flag = 1;};
    ap_tmp.neuronThresh            = ui->lineEditAdvNeuronDetectThresh->text().toDouble(&err);
    if(err==0){ errs.push_back("Neuron Detection Threshold"); err = 0; flag = 1;};
    ap_tmp.hitNoStepThresh         = ui->lineEditSkipExtraStep->text().toDouble(&err);
    if(err==0){ errs.push_back("Hit Threshold to Skip Extra Step"); err = 0; flag = 1;};
    ap_tmp.nDetectSamps            = ui->lineEditAdvDetectNSamps->text().toInt(&err);
    if(err==0){ errs.push_back("N of Samples to Detect Neuron"); err = 0; flag = 1;};
    ap_tmp.returnThresh            = ui->lineEditAdvReturnToHuntThresh->text().toDouble(&err);
    if(err==0){ errs.push_back("Threshold to Return to Neuron Hunt"); err = 0; flag = 1;};
    ap_tmp.startingPipetteNumber      = ui->lineEditStartPipetteNum->text().toInt(&err);
    if(err==0){ errs.push_back("Starting Pipette Number"); err = 0; flag = 1;};
    ap_tmp.headstageNum            = ui->lineEditHeadstageChannelNum->text().toInt(&err);
    if(err==0){ errs.push_back("Headstage Number"); err = 0; flag = 1;};
    ap_tmp.screenNumber            = ui->lineEditVStimScreenNumber->text().toInt(&err);
    if(err==0){ errs.push_back("Visual Stimulation Screen Number"); err = 0; flag = 1;};
    ap_tmp.numCurrentStepRepeats   = ui->lineEditNumCurrentStepRepeats->text().toInt(&err);
    if(err==0){ errs.push_back("Number of Current Step Repeats"); err = 0; flag = 1;};
    ap_tmp.numBACCurrentInjRepeats   = ui->lineEditNumBACCurrentInjRepeats->text().toInt(&err);
    if(err==0){ errs.push_back("Number of BAC Current Injection Sweep Repeats"); err = 0; flag = 1;};
    ap_tmp.numSampsToWaitToReleasePress  = ui->lineEditNumSampsToWaitReleasePress->text().toInt(&err);
    if(err==0){ errs.push_back("Time to wait after detection..."); err = 0; flag = 1;};
    ap_tmp.slowRetractStepSize  = ui->lineEditSlowRetractSize->text().toDouble(&err);
    if(err==0){ errs.push_back("Slow Retraction Step Size"); err = 0; flag = 1;};
    ap_tmp.waitForRecordingStabilization  = ui->lineEditWaitForRecordingStabilize->text().toDouble(&err);
    if(err==0){ errs.push_back("Time to wait after breaking for stabilization"); err = 0; flag = 1;};
    ap_tmp.numVisualStims  = ui->lineEditNumVisualStims->text().toDouble(&err);
    if(err==0){ errs.push_back("Maximum number of visual stimulations"); err = 0; flag = 1;};

    if(ui->radioButtonZap->isChecked())
    {
        ap_tmp.breakInType = 0;
    }
    else if(ui->radioButtonSuction->isChecked())
    {
        ap_tmp.breakInType = 1;
    }
    else if(ui->radioButtonRamp->isChecked())
    {
        ap_tmp.breakInType = 2;
    }
    else if(ui->radioButtonRampFeedback->isChecked())
    {
        ap_tmp.breakInType = 3;
    }

    if(ui->checkBoxSlowRetract->isChecked()) ap_tmp.slowRetractFlag = 1;
    else ap_tmp.slowRetractFlag = 0;

//    qWarning() << "Retrieving data from radio button" << ap_data.breakInType;
    if(flag == 1)
    {
        // Dialog Explaining Error
        qWarning() << "Errors:";
        for(int i=0; i<errs.size(); i++)
        {
            qWarning() << errs[i];
        }
        errs.clear();
        return false;
    }
    else
    {
        ap_data = ap_tmp;
        return true;
    }
}

void AutopatcherSettingsWindow::keyReleaseEvent(QKeyEvent* e)
{
    if(e->key() == Qt::Key_Enter || e->key() == Qt::Key_Return)
    {
        if(ui->pushButtonOk->hasFocus())
        {
            ui->pushButtonOk->animateClick(200);
            this->close();
        }
        if(ui->pushButtonCancel->hasFocus())
        {
            ui->pushButtonCancel->animateClick(200);
            this->close();
        }
    }
    else if(e->key() == Qt::Key_Escape)
    {
        this->close();
    }
}

void AutopatcherSettingsWindow::closeEvent(QCloseEvent *e)
{
    e->accept();
    this->close();
    emit windowClosed();
}

void AutopatcherSettingsWindow::on_pushButtonOk_clicked()
{
    if(registerGuiValues())
    {
        this->close();
    }
}

void AutopatcherSettingsWindow::on_pushButtonCancel_clicked()
{
    qWarning() << "Closing window";
    this->close();
}

void AutopatcherSettingsWindow::showEvent(QShowEvent *e)
{
    QWidget::showEvent(e);
    ui->pushButtonCancel->setFocus();
}

AutopatcherSettings AutopatcherSettingsWindow::getVals()
{
    return ap_data;
}


void AutopatcherSettingsWindow::on_lineEditNumSampsToWaitReleasePress_textChanged(const QString &arg1)
{
    if(!arg1.isEmpty())
    {
        if(arg1.toInt() <8)
        {
            ui->lineEditNumSampsToWaitReleasePress->setText("0");
        }
    }
}
