#ifndef SIMOBJECT_H
#define SIMOBJECT_H

#include "../properties/MyTransform.h"

class SimObject
{
protected:
    MyTransform* _transform;
    colors _color;

public:
    SimObject(Vector2d position, Vector2d size, colors color);
    ~SimObject();
    MyTransform* GetTransform();
};

#endif // SIMOBJECT_H
