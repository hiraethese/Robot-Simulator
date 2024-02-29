#ifndef MYTRANSFORM_H
#define MYTRANSFORM_H

#include "../icplib.h"

class MyTransform {
private:
    Vector2d _position;
    Vector2d _size;

public:
    MyTransform(Vector2d position, Vector2d size);
    void SetPosition(Vector2d newPosition);
    Vector2d GetPosition();
    Rectangle GetRect();
};

#endif // MYTRANSFORM_H
