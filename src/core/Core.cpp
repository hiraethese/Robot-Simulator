#include "Core.h"

Core* Core::_core = nullptr;

Core::Core()
{
    _FPS = 16; // Note: not actually "Frames Per Second", the name is for convenience
    _simIsRun = false;
    _simIsReady = true; // TODO: make setting arg from user by setting; now default true
    _factory = new SimFactory();
    _map = new SimMap("example.txt", 1800, 750);
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
        _factory->GetControlledRobot()->GetMovement()->SetSpeed(newSettings.newSpeedValue);
    }

    if(newSettings.flagNewAngle)
    {
        _factory->GetControlledRobot()->GetMovement()->SetAngleStep(newSettings.newAngleValue);
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
    return (int)_factory->GetControlledRobot()->GetMovement()->GetSpeed();
}

int Core::GetAngleValue()
{
    return _factory->GetControlledRobot()->GetMovement()->GetAngleStep();
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
    _factory->GetControlledRobot()->GetMovement()->RotateLeft();
}

void Core::RightRotateMoveSig()
{
    _factory->GetControlledRobot()->GetMovement()->RotateRight();
}

void Core::ForwardMoveSig()
{
    _factory->GetControlledRobot()->GetMovement()->EnableMovement();
}

void Core::StopMoveSig()
{
    _factory->GetControlledRobot()->GetMovement()->DisableMovement();
}

void Core::MoveAllObjects()
{
    _factory->GetControlledRobot()->GetMovement()->MoveForward();
}

Rectangle Core::RectFromCore()
{
    return _factory->GetControlledRobot()->GetTransform()->GetRect();
}
