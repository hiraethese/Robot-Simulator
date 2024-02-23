#include "core.h"
#include "entities/SimObject.h"

int SimStart()
{
    SimObject* newRect;
    newRect = new SimObject( {400.0f, 400.0f}, {20.0f, 20.0f} );
    return 0;
}
