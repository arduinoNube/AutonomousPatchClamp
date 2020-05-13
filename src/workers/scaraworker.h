#ifndef SCARAWORKER_H
#define SCARAWORKER_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QTimer>
#include <QVector>
#include "serialworker.h"
#include "worker.h"

class SCARAWorker : public SerialWorker
{
    Q_OBJECT
public:
    explicit SCARAWorker(QObject *parent = 0);
    ~SCARAWorker();

signals:
    void calibFinished();

public slots:
    void rotateArm(int armNumber, bool direction, int numSteps);
    void calibrate();
    void enableEndEffector(bool enable, bool sendEvent);
    void openEndEffector(bool sendEvent);
    void partialCloseEndEffector(bool sendEvent);
    void closeEndEffector(bool sendEvent);
    void moveNext(bool sendEvent);
    Q_INVOKABLE void fill1(bool sendEvent);
    Q_INVOKABLE void fill2(bool sendEvent);
    Q_INVOKABLE void fill3(bool sendEvent);
    Q_INVOKABLE void dispenseHighPressure(int msec,bool sendEvent);
    void resetCarousel();
    void carouselNextPipette(bool sendEvent);

    void powerDown();
    void powerUp();
    void peltier(bool on);
    void fan(bool on);
    void aboutToClose();
    void calibrateCarousel(bool sendEvent);
    void setHardwareVals(HardwareSettingsWindow *);
private:
    void hardwareInit();
};

#endif // SCARAWORKER_H
