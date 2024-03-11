#ifndef SIMULATIONOBJECTGUI_H
#define SIMULATIONOBJECTGUI_H

#include "../core/core.h"
#include "../controller/controller.h"
enum typeSimObjGUI{
    Robot,
    Wall
};

class SimulationObjectGUI
{
public:
    SimulationObjectGUI(unsigned w, unsigned h, typeSimObjGUI _typeOfSimObj);
    SimulationObjectGUI(Rectangle* rect);
    ~SimulationObjectGUI();
protected:
    typeSimObjGUI _typeOfSimObj;
    Rectangle* rect;
};

#endif // SIMULATIONOBJECTGUI_H
