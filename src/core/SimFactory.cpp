#include "SimFactory.h"

SimFactory::SimFactory()
{
    _controlledRobot = nullptr;
    _botRobotTemplate  = {30.0, 30.0, GREEN, true, false, 0, 0, 0};  // default value (now random)
    _controlledRobotTemplate = {30.0, 30.0, RED, true, true, 0, 0, 0};  // default value (now random)
    _wallTemplate = {30.0, 30.0, BLUE, false, false, 0, 0, 0};;
}
/*
typedef struct SimObjView {
    float h;
    float w;
    colors color;
    bool isRobot;
    bool isControlled;
    int speed;
    int angle;
    int way;
} SimObjView;
*/
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
