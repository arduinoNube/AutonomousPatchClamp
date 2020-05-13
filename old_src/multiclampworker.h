#ifndef MULTICLAMPWORKER_H
#define MULTICLAMPWORKER_H

#include <QObject>
#include <QCoreApplication>
#include <windows.h>
#include "AxMultiClampMsg.h"
#include <QTimer>


class MulticlampWorker : public QObject
{
    Q_OBJECT

    // find the first MultiClamp
    char szError[256];
    char szSerialNum[16];
    UINT uModel;
    UINT uCOMPortID;
    UINT uDeviceID;
    UINT uChannelID;
    int error;
    HMCCMSG h;      // Handle to the amplifier
    double scale;      // External Command Sensitivity scale (20mV/V)

    void DisplayErrorMsg();

    bool MMCisValid;
    QString path;

public:
    MulticlampWorker();
    ~MulticlampWorker();
    void autoFastCompensation();
    void autoSlowCompensation();
    void setMode(int mode);
    int findFirstMulticlamp();
    int findNextMulticlamp();
    bool getMMCisValid(){return MMCisValid;}
    double getCommandScale();
    void setCommandScale(double num);
    void setWholeCellCapComp(bool flag);
    void setPath(QString p);


signals:
    void multiclampInitReady();
    void multiclampInitError();
    void initComplete();
    void zapped();
    void switchPressure(int val);
    void autoOffsetComplete();
    
public slots:
    void init(int numMPCS);
    void setHoldingVoltage(double volt); // Be careful.  This function may change the mode briefly
    void setHoldingCurrent(double curr); // Be careful.  This function may changes the mode briefly
    void autoCorrectOffset();
    void check();
    void selectChannel(int id);
    void zap(double time);    
    void setHoldingVoltageChecked(bool flag);
    
};

#endif // MULTICLAMPWORKER_H
