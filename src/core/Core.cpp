#include "Core.h"
Core* Core::_core= nullptr;
Core::Core()
{
    _map = "";
    _simIsRun = false;
    _simIsReady = true;  //  TODO: make setting arg from user by setting; now default true
    _controlledRobot = new Robot({50.0f, 50.0f}, {100.0f, 100.0f}, 10.0f, 90.0f);
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

void Core::SetRunSim(bool setter)
{
    _simIsReady = setter;
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

Rectangle Core::RectFromCore()
{
    return _controlledRobot->GetTransform()->GetRect();
}