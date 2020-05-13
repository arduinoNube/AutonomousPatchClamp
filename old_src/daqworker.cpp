#include "daqworker.h"
#include <QDebug>
#include <QThread>
#include <vector>
#include <fstream>
#include <cmath>
#include <QEvent>
#include <QTime>
#include <fstream>

using namespace std;

DAQWorker::DAQWorker(QObject *parent) :
    QObject(parent)
{
    // Default values
    devName             = "Dev6";
    rate                = 10000.0;
    buffSize            = 700;  // should be rate/10
    stopResTimer        = 0;
    taskLock            = 0;
    amplitude           = 0.5;
    dtyCycle            = 0.5;
    freq                = 10;
    mTestFreq           = 50;
    numAve              = 10;
    convertMV2I         = 2000;   // Converts the amplifier output read by the DAQ to pA
    multiclampScaleVC   = 0.02; // mv/V from multiclamp commander
    multiclampScaleIC   = 400;  // pA/V from multiclamp commander
    AObuffSize          = round(numAve*rate/freq);  // This value must be an integer

    mTestBuffSize       = round(rate/mTestFreq);  // Buffer size for the membrane test tasks

    holdingVoltage      = 0;
    rampFlag            = 0;
    skipRCheck          = 0;
    AItaskHandle        = NULL;
    AOtaskHandle        = NULL;
    DOtaskHandle        = NULL;
    COtaskHandle        = NULL;

    skipMemTest         = 0;
    mTestValsSkip       = 0;
    aveMemTestVals      = QVector<double>(5);

    slowRetractDistance = 0.72; // This is the slow retract step size for each resistance measurement

    oneResCheckTimer.setSingleShot(true);
    connect(&oneResCheckTimer,SIGNAL(timeout())     ,this,SLOT(oneResCheck()),Qt::QueuedConnection);
}


DAQWorker::~DAQWorker()
{
    taskReady = 0;

    if(AItaskHandle != NULL) printDAQError( DAQmxClearTask(AItaskHandle) );
    if(AOtaskHandle != NULL) printDAQError( DAQmxClearTask(AOtaskHandle) );
    if(DOtaskHandle != NULL) printDAQError( DAQmxClearTask(DOtaskHandle) );
    if(COtaskHandle != NULL) printDAQError( DAQmxClearTask(COtaskHandle) );
}

void DAQWorker::initInThread()
{
    mTestTimer = new QTimer(this);// Makes sure timer is created in the new thread
    connect(mTestTimer,SIGNAL(timeout()),   this,SLOT(aquireMemTestRaw()));

    resTimer = new QTimer(this);  // Makes sure timer is created in the new thread
    rawTimer = new QTimer(this);  // Makes sure timer is created in the new thread
    connect(resTimer,SIGNAL(timeout()),this,SLOT(trigger()));  // Timer to calculate resistance every time a square wave is sent.
    connect(rawTimer,SIGNAL(timeout()),this,SLOT(aquireRaw()));  // Timer to handle the continuous streaming to the plot
}


bool DAQWorker::printDAQError(int32 error)
{
    if(error != false)
    {
        char        errBuff[2048]={'\0'};
        DAQmxGetExtendedErrorInfo(errBuff,2048);
        qWarning() << "Error! " << error<< " " << errBuff;

        printf("DAQmx Error: %s\n",errBuff);
        printf("End of program, press Enter key to quit\n");
        getchar();
        return true;
    }
    else
        return false;
}



void DAQWorker::stop()
{
    taskReady = 0;
    clearAllTasks();
    resTimer->stop();
    rawTimer->stop();
    mTestTimer->stop();
    taskLock = false;
}


void DAQWorker::setRate(double num)
{
    rate = num;
}


void DAQWorker::setBuffSize(int num)
{
    buffSize = num;
}


void DAQWorker::initDAQResCheck()
{
    qWarning() << "Initializing R Check";
    // Testing the device    
    int err = printDAQError(DAQmxSelfTestDevice(devName.toStdString().c_str()));

    if(!taskLock && err==0)
    {
        // DAQ  input setup
        printDAQError(DAQmxCreateTask("",&AItaskHandle));
        printDAQError(DAQmxCreateAIVoltageChan(AItaskHandle,"Dev6/ai0:1","",DAQmx_Val_RSE,-10.0,10.0,DAQmx_Val_Volts,NULL));
        printDAQError(DAQmxCfgSampClkTiming(AItaskHandle,"",rate,DAQmx_Val_Rising,DAQmx_Val_ContSamps,buffSize));

        // Hardware Trigger source
        printDAQError(DAQmxCreateTask("",&DOtaskHandle));
        printDAQError(DAQmxCreateDOChan(DOtaskHandle,"Dev6/PFI7","",DAQmx_Val_ChanPerLine));
        printDAQError(DAQmxStartTask(DOtaskHandle));

        // Counter to use on the analaog output
        printDAQError(DAQmxCreateTask("",&COtaskHandle));
        printDAQError(DAQmxCreateCOPulseChanFreq(COtaskHandle,"Dev6/ctr1","",DAQmx_Val_Hz,DAQmx_Val_Low,0,rate,0.5));
        printDAQError(DAQmxCfgImplicitTiming(COtaskHandle,DAQmx_Val_FiniteSamps,AObuffSize));
        printDAQError(DAQmxCfgDigEdgeStartTrig(COtaskHandle,"/Dev6/PFI7",DAQmx_Val_Rising) );
        printDAQError(DAQmxSetTrigAttribute(COtaskHandle, DAQmx_StartTrig_Retriggerable, TRUE));
        printDAQError(DAQmxStartTask(COtaskHandle));

        // DAQ Analog output setup
        double AOdata[AObuffSize];
        GenSqrWave(freq,dtyCycle,amplitude,numAve,rate,AOdata);
        printDAQError( DAQmxCreateTask("",&AOtaskHandle) );
        printDAQError( DAQmxCreateAOVoltageChan(AOtaskHandle,"Dev6/ao0","",-10.0,10.,DAQmx_Val_Volts,NULL) );
        printDAQError( DAQmxCfgSampClkTiming(AOtaskHandle,"/Dev6/Ctr1InternalOutput",rate*2,DAQmx_Val_Falling,DAQmx_Val_ContSamps,AObuffSize) );
        printDAQError( DAQmxWriteAnalogF64(AOtaskHandle, AObuffSize, FALSE, 10.0, DAQmx_Val_GroupByChannel, AOdata, NULL, NULL) );
        printDAQError( DAQmxStartTask(AOtaskHandle));

        taskReady = true;
        emit daqInitResCheckReady();
    }
    else
    {
        taskReady = false;
        char errBuff[2048] = {'\0'};
        printDAQError( DAQmxGetExtendedErrorInfo(errBuff,2048));
        qWarning() << "DAQ Error! " << errBuff;
        emit daqInitResCheckError();
    }
    qWarning() << "Done.";
    taskLock = 0;
//    if(foutg.is_open()) foutg.close();
//    static int f(0);
//    QString fname = "resistance calc buffer" + QString::number(f) +".csv";
//    foutg.open(fname.toStdString().c_str() );
//    f++;
//    qWarning() << "Here";

}


void DAQWorker::initDAQMemTest()
{
    qWarning() << "Initializing membrane Test:  Device " << devName;
    // Testing the device
    resTimer->stop();
    rawTimer->stop();
    skipMemTest = 0;

    bool32 done1(0),done2(0),done3(0),done4(0);
    printDAQError(DAQmxIsTaskDone(AItaskHandle,&done1));
    printDAQError(DAQmxIsTaskDone(DOtaskHandle,&done2));
    printDAQError(DAQmxIsTaskDone(COtaskHandle,&done3));
    printDAQError(DAQmxIsTaskDone(AOtaskHandle,&done4));

    if(!done1) printDAQError(DAQmxClearTask(AItaskHandle));
    if(!done2) printDAQError(DAQmxClearTask(DOtaskHandle));
    if(!done3) printDAQError(DAQmxClearTask(COtaskHandle));
    if(!done4) printDAQError(DAQmxClearTask(AOtaskHandle));

    int err = printDAQError(DAQmxSelfTestDevice(devName.toStdString().c_str()));

    if(err==0)
    {
        taskLock = true;
        qWarning() << "Beginning DAQ membrane test setup";
        qWarning() << "Buffer size: " << mTestBuffSize;
        // DAQ Continuous Analog Input
        printDAQError(DAQmxCreateTask("",&AItaskHandle));
        printDAQError(DAQmxCreateAIVoltageChan(AItaskHandle,"Dev6/ai0","",DAQmx_Val_RSE,-10.0,10.0,DAQmx_Val_Volts,NULL));
        printDAQError(DAQmxCfgSampClkTiming(AItaskHandle,"",rate,DAQmx_Val_Rising,DAQmx_Val_ContSamps,mTestBuffSize));

        // DAQ Continuous Analog Output
        double AOdata[mTestBuffSize];
        GenSqrWaveCont(mTestFreq,dtyCycle,amplitude,1,rate,AOdata);
//        std::ofstream fout;
//        fout.open("data.csv");
//        qWarning() << "Buffer size: " << mTestBuffSize;
//        for(int i=0; i<mTestBuffSize; i++)
//        {
//            fout << AOdata[i] <<", ";
//        }
//        fout.close();
        printDAQError( DAQmxCreateTask("",&AOtaskHandle) );
        printDAQError( DAQmxCreateAOVoltageChan(AOtaskHandle,"Dev6/ao0","",-10.0,10.,DAQmx_Val_Volts,NULL) );
        printDAQError( DAQmxCfgSampClkTiming(AOtaskHandle,"",rate,DAQmx_Val_Rising,DAQmx_Val_ContSamps,mTestBuffSize) );
        printDAQError( DAQmxCfgDigEdgeStartTrig(AOtaskHandle,"/Dev6/ai/StartTrigger",DAQmx_Val_Rising));
        printDAQError( DAQmxWriteAnalogF64(AOtaskHandle, mTestBuffSize, FALSE, 10.0, DAQmx_Val_GroupByChannel, AOdata, NULL, NULL) );
        printDAQError( DAQmxStartTask(AOtaskHandle));

        taskReady = true;
        taskLock = false;
        qWarning() << "Setup complete.  Starting memTest";
        startMemTest();
    }
    else
    {
        taskReady = false;
        char errBuff[2048] = {'\0'};
        printDAQError( DAQmxGetExtendedErrorInfo(errBuff,2048));
        qWarning() << "DAQ Error! " << errBuff;
        emit daqInitMemTestError();
        taskLock = false;
    }

    qWarning() << "Done";
}


void DAQWorker::initDAQIClampTest()
{

    // Change this code to inject current and record continuously


//    qWarning() << "Initializing current clamp test:  Device " << devName;
//    // Testing the device
//    resTimer->stop();
//    rawTimer->stop();
//    skipMemTest = 0;

//    bool32 done1(0),done2(0),done3(0),done4(0);
//    printDAQError(DAQmxIsTaskDone(AItaskHandle,&done1));
//    printDAQError(DAQmxIsTaskDone(DOtaskHandle,&done2));
//    printDAQError(DAQmxIsTaskDone(COtaskHandle,&done3));
//    printDAQError(DAQmxIsTaskDone(AOtaskHandle,&done4));

//    if(!done1) printDAQError(DAQmxClearTask(AItaskHandle));
//    if(!done2) printDAQError(DAQmxClearTask(DOtaskHandle));
//    if(!done3) printDAQError(DAQmxClearTask(COtaskHandle));
//    if(!done4) printDAQError(DAQmxClearTask(AOtaskHandle));

//    int err = printDAQError(DAQmxSelfTestDevice(devName.toStdString().c_str()));

//    if(err==0)
//    {
//        taskLock = true;
//        qWarning() << "Beginning DAQ membrane test setup";
//        qWarning() << "Buffer size: " << mTestBuffSize;
//        // DAQ Continuous Analog Input
//        printDAQError(DAQmxCreateTask("",&AItaskHandle));
//        printDAQError(DAQmxCreateAIVoltageChan(AItaskHandle,"Dev6/ai0","",DAQmx_Val_RSE,-10.0,10.0,DAQmx_Val_Volts,NULL));
//        printDAQError(DAQmxCfgSampClkTiming(AItaskHandle,"",rate,DAQmx_Val_Rising,DAQmx_Val_ContSamps,mTestBuffSize));

//        // DAQ Continuous Analog Output
//        double AOdata[mTestBuffSize];
//        GenSqrWaveCont(mTestFreq,dtyCycle,amplitude,1,rate,AOdata);
////        std::ofstream fout;
////        fout.open("data.csv");
////        qWarning() << "Buffer size: " << mTestBuffSize;
////        for(int i=0; i<mTestBuffSize; i++)
////        {
////            fout << AOdata[i] <<", ";
////        }
////        fout.close();
//        printDAQError( DAQmxCreateTask("",&AOtaskHandle) );
//        printDAQError( DAQmxCreateAOVoltageChan(AOtaskHandle,"Dev6/ao0","",-10.0,10.,DAQmx_Val_Volts,NULL) );
//        printDAQError( DAQmxCfgSampClkTiming(AOtaskHandle,"",rate,DAQmx_Val_Rising,DAQmx_Val_ContSamps,mTestBuffSize) );
//        printDAQError( DAQmxCfgDigEdgeStartTrig(AOtaskHandle,"/Dev6/ai/StartTrigger",DAQmx_Val_Rising));
//        printDAQError( DAQmxWriteAnalogF64(AOtaskHandle, mTestBuffSize, FALSE, 10.0, DAQmx_Val_GroupByChannel, AOdata, NULL, NULL) );
//        printDAQError( DAQmxStartTask(AOtaskHandle));

//        taskReady = true;
//        taskLock = false;
//        qWarning() << "Setup complete.  Starting memTest";
//        startMemTest();
//    }
//    else
//    {
//        taskReady = false;
//        char errBuff[2048] = {'\0'};
//        printDAQError( DAQmxGetExtendedErrorInfo(errBuff,2048));
//        qWarning() << "DAQ Error! " << errBuff;
//        emit daqInitMemTestError();
//        taskLock = false;
//    }

//    qWarning() << "Done";
}
// *********************************************


void DAQWorker::aquireRaw()
{
    if(taskReady && !taskLock && rawTimer->isActive())
    {
//        qWarning() << "Raw Start: " << QTime::currentTime().second() << " " << QTime::currentTime().msec();
        // Start task and read data
        mute.lock();
        taskLock = 1;

        // Aquiring
        int32 read;
        float64 tmp_buffer[buffSize*2];
        if(AItaskHandle != NULL)
        {
            // HANDLING RAW DATA
            printDAQError( DAQmxReadAnalogF64(AItaskHandle,buffSize,10.0,DAQmx_Val_GroupByChannel,tmp_buffer,buffSize*2,&read,NULL));

            std::vector<double> vec;
            vec.insert(vec.end(),&(tmp_buffer[0]),&(tmp_buffer[buffSize-1]));
            buffer1 = QVector<double>::fromStdVector(vec);

            emit rawDataReady();



            // MEASURING RESISTANCE

            // Aquiring data from channel 2 to syncrhonize the resistance measurement.
            vec.insert(vec.begin(),&(tmp_buffer[buffSize+1]),&(tmp_buffer[buffSize*2-1]));
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

                    // FIX THE NOISE IN THE DO/AI TRIGGER LINE!!!
                    // THIS IS A TEMPORARY FIX SO EXPECT OCCASIONAL
                    // NEGATIVE RESISTANCE VALUES AS A RESULT
                    if(buffer2[i] > 4.2 && buffer2[i+1] > 4.2)
                    {
//                        qWarning() << "Trig value" << buffer2[i];
//                        ofstream fout;
//                        QString fname = "data" +QString::number(QTime::currentTime().second()) +QString::number(QTime::currentTime().msec())+".csv";
//                        fout.open(fname.toStdString().c_str());
//                        if(buffer2.size()-i>10 && buffer2.size()-10>0)
//                        {
//                            for(int j=0; j<20; j++)
//                            {
//                                fout << buffer2[i+j-10] << ",";
//                            }
//                            fout.close();
//                        }

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

                // Ramping down holding voltage  (It's here just so it's in sync with the aquisition)

                if(rampFlag)
                {
                    static bool flag(1);
                    static QTime time;
                    if(time.msec() == -1)
                    {
                        time.start();
                    }

                    if(time.elapsed() > resTimer->interval()/10)
                    {
                        time.restart();

                        if(flag)
                        {
                            holdingVoltage = -0.029;
                            flag = 0;
                        }
                        if(holdingVoltage >-0.070)
                        {
                            holdingVoltage = holdingVoltage -0.0002;
                        }
                        else
                        {
                            flag = 1;  // Need to fix this flag so it resets every trial, not every time the check box is checked.
                            rampFlag = 0;
                        }
//                        qWarning() << "Holding V" << holdingVoltage;

                        emit setHoldingVoltage(holdingVoltage);
                    }
                }



                // Calculating the resistance value (the rest of the code below here)
                if(!first)
                {
                    j = 0;  // Start in the middle of the buffer when the trigger is detected,
                            // but for all subsequent buffers, start at the first sample becuase
                            // we need all the samples in the subsequent buffers until we reach
                            // the same size as the input square wave.
                }
                // Add points from buffer1 to resBuffer until it reaches the numAve*rate/freq size
//                qWarning() << resBuffer.size();  // Checking to see if it's cleared
                for(int i=j;  i<buffer1.size(); i++)
                {
                    resBuffer.push_back(buffer1[i]*convertMV2I);
                    if(resBuffer.size() == AObuffSize)
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
//                qWarning() << "Calculating" << resBuffer.size();;
//                std::ofstream fout;
//                fout.open("data3.csv");
//                for(int i=0; i<resBuffer.size(); i++)
//                {
//                    fout << resBuffer[i] << "\r" ;
//                }
//                fout.close();
                resistance = calcAmplitude2();
                qWarning() << "Resistance " << resistance ;
                resBuffer.clear();
//                qWarning() << "Skip R Check " << skipRCheck;
                if(!skipRCheck)
                {
                    emit resDataReady(resistance);
                }
                calculate = false;
            }
        }

        mute.unlock();
        taskLock = 0;
    }
    else
    {
        qWarning() << "The necessary tasks are not running on the DAQ";
    }
}


void DAQWorker::startRamp()
{
    emit setHoldingVoltageChecked(true);
    rampFlag = 1;
}


void DAQWorker::stopRamp()
{
    rampFlag = 0;
}

void DAQWorker::setHoldingVoltageNow(double val)
{

    mute.lock();
    holdingVoltage = val;
    emit setHoldingVoltage(val);
    mute.unlock();
}

void DAQWorker::startSlowRetract(double dist)
{
    slowRetractFlag = 1;
    slowRetractDistance = dist;
}

void DAQWorker::stopSlowRetract()
{
    slowRetractFlag = 0;
}

void DAQWorker::trigger()
{
    if(!skipRCheck)
    {
//        QThread::msleep(200);
//        qWarning() << "DAQ Start: " << QTime::currentTime().second() << " " << QTime::currentTime().msec();
        printDAQError( DAQmxWriteDigitalScalarU32(DOtaskHandle,TRUE,10.0,8,NULL) );
        printDAQError( DAQmxWriteDigitalScalarU32(DOtaskHandle,TRUE,10.0,0,NULL) );
    }
//    taskComplete();

    qWarning() << "DO Triggered";
}


void DAQWorker::taskComplete()
{
    bool32 a,b,c,d;
    printDAQError(DAQmxGetTaskComplete(AItaskHandle,&a));
    printDAQError(DAQmxGetTaskComplete(DOtaskHandle,&b));
    printDAQError(DAQmxGetTaskComplete(COtaskHandle,&c));
    printDAQError(DAQmxGetTaskComplete(AOtaskHandle,&d));
    qWarning() << a << " " << b << " " << c << " " << d;
}


void DAQWorker::resCheckStart(int delay)
{
    stopMemTest();
    rawAquireStart();
    resTimer->start(delay);  // How often to trigger to measure resistance.
    skipRCheck = 0;
}

void DAQWorker::clearAllTasks()
{
    printDAQError(DAQmxClearTask(AItaskHandle));
    printDAQError(DAQmxClearTask(AOtaskHandle));
    printDAQError(DAQmxClearTask(COtaskHandle));
    printDAQError(DAQmxClearTask(DOtaskHandle));

    AItaskHandle = NULL;
    AOtaskHandle = NULL;
    COtaskHandle = NULL;
    DOtaskHandle = NULL;
    taskLock = 0;
}


void DAQWorker::oneResCheck()
{
    skipRCheck = 0;
    if(rawTimer->isActive() && !taskLock)
    {
        trigger();
    }
    else if(!rawTimer->isActive())
    {
        rawTimer->start(buffSize/rate/2*1000);
        oneResCheckTimer.start(buffSize/rate/2*1000*2);
    }
    else
    {
        oneResCheckTimer.start(100);
    }

}


void DAQWorker::rawAquireStart()
{
    if(!rawTimer->isActive())
    {
        taskReady = 1;
        printDAQError(DAQmxStartTask(AItaskHandle));

        rawTimer->start(buffSize/rate/2*1000);
        //qWarning() << "Timer speed: " << buffSize/rate/2*1000 << "ms";
    }
}


void DAQWorker::getRawData(QVector<double> *data)
{
    mute.lock();
    // Converting to current measurements
    if(bufferCurrent.size() != buffer1.size()) bufferCurrent.resize(buffer1.size());

    for(int i=0; i<buffer1.size(); i++)
    {
        bufferCurrent[i] = buffer1[i]*convertMV2I;
    }
    *data = bufferCurrent;
    bufferCurrent.clear();
    mute.unlock();
}


double DAQWorker::getResData(void)
{
    mute.lock();
    return resistance;
    mute.unlock();
}


void DAQWorker::stopRCheck()
{
    if(resTimer->isActive())
    {
        resTimer->stop();
    }
    skipRCheck = 1;
    emit rCheckStopped();    
//    foutg.close();
}


void DAQWorker::stopRawAquire()
{
    rawTimer->stop();
}


void DAQWorker::aquireMemTestRaw()
{
    if(!skipMemTest)
    {
        if(taskReady && !taskLock && mTestTimer->isActive())
        {
            // Start task and read data
            mute.lock();
            taskLock = 1;

            // Aquiring
            int32 read;
            float64 tmp_buffer[mTestBuffSize];
            if(AItaskHandle != NULL)
            {
                // HANDLING RAQ DATA
                printDAQError( DAQmxReadAnalogF64(AItaskHandle,mTestBuffSize,10.0,DAQmx_Val_GroupByChannel,tmp_buffer,mTestBuffSize,&read,NULL));

                // Correcting for the scaling factor of the amplifier
                for(int i=0; i<mTestBuffSize; i++)
                {
                    tmp_buffer[i] = tmp_buffer[i]*convertMV2I;
                }
                std::vector<double> buff1,buff2;
                buff1.insert(buff1.end(),&(tmp_buffer[0]),&(tmp_buffer[0])+mTestBuffSize/2);
                buff2.insert(buff2.end(),&(tmp_buffer[0])+mTestBuffSize/2,&(tmp_buffer[0])+mTestBuffSize);
                QVector<double> qBuff1 = QVector<double>::fromStdVector(buff1);
                QVector<double> qBuff2 = QVector<double>::fromStdVector(buff2);

                static int j(0);
                if(j>200) // edit this to run every time
                {
                    emit rawMemTestDataReady(qBuff1+qBuff2);
                    j = 0;
                }
                j++;

                // Inverting the second buffer (because it's negative)
                for(int i=0; i<qBuff2.size(); i++)
                {
                    qBuff2[i] = -qBuff2[i];
                }

    //            saveBuffer(tmp_buffer,mTestBuffSize);
    //            saveVector(qBuff1,"buff1.csv");
    //            saveVector(qBuff2,"buff2.csv");



                // Calculating the membrane parameters by linear regression of the exponential and averaging the values
                static int l(0);

                if(l <= 100)  // Number of samples to average
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
                    emit updateMemTestVals(aveMemTestVals);
                    aveMemTestVals.clear();
                    aveMemTestVals=QVector<double>(5,0);
                    l=0;
                }

            }

            mute.unlock();
            taskLock = 0;
        }
        else
        {
            qWarning() << "The necessary tasks are not running on the DAQ for the membrane test";
        }
    }
}


QVector<double> DAQWorker::calculateMembraneParams(QVector<double> buff1,QVector<double> buff2)
{
    // Getting the steady stage membrane currents
    int startAtPercent = 75;
    int stopNsampesBeforeEnd = 3;
    double Hi1(0),Hi2(0),dI(0),Ra(0),Cm(0),Rm(0);
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

//    qWarning() << "Hi1 " << Hi1 << " Hi2 " << Hi2;
    // Getting the regression constants
    // params[0] = Iss
    // params[1] = Tau
    QVector<double> params1 = exponentialFit(buff1,Hi1,1,round(buff1.size()/2));
    QVector<double> params2 = exponentialFit(buff2,Hi2,1,round(buff2.size()/2));

//    double Iss1      = params1[0];
//    double Iss2      = params2[0];
    double Tau1      = params1[1];
    double Tau2      = params2[1];
//    double Imax1     = params1[2];
//    double Imax2     = params2[2];
    double integral1 = params1[3];
    double integral2 = params2[3];


    Ra = (Tau1*2*amplitude*multiclampScaleVC/(dI*Tau1+integral1) + Tau2*2*amplitude*multiclampScaleVC/(dI*Tau2+integral2))/2;

    Rm = 2*amplitude*multiclampScaleVC/dI-Ra;
    Cm = ((dI*Tau1+integral1)*(Ra+Rm)/(2*amplitude*multiclampScaleVC*Rm) + (dI*Tau2+integral2)*(Ra+Rm)/(2*amplitude*multiclampScaleVC*Rm))/2;
    QVector<double> vals(5);

    vals[0] = Cm;
    vals[1] = Rm*pow(10,6);
    vals[2] = Ra*pow(10,6);
    vals[3] = (Tau1+Tau2)/2*pow(10,6);
    vals[4] = (Hi1-Hi2)/2 + 12.75;    // Holding current.  12.75 is a fudge factor.  I'm not sure why it needs it.
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

        double x = (i-s)/rate;
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
        if(i<buff.size()-1) integral += (buff[i]/2+buff[i+1]/2-Hi)/rate;
        else                integral += (buff[i]/2+buff[i-1]/2-Hi)/rate;

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


void DAQWorker::startMemTest()
{
    bool32 done(0);
    printDAQError(DAQmxIsTaskDone(AItaskHandle,&done));
    qWarning() << "Done? " << done;
    skipMemTest = 0;
    if(done)
    {
        printDAQError(DAQmxStartTask(AItaskHandle));
        if(mTestBuffSize/rate/10*1000<1)
        {
            qWarning() << "mTestTimer time: " << 1;
            mTestTimer->start(1);
        }
        else
        {
            qWarning() << "mTestTimer time: " << mTestBuffSize/rate/10*1000;
            mTestTimer->start(mTestBuffSize/rate/10*1000);
        }

    }
    else
    {
        qWarning() << "Task not ready for mTest";
    }
}


void DAQWorker::stopMemTest()
{
    skipMemTest = 1;
    mTestTimer->stop();
    emit rCheckStopped();  // just reusing a signal slot for restarting
}

void DAQWorker::ignoreMemTestVals(bool flag)
{
    mTestValsSkip = flag;
}

void DAQWorker::setMulticlampScale(double scale)
{
    multiclampScaleVC = scale;
}


int DAQWorker::GenSqrWave(double freq, double dtyCycl, double amplitude, int periods, double rate, double sqrWave[])
{
    int numPts(periods*rate/freq);
    double tmp[numPts/periods];
    int g(0);

    for(int i=0; i<numPts/periods; i++)
    {
    //        qWarning() << i*1.0/numPts*periods;
        if(i*1.0/numPts*periods < dtyCycl)
        {
            tmp[i] = amplitude;
    //            qWarning() << "1";
        }
        else
        {
            tmp[i] = -amplitude;
    //            qWarning() << "-1";
        }
    }

    for(int i=0; i<periods; i++)
    {
        for(int j=0; j<numPts/periods; j++)
        {
            sqrWave[g] = tmp[j];
            g++;
        }
    }

    sqrWave[0] = 0;
    sqrWave[numPts-1] = 0;

//    std::ofstream fout;
//    fout.open("sqr.csv");
//    for(int i=0; i<numPts; i++)
//    {
//        fout << sqrWave[i] << "\r";
//    }
//    fout.close();

    return 0;
}


int DAQWorker::GenSqrWaveCont(double freq, double dtyCycl, double amplitude, int periods, double rate, double sqrWave[])
{
    int numPts(periods*rate/freq);
    double tmp[numPts/periods];
    int g(0);

    for(int i=0; i<numPts/periods; i++)
    {
    //        qWarning() << i*1.0/numPts*periods;
        if(i*1.0/numPts*periods < dtyCycl)
        {
            tmp[i] = amplitude;
    //            qWarning() << "1";
        }
        else
        {
            tmp[i] = -amplitude;
    //            qWarning() << "-1";
        }
    }

    for(int i=0; i<periods; i++)
    {
        for(int j=0; j<numPts/periods; j++)
        {
            sqrWave[g] = tmp[j];
            g++;
        }
    }

    // For the continuous waveform, the start and end should not be zero
//    sqrWave[0] = 0;
    sqrWave[numPts-1] = 0;

    return 0;
}


double DAQWorker::calcAmplitude()
{
    // THIS FUCTION NEEDS SOME WORK.
    // This function had to be hard coded because the counter output
    // clock telling the analog output when to send samples is running
    // a little faster than the analog in internal clock.  This makes
    // the analog input read the entire analog output signal in fewer
    // samples than there were in the analog output array.  I specified
    // the analog output array to have 10000 samples but the entire
    // waveform is read back in throught he analog input in only 9949
    // samples that correspond to the square wave being sent out.
    // That's about a 0.5% error between the two clocks.

    // In essense,
    // 1) the first 4 samples are bad after the trigger
    // 2) then read 995 samples for each period.  (it should be 1000 but it's not for some reason I can't figure out with the DAQ)
    // 3) average the values in each 995 sample period
    // 4) convert to resistance

    // THIS SECTION IS HARD CODED SO DON'T CHANGE numAVE, rate, buffSize, or freq UNTIL THIS IS FIXED.
    int periods = numAve;
    double max(0);
    double min(0);
    int maxCnt(0);
    int minCnt(0);

    if(false)  // Use this parametric code once the DAQ problem is figured out.
    {
    for(int j=0; j<periods; j++)
    {
        for(int i=2; i<AObuffSize/periods; i++)
        {
            if(i<=AObuffSize/periods/2)
            {                
                max += resBuffer.at(i+j*AObuffSize/periods);
//                qWarning() << "Max: " << buffer.at(i+j*buffSize/periods);
                maxCnt++;
            }
            else
            {
                min += resBuffer.at(i+j*AObuffSize/periods);
//                qWarning() << "Min: " << buffer.at(i+j*buffSize/periods);
                minCnt++;
            }
        }
    }
    }
    else if(false)
    {
        int ind[21]= {4, 499, 996, 1494, 1991, 2489, 2986, 3484, 3981, 4479, 4976, 5474, 5971, 6469, 6966, 7464, 7961, 8459, 8956, 9454, 9951};

        for(int k=0; k<21; k++)
        {
            for(int i=ind[k]; i<=ind[k+1]; i++)
            {
                if(k%2==0)
                {
                    max += resBuffer[i];
                    maxCnt++;
                }
                else
                {
                    min += resBuffer[i];
                    minCnt++;
                }
            }
        }
    }

    max = max/maxCnt;
    min = min/minCnt;

//    qWarning() << "Amplitude: " << max-min ;

    // measurement in volts, convert to current, divide amplitude by result.
    double voltage = 2*amplitude*multiclampScaleVC;
    double current = (max-min)*1e-12;
    // qWarning() << "R " << voltage/current*1e-6;
    return (voltage/current*1e-6);
}


double DAQWorker::calcAmplitude2()
{
    int periods = numAve;
    double max(0);
    double min(0);
    int maxCnt(0);
    int minCnt(0);
    if(false)  // Use this parametric code once the DAQ problem is figured out.
    {
    for(int j=0; j<periods; j++)
    {
        for(int i=2; i<AObuffSize/periods; i++)
        {
            if(i<=AObuffSize/periods/2)
            {
                max += resBuffer.at(i+j*AObuffSize/periods);
//                qWarning() << "Max: " << buffer.at(i+j*buffSize/periods);
                maxCnt++;
            }
            else
            {
                min += resBuffer.at(i+j*AObuffSize/periods);
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
                    max += resBuffer[i];
                    maxCnt++;
                }
                else
                {
                    min += resBuffer[i];
                    minCnt++;
                }
            }
        }
    }
    else  // New algorithm that only uses a subset of each part of the square wave
    {
        int numPtsStartH = 250;
        int numPtsEndH   = 490;
        int numPtsStartL = 995-250;
        int numPtsEndL   = 990;
        int numPts       = 995;  // Number of points per period
//        qWarning() << resBuffer.size();
        for(int i=0; i<periods; i++)
        {
            for(int j=numPtsStartH; j<numPtsEndH; j++)
            {
               max += resBuffer[i*numPts+j];
               maxCnt++;
            }
            for(int j=numPtsStartL; j<numPtsEndL; j++)
            {
               min += resBuffer[i*numPts+j];
               minCnt++;
            }
        }
    }

    max = max/maxCnt;
    min = min/minCnt;


//    qWarning() << "Saving file..." ;
//    for(int i=0; i<resBuffer.size(); i++)
//    {
//        foutg << resBuffer[i] << '\n';
//    }
//    foutg << '\n';
//    foutg << '\n';
//    qWarning() << "....Done" ;

//    qWarning() << "Amplitude: " << max-min ;

    // measurement in volts, convert to current, divide amplitude by result.
    double voltage = 2*amplitude*multiclampScaleVC;
    double current = (max-min)*1e-12;
    //qWarning() << "R " << voltage/current*1e-6;
    return (voltage/current*1e-6);
}


void DAQWorker::saveVector(QVector<double> vec,QString fname)
{
    std::ofstream fout;
    fout.open(fname.toStdString().c_str(),std::ios::trunc);

    for(int i=0; i<vec.size(); i++)
    {
        fout << vec[i] << '\n';
    }
    fout.close();
}

void DAQWorker::saveBuffer(float64 tmp[], int num)
{
    std::ofstream fout;
    fout.open("raw_buffer.csv",std::ios::trunc);
    for(int i=0; i<num; i++)
    {
        fout << tmp[i] << '\n';
    }
    fout.close();
}

