#ifndef CORE_H
#define CORE_H

#include <string>
#include "entities/Robot.h"

class Core
{
private:
    Core();
    static Core* _core;
    std::string _map;
    bool _simIsRun;
    bool _simIsReady;
    Robot* _controlledRobot;

public:
    static Core* getInstance();
    // Controller part
    std::string GetMapValue();
    int GetSpeedValue();
    int GetAngleValue(); // Note: get angle step value.
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
