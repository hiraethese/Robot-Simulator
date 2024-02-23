#include "SimEntity.h"

SimEntity::SimEntity(Vector2d position, Vector2d size)
{
    _transform = new MyTransform(position, size);
}

MyTransform* SimEntity::GetTransform()
{
    return _transform;
}
