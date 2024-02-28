#include "core.h"

SimObject* newRect = nullptr;

int SimStart()
{
    newRect = new SimObject({50.0, 50.0}, {100.0, 100.0});
    return 0;
}
