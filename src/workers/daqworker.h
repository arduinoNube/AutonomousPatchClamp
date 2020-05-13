#ifndef DAQWORKER_H
#define DAQWORKER_H

#include <QObject>
#include <QTimer>
#include <daqmx_libs/NIDAQmx.h>
#include <QMutex>
#include <QVector>
#include "worker.h"

class DAQWorker : public Worker
{
    Q_OBJECT

    // Task Handles
    TaskHandle  AItaskHandle;              // The handles for each task on the DAQ.
    TaskHandle  AOtaskHandle;
    TaskHandle  DOtaskHandle;
    TaskHandle  COtaskHandle;
    QString     devName;
    double      samplingRate;
    double      samplingRateTmp;            // Temporary sampling rate to store the new desired sampling rate while the current task finishes.
    double      dtyCycle;                  //
    int         dataAcquisitionType;       // This tells the raw acquire function which types of tasks are running and how to process the data
    QTimer      *acquireTimer;             // This timer times the acquisition intervals to stay ahead of the filling buffer on the DAQ
    QVector<double> buffer1, buffer2;
    // Flags
    QMutex mute;                           // Thread data locking variables
    bool taskReady;
    bool taskRunning;
    bool taskLock;
    double additiveFudgeV;
    double bias;

    // TYPES OF ACQUISITION
    // (1) Resistance Check (triggered 1 second 10 Hz square wave)
    //      1. when triggered, send out the same square wave
    //      2. when finished, send the resistance valud back to the GUI
    unsigned int    resCheckNPeriods;      // Number of periods in the AO square wave
    double          resCheckAmplitude;     // Amplitude of AO square wave
    double          resCheckFreq;          // 10 Hz AO square wave
    unsigned int    resCheckAOBuffSize;    // The actual buffer is temporary and is a difference size than the AI buffer
    unsigned int    resCheckAIBuffSize;    // should be less than samplingRate/10
    float64         *resCheckAIBuffer;     // One buffer for the raw data, another for the trigger detection
    QVector<double> resCheckDataBuffer;     // Buffer that stores the raw data after triggering until it get's all the data that is sampled simultaneously to the triggered analog output waveform


    // (2) Break In detection (continuous 1 period of 100 Hz square wave)
    //      1. Continuously send resistance measurements from the square wave to the GUI until stopped
    unsigned int    breakInNPeriods;       // Number of periods in the AO square wave
    double          breakInAmplitude;      // Amplitude of AO square wave
    double          breakInFreq;           // Frequency of AO square wave
    unsigned int    breakInAIAOBuffSize;   // This value must be an integer (one period only) and an even number. The buffers for continuous tasks are the same size as the AO buffer
    float64         *breakInAIBuffer;      // It also determines the plot update rate as one complete buffer is sent to the GUI at a time


    // (3) Membrane test (continuous 1 period of 50 Hz square wave)
    //      1. Continuously send membrane parameters to the GUI until stopped
    unsigned int    mTestNPeriods;         // Number of periods in the AO square wave
    double          mTestAmplitude;        // Amplitude of AO square wave
    double          mTestFreq;             // Frequency of AO square wave
    unsigned int    mTestAIAOBuffSize;     // Buffer size for the membrane test task.  This value must be an integer (one period only)
                                           // and an even number. The buffers for continuous tasks are the same size as the AO buffer
    float64         *mTestAIBuffer;        //

    // (4) Current injection (triggered a DC pulse with varying amplitude and duration)
    //      1. when triggered, change the amplitude of the DC pulse and send it out
    //      2. when finished, send the data back to the GUI
    double          currInjAmplitude;       // The amplitude of the injected current
    double          currInjTime;            // The length of the current injection in milliseconds
    int             currInjAOBuffSize;      // Buffer size for the analog output
    int             currInjAIBuffSize;      // AI buffer size
    float64         *currInjAIBuffer;       // AI buffer
    QVector<double> currInjDataBuffer;      // Buffer that stores the raw data after triggering until it get's all the data that is sampled simultaneously to the triggered analog output waveform

    // (5) BAC Current injection (triggered a train of 2 ms pulses to induce layer 5 BAC firing, with variable frequency and amplitude)
    int             bacCurrInjNumPulses;    //
    double          bacCurrInjAmplitude;    //
    double          bacCurrInjPulseWidth;   //
    double          bacCurrInjFrequency;    //
    double          bacCurrInjFrequencyMax; // constant
    double          bacCurrInjFrequencyMin; // constant
    int             bacCurrInjAOBuffSize;   //
    int             bacCurrInjAIBuffSize;   //
    float64         *bacCurrInjAIBuffer;    //
    QVector<double> bacCurrInjDataBuffer;   //

    // (6) Current Clamp Membrane test (continuous 1 period of 150 Hz square wave)
    //      1. Continuously send membrane parameters to the GUI until stopped
    unsigned int ic_mTestNPeriods   = 1;                        // Number of periods in the AO square wave
    double ic_mTestAmplitude        = 500*amplifierScaleIC;           // pA Amplitude of AO square wave (500 pA default)
    double ic_mTestFreq             = 150;                            // Frequency of AO square wave.  (150 Hz default)
    int ic_mTestAIAOBuffSize        = round(samplingRate/ic_mTestFreq);  // Buffer size for the current clampmembrane test task.  This value must be an integer (one period only)
                                                                    // and an even number. The buffers for continuous tasks are the same size as the AO buffer
    float64 *ic_mTestAIBuffer;

    // Data processing parmeters
    double          convertMV2I;           // conversion variable to convert from measured voltage to current.
    double          convertMV2V;           // converts the amplifier output voltage read by the daq to mV

    double          amplifierScaleVC;      // External command sensitivity from the amplifier (voltage clamp)
    double          amplifierScaleIC;      // External command sensitivity from the amplifier (current clamp)

    QVector<double> aveMemTestVals;        // The access resistance, membrane resistance, etc.
    int             numPeriodsMemTestAve;  // The number of periods to average together to calculate the membrane statistics
    int             numberOfMembraneTestVariables; // The number of membrane test variables that are returned.
    int fff;

    /* This is the actual code that specifies which values are in which position
     * vals[0] = Cm;
     * vals[1] = Rm*pow(10,6);
     * vals[2] = Ra*pow(10,6);
     * vals[3] = (Tau1+Tau2)/2*pow(10,6);
     * vals[4] = (Hi1-Hi2)/2 + 12.75;    // Holding current.  12.75 is a fudge factor.  I'm not sure why it needs it.
    */

    bool printDAQError(int32 error);
    void checkForResistanceValue(float64 *buffer, int buffSize);
    void checkForCurrentInj(QVector<double> dataBuff, QVector<double> triggerBuff);
    void checkForBACCurrentInj(QVector<double> dataBuff, QVector<double> triggerBuff);
    double calcResistanceAmplitude();
    void GenSqrWave    (double freq, double amplitude, int periods, double rate, double sqrWave[]);
    void GenSqrWaveCont(double freq, double amplitude, int periods, double rate, double sqrWave[]);
    void GenCurrInj(double amplitude, double msTime, double samplingRate, double *AOdata);
    void GenCurrInjBAC(double amplitude, double pulseWidthMs, int numPulses, double freq, double samplingRate, double *AOdata);

    QVector<double> calculateMembraneParams(QVector<double> buff1, QVector<double> buff2);
    QVector<double> exponentialFit(QVector<double> buff, double Hi, int s, int f);
    void initContinuous(double sampRate, int AIAOBuffSize, double AOData[]);
    void initTriggerable(double sampRate, int AIbuffSize, int numAIChannels, int AOBuffSize, double AOData[]);

    void setupConstants();
public:
    explicit DAQWorker(QObject *parent = 0);
    ~DAQWorker();

    // Methods
    void    setAmplifierScaleVC(double scale);
    void    setAmplifierScaleIC(double scale);
    double  getSamplingRate();
    void    getRawData(QVector<double> *data);
    void    setNPeriods(int n) { resCheckNPeriods = n;}

    // ENUM
    enum {
            TASKTYPE_RESISTANCE_CHECK,
            TASKTYPE_BREAK_IN_LOOP,
            TASKTYPE_MEMBRANE_TEST,
            TASKTYPE_CURRENT_INJECTION,
            TASKTYPE_BAC_CURRENT_INJECTION,
            TASKTYPE_IC_MEMBRANE_TEST
    };

    double getCurrInjAmplitude() const;



signals:
    void initReady();
    void initError();

    void initTaskReady();
    void initTaskError();

    //void taskType(int taskType);

    void rawDataReady();
    void rawDataReady(QVector<double>);
    void resDataReady(double res);
    void currInjDataReady(QVector<double>);
    void memTestValsReady(QVector<double> vals);
    void bacCurrInjDataReady(QVector<double>);
    void updateMemTestVals(QVector<double> mTestVals);
    void taskIsRunning(int flag);

public slots:    
    void aboutToClose();
    void initInThread();
    void init(QString devName);
    Q_INVOKABLE void setDevName(QString name){ devName = name;}

    void initTask(int taskType);
    //void sendTaskType();  not needed.  It only takes a few hundered msec to reinitialize the daq.
    void startTask();
    void stopTask();
    void trigger();          // Triggers the square wave output for triggerable tasks
    void clearAllTasks();
    void getTaskRunning();
    void setCurrInjAmplitude(double value);    
    void setBACCurrInjAmplitude(double value);
    void setBACCurrInjFrequency(double value);


    void setHardwareVals(HardwareSettingsWindow *hw_win);
private slots:
    void acquireData();
};

#endif // DAQWORKER_H
