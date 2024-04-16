#include "SimFactory.h"

SimFactory::SimFactory()
{
    _botRobotTemplate  = {0.0, 0.0, GREEN, true, false, 0, 0, 0};  // default value (now random)
    _controlledRobotTemplate = {0.0, 0.0, RED, true, true, 0, 0, 0};  // default value (now random)
    _wallTemplate = {0.0, 0.0, BLUE, true, false, 0, 0, 0};;
}
void SimFactory::DeleteAllObjects()
{
    if (!_robots.empty())
    {
        for (auto& robot : _robots)
        {
            delete robot;
        }
        _robots.clear();
    }
    if (!_walls.empty())
    {
        for (auto& wall : _walls)
        {
            delete wall;
        }
        _walls.clear();
    }
}

void SimFactory::AddWall(Wall* wall)
{
    _walls.push_back(wall);
}

void SimFactory::AddRobot(Robot *robot)
{
    _robots.push_back(robot);
}

const std::vector<Wall *> &SimFactory::GetWalls() const
{
    return _walls;
}

const std::vector<Robot *> &SimFactory::GetRobots() const
{
    return _robots;
}

Robot *SimFactory::GetFirstControlledRobot()
{
    for (Robot* robot : _robots)
    {
        if (robot->IsControlled())
        {
            return robot;
        }
    }
    return nullptr;
}

SimObjView SimFactory::GetControlledRobotTemp()
{
    return _controlledRobotTemplate;
}

SimObjView SimFactory::GetBotRobotTemp()
{
    return _botRobotTemplate;
}

SimObjView SimFactory::GetWallTemp()
{
    return _wallTemplate;
}
