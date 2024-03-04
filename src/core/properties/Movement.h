#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "MyTransform.h"

class Movement
{
private:
    float _speed;
    float _angleDegrees;
    MyTransform* _transform;

public:
    Movement(float speed, float angleDegrees, MyTransform* transform);
    void Move();
};

#endif // MOVEMENT_H
