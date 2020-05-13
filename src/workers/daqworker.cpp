#include "daqworker.h"
#include <cmath>
#include <QDebug>
#include <QTime>
#include <QThread>
#include <QApplication>
#include <fstream>
#include "worker.h"

using namespace std;

DAQWorker::DAQWorker(QObject *parent) : Worker(parent)
{
    samplingRate        = 20000.0;      // Default DAQ Sampling rate for all tasks, this can change but all the other constants need to be recomputed.
    samplingRateTmp     = 20000.0;      // When the samplingRateTmp is changed, the code will update the samplingRate when it's safe.
    resCheckAIBuffer    = NULL;
    breakInAIBuffer     = NULL;
    mTestAIBuffer       = NULL;
    currInjAIBuffer     = NULL;
    bacCurrInjAIBuffer  = NULL;
    ic_mTestAIBuffer    = NULL;

    setupConstants();
}


DAQWorker::~DAQWorker()
{
    delete[] resCheckAIBuffer;
    delete[] breakInAIBuffer;
    delete[] mTestAIBuffer;
    delete[] currInjAIBuffer;
    delete[] bacCurrInjAIBuffer;
}

void DAQWorker::setupConstants()
{
    // Data processing parameters
    convertMV2I         = 2000; // Converts the amplifier output read by the DAQ to pA
    convertMV2V         = 10;    // Converts the amplifier output voltage read by the daq to mV
    amplifierScaleVC    = 0.02; // mv/V from multiclamp commander
    amplifierScaleIC    = 400;  // pA/V from multiclamp commander

    // VARIABLES COMMON TO ALL ACQUISITION MODES
    dtyCycle            = 0.5;          // Counter clock duty cycle
    devName             = "Dev6";       // DAQ Device name
    taskReady           = false;        // Flag saying if the task is initialized
    taskLock            = false;        // Flag saying if the task is being used or modified
    additiveFudgeV      = .001;         // V fudge factor to reconcile differences between clampex and the NI DAQ in current clamp
    bias                = 0;            // Volts. (clampex will match with a -0.0165 V bias) If there is a slight bias in the command signal from ground loops or whatever, put that voltage here.
                                        // It will be added to any waveforms the daq generages
                                        // <<<<< THIS ONE IS IMPORTANT AND NEEDS TO BE TUNED WITH EVERY NEW SETUP >>>>>>>

    // Task handles
    AItaskHandle        = NULL;
    AOtaskHandle        = NULL;
    DOtaskHandle        = NULL;
    COtaskHandle        = NULL;

    // Mode Flags
    dataAcquisitionType = 0;  // This specifies which acquisition mode is currently being used (see below)

    // TYPES OF ACQUISITION
    // (1) Resistance Check (triggered 1 second 10 Hz square wave)
    //      1. when triggered, send out the same square wave
    //      2. when finished, send the resistance valud back to the GUI
    resCheckNPeriods    = 10;                                       // Number of periods in the AO square wave
    resCheckAmplitude   = 0.5;                                      // Amplitude of AO square wave (volts) amp = ppk/2
    resCheckFreq        = 10;                                       // 10 Hz AO square wave
    resCheckAOBuffSize  = round(resCheckNPeriods*samplingRate/resCheckFreq);// The actual buffer is temporary and is a difference size than the AI buffer
    resCheckAIBuffSize  = samplingRate/10;                                      // should be less than samplingRate/10 .   10 Hz is a good update rate for the plots.  Any faster and it boggs things down.
    if(resCheckAIBuffer != NULL){delete[] resCheckAIBuffer;}
    resCheckAIBuffer    = new float64[resCheckAIBuffSize*2];        // One buffer for the raw data, another for the trigger detection
    //    resCheckDataBuffer;


    // (2) Break In detection (continuous 1 period of 100 Hz square wave)
    //      1. Continuously send resistance measurements from the square wave to the GUI until stopped
    breakInNPeriods     = 1;                                // Number of periods in the AO square wave
    breakInAmplitude    = resCheckAmplitude;                // Amplitude of AO square wave
    breakInFreq         = 100;                              // Frequency of AO square wave  This should stay fast even though it's inaccurate.  If we slow this down then the response time to shut off the suction pressure will be longer.
    breakInAIAOBuffSize = round(breakInNPeriods*samplingRate/breakInFreq);  // This value must be an integer (one period only) and an even number. The buffers for continuous tasks are the same size as the AO buffer
    if(breakInAIBuffer != NULL){ delete[] breakInAIBuffer;} // It also determines the plot update rate as one complete buffer is sent to the GUI at a time
    breakInAIBuffer     = new float64[breakInAIAOBuffSize];


    // (3) Membrane test (continuous 1 period of 25 Hz square wave)
    //      1. Continuously send membrane parameters to the GUI until stopped
    mTestNPeriods       = 1;                                // Number of periods in the AO square wave
    mTestAmplitude      = resCheckAmplitude;                // Amplitude of AO square wave
    mTestFreq           = 25;                               // Frequency of AO square wave (was 100 and 50 but was too fast)
    mTestAIAOBuffSize   = round(samplingRate/mTestFreq);    // Buffer size for the membrane test task.  This value must be an integer (one period only)
                                                            // and an even number. The buffers for continuous tasks are the same size as the AO buffer
    if(mTestAIBuffer != NULL){ delete[] mTestAIBuffer;}
    mTestAIBuffer       = new float64[mTestAIAOBuffSize];   //


    // (4) Current injection (triggered 1 second of DC pulse with varying amplitude)
    //      1. when triggered, change the amplitude of the DC pulse and send it out
    //      2. when finished, send the data back to the GUI
//    currInjAmplitude;       // The amplitude of the injected current.  It is set during the trigger function call
    currInjTime          = 600;                                     // (ms) The length of the current injection in milliseconds (Same as Margrie 2014 paper)
    currInjAOBuffSize    = round(samplingRate*currInjTime/1000.0);    // Buffer size for the analog output
    currInjAIBuffSize    = samplingRate/10;                           // AI buffer size.   10 Hz is a good update rate for the plots.  Any faster and it boggs things down.
    if(currInjAIBuffer != NULL){ delete[] currInjAIBuffer; }
    currInjAIBuffer      = new float64[currInjAIBuffSize*2];          // AI buffer
    currInjAmplitude     = 0;                                       // Current injection step amplitude (pA)

    // (5) BAC Current injection (triggered a train of 2 ms pulses to induce layer 5 BAC firing, with variable frequency and amplitude)
    bacCurrInjNumPulses  = 3;
    bacCurrInjAmplitude  = 0;
    bacCurrInjPulseWidth = 2;  // ms
    bacCurrInjFrequency  = 10; // Hz
    bacCurrInjAOBuffSize = round(samplingRate*bacCurrInjNumPulses*(1/bacCurrInjFrequency));
    bacCurrInjAIBuffSize = currInjAIBuffSize;
    if(bacCurrInjAIBuffer != NULL){ delete[] bacCurrInjAIBuffer;}
    bacCurrInjAIBuffer   = new float64[bacCurrInjAIBuffSize*2];          // AI buffer

    // (6) Current Clamp Membrane test (continuous 1 period of 150 Hz square wave)
    //      1. Continuously send membrane parameters to the GUI until stopped
    ic_mTestNPeriods       = 1;                                // Number of periods in the AO square wave
    ic_mTestAmplitude      = 500/amplifierScaleIC/2;             // pA Amplitude of AO square wave (500 pA default)
    ic_mTestFreq           = 150;                              // Frequency of AO square wave.  (150 Hz default)
    ic_mTestAIAOBuffSize   = round(samplingRate/ic_mTestFreq); // Buffer size for the membrane test task.  This value must be an integer (one period only)
                                                               // and an even number. The buffers for continuous tasks are the same size as the AO buffer
    if(ic_mTestAIBuffer != NULL){ delete[] ic_mTestAIBuffer;}
    ic_mTestAIBuffer       = new float64[ic_mTestAIAOBuffSize];

    // Computation defaults
    numPeriodsMemTestAve = 25;
    numberOfMembraneTestVariables = 6;
    aveMemTestVals.resize(numberOfMembraneTestVariables);
}

void DAQWorker::setHardwareVals(HardwareSettingsWindow *hw_win)
{
    if(taskRunning)
    {
        samplingRateTmp = hw_win->daqSampRate;
    }
    else
    {
        samplingRate = hw_win->daqSampRate;
        setupConstants();
    }
}

void DAQWorker::aboutToClose()
{
    //delete acquireTimer;
    //this->moveToThread(QApplication::instance()->thread());
}

void DAQWorker::initInThread()
{
    acquireTimer = new QTimer(this);
    connect(acquireTimer,SIGNAL(timeout()),this,SLOT(acquireData()));  // Timer to aquire data from the DAQ
    acquireTimer->setSingleShot(true);
}

void DAQWorker::init(QString devName)
{
    DAQWorker::devName = devName;
    int err = printDAQError(DAQmxSelfTestDevice(devName.toStdString().c_str()));
    if(!err)
    {
        emit initReady();
    }
    else
    {
        char errBuff[2048] = {'\0'};
        printDAQError( DAQmxGetExtendedErrorInfo(errBuff,2048));
        qWarning() << "DAQ Error! " << errBuff;
        emit initError();
    }
}

void DAQWorker::initTask(int taskType)
{
    // Updating the sampling rate if changed
    if(samplingRate != samplingRateTmp)
    {
        samplingRate = samplingRateTmp;
        setupConstants();
    }
    // Testing the device
    int err = printDAQError(DAQmxSelfTestDevice(devName.toStdString().c_str()));
    if(!err)
    {
        clearAllTasks();
        dataAcquisitionType = taskType;
        qWarning() << "Init task called";
        switch(taskType)
        {
        case 0: // Resistance Check
        {
            qWarning() << "Initializing resistance check tasks:  Device " << devName;
            resCheckDataBuffer.clear();
            double AOdata[resCheckAOBuffSize];
            GenSqrWave(resCheckFreq,resCheckAmplitude,resCheckNPeriods,samplingRate,AOdata);
            initTriggerable(samplingRate,resCheckAIBuffSize,2,resCheckAOBuffSize,AOdata);
            taskReady = true;
            emit initTaskReady();
            break;
        }
        case 1: // Break In
        {
            qWarning() << "Initializing fast resistance check tasks for break in:  Device " << devName;
            double AOdata[breakInAIAOBuffSize];
            GenSqrWaveCont(breakInFreq, breakInAmplitude, breakInNPeriods, samplingRate, AOdata);
            initContinuous(samplingRate, breakInAIAOBuffSize, AOdata);
            taskReady = true;
            emit initTaskReady();
            break;
        }
        case 2: // Membrane Test
        {
            qWarning() << "Initializing membrane test tasks:  Device " << devName;
            double AOdata[mTestAIAOBuffSize];
            GenSqrWaveCont(mTestFreq, mTestAmplitude, mTestNPeriods, samplingRate, AOdata);
            initContinuous(samplingRate, mTestAIAOBuffSize, AOdata);
            taskReady = true;
            fff = 0;
            emit initTaskReady();
            break;
        }
        case 3: // Current Injection
        {
            qWarning() << "Initializing current injection tasks:  Device " << devName;
            double AOdata[currInjAOBuffSize];
            GenCurrInj(currInjAmplitude, currInjTime, samplingRate,AOdata);
            initTriggerable(samplingRate,currInjAIBuffSize,2,currInjAOBuffSize,AOdata);
            taskReady = true;
            currInjDataBuffer.clear();
            emit initTaskReady();
            break;
        }
        case 4: // BAC Current Injection
        {
            qWarning() << "Initializing BAC current injection tasks:  Device " << devName;
            double AOdata[bacCurrInjAOBuffSize];            
            GenCurrInjBAC(bacCurrInjAmplitude, bacCurrInjPulseWidth, bacCurrInjNumPulses, bacCurrInjFrequency, samplingRate, AOdata);
            initTriggerable(samplingRate,bacCurrInjAIBuffSize,2,bacCurrInjAOBuffSize,AOdata);
            taskReady = true;
            bacCurrInjDataBuffer.clear();
            qWarning() << "DAQ Initialized";
            emit initTaskReady();
            break;
        }
        case 5:  // Current clamp membrane test (for bridge balance adjustment)
        {
            qWarning() << "Initializing current clamp membrane test task:  Device " << devName;
            double AOdata[ic_mTestAIAOBuffSize];
            GenSqrWaveCont(ic_mTestFreq, ic_mTestAmplitude, ic_mTestNPeriods, samplingRate, AOdata);
            AOdata[ic_mTestAIAOBuffSize-1] = bias; // This is so it doesn't inject current after the task finishes (DOESN'T WORK 100% YET!) Stopping the task in the middle of a buffer keeps it from reaching this value!
            initContinuous(samplingRate, ic_mTestAIAOBuffSize, AOdata);
            taskReady = true;
            emit initTaskReady();
            break;
        }
        default:
        {
            dataAcquisitionType = -1;
            qWarning() << "The daq worker is not programmed for this task type: " << taskType;
            emit initTaskError();
        }
        }
    }
    else
    {
        qWarning() << "The DAQ is not present: " << devName << " to perform task: " << taskType;
        emit initTaskReady();
    }
}

void DAQWorker::startTask()
{
    if(taskReady && !taskRunning)
    {
        taskRunning = 1;
        if      (dataAcquisitionType == TASKTYPE_RESISTANCE_CHECK)      acquireTimer->setInterval(resCheckAIBuffSize/samplingRate*1000*0.8);
        else if (dataAcquisitionType == TASKTYPE_BREAK_IN_LOOP)         acquireTimer->setInterval(breakInAIAOBuffSize/samplingRate*1000*0.9);
        else if (dataAcquisitionType == TASKTYPE_MEMBRANE_TEST)         acquireTimer->setInterval(mTestAIAOBuffSize/samplingRate*1000*0.8);  // 0.9 wasn't fast enough.
        else if (dataAcquisitionType == TASKTYPE_CURRENT_INJECTION)     acquireTimer->setInterval(currInjAIBuffSize/samplingRate*1000*0.85);
        else if (dataAcquisitionType == TASKTYPE_BAC_CURRENT_INJECTION) acquireTimer->setInterval(bacCurrInjAIBuffSize/samplingRate*1000*0.85);
        else if (dataAcquisitionType == TASKTYPE_IC_MEMBRANE_TEST)     acquireTimer->setInterval(ic_mTestAIAOBuffSize/samplingRate*1000*0.85);
        else    {taskRunning = 0; qWarning() << "The daq worker is not programmed for task type (add a definition in the worker): " << dataAcquisitionType;}

        if(taskRunning)
        {
            qWarning() << "Raw acquisition started." << acquireTimer->interval() << "ms" << dataAcquisitionType;
            printDAQError(DAQmxStartTask(AItaskHandle));
            acquireTimer->start();
        }
    }
}

void DAQWorker::stopTask()
{
    if(dataAcquisitionType == 1 || dataAcquisitionType == 2)
    {
        printDAQError(DAQmxClearTask(AOtaskHandle));
        printDAQError( DAQmxCreateTask("",&AOtaskHandle) );
        printDAQError( DAQmxCreateAOVoltageChan(AOtaskHandle,"Dev6/ao0","",-10.0,10.,DAQmx_Val_Volts,NULL) );
        printDAQError( DAQmxWriteAnalogScalarF64(AOtaskHandle, TRUE, 10.0, 0,NULL) );
        printDAQError(DAQmxStartTask(AOtaskHandle));
    }
    clearAllTasks();
}

void DAQWorker::clearAllTasks()
{    
    acquireTimer->stop();

    printDAQError(DAQmxClearTask(AItaskHandle));
    printDAQError(DAQmxClearTask(AOtaskHandle));
    printDAQError(DAQmxClearTask(COtaskHandle));
    printDAQError(DAQmxClearTask(DOtaskHandle));

    AItaskHandle        =  NULL;
    AOtaskHandle        =  NULL;
    COtaskHandle        =  NULL;
    DOtaskHandle        =  NULL;
    taskLock            =  0;
    taskRunning         =  0;
    taskReady           =  0;
    dataAcquisitionType = -1;    
    currInjDataBuffer.clear();
    bacCurrInjDataBuffer.clear();
    buffer1.clear();
    buffer2.clear();
}

void DAQWorker::getTaskRunning()
{
    if(taskRunning)
    {
        emit taskIsRunning(dataAcquisitionType);
    }
    else
    {
        qWarning() << "Task not running so no signal emitted with the running task";
    }
}

void DAQWorker::initContinuous(double sampRate, int AIAOBuffSize, double AOData[])
{
    // DAQ Continuous Analog Input
    printDAQError(DAQmxCreateTask("",&AItaskHandle));
    printDAQError(DAQmxCreateAIVoltageChan(AItaskHandle,"Dev6/ai0","",DAQmx_Val_RSE,-10.0,10.0,DAQmx_Val_Volts,NULL));
    printDAQError(DAQmxCfgSampClkTiming(AItaskHandle,"",sampRate,DAQmx_Val_Rising,DAQmx_Val_ContSamps,AIAOBuffSize));

    // DAQ Continuous Analog Output
    printDAQError( DAQmxCreateTask("",&AOtaskHandle) );
    printDAQError( DAQmxCreateAOVoltageChan(AOtaskHandle,"Dev6/ao0","",-10.0,10.,DAQmx_Val_Volts,NULL) );
    printDAQError( DAQmxCfgSampClkTiming(AOtaskHandle,"",sampRate,DAQmx_Val_Rising,DAQmx_Val_ContSamps,AIAOBuffSize) );
    printDAQError( DAQmxCfgDigEdgeStartTrig(AOtaskHandle,"/Dev6/ai/StartTrigger",DAQmx_Val_Rising));
    printDAQError( DAQmxWriteAnalogF64(AOtaskHandle, AIAOBuffSize, FALSE, 10.0, DAQmx_Val_GroupByChannel, AOData, NULL, NULL) );
    printDAQError( DAQmxStartTask(AOtaskHandle));
}

void DAQWorker::initTriggerable(double sampRate, int AIBuffSize,int numAIChannels, int AOBuffSize, double AOData[])
{
    // DAQ  input setup
    printDAQError(DAQmxCreateTask("",&AItaskHandle));
    if(numAIChannels == 1)
    {
        printDAQError(DAQmxCreateAIVoltageChan(AItaskHandle,"Dev6/ai0","",DAQmx_Val_RSE,-10.0,10.0,DAQmx_Val_Volts,NULL));
    }
    else if(numAIChannels > 1 && numAIChannels < 16)
    {
        printDAQError(DAQmxCreateAIVoltageChan(AItaskHandle,QString("Dev6/ai0:"+QString::number(numAIChannels-1,'g',2)).toStdString().c_str(),"",DAQmx_Val_RSE,-10.0,10.0,DAQmx_Val_Volts,NULL));
    }
    printDAQError(DAQmxCfgSampClkTiming(AItaskHandle,"",sampRate,DAQmx_Val_Rising,DAQmx_Val_ContSamps,AIBuffSize));

    // Hardware Trigger source
    printDAQError(DAQmxCreateTask("",&DOtaskHandle));
    printDAQError(DAQmxCreateDOChan(DOtaskHandle,"Dev6/PFI7","",DAQmx_Val_ChanPerLine));
    printDAQError(DAQmxStartTask(DOtaskHandle));

    // Counter to use on the analaog output
    printDAQError(DAQmxCreateTask("",&COtaskHandle));
    printDAQError(DAQmxCreateCOPulseChanFreq(COtaskHandle,"Dev6/ctr1","",DAQmx_Val_Hz,DAQmx_Val_Low,0,sampRate,0.5));
    printDAQError(DAQmxCfgImplicitTiming(COtaskHandle,DAQmx_Val_FiniteSamps,AOBuffSize));
    printDAQError(DAQmxCfgDigEdgeStartTrig(COtaskHandle,"/Dev6/PFI7",DAQmx_Val_Rising) );
    printDAQError(DAQmxSetTrigAttribute(COtaskHandle, DAQmx_StartTrig_Retriggerable, TRUE));
    printDAQError(DAQmxStartTask(COtaskHandle));

    // DAQ Analog output setup
    printDAQError( DAQmxCreateTask("",&AOtaskHandle) );
    printDAQError( DAQmxCreateAOVoltageChan(AOtaskHandle,"Dev6/ao0","",-10.0,10.,DAQmx_Val_Volts,NULL) );
    printDAQError( DAQmxCfgSampClkTiming(AOtaskHandle,"/Dev6/Ctr1InternalOutput",sampRate*2,DAQmx_Val_Falling,DAQmx_Val_ContSamps,AOBuffSize) );
    printDAQError( DAQmxWriteAnalogF64(AOtaskHandle, AOBuffSize, FALSE, 10.0, DAQmx_Val_GroupByChannel, AOData, NULL, NULL) );
    printDAQError( DAQmxStartTask(AOtaskHandle));

}

void DAQWorker::acquireData()
{
    QTime profile;
    profile = profile.currentTime();
    if(taskReady && !taskLock && taskRunning)
    {
        mute.lock();
        taskLock = 1;

        int32 read;
        if(AItaskHandle != NULL)
        {
//            QTime tmp = QTime::currentTime();
            switch(dataAcquisitionType)
            {
            case TASKTYPE_RESISTANCE_CHECK: // Resistance Check
            {
                printDAQError( DAQmxReadAnalogF64(AItaskHandle,resCheckAIBuffSize,10.0,DAQmx_Val_GroupByChannel,resCheckAIBuffer,resCheckAIBuffSize*2,&read,NULL));
                acquireTimer->start();  // Starting timer for next acquisition

                std::vector<double> vec;
                vec.insert(vec.end(),&(resCheckAIBuffer[0]),&(resCheckAIBuffer[resCheckAIBuffSize-1]));
                buffer1 = QVector<double>::fromStdVector(vec);
                //emit rawDataReady();

                checkForResistanceValue(resCheckAIBuffer,resCheckAIBuffSize);
                break;
            }
            case TASKTYPE_BREAK_IN_LOOP:  // Break In Feedback
            {
                printDAQError( DAQmxReadAnalogF64(AItaskHandle,breakInAIAOBuffSize,10.0,DAQmx_Val_GroupByChannel,breakInAIBuffer,breakInAIAOBuffSize,&read,NULL));
                acquireTimer->start();

                // Reformatting the data and calculating the resistance
                std::vector<double> buff1,buff2;
                buff1.insert(buff1.end(),&(breakInAIBuffer[0]),&(breakInAIBuffer[0])+breakInAIAOBuffSize/2);
                buff2.insert(buff2.end(),&(breakInAIBuffer[0])+breakInAIAOBuffSize/2,&(breakInAIBuffer[0])+breakInAIAOBuffSize);
                QVector<double> qBuff1 = QVector<double>::fromStdVector(buff1);
                QVector<double> qBuff2 = QVector<double>::fromStdVector(buff2);

                buffer1 = qBuff1+qBuff2;
                emit rawDataReady();

                // Calculating the resistance every period of the square wave
                int start   = round(breakInAIAOBuffSize*0.25);  // start after the first 25% of the samples.  This eliminates the initial transients from the calculation.
                int end     = round(breakInAIAOBuffSize*0.95);  // end before the last 5% of the samples.  This eliminates the transients at the end of the half-period from the calculation.

                double high(0),low(0);
                for(unsigned int i=0; i<breakInAIAOBuffSize/2; i++)
                {
                    high+= buff1[i];
                    low += buff2[i];
                }
                high = high/(end-start);
                low  = low/(end-start);

                // measurement in volts, convert to current, divide amplitude by result.
                double voltage = 2*breakInAmplitude*amplifierScaleVC;
                double current = (high-low)*1e-12;
                emit resDataReady(voltage/current*1e-6/convertMV2I);
                break;
            }
            case TASKTYPE_MEMBRANE_TEST:  // Membrane Test
            {

                // HANDLING RAQ DATA
                printDAQError( DAQmxReadAnalogF64(AItaskHandle,mTestAIAOBuffSize,10.0,DAQmx_Val_GroupByChannel,mTestAIBuffer,mTestAIAOBuffSize,&read,NULL));
                acquireTimer->start();

                std::vector<double> buff1,buff2;
                buff1.insert(buff1.end(),&(mTestAIBuffer[0]),&(mTestAIBuffer[0])+mTestAIAOBuffSize/2);
                buff2.insert(buff2.end(),&(mTestAIBuffer[0])+mTestAIAOBuffSize/2,&(mTestAIBuffer[0])+mTestAIAOBuffSize);
                QVector<double> qBuff1 = QVector<double>::fromStdVector(buff1);
                QVector<double> qBuff2 = QVector<double>::fromStdVector(buff2);

                // Saves data to a file.
//                if(fff==3)
//                {
//                    ofstream fout;
//                    fout.open("data3.txt");
//                    for(int i=0; i< qBuff1.size(); i++)
//                    {
//                        fout << buff1[i] << "," << buff2[i] << "," << qBuff1[i] << "," <<qBuff2[i] <<  endl;
//                    }
//                    fout.close();

//                }
//                fff++;

                // Correcting for the scaling factor of the amplifier
                for(int i=0; i<qBuff1.length(); i++)
                {
                    qBuff1[i] = qBuff1[i]*convertMV2I;
                }
                for(int i=0; i<qBuff2.length(); i++)
                {
                    qBuff2[i] = qBuff2[i]*convertMV2I;
                }

                buffer1 = qBuff1+qBuff2;
                emit rawDataReady();
                // Inverting the second buffer (because it's the negative side of the squre wave)
                for(int i=0; i<qBuff2.size(); i++)
                {
                    qBuff2[i] = -qBuff2[i];
                }

                // Calculating the membrane parameters by linear regression of the exponential and averaging the values
                static int l(0);

                if(l <= numPeriodsMemTestAve)  // Number of periods to average
                {
                    QVector<double> tmp = calculateMembraneParams(qBuff1,qBuff2);
                    for(int i=0; i< tmp.size(); i++)
                    {
                        aveMemTestVals[i] += tmp[i];
                    }
                    l++;
                }
                else
                {
                    for(int i=0; i< aveMemTestVals.size(); i++)
                    {
                        aveMemTestVals[i] = aveMemTestVals[i]/l;
                    }
                    emit memTestValsReady(aveMemTestVals);
                    aveMemTestVals.clear();
                    aveMemTestVals=QVector<double>(numberOfMembraneTestVariables,0);
                    l=0;
                }
                break;
            }
            case TASKTYPE_CURRENT_INJECTION:  // Current clamp steps and ramps
            {
                printDAQError( DAQmxReadAnalogF64(AItaskHandle,currInjAIBuffSize,10.0,DAQmx_Val_GroupByChannel,currInjAIBuffer,currInjAIBuffSize*2,&read,NULL));
                acquireTimer->start();  // Starting timer for next acquisition

                std::vector<double> vec;
                vec.insert(vec.end(),&(currInjAIBuffer[0]),&(currInjAIBuffer[currInjAIBuffSize-1]));
                buffer1 = QVector<double>::fromStdVector(vec);
                buffer2 = buffer1;
                for(int i=0; i<buffer1.length(); i++)
                {
                    buffer1[i] = (buffer1[i]/convertMV2V+additiveFudgeV)/2;
                    buffer2[i] = buffer2[i]/convertMV2V+additiveFudgeV;
                }
                emit rawDataReady();
                emit rawDataReady(buffer2);

                // Acquiring data from channel 2 to syncrhonize the resistance measurement.
                std::vector<double> vec2;
                vec2.insert(vec2.begin(),&(currInjAIBuffer[currInjAIBuffSize+1]),&(currInjAIBuffer[currInjAIBuffSize*2-1]));

                checkForCurrentInj(buffer2,QVector<double>::fromStdVector(vec2));
                break;
            }
            case TASKTYPE_BAC_CURRENT_INJECTION:
            {
                printDAQError( DAQmxReadAnalogF64(AItaskHandle,currInjAIBuffSize,10.0,DAQmx_Val_GroupByChannel,currInjAIBuffer,currInjAIBuffSize*2,&read,NULL));

                // The line below is really the only line that is necessary for this task
                // but I left the others for future functionality just in case
                // someone needs to process the BAC firing pattern while receiving the data
                // live.
                acquireTimer->start();  // Starting timer for next acquisition,

                std::vector<double> vec;
                vec.insert(vec.end(),&(currInjAIBuffer[0]),&(currInjAIBuffer[currInjAIBuffSize-1]));
                buffer1 = QVector<double>::fromStdVector(vec);
                buffer2 = buffer1;
                for(int i=0; i<buffer1.length(); i++)
                {
                    buffer1[i] = (buffer1[i]/convertMV2V+additiveFudgeV)/2;
                    buffer2[i] = buffer2[i]/convertMV2V+additiveFudgeV;
                }
                //emit rawDataReady();  // This is commented out because I don't want a live feed the whole time.  Slows the computer down.  If enabled, it will send the data in buffer1
                emit rawDataReady(buffer2);  // doesn't actually need the data

                // Acquiring data from channel 2 to syncrhonize the resistance measurement.
                std::vector<double> vec2;
                vec2.insert(vec2.begin(),&(currInjAIBuffer[currInjAIBuffSize+1]),&(currInjAIBuffer[currInjAIBuffSize*2-1]));

                checkForBACCurrentInj(buffer2,QVector<double>::fromStdVector(vec2));
                break;
            }
            case TASKTYPE_IC_MEMBRANE_TEST:  // Membrane Test
            {
                // HANDLING RAQ DATA
                printDAQError( DAQmxReadAnalogF64(AItaskHandle,ic_mTestAIAOBuffSize,10.0,DAQmx_Val_GroupByChannel,ic_mTestAIBuffer,ic_mTestAIAOBuffSize,&read,NULL));
                acquireTimer->start();

                std::vector<double> buff1,buff2;
                buff1.insert(buff1.end(),&(ic_mTestAIBuffer[0]),&(ic_mTestAIBuffer[0])+ic_mTestAIAOBuffSize/2);
                buff2.insert(buff2.end(),&(ic_mTestAIBuffer[0])+ic_mTestAIAOBuffSize/2,&(ic_mTestAIBuffer[0])+ic_mTestAIAOBuffSize);
                QVector<double> qBuff1 = QVector<double>::fromStdVector(buff1);
                QVector<double> qBuff2 = QVector<double>::fromStdVector(buff2);

//                // Saves data to a file.
//                if(fff==3)
//                {
//                    ofstream fout;
//                    fout.open("data3.txt");
//                    for(int i=0; i< qBuff1.size(); i++)
//                    {
//                        fout << buff1[i] << "," << buff2[i] << "," << qBuff1[i] << "," <<qBuff2[i] <<  endl;
//                    }
//                    fout.close();

//                }
//                fff++;

                // Correcting for the scaling factor of the amplifier
                for(int i=0; i<qBuff1.length(); i++)
                {
                    qBuff1[i] = qBuff1[i]*convertMV2V;
                }
                for(int i=0; i<qBuff2.length(); i++)
                {
                    qBuff2[i] = qBuff2[i]*convertMV2V;
                }

                buffer1 = qBuff1+qBuff2;
                emit rawDataReady();
                emit rawDataReady(buffer1);
                break;
            }
            }
//            qWarning() << "DAQ READ DELAY: " << QTime::currentTime().msecsSinceStartOfDay() - tmp.msecsSinceStartOfDay();

        }
        mute.unlock();
        taskLock = 0;
    }
    else
    {
        qWarning() << "The necessary tasks are not initialized and running on the DAQ";
    }
}

void DAQWorker::checkForResistanceValue(float64 *buffer, int buffSize)
{
    // Acquiring data from channel 2 to syncrhonize the resistance measurement.
    std::vector<double> vec;
    vec.insert(vec.begin(),&(buffer[buffSize+1]),&(buffer[buffSize*2-1]));
    buffer2 = QVector<double>::fromStdVector(vec);

    static bool trigged(false);
    static bool first(false);
    static bool calculate(false);
    static int j(0);

    // Checking for the digital trigger wired to AI1
    if(!trigged)
    {
        // Checking for trigger in AO1
        int size = buffer2.size();
        for(int i=0; i<size-1; i++)
        {
            // FIX THE ELECTRICAL NOISE IN THE DO/AI TRIGGER!!!
            // IT CAUSES THIS CODE TO BECOME "TRIGGED" RANDOMLY
            // WHEN THERE ISN'T ANY ANALOG DATA BEING SENT TO
            // THE AMPLIFIER.  WITH NO SQUARE WAVE, IT CAN'T
            // MEASURE THE RESISTANCE PROPERLY.
            // THIS "IF" STATEMENT IS A TEMPORARY FIX SO
            // EXPECT OCCASIONAL WILD RESISTANCE VALUES AS A RESULT
            if(buffer2[i] > 4.2 && buffer2[i+1] > 4.2)
            {
                trigged = true;
                first = true;

                j = i;
                break;
            }
        }
    }

    // If triggered, fill the buffer "resBuffer" with the same number of samples as were in the square wave.
    if(trigged)
    {

        // Calculating the resistance value (the rest of the code below here)
        if(!first)
        {
            j = 0;  // Start in the middle of the buffer when the trigger is detected,
                    // but for all subsequent buffers, start at the first sample becuase
                    // we need all the samples in the subsequent buffers until we reach
                    // the same size as the input square wave.
        }
        // Add points from buffer1 to resBuffer until it reaches the numAve*rate/freq size
        for(int i=j;  i<buffer1.size(); i++)
        {
            resCheckDataBuffer.push_back(buffer1[i]*convertMV2I);
            if((unsigned int)resCheckDataBuffer.size() == resCheckAOBuffSize)
            {
                calculate = true;
                trigged = false;
                break;
            }
        }

        first = false;
    }

    // Once the buffer is filled, calculate the resistance and emit the signal.
    if(calculate)
    {
        double resistance = calcResistanceAmplitude();
        qWarning() << "Resistance " << resistance ;
        resCheckDataBuffer.clear();

        emit resDataReady(resistance);
        calculate = false;
    }
}

void DAQWorker::checkForCurrentInj(QVector<double> dataBuff, QVector<double> triggerBuff)
{
    static bool trigged(false);
    static bool first(false);
    static int j(0);
    // Checking for the digital trigger wired to AI1
    if(!trigged)
    {
        // Checking for trigger in AO1
        int size = triggerBuff.size();
        for(int i=0; i<size-1; i++)
        {
            // FIX THE ELECTRICAL NOISE IN THE DO/AI TRIGGER!!!
            // IT CAUSES THIS CODE TO BECOME "TRIGGED" RANDOMLY
            // WHEN THERE ISN'T ANY ANALOG DATA BEING SENT TO
            // THE AMPLIFIER.  WITH NO SQUARE WAVE, IT CAN'T
            // MEASURE THE RESISTANCE PROPERLY.
            // THIS "IF" STATEMENT IS A TEMPORARY FIX SO
            // EXPECT OCCASIONAL WILD RESISTANCE VALUES AS A RESULT
            if(triggerBuff[i] > 4.2 && triggerBuff[i+1] > 4.2)
            {
                trigged = true;
                first = true;

                j = i;
                break;
            }
        }
    }

    // If triggered, fill the buffer "resBuffer" with the same number of samples as were in the square wave.
    if(trigged)
    {
        // Calculating the resistance value (the rest of the code below here)
        if(!first)
        {
            j = 0;  // Start in the middle of the buffer when the trigger is detected,
                    // but for all subsequent buffers, start at the first sample becuase
                    // we need all the samples in the subsequent buffers until we reach
                    // the same size as the input square wave.
        }
        // Add points from buff to currInjCheckBuff until it reaches the numAve*rate/freq size
        for(int i=j;  i<dataBuff.size(); i++)
        {
            currInjDataBuffer.push_back(dataBuff[i]);
            if(currInjDataBuffer.size() == currInjAOBuffSize)
            {
                trigged = false;
                emit currInjDataReady(currInjDataBuffer);
                currInjDataBuffer.clear();
            }
        }
        first = false;
    }
}

void DAQWorker::checkForBACCurrentInj(QVector<double> dataBuff, QVector<double> triggerBuff)
{
    static bool trigged(false);
    static bool first(false);
    static int j(0);
    // Checking for the digital trigger wired to AI1
    if(!trigged)
    {
        // Checking for trigger in AO1
        int size = triggerBuff.size();
        for(int i=0; i<size-1; i++)
        {
            // FIX THE ELECTRICAL NOISE IN THE DO/AI TRIGGER!!!
            // IT CAUSES THIS CODE TO BECOME "TRIGGED" RANDOMLY
            // WHEN THERE ISN'T ANY ANALOG DATA BEING SENT TO
            // THE AMPLIFIER.  WITH NO SQUARE WAVE, IT CAN'T
            // MEASURE THE RESISTANCE PROPERLY.
            // THIS "IF" STATEMENT IS A TEMPORARY FIX SO
            // EXPECT OCCASIONAL WILD RESISTANCE VALUES AS A RESULT
            if(triggerBuff[i] > 4.2 && triggerBuff[i+1] > 4.2)
            {
                trigged = true;
                first = true;

                j = i;
                break;
            }
        }
        //qWarning() << "Not Trigged";
    }

    // If triggered, fill the buffer "resBuffer" with the same number of samples as were in the square wave.
    if(trigged)
    {
        emit rawDataReady();
        if(!first)
        {
            j = 0;  // Start in the middle of the buffer when the trigger is detected,
                    // but for all subsequent buffers, start at the first sample becuase
                    // we need all the samples in the subsequent buffers until we reach
                    // the same size as the input square wave.
        }
        // Add points from buff to currInjCheckBuff until it reaches the numAve*rate/freq size
        for(int i=j;  i<dataBuff.size(); i++)
        {
            bacCurrInjDataBuffer.push_back(dataBuff[i]);
            if(bacCurrInjDataBuffer.size() == bacCurrInjAOBuffSize)
            {
                trigged = false;
                emit bacCurrInjDataReady(bacCurrInjDataBuffer);
                bacCurrInjDataBuffer.clear();
                //qWarning() << "Sending signal";
                // This break is a problem if there are multiple triggers within this AI buffer.
                // As long as there is at least one analog buffer between triggers, it will be fine.
                break;
            }
        }
        first = false;
        //qWarning() << "Triggered " << bacCurrInjDataBuffer.size();
    }
}


void DAQWorker::trigger()
{
    if(dataAcquisitionType == TASKTYPE_RESISTANCE_CHECK)
    {
        printDAQError( DAQmxWriteDigitalScalarU32(DOtaskHandle,TRUE,10.0,8,NULL) );
        printDAQError( DAQmxWriteDigitalScalarU32(DOtaskHandle,TRUE,10.0,0,NULL) );
    }
    else if(dataAcquisitionType == TASKTYPE_CURRENT_INJECTION)
    {
        if((AOtaskHandle != NULL) && (DOtaskHandle != NULL))
        {
            float64 AOdata[currInjAOBuffSize];
            GenCurrInj(currInjAmplitude,currInjTime,samplingRate,AOdata);
            printDAQError( DAQmxStopTask(AOtaskHandle) );
            printDAQError( DAQmxWriteAnalogF64(AOtaskHandle, currInjAOBuffSize, FALSE, 10.0, DAQmx_Val_GroupByChannel, AOdata, NULL, NULL) );
            printDAQError( DAQmxStartTask(AOtaskHandle) );
            printDAQError( DAQmxWriteDigitalScalarU32(DOtaskHandle,TRUE,10.0,8,NULL) );
            printDAQError( DAQmxWriteDigitalScalarU32(DOtaskHandle,TRUE,10.0,0,NULL) );
        }
    }
    else if(dataAcquisitionType == TASKTYPE_BAC_CURRENT_INJECTION)
    {
        if((AOtaskHandle != NULL) && (DOtaskHandle != NULL))
        {
//            bacCurrInjAOBuffSize = round(samplingRate*bacCurrInjNumPulses*(1.0/bacCurrInjFrequency));
//            float64 AOdata[bacCurrInjAOBuffSize];
//            GenCurrInjBAC(bacCurrInjAmplitude, bacCurrInjPulseWidth, bacCurrInjNumPulses, bacCurrInjFrequency, samplingRate, AOdata);
//            qWarning() << bacCurrInjAmplitude << bacCurrInjPulseWidth <<  bacCurrInjNumPulses << bacCurrInjFrequency << bacCurrInjAOBuffSize;

//            printDAQError( DAQmxStopTask(AOtaskHandle) );
//            printDAQError( DAQmxWriteAnalogF64(AOtaskHandle, bacCurrInjAOBuffSize, FALSE, 10.0, DAQmx_Val_GroupByChannel, AOdata, NULL, NULL) );
//            printDAQError( DAQmxStartTask(AOtaskHandle) );
            printDAQError( DAQmxWriteDigitalScalarU32(DOtaskHandle,TRUE,10.0,8,NULL) );
            printDAQError( DAQmxWriteDigitalScalarU32(DOtaskHandle,TRUE,10.0,0,NULL) );
        }
    }
    else
    {
        qWarning() << "Triggering not supported for the current mode of data acquisition";
    }
}

double DAQWorker::getCurrInjAmplitude() const
{
    return currInjAmplitude;
}

void DAQWorker::setCurrInjAmplitude(double value)
{
    currInjAmplitude = value/amplifierScaleIC;
}
void DAQWorker::setBACCurrInjAmplitude(double value)
{
    bacCurrInjAmplitude = value/amplifierScaleIC;
    qWarning() << "Current amplitude for BAC set." << bacCurrInjAmplitude;
}

void DAQWorker::setBACCurrInjFrequency(double freq)
{
    bacCurrInjFrequency = freq;
    //qWarning() << "BAC Freq " << freq << " Hz.";
    if(dataAcquisitionType == TASKTYPE_BAC_CURRENT_INJECTION)
    {
        bool tmp = taskRunning;
        // Reinitializing after adjusting the frequency
        clearAllTasks();
        dataAcquisitionType = TASKTYPE_BAC_CURRENT_INJECTION;
        bacCurrInjAOBuffSize = round(samplingRate*bacCurrInjNumPulses*(1/bacCurrInjFrequency));
        double AOdata[bacCurrInjAOBuffSize];
        GenCurrInjBAC(bacCurrInjAmplitude, bacCurrInjPulseWidth, bacCurrInjNumPulses, bacCurrInjFrequency, samplingRate, AOdata);
        initTriggerable(samplingRate,bacCurrInjAIBuffSize,2,bacCurrInjAOBuffSize,AOdata);
        taskReady = true;
        bacCurrInjDataBuffer.clear();
        if(tmp)
        {
            startTask();
        }
    }
}

bool DAQWorker::printDAQError(int32 error)
{
    if(error != false)
    {
        char errBuff[2048]={'\0'};
        DAQmxGetExtendedErrorInfo(errBuff,2048);
        qWarning() << "Error! " << error<< " " << errBuff;
        return true;
    }
    else
    {
        return false;
    }
}

void DAQWorker::GenSqrWave(double freq, double amplitude, int periods, double rate, double sqrWave[])
{
    int numPts(periods*rate/freq);
    double tmp[numPts/periods];
    double dtyCycl = 0.5;
    int g(0);

    for(int i=0; i<numPts/periods; i++)
    {
        if(i*1.0/numPts*periods < dtyCycl)
        {
            tmp[i] = amplitude;
        }
        else
        {
            tmp[i] = -amplitude;
        }
    }

    for(int i=0; i<periods; i++)
    {
        for(int j=0; j<numPts/periods; j++)
        {
            sqrWave[g] = tmp[j]+bias;
            g++;
        }
    }

    sqrWave[0]          = 0+bias;
    sqrWave[numPts-1]   = 0+bias;
}

void DAQWorker::GenSqrWaveCont(double freq, double amplitude, int periods, double rate, double sqrWave[])
{
    int numPts(periods*rate/freq);
    double tmp[numPts/periods];
    double dtyCycle = 0.5;
    int g(0);

    for(int i=0; i<numPts/periods; i++)
    {
        if(i*1.0/numPts*periods < dtyCycle)
        {
            tmp[i] = amplitude;
        }
        else
        {
            tmp[i] = -amplitude;
        }
    }

    for(int i=0; i<periods; i++)
    {
        for(int j=0; j<numPts/periods; j++)
        {
            sqrWave[g] = tmp[j]+bias;
            g++;
        }
    }

    // This makes sure that when the task ends there is no residual voltage output.
    sqrWave[0]          = 0+bias;
    sqrWave[numPts-1]   = 0+bias;
}

void DAQWorker::GenCurrInj(double amplitude, double msTime, double samplingRate, double *AOdata)
{
    int numPts = round(msTime/1000*samplingRate);
    AOdata[0]           = bias;
    AOdata[numPts-1]    = bias;
    for(int i=1; i<numPts-1; i++)
    {
        AOdata[i] = amplitude+bias;
    }
}

void DAQWorker::GenCurrInjBAC(double amplitude, double pulseWidthMs, int numPulses, double freq, double samplingRate, double *AOdata)
{
    int numPts = round(1.0/freq*numPulses*samplingRate);
    int period = numPts*1.0/numPulses;  // in samples
    int highPts = pulseWidthMs*samplingRate/1000;
    // Clearing the buffer before using it. This also accounts for a few
    // values that are not set by the subsequent loops when there is a
    // mismatch between the buffer size and the exact number of points
    // set by the loops.
    for(int i=0; i<bacCurrInjAOBuffSize; i++)
    {
        AOdata[i] = bias;
    }
    for(int i=0; i<numPulses; i++)
    {
        if(pulseWidthMs > 1.0/freq*1000)  // If the pulse width is larger than the available period
        {
            for(int j=0; j<period; j++)
            {
                AOdata[i*period+j] = amplitude + bias;
            }
        }
        else
        {
            for(int j=0; j<period; j++)
            {
                if(j < highPts)
                {
                    AOdata[i*period+j] = amplitude+bias;
                }
                else
                {
                    AOdata[i*period+j] = bias;
                }
            }
        }
    }
    AOdata[0]        = 0+bias;
    AOdata[numPts-1] = 0+bias;


//    for(int i=0; i<numPts; i++)
//    {
//        qWarning() << AOdata[i];
//    }
//    qWarning() << endl << endl << endl;
}

void DAQWorker::setAmplifierScaleVC(double scale)
{
    amplifierScaleVC = scale;
}

void DAQWorker::setAmplifierScaleIC(double scale)
{
    amplifierScaleIC = scale;
}

double DAQWorker::getSamplingRate()
{
    return samplingRate;
}

QVector<double> DAQWorker::calculateMembraneParams(QVector<double> buff1,QVector<double> buff2)
{
    // These calculations are based on this paper:
    // https://physics.ucsd.edu/neurophysics/Manuals/Axon%20Instruments/pCLAMP10-User-Guide-RevA.pdf    pgs 163-166
    // Getting the steady stage membrane currents
    int startAtPercent = 60;
    int stopNsampesBeforeEnd = 0;
    double Hi1(0),Hi2(0),dI(0),Ra(0),Cm(0),Rm(0),CapComp(0);
    int f(0);
    for(int i=round(startAtPercent*buff1.size()/100); i<buff1.size()-stopNsampesBeforeEnd; i++)
    {
        // Steady State membrane currents
        dI  += buff1[i] + buff2[i];
        Hi1 += buff1[i];
        Hi2 += buff2[i];
        f++;
    }
    dI = dI/f;

    Hi1 = Hi1/f;
    Hi2 = Hi2/f;

    double min1(1e12);  // Really small number
    double min2(1e12);   // Really big number
    if(buff2.size() == buff1.size())  // some easy error checking, they should always be the same size
    {
        for(int i=0; i<5; i++)
        {
            if(buff1[i] < min1) min1 = buff1[i];
            if(buff2[i] < min2) min2 = buff2[i];
        }
    }
    else
    {
        min1 = Hi1;
        min2 = Hi2;
    }

    CapComp = -(-(min1+Hi2)+(-min2-Hi1))/(Hi1-Hi2)*100;  // Percent overshoot from too much capacitance compensation, this looks wierd but it is right.  The sign switching stuff is because the second buffer has already had a sign change done to it.
    //qWarning() << "Cap Comp Max: " << min1 << " Cap Comp Min: " << min2 << " " << Hi1 << " " << Hi2 << " " << dI << " " << CapComp;

    QVector<double> params1 = exponentialFit(buff1,Hi1,2,round(buff1.size()/2));
    QVector<double> params2 = exponentialFit(buff2,Hi2,2,round(buff2.size()/2));

    double Tau1      = params1[1];
    double Tau2      = params2[1];
    double integral1 = params1[3];
    double integral2 = params2[3];


    Ra = (Tau1*2*mTestAmplitude*amplifierScaleVC/(dI*Tau1+integral1) + Tau2*2*mTestAmplitude*amplifierScaleVC/(dI*Tau2+integral2))/2;

    Rm = 2*mTestAmplitude*amplifierScaleVC/dI-Ra;
    Cm = ((dI*Tau1+integral1)*(Ra+Rm)/(2*mTestAmplitude*amplifierScaleVC*Rm) + (dI*Tau2+integral2)*(Ra+Rm)/(2*mTestAmplitude*amplifierScaleVC*Rm))/2;
    QVector<double> vals(numberOfMembraneTestVariables);

    vals[0] = Cm;
    vals[1] = Rm*pow(10,6);
    vals[2] = Ra*pow(10,6);
    vals[3] = (Tau1+Tau2)/2*pow(10,6);
    vals[4] = (Hi1-Hi2)/2+19;    // Holding current.  19 is a fudge factor because there is a wierd offset in the amplifier or the NI DAQ
    vals[5] = CapComp;

    return vals;
}

QVector<double> DAQWorker::exponentialFit(QVector<double> buff,double Hi, int s, int f)
{
    // Fit an exponential to the data in the buffer
    // Processing values from both buffers
    double Imax(-9999);
    double sumY(0),sumX2Y(0),sumXY_2(0),sumYLY(0),sumXY(0),sumXYLY(0); // Regression constants
    double integral(0);
    for(int i=s; i<f; i++)
    {
        // Expenential regression

        double x = (i-s)/samplingRate;
        double y = buff[i]-Hi;
        if(y<=0)
        {
            y = 1e-99;
        }

        // Calculating the regression constants
        sumY    += y;
        sumX2Y  += pow(x,2)*y;
        sumXY   += x*y;
        sumYLY  += y*log(y);
        sumXYLY += x*y*log(y);

        // Calculating the integral of the waveform
        if(i<buff.size()-1) integral += (buff[i]/2+buff[i+1]/2-Hi)/samplingRate;
        else                integral += (buff[i]/2+buff[i-1]/2-Hi)/samplingRate;

        // Maximum value
        if(y>Imax) Imax = y;
    }

    sumXY_2 = pow(sumXY,2);

    double d    = sumY*sumX2Y-sumXY_2;
    double a    = (sumX2Y*sumYLY-sumXY*sumXYLY)/d;
    double b    = (sumY*sumXYLY-sumXY*sumYLY)/d;

    QVector<double> vals(4);
    vals[0] = exp(a);   // Rss
    vals[1] = -1/b;     // Tau
    vals[2] = Imax;     // Imax
    vals[3] = integral; // Q - charge stored on capacitor                                                                                  // fine         // fine       // fine            // fine          // fine          // not fine
//    qWarning() << "Imax " << Imax << " Rss " << vals[0] << " Tau " << vals[1] << " a " << a << " b " << b << " int " << integral << " " << sumY  << " " << sumXY << " " << sumXY_2 << " " << sumX2Y << " " << sumYLY << " " << sumXYLY;

    return (vals);
}

void DAQWorker::getRawData(QVector<double> *data)
{
    mute.lock();
    QVector<double> bufferCurrent;
    bufferCurrent.resize(buffer1.size());

    // Converting to current measurements
    for(int i=0; i<buffer1.size(); i++)
    {
        bufferCurrent[i] = buffer1[i]*convertMV2I;
    }
    *data = bufferCurrent;
    bufferCurrent.clear();
    mute.unlock();
}

double DAQWorker::calcResistanceAmplitude()
{
    int periods = resCheckNPeriods;
    double max(0);
    double min(0);
    int maxCnt(0);
    int minCnt(0);
    if(false)  // Use this parametric code once the DAQ problem is figured out.
    {
    for(int j=0; j<periods; j++)
    {
        for(unsigned int i=2; i<resCheckAOBuffSize/periods; i++)
        {
            if(i<=resCheckAOBuffSize/periods/2)
            {
                max += resCheckDataBuffer.at(i+j*resCheckAOBuffSize/periods);
//                qWarning() << "Max: " << buffer.at(i+j*buffSize/periods);
                maxCnt++;
            }
            else
            {
                min += resCheckDataBuffer.at(i+j*resCheckAOBuffSize/periods);
//                qWarning() << "Min: " << buffer.at(i+j*buffSize/periods);
                minCnt++;
            }
        }
    }
    }
    else if(false)  // Old hard coded code
    {
        int ind[21]= {4, 499, 996, 1494, 1991, 2489, 2986, 3484, 3981, 4479, 4976, 5474, 5971, 6469, 6966, 7464, 7961, 8459, 8956, 9454, 9951};

        for(int k=0; k<21; k++)
        {
            for(int i=ind[k]; i<=ind[k+1]; i++)
            {
                if(k%2==0)
                {
                    max += resCheckDataBuffer[i];
                    maxCnt++;
                }
                else
                {
                    min += resCheckDataBuffer[i];
                    minCnt++;
                }
            }
        }
    }
    else  // New algorithm that only uses a subset of each part of the square wave
    {
         // JUST FOR REFERENCE
//        resCheckNPeriods    = 10;                                       // Number of periods in the AO square wave
//        resCheckAmplitude   = 0.5;                                      // Amplitude of AO square wave
//        resCheckFreq        = 10;                                       // 10 Hz AO square wave
//        resCheckAOBuffSize  = round(resCheckNPeriods*samplingRate/resCheckFreq);// The actual buffer is temporary and is a difference size than the AI buffer
//        resCheckAIBuffSize  = 700;                                      // should be less than samplingRate/10
//        if(resCheckAIBuffer != NULL){delete[] resCheckAIBuffer;}
//        resCheckAIBuffer    = new float64[resCheckAIBuffSize*2];        // One buffer for the raw data, another for the trigger detection


        // These values have to change whenever the timing of the square wave is changed.
        int ptsPerPeriod = samplingRate/resCheckFreq; // the number of points per period
        int numPtsStartH = ptsPerPeriod*0.25;     // Start halfway through the first half of the period
        int numPtsEndH   = ptsPerPeriod*0.5 - samplingRate/1000.0;     // End at the first half of the period (minus a few points)
        int numPtsStartL = ptsPerPeriod*0.75; // Start halfway through the second half of the period.
        int numPtsEndL   = ptsPerPeriod - samplingRate/1000.0;     // End at the end of the period (minus a few points)
        int numPts       = ptsPerPeriod;     // Number of points per period (minus a few for some unknown reason.  Probably due to the way the trigger signal works)

        for(int i=0; i<periods; i++)
        {
            for(int j=numPtsStartH; j<numPtsEndH; j++)
            {
               max += resCheckDataBuffer[i*numPts+j];
               maxCnt++;
            }
            for(int j=numPtsStartL; j<numPtsEndL; j++)
            {
               min += resCheckDataBuffer[i*numPts+j];
               minCnt++;
            }
        }
    }

    max = max/maxCnt;
    min = min/minCnt;

    // measurement in volts, convert to current, divide amplitude by result.
    double voltage = 2*resCheckAmplitude*amplifierScaleVC;
    double current = (max-min)*1e-12;
    return (voltage/current*1e-6);
}

