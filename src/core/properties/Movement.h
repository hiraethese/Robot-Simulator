#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "MyTransform.h"
#include <iostream>

#define SIMFIELD_W 1800 // TO DO - Map class
#define SIMFIELD_H 750  // TO DO - Map class

class Movement
{
private:
    bool _isEnabled;
    float _speed;
    int _angleStep;
    int _angleDegrees;
    MyTransform* _transform;

public:
    Movement(float speed, int angleStep, int angleDegrees, MyTransform* transform);
    float GetSpeed();
    int GetAngleStep();
    int GetAngleDegrees();
    void SetSpeed(float newSpeed);
    void SetAngleStep(int newAngleStep);
    void SetAngleDegrees(int newAngleDegrees);
    void EnableMovement();
    void DisableMovement();
    void RotateLeft();
    void RotateRight();
    void MoveForward();
};

#endif // MOVEMENT_H
