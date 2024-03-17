#include "SimMap.h"

SimMap::SimMap(std::string path, int width, int height)
{
    _path = path;
    _width = width;
    _height = height;
    _factory = new SimFactory();
    // LoadObjects(); // TODO: load objects implementation
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

int SimMap::LoadObjects()
{
    // Restart all objects
    _factory->DeleteAllObjects();

    // Open the map
    std::ifstream _map(_path);

    // Check if the map is opened
    if (!_map.is_open())
    {
        std::cerr << "Error: Unable to open map\n";
        return 1;
    }

    // Read each line from the file
    std::string _line;

    while (std::getline(_map, _line))
    {
        // Empty line
        if (_line.empty()) continue;

        // Controlled robot
        if (_line.find("[ControlledRobot]") == 0)
        {
            float x, y, w, h;
            float speed;
            int angleStep, angleDegrees;

            if (sscanf(_line.c_str(), "[ControlledRobot] x=%f, y=%f, w=%f, h=%f, speed=%f, angleStep=%d, angleDegrees=%d",
                                                        &x,   &y,   &w,   &h,   &speed,   &angleStep,   &angleDegrees) == 7)
            {
                if (_factory->GetControlledRobot() == nullptr)
                {
                    Robot* controlledRobot = new Robot({x, y}, {w, h}, speed, angleStep, angleDegrees);
                    _factory->SetControlledRobot(controlledRobot);
                }
                else
                {
                    std::cerr << "Error: Only one controlled robot\n";
                    return 2;
                }
            }
            else
            {
                std::cerr << "Error: Invalid format for [ControlledRobot] line\n";
                return 3;
            }
        }

        // Wall
        else if (_line.find("[Wall]") == 0)
        {
            float x, y, w, h;

            if (sscanf(_line.c_str(), "[Wall] x=%f, y=%f, w=%f, h=%f", &x, &y, &w, &h) == 4)
            {
                Wall* wall = new Wall({x, y}, {w, h});
                _factory->AddWall(wall);
            }
            else
            {
                std::cerr << "Error: Invalid format for [Wall] line\n";
                return 3;
            }
        }

        // Other
        else
        {
            std::cerr << "Error: Unrecognized object type\n";
            return 4;
        }
    }

    return 0;
}
