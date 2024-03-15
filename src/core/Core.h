#ifndef CORE_H
#define CORE_H

#include <string>
#include "SimMap.h"
#include "entities/Robot.h"

class Core
{
private:
    Core();
    static Core* _core;
    int _FPS;
    bool _simIsRun;
    bool _simIsReady;
    SimMap* _map;
    Robot* _controlledRobot;

public:
    static Core* getInstance();
    // Controller part
    int GetFPS();
    void SetFPS(int FPS);
    std::string GetMapValue();
    int GetMapWidth();
    int GetMapHeight();
    int GetSpeedValue();
    int GetAngleValue(); // Note: get angle step value
    bool IsSimReady();
    bool IsSimRun();
    void SetRunSim(bool setter);
    void LeftRotateMoveSig();
    void RightRotateMoveSig();
    void ForwardMoveSig();
    void StopMoveSig();
    void MoveAllObjects();
    Rectangle RectFromCore();
};

#endif // CORE_H
