#ifndef CORE_H
#define CORE_H

#include "entities/Robot.h"

#define SIMFIELD_W 1800.0f
#define SIMFIELD_H 750.0f

extern Robot* controlledRobot;

int SimStart();
int SimEnd();

#endif // CORE_H
