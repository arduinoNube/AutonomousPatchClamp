#ifndef THORWORKER_H
#define THORWORKER_H

#include <QObject>
#include <QAxWidget>
#include "worker.h"

class ThorWorker : public Worker
{
    Q_OBJECT
    QVariant serialNum;
    QVariant chanID;
    QAxWidget *motor;
    float motorPosition;
    void enableMotor();
    double fastVel;  // not used at the moment
    double slowVel;  // not used at the moment

public:
    explicit ThorWorker(QObject *parent = 0);
    ~ThorWorker();

signals:
    void initReady();
    void initError();
    void calibFinished();
    void moveMotorFinished();
    void currentMotorPosition(float position);

public slots:
    void init(int serialNum);
    void calibrate();
    void moveMotorAbsolute(float pos, float vel);
    void moveMotorAbsoluteWait(float pos, float vel);
    void moveMotorRelative(float pos, float vel);
    float getPosition() const;
    void getPosition(bool sendEvent);
    void haltMotor();
    void aboutToClose();
    void setHardwareVals(HardwareSettingsWindow *hw_win);
private slots:
    void homeFinished(int i);
    void moveFinished(int i);
};

#endif // THORWORKER_H
