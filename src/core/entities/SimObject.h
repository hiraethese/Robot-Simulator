#ifndef SIMOBJECT_H
#define SIMOBJECT_H

#include "../properties/MyTransform.h"
#include <iostream>

class SimObject
{
protected:
    MyTransform* _transform;
    int _orderIndex;
    colors _color;
public:
    SimObject(Vector2d position, Vector2d size, colors color, int orderIndex);
    virtual ~SimObject();
    MyTransform* GetTransform();
    int GetOrderIndex();
    virtual SimObjView GetSimObjView() = 0;
};

#endif // SIMOBJECT_H
