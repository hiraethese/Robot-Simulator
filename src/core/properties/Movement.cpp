#include "Movement.h"

Movement::Movement(float speed, float angleDegrees, MyTransform *transform)
{
    _isMoving = true;
    _speed = speed;
    _stepAngle = angleDegrees;
    _angleDegrees = _stepAngle;
    _transform = transform;
}

float Movement::GetSpeed()
{
    return _speed;
}

float Movement::GetAngle()
{
    return _stepAngle;
}

void Movement::SetSpeed(float newSpeed)
{
    _speed = newSpeed;
}

void Movement::SetAngle(float newAngleDegrees)
{
    _angleDegrees = newAngleDegrees;
}

void Movement::RotateLeft()
{
    _angleDegrees -= _stepAngle;
    // std::cout << "left rotate: " << _angleDegrees << std::endl;
}

void Movement::RotateRight()
{
    _angleDegrees += _stepAngle;
    // std::cout << "right rotate: " << _angleDegrees << std::endl;
}

void Movement::MoveForward()
{
    if (_isMoving) {
        float angleRadians = _angleDegrees * ( M_PI / 180.0f );

        Vector2d position = _transform->GetPosition();
        Vector2d size = _transform->GetSize();

        position.x += _speed * cos(angleRadians);
        position.y += _speed * sin(angleRadians);

        if (position.x - size.x * 0.5f < 0)
            position.x = size.x * 0.5f;
        if (position.x + size.x * 0.5f > SIMFIELD_W)
            position.x = SIMFIELD_W - 0.5f;
        if (position.y - size.y * 0.5f < 0)
            position.y = size.y * 0.5f;
        if (position.y + size.y * 0.5f > SIMFIELD_H)
            position.y = SIMFIELD_H - 0.5f;

        _transform->SetPosition(position);
        // std::cout << "forward move " << "x = " << position.x << " " << "y = " << position.y << std::endl;
    }
}

void Movement::StopMoving()
{
    if (_isMoving) {
        _isMoving = false;
    } else {
        _isMoving = true;
    }
}
