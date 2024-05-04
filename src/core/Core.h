#ifndef CORE_H
#define CORE_H

#include <string>
#include <iostream>
#include "SimMap.h"

// Core class with controller methods
class Core
{
private:
    Core();
    static Core* _core;
    int _FPS;
    SimMap* _map = nullptr;  // TODO: make method for recreating value

public:
    void ClearCoreMemory();
    static Core* getInstance();
    std::string GetMapValue();
    int GetFPS();
    int GetMapWidth();
    int GetMapHeight();
    int GetSpeedValue(); // TODO: speed in percent
    int GetAngleValue(); // Note: get angle step value
    void SetFPS(int FPS); // TODO: implement this as part of the settings
    void LeftRotateMoveSig();
    void RightRotateMoveSig();
    void ForwardMoveSig();
    void StopMoveSig();
    void MoveAllObjects();
    ICP_CODE CreateNewControlledRobotFromTemplate(float x, float y);
    ICP_CODE CreateNewAutomatedRobotFromTemplate(float x, float y);
    ICP_CODE CreateNewWallFromTemplate(float x, float y);
    ICP_CODE UpdateRobotState(SimObjView view);
    ICP_CODE UpdateWallState(SimObjView view);
    ICP_CODE RemoveRobotByOrderIndex(int orderIndex);
    ICP_CODE RemoveWallByOrderIndex(int orderInex);
    ICP_CODE LoadingMap(std::string path);
    const std::vector<Wall*>& GetVectorWalls() const;
    const std::vector<Robot*>& GetVectorRobots() const;
    std::vector<SimObjView> GetVectorWallsView();
    std::vector<SimObjView> GetVectorRobotsView();
    SimObjView GetControlledRobotTemp();
    SimObjView GetAutomatedRobotTemp();
    SimObjView GetWallTemp();
    ICP_CODE GetViewByOrderGUI(SimObjView* view, int orderIndex, bool IsRobot);
    void SetControlledRobotTemp(SimObjView newTemp);
    void SetAutomatedRobotTemp(SimObjView newTemp);
    void SetWallTemp(SimObjView newTemp);
    int GetLastOrderIndex();
};

#endif // CORE_H
