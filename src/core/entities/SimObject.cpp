#include "SimObject.h"

// SimObject

SimObject::SimObject(Vector2d position, Vector2d size)
{
    _transform = new MyTransform(position, size);
}

SimObject::~SimObject()
{
    delete _transform;
}

MyTransform* SimObject::GetTransform()
{
    return _transform;
}

// Wall

Wall::Wall(Vector2d position, Vector2d size) : SimObject(position, size) {}

// Robot

Robot::Robot(Vector2d position, Vector2d size, float speed, float angle) : SimObject(position, size)
{
    _movement = new Movement(speed, angle, _transform);
}

Robot::~Robot()
{
    delete _movement;
}
