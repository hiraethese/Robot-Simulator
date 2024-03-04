#include "Movement.h"

Movement::Movement(float speed, float angle, MyTransform *transform)
{
    _speed = speed;
    _angle = angle;
    _transform = transform;
}

void Movement::Move()
{
    Vector2d position = _transform->GetPosition();
    Vector2d size = _transform->GetSize();
    
    position.x += _speed * cos(_angle);
    position.y += _speed * sin(_angle);

    if (position.x - size.x * 0.5f < 0)
        position.x = size.x * 0.5f;
    if (position.x + size.x * 0.5f > SIMFIELD_W)
        position.x = SIMFIELD_W - 0.5f;
    if (position.y - size.y * 0.5f < 0)
        position.y = size.y * 0.5f;
    if (position.y + size.y * 0.5f > SIMFIELD_H)
        position.y = SIMFIELD_H - 0.5f;

    _transform->SetPosition(position);
}
