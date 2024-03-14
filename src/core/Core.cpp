#include "Core.h"

Core* Core::_core = nullptr;

Core::Core()
{
    _map = "";
    _simIsRun = false;
    _simIsReady = true; // TODO: make setting arg from user by setting; now default true
    _controlledRobot = new Robot({50.0f, 50.0f}, {100.0f, 100.0f}, 5.0f, 45, 0);
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
    return _controlledRobot->GetMovement()->GetAngleStep();
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
    _simIsRun = setter;
}

void Core::LeftRotateMoveSig()
{
    _controlledRobot->GetMovement()->RotateLeft();
}

void Core::RightRotateMoveSig()
{
    _controlledRobot->GetMovement()->RotateRight();
}

void Core::ForwardMoveSig()
{
    _controlledRobot->GetMovement()->EnableMovement();
}

void Core::StopMoveSig()
{
    _controlledRobot->GetMovement()->DisableMovement();
}

void Core::MoveAllObjects()
{
    _controlledRobot->GetMovement()->MoveForward();
}

Rectangle Core::RectFromCore()
{
    return _controlledRobot->GetTransform()->GetRect();
}
