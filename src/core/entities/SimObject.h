#ifndef SIMOBJECT_H
#define SIMOBJECT_H

#include "../properties/MyTransform.h"
#include "../properties/Movement.h"

class SimObject
{
protected:
    MyTransform* _transform;

public:
    SimObject(Vector2d position, Vector2d size);
    ~SimObject();
    MyTransform* GetTransform();
};

#endif // SIMOBJECT_H
