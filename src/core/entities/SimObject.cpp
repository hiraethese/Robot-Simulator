#include "SimObject.h"

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
