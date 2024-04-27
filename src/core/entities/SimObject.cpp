#include "SimObject.h"

SimObject::SimObject(Vector2d position, Vector2d size, colors color, int orderIndex)
{
    _transform = new MyTransform(position, size);
    _orderIndex = orderIndex;
    _color = color;
}

SimObject::~SimObject()
{
    delete _transform;
}

MyTransform* SimObject::GetTransform()
{
    return _transform;
}

int SimObject::GetOrderIndex()
{
    return _orderIndex;
}
