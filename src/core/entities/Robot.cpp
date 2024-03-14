#include "Robot.h"

Robot::Robot(Vector2d position, Vector2d size, float speed, int angleStep, int angleDegrees) : SimObject(position, size)
{
    _movement = new Movement(speed, angleStep, angleDegrees, _transform);
}

Robot::~Robot()
{
    delete _movement;
}

Movement* Robot::GetMovement()
{
    return _movement;
}
