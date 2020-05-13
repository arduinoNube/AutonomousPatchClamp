#include "statehelperfunctions.h"

StateHelperFunctions::StateHelperFunctions()
{

}

StateHelperFunctions::~StateHelperFunctions()
{

}

int StateHelperFunctions::countActionPotentials(QVector<double> injData, AutopatcherSettings &data, double samplingRate)
{
    // 1. Check for and count action potentials.
    int count = 0;
    int apDelta = round(0.003*samplingRate);
    for(int i=0; i<injData.length(); i++)
    {
        // If > -10mV, action potential found
        if((injData[i] > -0.01) && (injData.length() > i+apDelta+1))
        {
            // skipping the rest of the action potential points.
            i = i + apDelta;  // Making sure not to double count the same action potential (AP width is about 3ms)
            count++;
            double apMax(-999);
            for(int j=0; j<apDelta; j++)
            {
                if(injData[i+j] > apMax) apMax = injData[i+j];
            }
            data.LOG_actionPotentialAmplitude.push_back(apMax);
        }
    }
    return count;
}
