#ifndef ARDUINO_H
#define ARDUINO_H

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

class Arduino : public QObject
{
    Q_OBJECT
    QSerialPort *port;
    void sendSerialCommand(QString str);
    double highP,highV,lowP,lowV;
public:
    Arduino(QObject *parent = 0);
    ~Arduino();
    enum {PRESSURE_HIGHP,
          PRESSURE_LOWP,
          PRESSURE_ATM,
          PRESSURE_LOWV,
          PRESSURE_HIGHV};
    bool vFlag;

    
signals:
    void breakInFinished();
    void clearPipetteFinished();
    void arduinoInitReady();
    void arduinoInitError();
    
public slots:
    Q_INVOKABLE void switchBNC(bool on);

    Q_INVOKABLE void init(QString comPort);
    void switchPressure(int pres);
    void softwarePressure(bool flag);
    void setPressure(int num,double val);
    void breakIn(int time,int msWaitBetween,int numPulses);
    void breakInRamp(int time , int pressure);
    void closeArduinoPort();
};

#endif // ARDUINO_H
