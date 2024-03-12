#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "MyTransform.h"
#include <iostream>

#define SIMFIELD_W 1800 // TO DO - Map class
#define SIMFIELD_H 750  // TO DO - Map class

class Movement
{
private:
    bool _isMoving;
    float _speed;
    float _stepAngle;
    float _angleDegrees;
    MyTransform* _transform;

public:
    Movement(float speed, float angleDegrees, MyTransform* transform);
    float GetSpeed();
    float GetAngle(); // Note: Get step angle.
    void SetSpeed(float newSpeed);
    void SetAngle(float newAngleDegrees);
    void RotateLeft();
    void RotateRight();
    void MoveForward();
    void StopMoving();
};

#endif // MOVEMENT_H
