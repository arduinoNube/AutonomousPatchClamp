#ifndef NIDAQ_WRAPPER_H
#define NIDAQ_WRAPPER_H

#include <string>
#include <NIDAQmx.h>

class NIDAQ_wrapper
{
public:
    NIDAQ_wrapper();

private:
    // Aquisition variables
    string physicalChannel;

    double maxVolt;
    double minVolt;
    double sampFreq;


    // Generation Variables

    // Task, Channel, and Timing variables

    TaskHandle taskHandle;

};

#endif // NIDAQ_WRAPPER_H
