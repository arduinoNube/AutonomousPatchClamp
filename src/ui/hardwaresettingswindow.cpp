#include "hardwaresettingswindow.h"
#include "ui_hardwaresettingswindow.h"
#include <QDebug>

HardwareSettingsWindow::HardwareSettingsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HardwareSettingsWindow)
{
    ui->setupUi(this);
    ui->lineEditMulticlampHeadstageNum->        setValidator(new QIntValidator(1,2,this));
    ui->lineEditThorSerial->                    setValidator(new QIntValidator(0,99999999,this));
    ui->lineEditThorSlowVel->                   setValidator(new QIntValidator(0,9999,this));
    ui->lineEditThorFastVel->                   setValidator(new QIntValidator(0,10,this));
    ui->lineEditDAQSampRate->                   setValidator(new QIntValidator(1,50000,this));
    ui->lineEditHighP->                         setValidator(new QDoubleValidator(0,999,0,this));
    ui->lineEditLowP->                          setValidator(new QDoubleValidator(0,99.9,1,this));
    ui->lineEditHighV->                         setValidator(new QDoubleValidator(0,999,0,this));
    ui->lineEditLowV->                          setValidator(new QDoubleValidator(0,99.9,1,this));
    registerGUIValues(); // The default values for all the variables are what you see in the GUI.
}

HardwareSettingsWindow::~HardwareSettingsWindow()
{
    delete ui;
}

void HardwareSettingsWindow::on_pushButtonOk_released()
{
    if(registerGUIValues())
    {
        this->close();
        emit windowClosed();
    }
    else
    {
        qWarning() << "Error in one of the fields";
    }
}

bool HardwareSettingsWindow::registerGUIValues()
{
    a_COM                       = ui->lineEditAutopatcherCOM->text();
    s_COM                       = ui->lineEditSCARACOM->text();
    f_COM                       = ui->lineEditFillerCOM->text();
    h_COM                       = ui->lineEditHeadstageCOM->text();
    multiclampHeadstageNumber   = ui->lineEditHeadstageCOM->text().toInt();
    multiclampPath              = ui->lineEditMulticlampPath->text();
    devName                     = ui->lineEditDAQDevName->text();
    thorSerial                  = ui->lineEditThorSerial->text().toInt();
    thorSlowVel                 = ui->lineEditThorSlowVel->text().toInt();
    thorFastVel                 = ui->lineEditThorFastVel->text().toInt();
    visualStimIP                = ui->lineEditVisualIP->text();
    visualStimPort              = ui->lineEditVisualPort->text();
    daqSampRate                 = ui->lineEditDAQSampRate->text().toInt();
    highP                       = ui->lineEditHighP->text().toDouble();
    lowP                        = ui->lineEditLowP->text().toDouble();
    highV                       = ui->lineEditHighV->text().toDouble();
    lowV                        = ui->lineEditLowV->text().toDouble();
    // qWarning() << highP << lowP << highV << lowV;
    return true;
}

void HardwareSettingsWindow::on_pushButtonCancel_released()
{
    this->close();
}
