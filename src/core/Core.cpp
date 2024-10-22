/**
 * @file Core.cpp
 * @author Baturov Illia (xbatur00@stud.fit.vutbr.cz)
 * @author Kukhta Myron (xkukht01@stud.fit.vutbr.cz)
 * @brief Implementation of the simulation core using singleton pattern
 */

#include "Core.h"

Core* Core::_core = nullptr;

Core::Core()
{
    _map = new SimMap(1800, 750);
}

void Core::ClearCoreMemory()
{
    delete _map;
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
            robot->GetMovement()->MoveControlledRobot( robot->GetOrderIndex() );
        }
        else
        {
            robot->GetMovement()->MoveAutomatedRobot( robot->GetOrderIndex() );
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

ICP_CODE Core::UpdateRobotState(SimObjView view)
{
    return _map->UpdateRobotState(view);
}

ICP_CODE Core::UpdateWallState(SimObjView view)
{
    return _map->UpdateWallState(view);
}

ICP_CODE Core::RemoveRobotByOrderIndex(int orderIndex)
{
    return _map->RemoveRobotByOrderIndex(orderIndex);
}

ICP_CODE Core::RemoveWallByOrderIndex(int orderIndex)
{
    return _map->RemoveWallByOrderIndex(orderIndex);
}

ICP_CODE Core::LoadingMap(std::string path)
{
    return _map->LoadObjectsFromFile(path);
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

ICP_CODE Core::GetViewByOrderGUI(SimObjView* view, int orderIndex, bool isRobot)
{
    if(isRobot){
        return _map->GetRobotViewByOrderGUI(view, orderIndex);
    }
    else{
        return _map->GetWallViewByOrderGUI(view, orderIndex);
    }
}

int Core::GetLastOrderIndex(){
    return _map->GetLastOrderIndex();
}
