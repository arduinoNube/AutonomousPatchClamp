#ifndef HARDWAREINIT_H
#define HARDWAREINIT_H

#include <QObject>
#include <QString>
#include <state.h>
#include <ui/hardwaresettingswindow.h>

class HardwareInit : public State
{
    Q_OBJECT
    int autopatcherInit;
    int scaraInit;
    int fillerInit;
    int headstageClampInit;
    int multiclampInit;
    int thorInit;
    int daqInit;
    int visualInit;
    int lengthInit;

    QString a_COM;
    QString s_COM;
    QString f_COM;
    QString h_COM;
    int multiclampHeadstageNumber;         // Headstage number to use
    QString multiclampPath;    // Path to MC700B.exe
    QString devName;        // device name i.e. "Dev1"
    int thorSerial;  // ThorLabs T-Cube Serial number
    int thorSlowVel; // Velocity for slow movements
    int thorFastVel; // Velocity used for fast movements

    QString visualStimIP;
    QString visualStimPort;

    QTimer timer1;

    int setNumStepsScaraAdjust;

public:
    HardwareInit(QObject *parent = 0);
    ~HardwareInit();
    void setHardwareVals(HardwareSettingsWindow *hw_win);

    void firstRun();

public slots:
    void pauseState(bool toggled);
    void haltState();

private slots:

    // FROM HERE DOWN IS PROCEDURAL OR PARALLEL
    void autopatcher_initReady()        { autopatcherInit = 1;      qDebug() << "autopatcherInit ready.";}
    void autopatcher_initError()        { autopatcherInit = -1;     qDebug() << "autopatcherInit error.";}
    void headstageClamp_initReady()     { headstageClampInit = 1;   qDebug() << "headstageInit ready.";}
    void headstageClamp_initError()     { headstageClampInit = -1;  qDebug() << "headstageInit error.";}
    void scara_initReady()              { scaraInit = 1;            qDebug() << "scaraInit ready.";}
    void scara_initError()              { scaraInit = -1;           qDebug() << "scaraInit error.";}
    void filler_initReady()             { fillerInit= 1;            qDebug() << "fillerInit ready.";}
    void filler_initError()             { fillerInit= -1;           qDebug() << "fillerInit error.";}
    void thorLabsMotor_initReady()      { thorInit = 1;             qDebug() << "thorInit ready.";}
    void thorLabsMotor_initError()      { thorInit = -1;            qDebug() << "thorInit error.";}
    void multiclamp_initReady()         { multiclampInit = 1;       qDebug() << "multiclampInit ready.";}
    void multiclamp_initError()         { multiclampInit = -1;      qDebug() << "multiclampInit error.";}
    void daq_initReady()                { daqInit = 1;              qDebug() << "daqInit ready.";}
    void daq_initError()                { daqInit = -1;             qDebug() << "daqInit error.";}
    void visual_initReady()             { visualInit = 1;           qDebug() << "visualInit ready.";}
    void visual_initError()             { visualInit = -1;          qDebug() << "visualInit error.";}
    void length_initReady()             { lengthInit = 1;           qDebug() << "lengthInit ready.";}
    void length_initError()             { lengthInit = -1;          qDebug() << "lengthInit error.";}

    void checkInit();

signals:

};

#endif // HARDWAREINIT_H
