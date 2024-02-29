#include "MyTransform.h"

MyTransform::MyTransform(Vector2d position, Vector2d size)
{
    _position = position;
    _size = size;
}

Rectangle MyTransform::GetRect()
{
    return {_position.x - 0.5f * _size.x,
            _position.y - 0.5f * _size.y,
            _size.x,
            _size.y};
}
