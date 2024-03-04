#ifndef ROBOT_H
#define ROBOT_H

#include "SimObject.h"

class Robot : public SimObject
{
private:
    Movement* _movement;

public:
    Robot(Vector2d position, Vector2d size, float speed, float angle);
    ~Robot();
};

#endif // ROBOT_H
