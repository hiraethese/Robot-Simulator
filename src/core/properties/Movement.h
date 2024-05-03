#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <iostream>
#include <unordered_map>
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
    std::unordered_map<int, bool> wallZoneRotationCalled;
    std::unordered_map<int, bool> robotZoneRotationCalled;

public:
    Movement(float speed,
            float collisionDistance,
            int angleStep,
            int angleDegrees,
            int rotateClockwise,
            MyTransform* transform);
    ~Movement();
    float GetSpeed();
    float GetCollisionDistance();
    int GetAngleStep();
    int GetAngleDegrees();
    int GetRotateClockwise();
    void SetSpeed(float newSpeed);
    void SetAngleStep(int newAngleStep);
    void SetAngleDegrees(int newAngleDegrees);
    void SetCollisionDistance(float newCollisionDistance);
    void SetRotateClockwise(int rotateClockwise);
    void EnableMovement();
    void DisableMovement();
    void RotateAutomatedRobot();
    void RotateRight();
    void RotateLeft();
    void MoveControlledRobot(int orderIndex);
    void MoveAutomatedRobot(int orderIndex);
};

#endif // MOVEMENT_H
