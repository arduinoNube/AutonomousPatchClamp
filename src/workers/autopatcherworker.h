#ifndef AUTOPATCHERWORKER_H
#define AUTOPATCHERWORKER_H

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
//#include <QTimer>
#include <QVector>
#include "serialworker.h"
#include "worker.h"

class AutopatcherWorker : public SerialWorker
{
    Q_OBJECT
    // Pressure values
    double highP;
    double highV;
    double lowP;
    double lowV;
    QTimer *timer1;

public:
    AutopatcherWorker(QObject *parent = 0);
    ~AutopatcherWorker();

    enum {PRESSURE_HIGH_P,
              PRESSURE_LOW_P,
              PRESSURE_ATM,
              PRESSURE_LOW_V,
              PRESSURE_HIGH_V};

signals:
    void breakInFinished();
    void breakInRampFinished();

public slots:
    void switchBNC(bool on              , bool sendEvent);
    void switchPressure(int pres        , bool sendEvent);
    void softwarePressure(bool flag     , bool sendEvent);
    void setPressure(int num,double val , bool sendEvent);
    void breakIn(int time,int msWaitBetween,int numPulses);
    void breakInRamp(int time , int pressure);


    void breakInRampFeedback(int time);
    void stopRamp();
    void aboutToClose();
    void initInThread();
    void setHardwareVals(HardwareSettingsWindow *win);
private slots:
    void timer1_timeout();
    void moveThreadBack();
private:
    void hardwareInit();
};

#endif // AUTOPATCHERWORKER_H
