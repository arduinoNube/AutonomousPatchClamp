#include "state.h"
#include <QDebug>


AutopatcherSettings State::getData() const
{
    return data;
}

void State::setData(const AutopatcherSettings &value)
{
    data = value;
}
State::State(QObject *parent) :
    QObject(parent)
{
    // The decision variable defaults to -1 if no decision was made during the execution
    // such as when the state is terminated before it finishes.  Values 0+ indicate that
    // the state completed it's execution and is informing the state controller which
    // state it should switch to next.
    decision = -1;
}

State::~State()
{
    decision = -1;
}

