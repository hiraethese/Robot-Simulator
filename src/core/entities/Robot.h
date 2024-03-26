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
            int angleStep,
            int angleDegrees,
            colors color = RED,
            bool isControlled = true);
    ~Robot();
    Movement* GetMovement();
    SimObjView GetSimObjView() override;
};

#endif // ROBOT_H
