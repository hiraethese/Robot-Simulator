#include "Spawner.h"

// typedef struct SimObjView {
//     float x;
//     float y;
//     float w;
//     float h;
//     float speed;
//     float collisionDistance;
//     int angleStep;
//     int angleDegrees;
//     int rotateClockwise;
//     colors colorCode;
//     int orderIndex;
//     bool isControlled;
//     bool isRobot;
// } SimObjView;

Spawner::Spawner()
{
    _controlledRobotTemp = { 0.0, 0.0, 50.0, 50.0, 5.0, 75.0, 45, 0, 1, RED, -1, true, true }; // default values
    _automatedRobotTemp = { 0.0, 0.0, 50.0, 50.0, 5.0, 75.0, 45, 0, 1, GREEN, -1, false, true }; // default values
    _wallTemp = { 0.0, 0.0, 50.0, 50.0, 0.0, 0.0, 0, 0, 0, BLUE, -1, false, false }; // default values
}

Robot* Spawner::GenNewRobot(float x, float y, int orderIndex, bool isControlled)
{
    // Debug
    std::cout << x << y << orderIndex << isControlled;

    // return new Robot({ x, y }, { w, h }, speed, collisionDistance, angleStep, angleDegrees, rotateClockwise, colorCode, orderIndex, isControlled);
    if (isControlled)
    {
        return new Robot(
                            { x, y },
                            { _controlledRobotTemp.w, _controlledRobotTemp.h },
                            _controlledRobotTemp.speed,
                            _controlledRobotTemp.collisionDistance,
                            _controlledRobotTemp.angleStep,
                            _controlledRobotTemp.angleDegrees,
                            _controlledRobotTemp.rotateClockwise,
                            _controlledRobotTemp.color,
                            orderIndex,
                            isControlled
                        );
    }
    else
    {
        return new Robot(
                            { x, y },
                            { _automatedRobotTemp.w, _automatedRobotTemp.h },
                            _automatedRobotTemp.speed,
                            _automatedRobotTemp.collisionDistance,
                            _automatedRobotTemp.angleStep,
                            _automatedRobotTemp.angleDegrees,
                            _automatedRobotTemp.rotateClockwise,
                            _automatedRobotTemp.color,
                            orderIndex,
                            isControlled
                        );
    }
}

Wall* Spawner::GenNewWall(float x, float y, int orderIndex)
{
    // Debug
    std::cout << x << y << orderIndex;

    // return new Wall({ x, y }, { w, h }, colorCode, orderIndex);
    return new Wall (
                        { x, y },
                        { _wallTemp.w, _wallTemp.h },
                        _wallTemp.color,
                        orderIndex
                    );
}

Robot* Spawner::GenNewRobot(std::istringstream& specification, int orderIndex, bool isControlled)
{
    float x, y, w, h, speed, collisionDistance;
    int angleStep, angleDegrees, rotateClockwise;
    std::string colorString, test;
    colors color;

    if (!(specification >> x >> y >> w >> h >> speed >> collisionDistance >> angleStep >> angleDegrees >> rotateClockwise >> colorString))
    {
        std::cerr << "Error: Invalid format for [ControlledRobot] line\n";
        return nullptr;
    }
    if (specification >> test) {
        std::cerr << "Error: Invalid format for [ControlledRobot] line\n";
        return nullptr;
    }
    if (!convertColorsStringToCode(colorString, &color)) {
        std::cerr << "Error: Invalid colors format for robot";
        return nullptr;
    }
    if(rotateClockwise != -1 && rotateClockwise != 1){
        std::cerr << "Error: Invalid rotate clockwise valeu for robot";
        return nullptr;
    }

    // Debug
    std::cout << "Controlled robot: "
        << "x=" << x << ", y=" << y << ", w=" << w << ", h=" << h << ", speed=" << speed << ", collisionDistance=" << collisionDistance
        << ", angleStep=" << angleStep << ", angleDegrees=" << angleDegrees << ", rotateClockwise=" << rotateClockwise
        << std::endl;

    return new Robot(
                        { x, y },
                        { w, h },
                        speed,
                        collisionDistance,
                        angleStep,
                        angleDegrees,
                        rotateClockwise,
                        color,
                        orderIndex,
                        isControlled
                    );
}

Wall* Spawner::GenNewWall(std::istringstream& specification, int orderIndex)
{
    float x, y, w, h;
    std::string colorString, test;
    colors color;

    if (!(specification >> x >> y >> w >> h >> colorString))
    {
        std::cerr << "Error: Invalid format for [Wall] line\n";
        return nullptr;
    }
    if (specification >> test) {
        std::cerr << "Error: Invalid format for [Wall] line\n";
        return nullptr;
    }
    if (!convertColorsStringToCode(colorString, &color)) {
        std::cerr << "Error: Invalid colors format for robot";
        return nullptr;
    }

    // Debug
    std::cout << "Wall: "
        << "x=" << x << ", y=" << y << ", w=" << w << ", h=" << h
        << std::endl;

    return new Wall (
                        { x, y },
                        { w, h },
                        color,
                        orderIndex
                    );
}

SimObjView Spawner::GetControlledRobotTemp()
{
    return _controlledRobotTemp;
}

SimObjView Spawner::GetAutomatedRobotTemp()
{
    return _automatedRobotTemp;
}

SimObjView Spawner::GetWallTemp()
{
    return _wallTemp;
}

void Spawner::SetControlledRobotTemp(SimObjView newTemp)
{
    _controlledRobotTemp = newTemp;
}

void Spawner::SetAutomatedRobotTemp(SimObjView newTemp)
{
    _automatedRobotTemp = newTemp;
}

void Spawner::SetWallTemp(SimObjView newTemp)
{
    _wallTemp = newTemp;
}
