#include "SimFactory.h"

SimFactory::SimFactory()
{
    _controlledRobot = nullptr;
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

void SimFactory::SetControlledRobot(Robot *controlledRobot)
{
    _controlledRobot = controlledRobot;
}

Robot *SimFactory::GetControlledRobot()
{
    return _controlledRobot;
}

const std::vector<Wall *> &SimFactory::GetWalls() const
{
    return _walls;
}
