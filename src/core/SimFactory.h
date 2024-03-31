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
    SimObjView _controlledRobotTemplate;
    SimObjView _botRobotTemplate;
    SimObjView _wallTemplate;
public:
    SimFactory();
    void DeleteAllObjects();
    void AddWall(Wall* wall);
    void SetControlledRobot(Robot* controlledRobot);
    Robot* GetControlledRobot();
    SimObjView GetControlledRobotTemp();
    SimObjView GetBotRobotTemp();
    SimObjView GetWallTemp();
    const std::vector<Wall*>& GetWalls() const;
};

#endif // SIMFACTORY_H
