#include "core.h"

SimObject* newRect = nullptr;

int SimStart()
{
    newRect = new SimObject({50.0f, 50.0f}, {100.0f, 100.0f});
    return 0;
}
