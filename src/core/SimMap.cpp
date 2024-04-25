#include "SimMap.h"

SimMap::SimMap(int width, int height)
{
    //_path = path;
    _width = width;
    _height = height;
    _spawner = new Spawner();
}

void SimMap::DeleteAllObjects()
{
    if (!_robots.empty())
    {
        for (auto& robot : _robots)
        {
            delete robot;
        }
        _robots.clear();
    }
    if (!_walls.empty())
    {
        for (auto& wall : _walls)
        {
            delete wall;
        }
        _walls.clear();
    }
}

std::string SimMap::GetPath()
{
    return _path;
}

int SimMap::GetWidth()
{
    return _width;
}

int SimMap::GetHeight()
{
    return _height;
}

void SimMap::SetPath(std::string newPath)
{
    _path = newPath;
}

int SimMap::LoadObjectsFromFile(std::string path)
{
    _orderIndex = 1;
    _path = path;
    // Restart all objects    
    DeleteAllObjects();
    // Open the file

    QFileInfo infoAboutPath(QString::fromStdString(path));

    if(!infoAboutPath.exists()){

        std::cout << "file not exist" << std::endl;
        return 6;
    }

    if(!infoAboutPath.isFile()){
        std::cout << "it is not file" << std::endl;
        return 7;
    }

    std::ifstream file(_path);
    // Check if the file is opened
    if (!file.is_open())
    {
        std::cerr << "Error: Unable to open map file\n";
        return 1; // Error openning map file
    }
    // Read each line from the file
    std::string line;
    while (std::getline(file, line))
    {
        // Empty line
        if (line.empty()) continue;
        // Create a stringstream from the line
        std::istringstream iss(line);
        // Read the first token
        std::string token;
        if (!(iss >> token))
        {
            std::cerr << "Error: Unable to read token from line\n";
            return 2; // Error reading token from line
        }
        // Controlled robot
        if (token == "[ControlledRobot]")
        {
            Robot* newRobot = _spawner->GenNewRobot(iss, _orderIndex, true);
            if (!newRobot)
            {
                return 3; // Error processing controlled robot line
            }
            _robots.push_back(newRobot);
        }
        // Automated robot
        else if (token == "[AutomatedRobot]")
        {
            Robot* newRobot = _spawner->GenNewRobot(iss, _orderIndex, false);
            if (!newRobot)
            {
                return 4; // Error processing automated robot line
            }
            _robots.push_back(newRobot);
        }
        // Wall
        else if (token == "[Wall]")
        {
            Wall* newWall = _spawner->GenNewWall(iss, _orderIndex);
            if (!newWall)
            {
                return 5; // Error processing wall line
            }
            _walls.push_back(newWall);
        }
        // Other
        else
        {
            std::cerr << "Error: Unrecognized object type\n";
            return 6; // Error with object type from token
        }
        ++_orderIndex;
    }
    return 0;
}


SimObjView SimMap::GetControlledRobotTemp()
{
    return _spawner->GetControlledRobotTemp();
}

SimObjView SimMap::GetBotRobotTemp()
{
    return _spawner->GetAutoRobotTemp();
}

SimObjView SimMap::GetWallTemp()
{
    return _spawner->GetWallTemp();
}

const std::vector<Wall*>& SimMap::GetWalls() const
{
    return _walls;
}

const std::vector<Robot*>& SimMap::GetRobots() const
{
    return _robots;
}


std::vector<SimObjView> SimMap::GetVectorWallsView()
{
    std::vector<SimObjView> wallsView;

    for (Wall* wall : _walls)
    {
        wallsView.push_back(wall->GetSimObjView());
    }

    return wallsView;
}

std::vector<SimObjView> SimMap::GetVectorRobotsView()
{
    std::vector<SimObjView> robotsView;

    for (Robot* robot : _robots)
    {
        robotsView.push_back(robot->GetSimObjView());
    }

    return robotsView;

}



Robot* SimMap::GetFirstControlledRobot()
{
    for (Robot* robot : _robots)
    {
        if (robot->IsControlled())
        {
            return robot;
        }
    }
    return nullptr;
}
