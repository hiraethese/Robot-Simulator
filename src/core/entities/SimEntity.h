#ifndef SIMENTITY_H
#define SIMENTITY_H

#include "../properties/MyTransform.h"

class SimEntity
{
private:
    MyTransform* _transform;

public:
    SimEntity(Vector2d position, Vector2d size);
    MyTransform* GetTransform();
};

#endif // SIMENTITY_H
