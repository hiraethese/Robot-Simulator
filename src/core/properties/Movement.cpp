#include "Movement.h"

#include "../Core.h" // Note: include errors

Movement::Movement(float speed,
                    float collisionDistance,
                    int angleStep,
                    int angleDegrees,
                    int rotateClockwise,
                    MyTransform* transform)
{
    _isEnabled = false;
    _speed = speed;
    _collisionDistance = collisionDistance;
    _angleStep = angleStep % 360;
    _angleDegrees = angleDegrees % 360;
    _rotateClockwise = rotateClockwise;
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

void Movement::Rotate()
{
    // Check if movement is enabled
    if (!_isEnabled)
    {
        return;
    }
    switch (_rotateClockwise)
    {
        case 1:
            _angleDegrees = (_angleDegrees + _angleStep) % 360;
            break;
        case -1:
            _angleDegrees = (_angleDegrees - _angleStep) % 360;
            break;
        case 0:
            break;
        default:
            break;
    }
}

void Movement::RotateRight()
{
    // Check if movement is enabled
    if (!_isEnabled)
    {
        return;
    }
    _angleDegrees = (_angleDegrees + _angleStep) % 360;
}

void Movement::RotateLeft()
{
    // Check if movement is enabled
    if (!_isEnabled)
    {
        return;
    }
    _angleDegrees = (_angleDegrees - _angleStep) % 360;
}

void Movement::EnableMovement()
{
    _isEnabled = true;
}

void Movement::DisableMovement()
{
    _isEnabled = false;
}

void Movement::MoveControlledRobot()
{
    // 1) Calculate direction

    // Check if movement is enabled
    if (!_isEnabled)
    {
        return;
    }

    Vector2d direction = {0.0f, 0.0f};

    float angleRadians = _angleDegrees * ( M_PI / 180.0f );

    direction.x = _speed * cos(angleRadians);
    direction.y = _speed * sin(angleRadians);

    // 2) Move with direction

    Core* core = Core::getInstance();
    const std::vector<Wall*>& walls = core->GetVectorWalls();

    int map_width = core->GetMapWidth();
    int map_height = core->GetMapHeight();

    Vector2d position = _transform->GetPosition();
    Vector2d size = _transform->GetSize();

    float radius = std::max(size.x, size.y) * 0.5f;

    // Calculate new estimated position
    Vector2d newPosition = position + direction;

    // Check for collision with walls
    for (Wall* wall : walls)
    {
        Vector2d wallPosition = wall->GetTransform()->GetPosition();
        Vector2d wallSize = wall->GetTransform()->GetSize();

        if (newPosition.x + radius >= wallPosition.x - wallSize.x * 0.5f &&
            newPosition.x - radius <= wallPosition.x + wallSize.x * 0.5f &&
            newPosition.y + radius >= wallPosition.y - wallSize.y * 0.5f &&
            newPosition.y - radius <= wallPosition.y + wallSize.y * 0.5f)
        {
            if         (newPosition.x < wallPosition.x &&
                        newPosition.y < wallPosition.y + wallSize.y * 0.5f &&
                        newPosition.y > wallPosition.y - wallSize.y * 0.5f)
            {
                newPosition.x = wallPosition.x - wallSize.x * 0.5f - radius;
            }
            else if    (newPosition.x > wallPosition.x &&
                        newPosition.y < wallPosition.y + wallSize.y * 0.5f &&
                        newPosition.y > wallPosition.y - wallSize.y * 0.5f)
            {
                newPosition.x = wallPosition.x + wallSize.x * 0.5f + radius;
            }
            else if    (newPosition.y < wallPosition.y &&
                        newPosition.x < wallPosition.x + wallSize.x * 0.5f &&
                        newPosition.x > wallPosition.x - wallSize.x * 0.5f)
            {
                newPosition.y = wallPosition.y - wallSize.y * 0.5f - radius;
            }
            else if    (newPosition.y > wallPosition.y &&
                        newPosition.x < wallPosition.x + wallSize.x * 0.5f &&
                        newPosition.x > wallPosition.x - wallSize.x * 0.5f)
            {
                newPosition.y = wallPosition.y + wallSize.y * 0.5f + radius;
            }
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
}

void Movement::MoveAutomatedRobot() // TO DO
{
    // 1) Calculate direction

    // Check if movement is enabled
    if (!_isEnabled)
    {
        return;
    }

    Vector2d direction = {0.0f, 0.0f};

    float angleRadians = _angleDegrees * ( M_PI / 180.0f );

    direction.x = _speed * cos(angleRadians);
    direction.y = _speed * sin(angleRadians);

    // 2) Move with direction

    Core* core = Core::getInstance();
    const std::vector<Wall*>& walls = core->GetVectorWalls();

    int map_width = core->GetMapWidth();
    int map_height = core->GetMapHeight();

    Vector2d position = _transform->GetPosition();
    Vector2d size = _transform->GetSize();

    float radius = std::max(size.x, size.y) * 0.5f;

    // Calculate new estimated position
    Vector2d newPosition = position + direction;

    // Check for collision with walls
    for (Wall* wall : walls)
    {
        Vector2d wallPosition = wall->GetTransform()->GetPosition();
        Vector2d wallSize = wall->GetTransform()->GetSize();

        if (newPosition.x + radius >= wallPosition.x - wallSize.x * 0.5f &&
            newPosition.x - radius <= wallPosition.x + wallSize.x * 0.5f &&
            newPosition.y + radius >= wallPosition.y - wallSize.y * 0.5f &&
            newPosition.y - radius <= wallPosition.y + wallSize.y * 0.5f)
        {
            if         (newPosition.x < wallPosition.x &&
                        newPosition.y < wallPosition.y + wallSize.y * 0.5f &&
                        newPosition.y > wallPosition.y - wallSize.y * 0.5f)
            {
                newPosition.x = wallPosition.x - wallSize.x * 0.5f - radius;
            }
            else if    (newPosition.x > wallPosition.x &&
                        newPosition.y < wallPosition.y + wallSize.y * 0.5f &&
                        newPosition.y > wallPosition.y - wallSize.y * 0.5f)
            {
                newPosition.x = wallPosition.x + wallSize.x * 0.5f + radius;
            }
            else if    (newPosition.y < wallPosition.y &&
                        newPosition.x < wallPosition.x + wallSize.x * 0.5f &&
                        newPosition.x > wallPosition.x - wallSize.x * 0.5f)
            {
                newPosition.y = wallPosition.y - wallSize.y * 0.5f - radius;
            }
            else if    (newPosition.y > wallPosition.y &&
                        newPosition.x < wallPosition.x + wallSize.x * 0.5f &&
                        newPosition.x > wallPosition.x - wallSize.x * 0.5f)
            {
                newPosition.y = wallPosition.y + wallSize.y * 0.5f + radius;
            }
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
}
