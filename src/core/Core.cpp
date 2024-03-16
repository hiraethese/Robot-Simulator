#include "Core.h"

Core* Core::_core = nullptr;

Core::Core()
{
    _FPS = 16; // Note: not actually "Frames Per Second", the name is for convenience
    _simIsRun = false;
    _simIsReady = true; // TODO: make setting arg from user by setting; now default true
    _map = new SimMap("example.txt", 1800, 750);
    _controlledRobot = new Robot({50.0f, 50.0f}, {100.0f, 100.0f}, 5.0f, 45, 0);
}

Core *Core::getInstance()
{
    if (!_core) {
        _core = new Core();
    }
    return _core;
}

void Core::SetNewSettings(const SimSettings &newSettings)
{
    if(newSettings.flagNewMap)
    {
        _map->SetPath(newSettings.newMapValue);
        _simIsReady = true;
    }

    if(newSettings.flagNewSpeed)
    {
        _controlledRobot->GetMovement()->SetSpeed(newSettings.newSpeedValue);
    }

    if(newSettings.flagNewAngle)
    {
        _controlledRobot->GetMovement()->SetAngleStep(newSettings.newAngleValue);
    }
}

std::string Core::GetMapValue()
{
    return _map->GetPath();
}

int Core::GetFPS()
{
    return _FPS;
}

int Core::GetMapWidth()
{
    return _map->GetWidth();
}

int Core::GetMapHeight()
{
    return _map->GetHeight();
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

void Core::SetFPS(int FPS)
{
    _FPS = FPS;
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
