#include "Movement.h"

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
    std::cout << "left rotate: " << _angleDegrees << std::endl; // Debug
}

void Movement::RotateRight()
{
    _angleDegrees = (_angleDegrees + _angleStep) % 360;
    std::cout << "right rotate: " << _angleDegrees << std::endl; // Debug
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

    float angleRadians = _angleDegrees * ( M_PI / 180.0f );

    Vector2d position = _transform->GetPosition();
    Vector2d size = _transform->GetSize();

    position.x += _speed * cos(angleRadians);
    position.y += _speed * sin(angleRadians);

    if (position.x - size.x * 0.5f < 0)
        position.x = size.x * 0.5f;
    if (position.x + size.x * 0.5f > SIMFIELD_W)
        position.x = SIMFIELD_W - size.x * 0.5f;
    if (position.y - size.y * 0.5f < 0)
        position.y = size.y * 0.5f;
    if (position.y + size.y * 0.5f > SIMFIELD_H)
        position.y = SIMFIELD_H - size.y * 0.5f;

    _transform->SetPosition(position);
    std::cout << "forward move " << "x = " << position.x << " " << "y = " << position.y << std::endl; // Debug
}
