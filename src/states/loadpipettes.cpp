#include "loadpipettes.h"

LoadPipettes::LoadPipettes(QObject * parent) : State(parent)
{
    name = "Load Pipettes";
    description = "This state pauses the state machine and directs the user to load the \
carousel with pipettes, remove any old pipettes, and load the filler with internal solution.";
}

LoadPipettes::~LoadPipettes()
{

}


void LoadPipettes::pauseState(bool) // 1 tells the state to pause, 0 to continue
{

}

void LoadPipettes::haltState()
{

}

void LoadPipettes::firstRun()
{
    decision = 0;
    emit gui_setCurrentPageIndex("page_load_pipettes");
    emit gui_enablePages(true);
    emit gui_busy_stop("Ready");
    emit scara_peltier(true);  // Starting the cooling system
    emit scara_fan(true);      // Starting the cooling system
    emit scara_enableEndEffector(true,false);
    emit scara_openEndEffector(false);
}

void LoadPipettes::gui_pushbuttonNextLoadPipettesReleased()
{
    decision = 1;
    emit stateFinished();
}

