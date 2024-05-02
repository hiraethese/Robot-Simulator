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
    std::string GetPath();
    int GetWidth();
    int GetHeight();
    void SetPath(std::string newPath);
    ICP_CODE CreateNewControlledRobotFromTemplate(float x, float y);
    ICP_CODE CreateNewAutomatedRobotFromTemplate(float x, float y);
    ICP_CODE CreateNewWallFromTemplate(float x, float y);
    ICP_CODE UpdateRobotState(SimObjView view);
    ICP_CODE UpdateWallState(SimObjView view);
    ICP_CODE LoadObjectsFromFile(std::string path);
    bool RobotWithRobotsCollision(Vector2d position, float radius, int orderIndex);
    bool RobotWithWallsCollision(Vector2d position, float radius);
    bool RobotWithBordersCollision(Vector2d position, float radius);
    bool WallWithRobotsCollision(Vector2d position, Vector2d size);
    bool WallWithBordersCollision(Vector2d position, Vector2d size);
    const std::vector<Wall*>& GetWalls() const;
    const std::vector<Robot*>& GetRobots() const;
    std::vector<SimObjView> GetVectorWallsView();
    std::vector<SimObjView> GetVectorRobotsView();
    Robot* GetFirstControlledRobot();
    Spawner* GetSpawner();
    std::vector<Robot*>::iterator GetRobotByOrderIndex(int orderIndex);
    std::vector<Wall*>::iterator GetWallByOrderIndex(int orderIndex);
    ICP_CODE RemoveRobotByOrderIndex(int orderIndex);
    ICP_CODE RemoveWallByOrderIndex(int orderIndex);
    void DeleteAllObjects();
    int GetLastOrderIndex();
    ICP_CODE GetRobotViewByOrderGUI(SimObjView* view, int orderIndex);
    ICP_CODE GetWallViewByOrderGUI(SimObjView* view, int orderIndex);
};

#endif // SIMMAP_H
