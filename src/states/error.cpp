#include "error.h"
#include <QDebug>

Error::Error(QObject *parent) : State(parent)
{
    name = "Error State";

}

Error::~Error()
{

}

void Error::firstRun()
{
    emit gui_busy_stop_error("Error state!");
}

void Error::pauseState(bool) // 1 tells the state to pause, 0 to continue
{

}

void Error::haltState()
{

}

