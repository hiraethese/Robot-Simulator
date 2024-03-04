#include "core.h"

Wall* newRect = nullptr;

int SimStart()
{
    newRect = new Wall({50.0f, 50.0f}, {100.0f, 100.0f});
    return 0;
}

int SimEnd()
{
    delete newRect;
    return 0;
}
