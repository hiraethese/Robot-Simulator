#include "Core.h"

Core* Core::_core = nullptr;

Core::Core()
{
    _FPS = 16; // Note: not actually "Frames Per Second", the name is for convenience
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


void Core::SetFPS(int FPS)
{
    _FPS = FPS;
}

void Core::LeftRotateMoveSig()
{
    for (Robot* robot : GetVectorRobots()) {
        if (robot->IsControlled()) {
            robot->GetMovement()->RotateLeft();
        }
    }
}

void Core::RightRotateMoveSig()
{
    for (Robot* robot : GetVectorRobots()) {
        if (robot->IsControlled()) {
            robot->GetMovement()->RotateRight();
        }
    }
}

void Core::ForwardMoveSig()
{
    for (Robot* robot : GetVectorRobots()) {
        if (robot->IsControlled()) {
            robot->GetMovement()->EnableMovement();
        }
    }
}

void Core::StopMoveSig()
{
    for (Robot* robot : GetVectorRobots()) {
        if (robot->IsControlled()) {
            robot->GetMovement()->DisableMovement();
        }
    }
}

void Core::MoveAllObjects()
{
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
    return _map->CreateNewControlledRobotFromTemplate(x, y);
}

ICP_CODE Core::CreateNewAutomatedRobotFromTemplate(float x, float y)
{
    return _map->CreateNewAutomatedRobotFromTemplate(x, y);
}

ICP_CODE Core::CreateNewWallFromTemplate(float x, float y)
{
    return _map->CreateNewWallFromTemplate(x, y);
}

void Core::RemoveRobotByOrderIndex(int orderIndex)
{
    _map->RemoveRobotByOrderIndex(orderIndex);
}

void Core::RemoveWallByOrderIndex(int orderIndex)
{
    _map->RemoveWallByOrderIndex(orderIndex);
}

ICP_CODE Core::LoadingMap(std::string path)
{
    return _map->LoadObjectsFromFile(path);// TODO: call load objects from file from the gui
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
