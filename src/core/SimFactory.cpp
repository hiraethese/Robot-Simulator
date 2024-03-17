#include "SimFactory.h"

SimFactory::SimFactory()
{
    _controlledRobot = new Robot({50.0f, 50.0f}, {100.0f, 100.0f}, 5.0f, 45, 0);
}

void SimFactory::AddWall(Wall* wall)
{
    _walls.push_back(wall);
}

Robot *SimFactory::GetControlledRobot()
{
    return _controlledRobot;
}
