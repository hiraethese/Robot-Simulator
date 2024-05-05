/**
 * @file Spawner.h
 * @author Baturov Illia (xbatur00@stud.fit.vutbr.cz)
 * @author Kukhta Myron (xkukht01@stud.fit.vutbr.cz)
 * @brief Spawner header file
 * Note: This file is a freestyle interpretation of the factory method
 */

#ifndef SPAWNER_H
#define SPAWNER_H

#include "icplib.h"
#include "entities/Robot.h"
#include "entities/Wall.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "../gui/style.h"

/**
 * @brief Class that represents a spawner object
 */
class Spawner
{

private:
	/**
	 * @brief Controlled robot template
	 */
	SimObjView _controlledRobotTemp;

	/**
	 * @brief Automated robot template
	 */
	SimObjView _automatedRobotTemp;

	/**
	 * @brief Wall template
	 */
	SimObjView _wallTemp;

public:
	/**
	 * @brief Construct a new Spawner object
	 */
	Spawner();

	/**
	 * @brief Generates a new Robot class object using template
	 * 
	 * @param x X coordinate of the robot
	 * @param y Y coordinate of the robot
	 * @param orderIndex order index of the robot
	 * @param isControlled controlled or automated robot
	 * @return Robot*
	 * Returns a pointer to a new Robot class object
	 */
	Robot* GenNewRobot(float x, float y, int orderIndex, bool isControlled);

	/**
	 * @brief Generates a new Wall class object using template
	 * 
	 * @param x X coordinate of the wall
	 * @param y Y coordinate of the wall
	 * @param orderIndex order index of the wall
	 * @return Wall*
	 * Returns a pointer to a new Wall class object
	 */
	Wall* GenNewWall(float x, float y, int orderIndex);

	/**
	 * @brief Generates a new Robot class object using string stream
	 * 
	 * @param specification robot specification
	 * @param orderIndex robot order index
	 * @param isControlled controlled or automated robot
	 * @return Robot*
	 * Returns a pointer to a new Robot class object
	 */
	Robot* GenNewRobot(std::istringstream& specification, int orderIndex, bool isControlled);

	/**
	 * @brief Generates a new Wall class object using string stream
	 * 
	 * @param specification wall specification
	 * @param orderIndex wall order index
	 * @return Wall*
	 * Returns a pointer to a new Wall class object
	 */
	Wall* GenNewWall(std::istringstream& specification, int orderIndex);

	/**
	 * @brief Get the controlled robot template
	 * 
	 * @return SimObjView
	 */
	SimObjView GetControlledRobotTemp();

	/**
	 * @brief Get the automated robot template
	 * 
	 * @return SimObjView
	 */
	SimObjView GetAutomatedRobotTemp();

	/**
	 * @brief Get the wall template
	 * 
	 * @return SimObjView
	 */
	SimObjView GetWallTemp();

	/**
	 * @brief Set the controlled robot template
	 * 
	 * @param newTemp new controlled robot template
	 */
	void SetControlledRobotTemp(SimObjView newTemp);

	/**
	 * @brief Set the automated robot template
	 * 
	 * @param newTemp new automated robot template
	 */
	void SetAutomatedRobotTemp(SimObjView newTemp);

	/**
	 * @brief Set the wall template
	 * 
	 * @param newTemp new wall template
	 */
	void SetWallTemp(SimObjView newTemp);
};

#endif // SPAWNER_H
