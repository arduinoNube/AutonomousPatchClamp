#ifndef STATEHELPERFUNCTIONS_H
#define STATEHELPERFUNCTIONS_H

#include "ui/autopatchersettings.h"

class StateHelperFunctions
{
public:
    StateHelperFunctions();
    ~StateHelperFunctions();
protected:
    int countActionPotentials(QVector<double> injData, AutopatcherSettings &data, double samplingRate);
};

#endif // STATEHELPERFUNCTIONS_H
