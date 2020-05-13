#ifndef MEASURERESISTANCE_H
#define MEASURERESISTANCE_H
#include <stdio.h>
#include "NIDAQmx.h"
class MeasureResistance
{
public:
    MeasureResistance();
    void aquire(float64* data,int n);
    TaskHandle  taskHandle=0;
};

#endif // MEASURERESISTANCE_H
