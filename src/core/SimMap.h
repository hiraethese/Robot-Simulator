#ifndef SIMMAP_H
#define SIMMAP_H

#include <string>
#include <fstream>
#include <sstream>
#include <QFileInfo>
#include <QString>
#include <vector>
#include <string>
#include "Spawner.h"

class SimMap
{
    // TODO: return 0 if i give path "/mnt"
private:
    std::string _path {};
    int _width;
    int _height;
    int _orderIndex;
    // new
    Spawner* _spawner;
    std::vector<Wall*> _walls;
    std::vector<Robot*> _robots;

public:
    SimMap(int width, int height);
    void DeleteAllObjects();
    std::string GetPath();
    int GetWidth();
    int GetHeight();
    void SetPath(std::string newPath);
    ICP_CODE CreateNewControlledRobotFromTemplate(float x, float y);
    ICP_CODE CreateNewAutomatedRobotFromTemplate(float x, float y);
    ICP_CODE CreateNewWallFromTemplate(float x, float y);
    ICP_CODE LoadObjectsFromFile(std::string path);
    const std::vector<Wall*>& GetWalls() const;
    const std::vector<Robot*>& GetRobots() const;
    std::vector<SimObjView> GetVectorWallsView();
    std::vector<SimObjView> GetVectorRobotsView();
    Robot* GetFirstControlledRobot();
    Spawner* GetSpawner();
};

#endif // SIMMAP_H
