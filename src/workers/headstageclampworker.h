#ifndef HEADSTAGECLAMPWORKER_H
#define HEADSTAGECLAMPWORKER_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QTimer>
#include <QVector>
#include "serialworker.h"
#include "worker.h"

class HeadstageClampWorker : public SerialWorker
{
    Q_OBJECT
public:
    explicit HeadstageClampWorker(QObject *parent = 0);
    ~HeadstageClampWorker();
    int threaded;

signals:

public slots:
    void openClamp(bool sendEvent);
    void halfClamp(bool sendEvent);
    void closeClamp(bool sendEvent);
    void threadWire(bool sendEvent);
    void retractWire(bool sendEvent);

    void aboutToClose();
    void setHardwareVals(HardwareSettingsWindow *);
private:
    QString openClampCommand;
    QString closeClampCommand;
    QString partialCloseClampCommand;
    QString threadWireCommand;
    QString retractWireCommand;

private:
    void hardwareInit();
};

#endif // HEADSTAGECLAMPWORKER_H
