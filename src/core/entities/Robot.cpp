#include "Robot.h"

Robot::Robot(Vector2d position, Vector2d size, float speed, float angle) : SimObject(position, size)
{
    _movement = new Movement(speed, angle, _transform);
}

Robot::~Robot()
{
    delete _movement;
}

Movement* Robot::GetMovement()
{
    return _movement;
}
