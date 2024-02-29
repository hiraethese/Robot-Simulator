#include "core.h"

SimField* simField = nullptr;
SimObject* newRect = nullptr;

int SimStart()
{
    simField = new SimField(1800, 750);
    newRect = new SimObject({50.0f, 50.0f}, {100.0f, 100.0f});
    return 0;
}

int SimEnd()
{
    delete simField;
    delete newRect;
    return 0;
}
