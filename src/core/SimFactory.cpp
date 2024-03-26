#include "SimFactory.h"

SimFactory::SimFactory()
{
    _controlledRobot = nullptr;
    _botRobotTemplate  = {{0.0, 0.0, 30.0, 30.0}, 30, 30, 30, GREEN, false};  // default value (now random)
    _controlledRobotTemplate = {{0.0, 0.0, 30.0, 30.0}, 30, 30, 30, RED, true};  // default value (now random)
    _wallTemplate = {{0.0, 0.0, 30.0, 30.0}, BLUE};
    //_wallTemplate = new Wall({0.0, 0.0},{30.0, 30.0});   // default value (now random)
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

RobotView SimFactory::GetControlledRobotTemp()
{
    return _controlledRobotTemplate;
}

RobotView SimFactory::GetBotRobotTemp()
{
    return _botRobotTemplate;
}

WallView SimFactory::GetWallTemp()
{
    return _wallTemplate;
}
