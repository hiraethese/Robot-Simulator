#include "Core.h"

Core* Core::_core = nullptr;

Core::Core()
{
    _FPS = 16; // Note: not actually "Frames Per Second", the name is for convenience
    // TODO: after in end delete this
    //_simIsRun = false;
    _simIsReady = false; // TODO: make setting arg from user by setting; now default true
    _map = new SimMap(1800, 750);
}

Core *Core::getInstance()
{
    if (!_core) {
        _core = new Core();
    }
    return _core;
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
    return (int)_map->GetFirstControlledRobot()->GetMovement()->GetSpeed();
}

int Core::GetAngleValue()
{
    return _map->GetFirstControlledRobot()->GetMovement()->GetAngleStep();
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
    // _map->GetFactory()->GetControlledRobot()->GetMovement()->RotateLeft();
    for (Robot* robot : GetVectorRobots()) {
        if (robot->IsControlled()) {
            robot->GetMovement()->RotateLeft();
        }
    }
}

void Core::RightRotateMoveSig()
{
    // _map->GetFactory()->GetControlledRobot()->GetMovement()->RotateRight();
    for (Robot* robot : GetVectorRobots()) {
        if (robot->IsControlled()) {
            robot->GetMovement()->RotateRight();
        }
    }
}

void Core::ForwardMoveSig()
{
    // _map->GetFactory()->GetControlledRobot()->GetMovement()->EnableMovement();
    for (Robot* robot : GetVectorRobots()) {
        if (robot->IsControlled()) {
            robot->GetMovement()->EnableMovement();
        }
    }
}

void Core::StopMoveSig()
{
    // _map->GetFactory()->GetControlledRobot()->GetMovement()->DisableMovement();
    for (Robot* robot : GetVectorRobots()) {
        if (robot->IsControlled()) {
            robot->GetMovement()->DisableMovement();
        }
    }
}

void Core::MoveAllObjects()
{
    // _map->GetFactory()->GetControlledRobot()->GetMovement()->MoveAutomatedRobot();
    for (Robot* robot : GetVectorRobots()) {
        if (robot->IsControlled()) {
            robot->GetMovement()->MoveControlledRobot();
        } 
        else
        {
            robot->GetMovement()->MoveAutomatedRobot();
        }
    }
}

const std::vector<Wall *>& Core::GetVectorWalls() const
{
    return _map->GetWalls();
}

const std::vector<Robot*>& Core::GetVectorRobots() const
{
    return _map->GetRobots();
}

std::vector<SimObjView> Core::GetVectorWallsView()
{
    return _map->GetVectorWallsView();
}

std::vector<SimObjView> Core::GetVectorRobotsView()
{
    return _map->GetVectorRobotsView();
}

ICP_CODE Core::CreateNewControlledRobotFromTemplate(float x, float y)
{
    return _map->CreateNewObjectFromTemplate(x, y, true, true);
}

ICP_CODE Core::CreateNewAutomatedRobotFromTemplate(float x, float y)
{
    return _map->CreateNewObjectFromTemplate(x, y, true, false);
}

ICP_CODE Core::CreateNewWallFromTemplate(float x, float y)
{
    return _map->CreateNewObjectFromTemplate(x, y, false, false);
}

ICP_CODE Core::LoadingMap(std::string path)
{
    ICP_CODE result = _map->LoadObjectsFromFile(path); // TODO: call load objects from file from the gui
    if(!result){

        _simIsReady = true;

    }
    else{

        _simIsReady = false;

    }
    return result;
}

SimObjView Core::GetControlledRobotTemp()
{
    return _map->GetSpawner()->GetControlledRobotTemp();
}

SimObjView Core::GetAutomatedRobotTemp()
{
    return _map->GetSpawner()->GetAutomatedRobotTemp();
}

SimObjView Core::GetWallTemp()
{
    return _map->GetSpawner()->GetWallTemp();
}

void Core::SetControlledRobotTemp(SimObjView newTemp)
{
    _map->GetSpawner()->SetControlledRobotTemp(newTemp);
}

void Core::SetAutomatedRobotTemp(SimObjView newTemp)
{
    _map->GetSpawner()->SetAutomatedRobotTemp(newTemp);
}

void Core::SetWallTemp(SimObjView newTemp)
{
    _map->GetSpawner()->SetWallTemp(newTemp);
}
