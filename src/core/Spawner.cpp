/**
 * @file Spawner.cpp
 * @author Baturov Illia (xbatur00@stud.fit.vutbr.cz)
 * @author Kukhta Myron (xkukht01@stud.fit.vutbr.cz)
 * @brief Implementation of the spawner class and its methods
 * Note: This file is a freestyle interpretation of the factory method
 */

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
    _controlledRobotTemp = { 0.0, 0.0, 0.0, 0.0, 50.0, 50.0, 5.0, 75.0, 45, 0, 1, RED, -1, true, true }; // default values
    _automatedRobotTemp = { 0.0, 0.0, 0.0, 0.0, 50.0, 50.0, 5.0, 75.0, 45, 0, 1, GREEN, -1, false, true }; // default values
    _wallTemp = { 0.0, 0.0, 0.0, 0.0, 50.0, 50.0, 0.0, 0.0, 0, 0, 0, BLUE, -1, false, false }; // default values
}

Robot* Spawner::GenNewRobot(float x, float y, int orderIndex, bool isControlled)
{
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
    return new Wall (
                        { x, y },
                        { _wallTemp.w, _wallTemp.h },
                        _wallTemp.color,
                        orderIndex
                    );
}

Robot* Spawner::GenNewRobot(std::istringstream& specification, int orderIndex, bool isControlled)
{
    float x, y, d, speed, collisionDistance;
    int angleStep, angleDegrees, rotateClockwise;
    std::string colorString, test;
    colors color;

    if (!(specification >> x >> y >> d >> speed >> collisionDistance >> angleStep >> angleDegrees >> rotateClockwise >> colorString))
    {
        return nullptr;
    }
    if (specification >> test)
    {
        return nullptr;
    }
    if (!convertColorsStringToCode(colorString, &color))
    {
        return nullptr;
    }
    if(rotateClockwise != -1 && rotateClockwise != 1)
    {
        return nullptr;
    }

    if(!(d >= 10 && d <= 1000))
    {
        return nullptr;
    }

    if(!(speed >= 0 && speed <= 100))
    {
        return nullptr;
    }

    if(!(collisionDistance >= 0 && collisionDistance <= 1000))
    {
        return nullptr;
    }

    return new Robot(
                        { x, y },
                        { d, d },
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
        return nullptr;
    }
    if (specification >> test)
    {
        return nullptr;
    }
    if (!convertColorsStringToCode(colorString, &color))
    {
        return nullptr;
    }

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
