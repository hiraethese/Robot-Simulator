#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "MyTransform.h"
#include <iostream>
#define SIMFIELD_W 1800
#define SIMFIELD_H 750

class Movement
{
private:
    float _speed;
    float _angleDegrees;
    float _stepAngle;
    MyTransform* _transform;

public:
    Movement(float speed, float angleDegrees, MyTransform* transform);
    float GetSpeed();
    float GetAngle();
    void SetSpeed(float newSpeed);
    void SetAngle(float newAngleDegrees);
    void RotateLeft();
    void RotateRight();
    void MoveForward();
};

#endif // MOVEMENT_H
