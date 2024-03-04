#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "MyTransform.h"

#include "../core.h"
// Note: We need this to get simulation field width and height

class Movement
{
private:
    float _speed;
    float _angle;
    MyTransform* _transform;

public:
    Movement(float speed, float angle, MyTransform* transform);
    void Move();
};

#endif // MOVEMENT_H
