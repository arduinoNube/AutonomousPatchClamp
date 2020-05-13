#ifndef MULTICLAMPWORKER_H
#define MULTICLAMPWORKER_H

#include <QObject>
#include <QCoreApplication>
#include <windows.h>
#include "AxMultiClampMsg.h"
#include <QTimer>
#include "worker.h"


class MulticlampWorker : public Worker
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
    double scaleVC; // External Command Sensitivity scale (20mV/V)
    double scaleIC; // External Command Sensitivity scale (400pA/V)

    void DisplayErrorMsg();

    bool MMCisValid;
    QString path;


public:
    MulticlampWorker();
    ~MulticlampWorker();
    int findFirstMulticlamp();
    int findNextMulticlamp();
    bool getMMCisValid(){return MMCisValid;}
    double getCommandScale();
    void setCommandScale(double num);
    void setPath(QString p);


signals:
    void initReady();
    void initError();
    void initComplete();
    void zapped();
    void switchPressure(int val);
    void autoOffsetComplete();
    void autoFastCapacitanceComplete();
    void setHoldingVoltageSafeComplete();
    void setHoldingCurrentSafeComplete();
    void pipetteCapacitanceCompensationValue(double val);
    void holdingCurrentCheckedComplete();
    void setBridgeBalanceComplete();
    void getBridgeBalanceComplete(double resMOhms);

    
public slots:
    void init(int numMPCS,QString path);
    void setMode(int mode);

    // Be careful.  This function may change the mode briefly but should always work.
    // If the amplifier is not in voltage clamp, it will switch to voltage clamp,
    // change the holding voltage and then switch back to whichever mode it was in
    // before issuing this command.
    void setHoldingVoltageSafe(double volt,bool sendEvent);

    // Be careful.  This function may set the voltage on the wrong channel and
    // the wrong mode. It is the user's responsibility to make sure it is voltage
    // clamp and the proper channel is selected.  It is optimized for speed.
    void setHoldingVoltageRaw(double volt);

    // Be careful.  This function may changes the mode briefly but should always work.
    // If the amplifier is not in current clamp, it will switch to current clamp,
    // change the holding current and then switch back to whichever mode it was in
    // before issuing this command.
    void setHoldingCurrentSafe(double curr,bool sendEvent);

    // Be careful.  This function may set the current on the wrong channel or even
    // set the voltage in voltage clamp if the wrong mode is selected.  It is
    // optimized for speed the wrong mode. It is the user's responsibility to make
    // sure it is current clamp and the proper channel is selected.
    void setHoldingCurrentRaw(double curr);

    void autoCorrectOffset();
    void selectChannel(int id);
    void zap(double time);    
    void setHoldingVoltageChecked(bool flag);    
    void setHoldingCurrentChecked(bool flag, bool sendEvent = 0);
    void autoSlowCapacitance();
    void autoFastCapacitance();
    double getFastCapacitanceValue();
    void enablePipetteCapacitanceCompensation(bool flag);
    void setPipetteCapacitanceCompensation(double val);
    void setFastCapacitanceValue(double val);
    void autoBridgeBalance();
    void setBridgeBalance(double resMOhms, bool sendEvent);
    void getPipetteCapacitanceCompensation();
    void aboutToClose();
    void injectSlowCurrentEnable(bool flag);
    void injectSlowCurrentSetTimeConstant(double time);
    void injectSlowCurrentSetVoltage(double volt);
    void leakSubtractionChecked(bool checked);
    void setHardwareVals(HardwareSettingsWindow *);
    void getBridgeBalance();
    void setWholeCellChecked(bool flag);
    void zapWithDelay(double zapTimeSec, int delayTimeMs);
};

#endif // MULTICLAMPWORKER_H
