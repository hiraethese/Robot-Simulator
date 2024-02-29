#ifndef CORE_H
#define CORE_H

#include "entities/SimField.h"
#include "entities/SimObject.h"

extern SimField* simField;
extern SimObject* newRect;

int SimStart();
int SimEnd();

#endif // CORE_H
