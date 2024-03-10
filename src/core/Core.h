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
    int GetAngleValue();
    bool IsSimReady();
    bool IsSimRun();
    void ForwardMoveSig();
    void LeftRotateMoveSig();
    void RightRotateMoveSig();
};

#endif // CORE_H
