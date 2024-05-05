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
     * @brief Variable that stores pointer to an object of the MyTransform class
     * Contains parameters for the position and size of the object
     */
    MyTransform* _transform;

    /**
     * @brief Unordered map that associates a unique object index and a boolean value
     * Used to check collision detection of automated robots with all walls
     */
    std::unordered_map<int, bool> wallZoneRotationCalled;

    /**
     * @brief Unordered map that associates a unique object index and a boolean value
     * Used to check collision detection of automated robots with other robots
     */
    std::unordered_map<int, bool> robotZoneRotationCalled;

public:
    /**
     * @brief Construct a new Movement object
     * 
     * @param speed object speed
     * @param collisionDistance object detection zone size
     * @param angleStep object rotation step
     * (in degrees)
     * @param angleDegrees object movement direction
     * (in degrees)
     * @param rotateClockwise object rotation direction
     * (1 is clockwise, -1 is counterclockwise)
     * @param transform pointer to an object that contains position and size
     */
    Movement(float speed,
            float collisionDistance,
            int angleStep,
            int angleDegrees,
            int rotateClockwise,
            MyTransform* transform);

    /**
     * @brief Get the Speed object
     * Get current speed of an object
     * @return float
     */
    float GetSpeed();

    /**
     * @brief Get the Collision Distance object
     * Get current collision distance (or size of detection zone) of an object
     * @return float 
     */
    float GetCollisionDistance();

    /**
     * @brief Get the Angle Step object
     * Get current rotation step of an object
     * @return int
     * (in degrees)
     */
    int GetAngleStep();

    /**
     * @brief Get the Angle Degrees object
     * Get current movement direction of an object
     * @return int
     * (in degrees)
     */
    int GetAngleDegrees();

    /**
     * @brief Get the Rotate Clockwise object
     * Get rotation direction of an object
     * @return int
     * (1, -1)
     */
    int GetRotateClockwise();

    /**
     * @brief Set the Speed object
     * Set new object speed
     * @param newSpeed new speed
     */
    void SetSpeed(float newSpeed);

    /**
     * @brief Set the Angle Step object
     * Set new object rotation step
     * @param newAngleStep new angle step
     */
    void SetAngleStep(int newAngleStep);

    /**
     * @brief Set the Angle Degrees object
     * Set new object movement direction
     * @param newAngleDegrees new angle degrees
     */
    void SetAngleDegrees(int newAngleDegrees);

    /**
     * @brief Set the Collision Distance object
     * Set new object detection zone size
     * @param newCollisionDistance new collision distance
     */
    void SetCollisionDistance(float newCollisionDistance);

    /**
     * @brief Set the Rotate Clockwise object
     * Set new object rotation direction
     * @param rotateClockwise rotate clockwise or counterclockwise
     */
    void SetRotateClockwise(int rotateClockwise);

    /**
     * @brief Allow object movement
     * Sets _isEnabled to true
     */
    void EnableMovement();

    /**
     * @brief Stop object movement
     * Sets _isEnabled to false
     */
    void DisableMovement();

    /**
     * @brief Rotate automatic robot clockwise or counterclockwise
     * Makes one rotation step
     */
    void RotateAutomatedRobot();

    /**
     * @brief Rotate controlled robot clockwise
     * Makes one rotation step
     */
    void RotateRight();

    /**
     * @brief Rotate controlled robot counterclockwise
     * Makes one rotation step
     */
    void RotateLeft();

    /**
     * @brief Method that performs one step of controlled robot during simulation
     * Takes into account all possible collisions during simulation
     * @param orderIndex takes the unique order number of the controlled robot that will move
     */
    void MoveControlledRobot(int orderIndex);

    /**
     * @brief Method that performs one step of automated robot during simulation
     * If an obstacle is detected within the radius of the detection zone, it calls the automated robot's rotation method
     * Takes into account all possible collisions during simulation
     * @param orderIndex takes the unique order number of the automated robot that will move
     */
    void MoveAutomatedRobot(int orderIndex);
};

#endif // MOVEMENT_H
