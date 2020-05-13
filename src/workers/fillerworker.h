#ifndef FILLERWORKER_H
#define FILLERWORKER_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QTimer>
#include <QVector>
#include "serialworker.h"
#include "worker.h"

class FillerWorker : public SerialWorker
{
    Q_OBJECT
public:
    explicit FillerWorker(QObject *parent = 0);
    ~FillerWorker();

signals:

public slots:

    void aspirateVolume(float volume, bool sendEvent);
    void dispenseVolume(float volume, bool sendEvent);
    Q_INVOKABLE void enablePressureControl(bool flag, bool sendEvent);

    void aboutToClose();
    void setHardwareVals(HardwareSettingsWindow *);
private:
    void hardwareInit();
};

#endif // FILLERWORKER_H
