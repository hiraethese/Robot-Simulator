/**
 * @file Robot.h
 * @author Baturov Illia (xbatur00@stud.fit.vutbr.cz)
 * @author Kukhta Myron (xkukht01@stud.fit.vutbr.cz)
 * @brief Header of the robot class, which inherits from the simulation object class
 */

#ifndef ROBOT_H
#define ROBOT_H

#include "SimObject.h"
#include "../properties/Movement.h"
#include <iostream>

/**
 * @brief Class that represents a robot simulation object
 * Robot is a moving simulation object
 */
class Robot : public SimObject
{

private:
    /**
     * @brief Pointer to an object of the Movement class
     * Contains the parameters necessary for the movement of the robot
     */
    Movement* _movement;

    /**
     * @brief Variable indicating robot type
     * The robot can be controlled (true) or automated (false)
     */
    bool _isControlled;

public:
    /**
     * @brief Construct a new Robot object
     * 
     * @param position robot position
     * @param size robot size
     * @param speed robot speed
     * @param collisionDistance size of the detection zone around the robot
     * @param angleStep robot rotation step
     * (in degrees)
     * @param angleDegrees direction of robot movement
     * (in degrees)
     * @param rotateClockwise rotation of the robot clockwise or counterclockwise
     * (1 is clockwise, -1 is counterclockwise)
     * @param color robot color
     * @param orderIndex robot unique number
     * @param isControlled robot type
     */
    Robot(  Vector2d position,
            Vector2d size,
            float speed,
            float collisionDistance,
            int angleStep,
            int angleDegrees,
            int rotateClockwise,
            colors color,
            int orderIndex,
            bool isControlled);

    /**
     * @brief Destroy the Robot object
     */
    ~Robot();

    /**
     * @brief Returns the robot type
     * 
     * @return true
     * (if the robot is controlled)
     * @return false
     * (if the robot is automated)
     */
    bool IsControlled();

    /**
     * @brief Get the Movement object
     * 
     * @return Movement*
     * Returns a pointer to the robot's movement object
     */
    Movement* GetMovement();

    /**
     * @brief Get the Sim Obj View object
     * 
     * @return SimObjView*
     * Returns a pointer to a structure that contains all the necessary information about the robot
     */
    SimObjView* GetSimObjView() override;

    /**
     * @brief Set the Sim Obj View object
     * 
     * @param view structure that sets new robot values
     */
    void SetSimObjView(SimObjView view) override;
};

#endif // ROBOT_H
