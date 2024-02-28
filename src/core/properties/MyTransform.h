#ifndef MYTRANSFORM_H
#define MYTRANSFORM_H

#include "../icplib.h"

#include <QRectF>

class MyTransform {
private:
    Vector2d _position;
    Vector2d _size;

public:
    MyTransform(Vector2d position, Vector2d size);
    QRectF GuiGetQRectF();
};

#endif // MYTRANSFORM_H
