#include "Core.h"

Core::Core()
{
    _map = "";
    _simIsRun = false;
    _simIsReady = false;
    _controlledRobot = new Robot({50.0f, 50.0f}, {100.0f, 100.0f}, 10.0f, 180.0f);
}

Core *Core::getInstance()
{
    if (!_core) {
        _core = new Core();
    }
    return _core;
}

// Controller part

std::string Core::GetMapValue()
{
    return _map;
}

int Core::GetSpeedValue()
{
    return (int)_controlledRobot->GetMovement()->GetSpeed();
}

int Core::GetAngleValue()
{
    return (int)_controlledRobot->GetMovement()->GetAngle();
}

bool Core::IsSimReady()
{
    return _simIsReady;
}

bool Core::IsSimRun()
{
    return _simIsRun;
}

void Core::ForwardMoveSig()
{
    _controlledRobot->GetMovement()->MoveForward();
}

void Core::LeftRotateMoveSig()
{
    _controlledRobot->GetMovement()->RotateLeft();
}

void Core::RightRotateMoveSig()
{
    _controlledRobot->GetMovement()->RotateRight();
}
