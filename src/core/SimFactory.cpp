#include "SimFactory.h"

SimFactory::SimFactory()
{
    _controlledRobot = new Robot({50.0f, 50.0f}, {100.0f, 100.0f}, 5.0f, 45, 0);
}

void SimFactory::DeleteAllObjects()
{
    if (_controlledRobot != nullptr)
    {
        delete _controlledRobot;
        _controlledRobot = nullptr;
    }

    if (!_walls.empty())
    {
        for (auto& _wall : _walls)
        {
            delete _wall;
        }
        _walls.clear();
    }
}

void SimFactory::AddWall(Wall* wall)
{
    _walls.push_back(wall);
}

Robot *SimFactory::GetControlledRobot()
{
    return _controlledRobot;
}
