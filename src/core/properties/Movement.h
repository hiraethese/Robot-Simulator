#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "MyTransform.h"

class Movement
{
private:
    float _speed;
    float _angle;
    MyTransform* _transform;

public:
    Movement(float speed, float angle, MyTransform* transform);
};

#endif // MOVEMENT_H
