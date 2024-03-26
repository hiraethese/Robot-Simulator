#ifndef SIMFACTORY_H
#define SIMFACTORY_H

#include <vector>
#include "entities/Wall.h"
#include "entities/Robot.h"

class SimFactory
{
private:
    Robot* _controlledRobot;
    std::vector<Wall*> _walls;
    RobotView _controlledRobotTemplate;
    RobotView _botRobotTemplate;
    WallView _wallTemplate;
public:
    SimFactory();
    void DeleteAllObjects();
    void AddWall(Wall* wall);
    void SetControlledRobot(Robot* controlledRobot);
    Robot* GetControlledRobot();
    RobotView GetControlledRobotTemp();
    RobotView GetBotRobotTemp();
    WallView GetWallTemp();
    const std::vector<Wall*>& GetWalls() const;
};

#endif // SIMFACTORY_H
