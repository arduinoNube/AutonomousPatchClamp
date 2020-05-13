#ifndef DAQWORKER_H
#define DAQWORKER_H

#include <QObject>
#include <NIDAQmx.h>
#include <QTimer>
#include <QMutex>
#include <QVector>
#include <fstream>

class DAQWorker : public QObject
{
    Q_OBJECT

    // Private Variables
    QString devName;                // name of the daq device    
    TaskHandle AItaskHandle,AOtaskHandle,DOtaskHandle,COtaskHandle;  // The handles for each task on the DAQ.
    int buffSize;                   // data read buffer size
    double rate;                    // DAQ sampling rate

    int mTestBuffSize;

    QVector< QVector<double> > mTestVals;  // Each vector contains 5 doubles, in this order: Ra, Rm, Cm, Hv, Tau;  Each vector is saved for each plot update

    QVector<double> buffer1, buffer2;   // the buffers of measured data from the DAQ for the current data sample.
    QVector<double> bufferCurrent;      // This is the buffer that contains the measured current (basically just a scalar multiple of "buffer"
    QVector<double> resBuffer;          // This buffer accumulates all the poins used to calculate the resistance.
                                        // It may be several times the size of the raw data buffers depending on the length of the square wave used to calculate the resistance

    double amplitude;               // the amplitude of the output square wave (peak to peak is 2*amplitude)
    double dtyCycle;                // the duty cycle of the square wave used to measure resistance.
    double freq;                    // frequency of the square wave
    int numAve;                     // Number of square wave periods to average a resistance measurement over
    int AObuffSize;                 // The size of the buffer holding the square wave used to measure resistance
    double convertV2I;              // conversion variable to convert from measured current to resistance.
    double convertMV2I;             // conversion variable to convert from measured voltage to current.
    double multiclampScaleVC;       // Scaling factor for the command voltage in the multiclamp amplifier (voltage clamp)
    double multiclampScaleIC;       // Scaling factor for the command voltage in the multiclamp amplifier (currrent clamp)
    double resistance;              // the measured resistance for the current data set


    QMutex mute;                    // Thread data locking variables
    int taskLock;                   // task lock flag.
    bool taskReady;
    QTimer *resTimer;               // Timer used to calculate the resistance
    QTimer *rawTimer;               // Timer used to continuously aquire raw samples
    bool stopResTimer;

    QTimer oneResCheckTimer;        // The timer to retrigger a oneResCheck event if the task is busy or locked

    double offset;                  // The offset applied to the square wave during gigasealing
    bool rampFlag;
    double holdingVoltage;          // The holding voltage sent to multiclamp commander
    bool skipRCheck;                // This stops the DAQ worker from sending resistance values to the mainwindow.  I think events are piling up and even though the timer stops, events keep coming.

    bool slowRetractFlag;           // This allows this thread to emit move commands to slowly retract the pipette in between each resistance measurement.
    double slowRetractDistance;     // This is the step size for the slow retraction after each measurement.

    QVector<double> buffer;
    QTimer *mTestTimer;
    double mTestFreq;               // This is the frequency of the square wave used for the membrane test
    void ignoreMemTestVals(bool flag);

    QVector<double> aveMemTestVals; // Membrane Test values


    // Computation algorithms
    double calcAmplitude(void);     // Calculates the average of the amplitude of the square wave and returns the resistance
    double calcAmplitude2(void);    
//    std::ofstream foutg;

    // DAQ Functions
    int GenSqrWave(double freq, double dtyCycl, double amplitude, int periods, double rate, double sqrWave[]);
    int GenSqrWaveCont(double freq, double dtyCycl, double amplitude, int periods, double rate, double sqrWave[]);
    void taskComplete();

    // Error Checking DAQ
    bool printDAQError(int32 error);

    // Membrane test aquisition slot
    bool mTestValsSkip;
    bool skipMemTest;

    // Saving data for debuggin
    void saveVector(QVector<double> data,QString fname);
    void saveBuffer(float64 tmp[], int num);
    QVector<double> calculateMembraneParams(QVector<double> buff1,QVector<double> buff2);
    QVector<double> exponentialFit(QVector<double> buff, double Hi, int s, int f);


public:
    DAQWorker(QObject *parent = 0);
    ~DAQWorker();
    void getRawData(QVector<double> *raw);
    double getResData(void);
    void stopRawAquire();

signals:
    void daqInitResCheckReady();
    void daqInitResCheckError();
    void daqInitMemTestReady();
    void daqInitMemTestError();
    void rawDataReady();
    void resDataReady(double res);
    void rawMemTestDataReady(QVector<double> buffer);
    void firstResCheckDone(double average, double stdev);
    void setHoldingVoltage(double volt);
    void rCheckStopped();
    void updateMemTestVals(QVector<double> vals);
    void setHoldingVoltageChecked(bool flag);

private slots:

    void aquireRaw();
    void aquireMemTestRaw();
    void trigger();

public slots:

    Q_INVOKABLE void initInThread();
    Q_INVOKABLE void initDAQResCheck();
    Q_INVOKABLE void initDAQMemTest();
    void initDAQIClampTest();
    Q_INVOKABLE void stop();
    void resCheckStart(int delay);
    void oneResCheck();
    void rawAquireStart();
    Q_INVOKABLE void stopRCheck();
    Q_INVOKABLE void setBuffSize(int num);
    Q_INVOKABLE void setRate(double num);
    void startRamp();
    void stopRamp();

    void startSlowRetract(double dist);
    void stopSlowRetract();

    void startMemTest();
    void stopMemTest();
    void setMulticlampScale(double scale);

    Q_INVOKABLE void setDevName(QString name){ devName = name;}

    void clearAllTasks();
    void setHoldingVoltageNow(double val);

};

#endif // DAQWORKER_H
