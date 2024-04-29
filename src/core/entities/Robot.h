#ifndef ROBOT_H
#define ROBOT_H

#include "SimObject.h"
#include "../properties/Movement.h"
#include <iostream>

class Robot : public SimObject
{
private:
    Movement* _movement;
    bool _isControlled;

public:
    Robot(  Vector2d position,
            Vector2d size,
            float speed,
            float collisionDistance,
            int angleStep,
            int angleDegrees,
            int rotateClockwise,
            colors color,
            int orderIndex,
            bool isControlled);
    ~Robot();
    bool IsControlled();
    Movement* GetMovement();
    SimObjView GetSimObjView() override;
    void SetSimObjView(SimObjView view) override;
};

#endif // ROBOT_H
