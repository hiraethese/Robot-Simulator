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
    // Check if movement is enabled
    if (!_isEnabled)
    {
        return;
    }

    Core* core = Core::getInstance();
    const std::vector<Wall*>& walls = core->GetVectorWalls();

    int map_width = core->GetMapWidth();
    int map_height = core->GetMapHeight();

    Vector2d position = _transform->GetPosition();
    Vector2d size = _transform->GetSize();

    float angleRadians = _angleDegrees * ( M_PI / 180.0f );
    float radius = std::max(size.x, size.y) / 2;

    // Calculate new estimated position
    Vector2d newPosition;
    newPosition.x = position.x + _speed * cos(angleRadians);
    newPosition.y = position.y + _speed * sin(angleRadians);

    // Check for collision with walls - TODO: check if robot will be inside the wall (?)
    for (Wall* wall : walls)
    {
        Vector2d wallPosition = wall->GetTransform()->GetPosition();
        Vector2d wallSize = wall->GetTransform()->GetSize();

        float testX = newPosition.x;
        float testY = newPosition.y;

        if (newPosition.x < wallPosition.x - wallSize.x * 0.5f + radius)
        {
            testX = wallPosition.x - wallSize.x * 0.5f;
        }
        else if (newPosition.x > wallPosition.x + wallSize.x * 0.5f - radius)
        {
            testX = wallPosition.x + wallSize.x * 0.5f;
        }

        if (newPosition.y < wallPosition.y - wallSize.y * 0.5f + radius)
        {
            testY = wallPosition.y - wallSize.y * 0.5f;
        }
        else if (newPosition.y > wallPosition.y + wallSize.y * 0.5f - radius)
        {
            testY = wallPosition.y + wallSize.y * 0.5f;
        }

        float distX = newPosition.x - testX;
        float distY = newPosition.y - testY;
        float distance = sqrt(distX * distX + distY * distY);

        if (distance < radius)
        {
            float overlap = radius - distance;
            newPosition.x += distX / distance * overlap;
            newPosition.y += distY / distance * overlap;
        }
    }

    // Check map boundaries
    if (newPosition.x - radius < 0)
    {
        newPosition.x = radius;
    }
    if (newPosition.x + radius > map_width)
    {
        newPosition.x = map_width - radius;
    }
    if (newPosition.y - radius < 0)
    {
        newPosition.y = radius;
    }
    if (newPosition.y + radius > map_height)
    {
        newPosition.y = map_height - radius;
    }

    _transform->SetPosition(newPosition);
    // std::cout << "forward move " << "x = " << position.x << " " << "y = " << position.y << std::endl;
}
