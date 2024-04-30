#ifndef WALL_H
#define WALL_H

#include "SimObject.h"

class Wall : public SimObject
{
public:
    Wall(Vector2d position, Vector2d size, colors color,  int orderIndex);
    SimObjView *GetSimObjView() override;
    SimObjView* GetSimObjViewGUI() override;
    void SetSimObjView(SimObjView view) override;
};

#endif // WALL_H
