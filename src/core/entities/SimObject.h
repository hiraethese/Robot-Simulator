#ifndef SIMOBJECT_H
#define SIMOBJECT_H

#include "../properties/MyTransform.h"

class SimObject {
private:
    MyTransform* _transform;

public:
    SimObject(Vector2d position, Vector2d size);
    MyTransform* GetTransform();
};

#endif // SIMOBJECT_H
