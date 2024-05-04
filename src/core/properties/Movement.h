/**
 * @file Movement.h
 * @author Baturov Illia (xbatur00@stud.fit.vutbr.cz)
 * @author Kukhta Myron (xkukht01@stud.fit.vutbr.cz)
 * @brief Header of the movement class
 */

#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <iostream>
#include <unordered_map>
#include "MyTransform.h"

/**
 * @brief Class that represents the movement of objects
 * Each moving object contains a pointer to the object of movement
 */
class Movement
{

private:
    /**
     * @brief Variable that represents the ability to move
     * (true means the object can move, false means the object cannot move)
     */
    bool _isEnabled;

    /**
     * @brief Variable that stores the speed of the simulation object
     * (minimum value is 0.0, maximum value is 50.0)
     */
    float _speed;

    /**
     * @brief Variable that stores obstacle detection distance
     * (minimum value is 0.0, maximum value is 1000.0)
     */
    float _collisionDistance;

    /**
     * @brief Variable that stores the object rotation step
     * (in degrees)
     */
    int _angleStep;

    /**
     * @brief Variable that stores the direction of movement of the object
     * (in degrees)
     */
    int _angleDegrees;

    /**
     * @brief Variable that stores the direction of rotation of the object
     * (1 is clockwise, -1 is counterclockwise)
     */
    int _rotateClockwise;

    /**
     * @brief 
     * 
     */
    MyTransform* _transform;

    /**
     * @brief 
     * 
     */
    std::unordered_map<int, bool> wallZoneRotationCalled;

    /**
     * @brief 
     * 
     */
    std::unordered_map<int, bool> robotZoneRotationCalled;

public:
    /**
     * @brief Construct a new Movement object
     * 
     * @param speed 
     * @param collisionDistance 
     * @param angleStep 
     * @param angleDegrees 
     * @param rotateClockwise 
     * @param transform 
     */
    Movement(float speed,
            float collisionDistance,
            int angleStep,
            int angleDegrees,
            int rotateClockwise,
            MyTransform* transform);

    /**
     * @brief Get the Speed object
     * 
     * @return float 
     */
    float GetSpeed();

    /**
     * @brief Get the Collision Distance object
     * 
     * @return float 
     */
    float GetCollisionDistance();

    /**
     * @brief Get the Angle Step object
     * 
     * @return int 
     */
    int GetAngleStep();

    /**
     * @brief Get the Angle Degrees object
     * 
     * @return int 
     */
    int GetAngleDegrees();

    /**
     * @brief Get the Rotate Clockwise object
     * 
     * @return int 
     */
    int GetRotateClockwise();

    /**
     * @brief Set the Speed object
     * 
     * @param newSpeed 
     */
    void SetSpeed(float newSpeed);

    /**
     * @brief Set the Angle Step object
     * 
     * @param newAngleStep 
     */
    void SetAngleStep(int newAngleStep);

    /**
     * @brief Set the Angle Degrees object
     * 
     * @param newAngleDegrees 
     */
    void SetAngleDegrees(int newAngleDegrees);

    /**
     * @brief Set the Collision Distance object
     * 
     * @param newCollisionDistance 
     */
    void SetCollisionDistance(float newCollisionDistance);

    /**
     * @brief Set the Rotate Clockwise object
     * 
     * @param rotateClockwise 
     */
    void SetRotateClockwise(int rotateClockwise);

    /**
     * @brief 
     * 
     */
    void EnableMovement();

    /**
     * @brief 
     * 
     */
    void DisableMovement();

    /**
     * @brief 
     * 
     */
    void RotateAutomatedRobot();

    /**
     * @brief 
     * 
     */
    void RotateRight();

    /**
     * @brief 
     * 
     */
    void RotateLeft();

    /**
     * @brief 
     * 
     * @param orderIndex 
     */
    void MoveControlledRobot(int orderIndex);

    /**
     * @brief 
     * 
     * @param orderIndex 
     */
    void MoveAutomatedRobot(int orderIndex);
};

#endif // MOVEMENT_H
