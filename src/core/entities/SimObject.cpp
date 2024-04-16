#include "SimObject.h"

SimObject::SimObject(Vector2d position, Vector2d size, colors color, int orderIndex)
{
    _transform = new MyTransform(position, size);
    _color = color;
    _orderIndex = orderIndex;
}

SimObject::~SimObject()
{
    delete _transform;
}

MyTransform* SimObject::GetTransform()
{
    return _transform;
}
