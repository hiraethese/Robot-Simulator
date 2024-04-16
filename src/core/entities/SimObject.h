#ifndef SIMOBJECT_H
#define SIMOBJECT_H

#include "../properties/MyTransform.h"
#include <iostream>

class SimObject
{
protected:
    MyTransform* _transform;
    colors _color;
    int _orderIndex;
public:
    SimObject(Vector2d position, Vector2d size, colors color, int orderIndex);
    virtual ~SimObject();
    MyTransform* GetTransform();
    virtual SimObjView GetSimObjView() = 0;
};

#endif // SIMOBJECT_H
