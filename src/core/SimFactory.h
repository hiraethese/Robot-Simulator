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

public:
    SimFactory();
    void AddWall(Wall* wall);
    Robot* GetControlledRobot();
};

#endif // SIMFACTORY_H
