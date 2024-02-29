#include "Movement.h"

Movement::Movement(float speed, float angle, MyTransform *transform)
{
    _speed = speed;
    _angle = angle;
    _transform = transform;
}
