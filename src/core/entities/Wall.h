#ifndef WALL_H
#define WALL_H
#include "SimObject.h"

class Wall : public SimObject
{
public:
    Wall(Vector2d position, Vector2d size, colors color=BLUE);
    WallView GetWallView();
};

#endif // WALL_H
