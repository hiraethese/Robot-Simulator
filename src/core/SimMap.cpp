#include "SimMap.h"

SimMap::SimMap(int width, int height)
{
    //_path = path;
    _width = width;
    _height = height;
    _factory = new SimFactory();
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

SimFactory *SimMap::GetFactory()
{
    return _factory;
}

void SimMap::SetPath(std::string newPath)
{
    _path = newPath;
}

int SimMap::LoadObjectsFromFile(std::string path)
{
    _path = path;
    // Restart all objects    
    _factory->DeleteAllObjects();
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
            if (!ProcessControlledRobotLine(iss))
            {
                return 3; // Error processing controlled robot line
            }
        }
        // Wall
        else if (token == "[Wall]")
        {
            if (!ProcessWallLine(iss))
            {
                return 4; // Error processing wall line
            }
        }
        // Other
        else
        {
            std::cerr << "Error: Unrecognized object type\n";
            return 5; // Error with object type from token
        }
    }
    return 0;
}

bool SimMap::ProcessControlledRobotLine(std::istringstream &iss)
{
    float x, y, w, h, speed, collisionDistance;
    int angleStep, angleDegrees, rotateClockwise;
    if (!(iss >> x >> y >> w >> h >> speed >> collisionDistance >> angleStep >> angleDegrees >> rotateClockwise))
    {
        std::cerr << "Error: Invalid format for [ControlledRobot] line\n";
        return false;
    }

    // Debug
    std::cout   << "Controlled robot: "
                << "x=" << x << ", y=" << y << ", w=" << w << ", h=" << h << ", speed=" << speed << ", collisionDistance=" << collisionDistance
                << ", angleStep=" << angleStep << ", angleDegrees=" << angleDegrees << ", rotateClockwise=" << rotateClockwise
                << std::endl;

    Robot* controlledRobot = new Robot({x, y}, {w, h}, speed, collisionDistance, angleStep, angleDegrees, rotateClockwise, RED, true);
    _factory->AddRobot(controlledRobot);
    return true;
}

bool SimMap::ProcessWallLine(std::istringstream &iss)
{
    float x, y, w, h;
    if (!(iss >> x >> y >> w >> h))
    {
        std::cerr << "Error: Invalid format for [Wall] line\n";
        return false;
    }

    // Debug
    std::cout   << "Wall: "
                << "x=" << x << ", y=" << y << ", w=" << w << ", h=" << h
                << std::endl;

    Wall* wall = new Wall({x, y}, {w, h});
    _factory->AddWall(wall);
    return true;
}
