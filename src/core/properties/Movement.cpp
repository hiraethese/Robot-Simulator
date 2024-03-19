#include "Movement.h"

#include "../Core.h" // Note: include errors

Movement::Movement(float speed, int angleStep, int angleDegrees, MyTransform *transform)
{
    _isEnabled = false;
    _speed = speed;
    _angleStep = angleStep % 360;
    _angleDegrees = angleDegrees % 360;
    _transform = transform;
}

float Movement::GetSpeed()
{
    return _speed;
}

int Movement::GetAngleStep()
{
    return _angleStep;
}

int Movement::GetAngleDegrees()
{
    return _angleDegrees;
}

void Movement::SetSpeed(float newSpeed)
{
    _speed = newSpeed;
}

void Movement::SetAngleStep(int newAngleStep)
{
    _angleStep = newAngleStep % 360;
}

void Movement::SetAngleDegrees(int newAngleDegrees)
{
    _angleDegrees = newAngleDegrees % 360;
}

void Movement::RotateLeft()
{
    _angleDegrees = (_angleDegrees - _angleStep) % 360;
    // std::cout << "left rotate: " << _angleDegrees << std::endl;
}

void Movement::RotateRight()
{
    _angleDegrees = (_angleDegrees + _angleStep) % 360;
    // std::cout << "right rotate: " << _angleDegrees << std::endl;
}

void Movement::EnableMovement()
{
    _isEnabled = true;
}

void Movement::DisableMovement()
{
    _isEnabled = false;
}

void Movement::MoveForward()
{
    if (!_isEnabled) return;

    Core* core = Core::getInstance();

    int map_width = core->GetMapWidth();
    int map_height = core->GetMapHeight();

    Vector2d position = _transform->GetPosition();
    Vector2d size = _transform->GetSize();

    float angleRadians = _angleDegrees * ( M_PI / 180.0f );

    position.x += _speed * cos(angleRadians);
    position.y += _speed * sin(angleRadians);

    if (position.x - size.x * 0.5f < 0)
        position.x = size.x * 0.5f;
    if (position.x + size.x * 0.5f > map_width)
        position.x = map_width - size.x * 0.5f;
    if (position.y - size.y * 0.5f < 0)
        position.y = size.y * 0.5f;
    if (position.y + size.y * 0.5f > map_height)
        position.y = map_height - size.y * 0.5f;

    _transform->SetPosition(position);
    // std::cout << "forward move " << "x = " << position.x << " " << "y = " << position.y << std::endl;
}
