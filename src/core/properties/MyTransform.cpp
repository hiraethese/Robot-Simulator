#include "MyTransform.h"

MyTransform::MyTransform(Vector2d position, Vector2d size)
{
    _position = position;
    _size = size;
}

void MyTransform::SetPosition(Vector2d newPosition)
{
    _position = newPosition;
}
void MyTransform::SetSize(Vector2d newSize){
    _size = newSize;
}
Vector2d MyTransform::GetPosition()
{
    return _position;
}

Vector2d MyTransform::GetSize()
{
    return _size;
}
