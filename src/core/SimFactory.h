#ifndef SIMFACTORY_H
#define SIMFACTORY_H

#include <vector>
#include "entities/Wall.h"
#include "entities/Robot.h"

class SimFactory
{
private:
    std::vector<Wall*> _walls;
    std::vector<Robot*> _robots;
    SimObjView _controlledRobotTemplate;
    SimObjView _botRobotTemplate;
    SimObjView _wallTemplate;
public:
    SimFactory();
    void DeleteAllObjects();
    void AddWall(Wall* wall);
    void AddRobot(Robot* robot);
    SimObjView GetControlledRobotTemp();
    SimObjView GetBotRobotTemp();
    SimObjView GetWallTemp();
    const std::vector<Wall*>& GetWalls() const;
    const std::vector<Robot*>& GetRobots() const;
    Robot* GetFirstControlledRobot();
    std::vector<SimObjView> GetVectorWallsView();
    std::vector<SimObjView> GetVectorRobotsView();
    void UnsetOrderIndex();
};
#endif // SIMFACTORY_H
