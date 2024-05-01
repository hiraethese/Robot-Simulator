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

class Spawner
{
public:
	Spawner();
	Robot* GenNewRobot(float x, float y, int orderIndex, bool isControlled);
	Wall* GenNewWall(float x, float y, int orderIndex);
	Robot* GenNewRobot(std::istringstream& specification, int orderIndex, bool isControlled);
	Wall* GenNewWall(std::istringstream& specification, int orderIndex);
	SimObjView GetControlledRobotTemp();
	SimObjView GetAutomatedRobotTemp();
	SimObjView GetWallTemp();
	void SetControlledRobotTemp(SimObjView newTemp);
	void SetAutomatedRobotTemp(SimObjView newTemp);
	void SetWallTemp(SimObjView newTemp);

private:
	SimObjView _controlledRobotTemp;
	SimObjView _automatedRobotTemp;
	SimObjView _wallTemp;
};

#endif // SPAWNER_H
