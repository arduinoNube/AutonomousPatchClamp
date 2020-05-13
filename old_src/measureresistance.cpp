#include "measureresistance.h"
#include <string>
#include <QDebug>

MeasureResistance::MeasureResistance()
{


}

void MeasureResistance::aquire(float64* data,int size)
{
    int32       error=0;    
    int32       read;
    char        errBuff[2048]={'\0'};
    double      rate(10000.0);
    double      rangeUpper(10.0);  // volts
    double      rangeLower(-10.0); // volts
    std::string deviceName("Dev6/ai0");
    int err(0);
    uInt32 serial(0);
    char *data2;
    uInt32 buffer(2048);

    /*********************************************/
    // DAQmx Configure Code
    /*********************************************/
    qWarning() << DAQmxFailed(DAQmxCreateTask("task",&taskHandle));
    qWarning() << DAQmxFailed(DAQmxGetSysDevNames(data2,buffer));
    qWarning() << buffer;
    qWarning() << DAQmxFailed(DAQmxCreateAIVoltageChan(taskHandle,"Dev6/ai0","thing",DAQmx_Val_Cfg_Default,-10.0,10.0,DAQmx_Val_Volts,NULL));
    qWarning() << DAQmxFailed(DAQmxCfgSampClkTiming(taskHandle,"Dev6/ai0",10000.0,DAQmx_Val_Rising,DAQmx_Val_FiniteSamps,1000));

    /*********************************************/
    // DAQmx Start Code
    /*********************************************/
    qWarning() << DAQmxFailed(DAQmxStartTask(&taskHandle));
    qWarning() << DAQmxGetExtendedErrorInfo(errBuff,2048);
    qWarning() << errBuff;

    /*********************************************/
    // DAQmx Read Code
    /*********************************************/
    qWarning() << DAQmxFailed(DAQmxReadAnalogF64(&taskHandle,1000,10.0,
                              DAQmx_Val_GroupByChannel,data,1000,&read,NULL));

    qWarning() << DAQmxGetExtendedErrorInfo(errBuff,2048);
    qWarning() << errBuff;

    printf("Acquired %d points. \n",(int)read);
}
