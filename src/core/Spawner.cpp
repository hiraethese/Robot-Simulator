#include "Spawner.h"
Spawner::Spawner()
{
    _autoRobotTemplate = { -1, 0.0, 0.0, 30.0, 30.0, GREEN, true, false, 0, 0, 0 };  // default value
    _controlledRobotTemplate = { -1, 0.0, 0.0, 30.0, 30.0, RED, true, true, 0, 0, 0 };  // default value
    _wallTemplate = { -1, 0.0, 0.0, 30.0, 30.0, BLUE, false, false, 0, 0, 0 };  // default value
}

Robot* Spawner::GenNewRobot(float x, float y, int orderIndex, bool isControlled)
{
    std::cout << x << y << orderIndex << isControlled;
    return nullptr;
}

Wall* Spawner::GenNewWall(float x, float y, int orderIndex)
{
    std::cout << x << y << orderIndex;
    return nullptr;
}

Robot* Spawner::GenNewRobot(std::istringstream& specification, int orderIndex, bool isControlled)
{
    float x, y, w, h, speed, collisionDistance;
    int angleStep, angleDegrees, rotateClockwise;
    std::string colorString;
    colors colorCode;
        if (!(specification >> x >> y >> w >> h >> speed >> collisionDistance >> angleStep >> angleDegrees >> rotateClockwise >> colorString))
        {
            std::cerr << "Error: Invalid format for [ControlledRobot] line\n";
            return nullptr;
        }
    if (!convertColorsStringToCode(colorString, &colorCode)) {
        std::cerr << "Error: Invalid colors format for robot";
        return nullptr;
    }
    // Debug
    std::cout << "Controlled robot: "
        << "x=" << x << ", y=" << y << ", w=" << w << ", h=" << h << ", speed=" << speed << ", collisionDistance=" << collisionDistance
        << ", angleStep=" << angleStep << ", angleDegrees=" << angleDegrees << ", rotateClockwise=" << rotateClockwise
        << std::endl;

    return new Robot({ x, y }, { w, h }, speed, collisionDistance, angleStep, angleDegrees, rotateClockwise, colorCode, orderIndex, isControlled);
}
Wall* Spawner::GenNewWall(std::istringstream& specification, int orderIndex)
{
    float x, y, w, h;
    std::string colorString;
    colors colorCode;
    if (!(specification >> x >> y >> w >> h >> colorString))
    {
        std::cerr << "Error: Invalid format for [Wall] line\n";
        return nullptr;
    }
    if (!convertColorsStringToCode(colorString, &colorCode)) {
        std::cerr << "Error: Invalid colors format for robot";
            return nullptr;
    }
    // Debug
    std::cout << "Wall: "
        << "x=" << x << ", y=" << y << ", w=" << w << ", h=" << h
        << std::endl;

    return new Wall({ x, y }, { w, h }, colorCode, orderIndex);
    
}

SimObjView Spawner::GetControlledRobotTemp()
{
    return _controlledRobotTemplate;
}

SimObjView Spawner::GetAutoRobotTemp()
{
    return _autoRobotTemplate;
}

SimObjView Spawner::GetWallTemp()
{
    return _wallTemplate;
}

