#include "Core.h"

Core* Core::_core = nullptr;

Core::Core()
{
    _FPS = 16; // Note: not actually "Frames Per Second", the name is for convenience
    //_simIsRun = false;
    //_simIsReady = true; // TODO: make setting arg from user by setting; now default true
    _map = new SimMap(1800, 750);
    //_map->LoadObjectsFromFile(); // TODO: call load objects from file from the gui
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
        //_simIsReady = true;
    }

    if(newSettings.flagNewSpeed)
    {
        // _map->GetFactory()->GetControlledRobot()->GetMovement()->SetSpeed(newSettings.newSpeedValue);
        for (Robot* robot : GetVectorRobots()) {
            if (robot->IsControlled()) {
                robot->GetMovement()->SetSpeed(newSettings.newSpeedValue);
            }
        }
    }

    if(newSettings.flagNewAngle)
    {
        // _map->GetFactory()->GetControlledRobot()->GetMovement()->SetAngleStep(newSettings.newAngleValue);
        for (Robot* robot : GetVectorRobots()) {
            if (robot->IsControlled()) {
                robot->GetMovement()->SetAngleStep(newSettings.newAngleValue);
            }
        }
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
    return (int)_map->GetFactory()->GetFirstControlledRobot()->GetMovement()->GetSpeed();
}

int Core::GetAngleValue()
{
    return _map->GetFactory()->GetFirstControlledRobot()->GetMovement()->GetAngleStep();
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
    return _map->GetFactory()->GetWalls();
}

const std::vector<Robot*>& Core::GetVectorRobots() const
{
    return _map->GetFactory()->GetRobots();
}


std::vector<SimObjView> Core::GetVectorWallsView()
{
    return _map->GetFactory()->GetVectorWallsView();
}

std::vector<SimObjView> Core::GetVectorRobotsView()
{
    return _map->GetFactory()->GetVectorRobotsView();
}

int Core::LoadingMap(std::string path)
{
    int result = _map->LoadObjectsFromFile(path); // TODO: call load objects from file from the gui

    if(!result){

        _core->_simIsReady = true;

    }
    else{

        _core->_simIsReady = false;

    }

    return result;
}

SimObjView Core::GetControlledRobotTemp()
{
    return _map->GetFactory()->GetControlledRobotTemp();
}

SimObjView Core::GetBotRobotTemp()
{
    return _map->GetFactory()->GetBotRobotTemp();
}

SimObjView Core::GetWallTemplate(){
    return _map->GetFactory()->GetWallTemp();
}
