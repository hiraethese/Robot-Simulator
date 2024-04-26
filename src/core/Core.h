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
    bool _simIsRun = false;
    bool _simIsReady = false;
    SimMap* _map = nullptr;  // TODO: make method for recreating value

public:
    static Core* getInstance();
    std::string GetMapValue();
    int GetFPS();
    int GetMapWidth();
    int GetMapHeight();
    int GetSpeedValue(); // TODO: speed in percent
    int GetAngleValue(); // Note: get angle step value
    bool IsSimReady();
    bool IsSimRun();
    void SetFPS(int FPS); // TODO: implement this as part of the settings
    void SetRunSim(bool setter);
    void LeftRotateMoveSig();
    void RightRotateMoveSig();
    void ForwardMoveSig();
    void StopMoveSig();
    void MoveAllObjects();
    ICP_CODE LoadingMap(std::string path);
    const std::vector<Wall*>& GetVectorWalls() const;
    const std::vector<Robot*>& GetVectorRobots() const;
    std::vector<SimObjView> GetVectorWallsView();
    std::vector<SimObjView> GetVectorRobotsView();
    SimObjView GetControlledRobotTemp();
    SimObjView GetBotRobotTemp();
    SimObjView GetWallTemplate();
};

#endif // CORE_H
