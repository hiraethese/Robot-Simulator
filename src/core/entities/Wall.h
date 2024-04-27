#ifndef WALL_H
#define WALL_H

#include "SimObject.h"

class Wall : public SimObject
{
public:
    Wall(Vector2d position, Vector2d size, colors color,  int orderIndex);
    SimObjView GetSimObjView() override;
};

#endif // WALL_H
