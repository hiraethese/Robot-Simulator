#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <iostream>
#include "MyTransform.h"

class Movement
{
private:
    bool _isEnabled;
    float _speed;
    float _collisionDistance;
    int _angleStep;
    int _angleDegrees;
    int _rotateClockwise;
    MyTransform* _transform;

public:
    Movement(float speed,
            float collisionDistance,
            int angleStep,
            int angleDegrees,
            int rotateClockwise,
            MyTransform* transform);
    float GetSpeed();
    int GetAngleStep();
    int GetAngleDegrees();
    void SetSpeed(float newSpeed);
    void SetAngleStep(int newAngleStep);
    void SetAngleDegrees(int newAngleDegrees);
    void EnableMovement();
    void DisableMovement();
    void RotateAutomatedRobot();
    void RotateRight();
    void RotateLeft();
    void MoveControlledRobot();
    void MoveAutomatedRobot();
};

#endif // MOVEMENT_H
