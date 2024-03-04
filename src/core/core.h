#ifndef CORE_H
#define CORE_H

#include "entities/SimObject.h"

class Wall;

#define SIMFIELD_W 1800.0f
#define SIMFIELD_H 750.0f

extern Wall* newRect;

int SimStart();
int SimEnd();

#endif // CORE_H
