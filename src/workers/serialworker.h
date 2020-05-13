#ifndef SERIALWORKER_H
#define SERIALWORKER_H

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QTimer>
#include <QVector>
#include <worker.h>

class SerialWorker : public Worker
{
    Q_OBJECT
protected:
    QString workerName;
    QSerialPort *port;
    QVector<QString> pendingCommands;
    QVector<bool> pendingCommandsResponseFlags;
    QByteArray msg;
    void sendSerialCommand(QString str, bool sendEvent);
    void sendNextCommand(QString str);
    void closePort();
    virtual void hardwareInit() = 0;  // This runs after the COM port is opened
    bool idle;
public:
    explicit SerialWorker(QObject *parent = 0);
    ~SerialWorker();

signals:    
    void initReady();
    void initError();
    void commandFinished();

public slots:
    void init(QString comPort);
private slots:
    void checkCommandFinished();
};

#endif // SERIALWORKER_H
