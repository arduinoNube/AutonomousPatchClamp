#ifndef IC_RESTINGVOLTAGE_H
#define IC_RESTINGVOLTAGE_H

#include <QObject>
#include <state.h>
#include <QMessageBox>

class IC_RestingVoltage : public State
{
    Q_OBJECT
    QVector<double> rawDataLog;
    QMessageBox *dlg;
    double samplingRate;
public:
    IC_RestingVoltage(QObject *parent = 0);
    ~IC_RestingVoltage();
    void firstRun();

public slots:
    void pauseState(bool toggled);
    void haltState();
    void daq_initTaskReady();
    void daq_initTaskError();
    void multiclamp_setHoldingCurrentSafeComplete();
    void daq_rawDataReady(QVector<double> rawData);
    void setHardwareVals(HardwareSettingsWindow *hw_win);
private slots:
    void dialogClose();
};

#endif // IC_RESTINGVOLTAGE_H
