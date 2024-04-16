#include "SimFactory.h"

SimFactory::SimFactory()
{
    _botRobotTemplate  = {-1, 0.0, 0.0, 30.0, 30.0, GREEN, true, false, 0, 0, 0};  // default value (now random)
    _controlledRobotTemplate = {-1, 0.0, 0.0, 30.0, 30.0, RED, true, true, 0, 0, 0};  // default value (now random)
    _wallTemplate = {-1, 0.0, 0.0, 30.0, 30.0, BLUE, true, false, 0, 0, 0};
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


std::vector<SimObjView> SimFactory::GetVectorWallsView()
{
    std::vector<SimObjView> wallsView;

    for(Wall* wall: _walls)
    {
        wallsView.push_back(wall->GetSimObjView());
    }

    return wallsView;
}

std::vector<SimObjView> SimFactory::GetVectorRobotsView()
{
    std::vector<SimObjView> robotsView;

    for(Robot* robot: _robots)
    {
        robotsView.push_back(robot->GetSimObjView());
    }

    return robotsView;

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
