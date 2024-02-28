#include "MyTransform.h"

MyTransform::MyTransform(Vector2d position, Vector2d size)
{
    _position = position;
    _size = size;
}

QRectF MyTransform::GuiGetQRectF()
{
    return QRectF(  _position.x - _size.x * 0.5,
                    _position.y - _size.y * 0.5,
                    _size.x,
                    _size.y);
}
