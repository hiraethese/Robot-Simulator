#include "core.h"

SimObject* newRect = nullptr;

int SimStart()
{
    newRect = new SimObject({400.0f, 400.0f}, {20.0f, 20.0f});
    return 0;
}
