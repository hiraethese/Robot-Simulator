#ifndef CORE_H
#define CORE_H

#include <string>
#include "SimMap.h"
#include "SimFactory.h"

// Simulation settings structure with default values
struct SimSettings
{
    bool flagNewMap = false;
    std::string newMapValue = "example.txt";
    bool flagNewSpeed = false;
    int newSpeedValue = 5;
    bool flagNewAngle = false;
    int newAngleValue = 45;
};

// Core class with controller methods
class Core
{
private:
    Core();
    static Core* _core;
    int _FPS;
    bool _simIsRun;
    bool _simIsReady;
    SimFactory* _factory;
    SimMap* _map;

public:
    static Core* getInstance();
    void SetNewSettings(const SimSettings& newSettings);
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
    Rectangle RectFromCore();
};

#endif // CORE_H
