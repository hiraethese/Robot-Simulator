#include "core.h"

Robot* controlledRobot = nullptr;

int SimStart()
{
    controlledRobot = new Robot({50.0f, 50.0f}, {100.0f, 100.0f}, 10.0f, 180.0f);
    return 0;
}

int SimEnd()
{
    delete controlledRobot;
    return 0;
}
