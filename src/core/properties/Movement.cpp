#include "Movement.h"

// Note: include errors
#include "../Core.h"

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

Movement::~Movement()
{
    delete _transform;
}

float Movement::GetSpeed()
{
    return _speed;
}

float Movement::GetCollisionDistance()
{
    return _collisionDistance;
}

int Movement::GetAngleStep()
{
    return _angleStep;
}

int Movement::GetAngleDegrees()
{
    return _angleDegrees;
}

int Movement::GetRotateClockwise()
{
    return _rotateClockwise;
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


void Movement::SetCollisionDistance(float newCollisionDistance)
{
    _collisionDistance = newCollisionDistance;
}

void Movement::SetRotateClockwise(int rotateClockwise)
{
    _rotateClockwise = rotateClockwise;
}

void Movement::RotateAutomatedRobot()
{
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

void Movement::MoveControlledRobot(int orderIndex)
{
    // 1) Calculate direction

    // Check if movement is enabled
    if (!_isEnabled)
    {
        return;
    }

    Vector2d direction = {0.0f, 0.0f};

    float angleRadians = ConvertDegreesToRadians(_angleDegrees);

    direction.x = _speed * cos(angleRadians);
    direction.y = _speed * sin(angleRadians);

    // 2) Move with direction

    // Note: vector from argument is include error from core
    Core* _core = Core::getInstance();
    const std::vector<Wall*> &walls = _core->GetVectorWalls();
    const std::vector<Robot*> &robots = _core->GetVectorRobots();

    int map_width = _core->GetMapWidth();
    int map_height = _core->GetMapHeight();

    Vector2d position = _transform->GetPosition();
    Vector2d size = _transform->GetSize();

    float radius = std::max(size.x, size.y) * 0.5f;

    // Calculate new estimated position
    Vector2d newPosition = position + direction;

    // Check for collisions with other robots
    for (Robot* robot : robots)
    {
        // If it is not the same robot
        if ( robot->GetOrderIndex() != orderIndex )
        {
            Vector2d robotPosition = robot->GetTransform()->GetPosition();
            Vector2d robotSize = robot->GetTransform()->GetSize();
            float robotRadius = std::max(robotSize.x, robotSize.y) * 0.5f;

            if ( CircCircCollision(newPosition, radius, robotPosition, robotRadius) )
            {
                Vector2d directionToRobot = robotPosition - position;
                float distanceToRobot = directionToRobot.getLength();
                float distanceToTouch = distanceToRobot - radius - robotRadius;
                directionToRobot.Normalize();
                newPosition = position + directionToRobot * distanceToTouch;
            }
        }
    }

    // Check for collisions with all walls
    for (Wall* wall : walls)
    {
        Vector2d wallPosition = wall->GetTransform()->GetPosition();
        Vector2d wallSize = wall->GetTransform()->GetSize();

        if ( CircRectCollision(newPosition, radius, wallPosition, wallSize) )
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

    // New value
    _transform->SetPosition(newPosition);
}

void Movement::MoveAutomatedRobot(int orderIndex)
{
    // 1) Calculate direction

    Vector2d direction = {0.0f, 0.0f};

    float angleRadians = ConvertDegreesToRadians(_angleDegrees);

    direction.x = _speed * cos(angleRadians);
    direction.y = _speed * sin(angleRadians);

    // 2) Move with direction

    // Note: vector from argument is include error from core
    Core* _core = Core::getInstance();
    const std::vector<Wall*> &walls = _core->GetVectorWalls();
    const std::vector<Robot*> &robots = _core->GetVectorRobots();

    int map_width = _core->GetMapWidth();
    int map_height = _core->GetMapHeight();

    Vector2d position = _transform->GetPosition();
    Vector2d size = _transform->GetSize();

    float radius = std::max(size.x, size.y) * 0.5f;

    // Calculate new estimated position
    Vector2d newPosition = position + direction;

    // Check for collisions with other robots
    for (Robot* robot : robots)
    {
        int checkRobotIndex = robot->GetOrderIndex();

        // If it is not the same robot
        if ( orderIndex != checkRobotIndex )
        {
            Vector2d robotPosition = robot->GetTransform()->GetPosition();
            Vector2d robotSize = robot->GetTransform()->GetSize();
            float robotRadius = std::max(robotSize.x, robotSize.y) * 0.5f;
            float robotCollisionZoneRadius = robotRadius + _collisionDistance;

            // 3) Check for robot collision zone

            if ( CircCircCollision(newPosition, radius, robotPosition, robotCollisionZoneRadius) )
            {
                if ( !robotZoneRotationCalled[checkRobotIndex] )
                {
                    robotZoneRotationCalled[checkRobotIndex] = true;
                    RotateAutomatedRobot();
                }
            }
            else
            {
                robotZoneRotationCalled[checkRobotIndex] = false;
            }

            // 4) Check for collision with robots

            if ( CircCircCollision(newPosition, radius, robotPosition, robotRadius) )
            {
                Vector2d directionToRobot = robotPosition - position;
                float distanceToRobot = directionToRobot.getLength();
                float distanceToTouch = distanceToRobot - radius - robotRadius;
                directionToRobot.Normalize();
                newPosition = position + directionToRobot * distanceToTouch;
                RotateAutomatedRobot();
            }
        }
    }

    // Check for collisions with all walls
    for (Wall* wall : walls)
    {
        int checkWallIndex = wall->GetOrderIndex();

        Vector2d wallPosition = wall->GetTransform()->GetPosition();
        Vector2d wallSize = wall->GetTransform()->GetSize();
        Vector2d wallCollisionZone = {wallSize.x + _collisionDistance * 2, wallSize.y + _collisionDistance * 2};

        // 5) Check for wall collision zone

        if ( CircRectCollision(newPosition, radius, wallPosition, wallCollisionZone) )
        {
            if ( !wallZoneRotationCalled[checkWallIndex] )
            {
                wallZoneRotationCalled[checkWallIndex] = true;
                RotateAutomatedRobot();
            }
        }
        else
        {
            wallZoneRotationCalled[checkWallIndex] = false;
        }

        // 6) Check for collision with walls

        if ( CircRectCollision(newPosition, radius, wallPosition, wallSize) )
        {
            if         (newPosition.x < wallPosition.x &&
                        newPosition.y < wallPosition.y + wallSize.y * 0.5f &&
                        newPosition.y > wallPosition.y - wallSize.y * 0.5f)
            {
                newPosition.x = wallPosition.x - wallSize.x * 0.5f - radius;
                RotateAutomatedRobot();
            }
            else if    (newPosition.x > wallPosition.x &&
                        newPosition.y < wallPosition.y + wallSize.y * 0.5f &&
                        newPosition.y > wallPosition.y - wallSize.y * 0.5f)
            {
                newPosition.x = wallPosition.x + wallSize.x * 0.5f + radius;
                RotateAutomatedRobot();
            }
            else if    (newPosition.y < wallPosition.y &&
                        newPosition.x < wallPosition.x + wallSize.x * 0.5f &&
                        newPosition.x > wallPosition.x - wallSize.x * 0.5f)
            {
                newPosition.y = wallPosition.y - wallSize.y * 0.5f - radius;
                RotateAutomatedRobot();
            }
            else if    (newPosition.y > wallPosition.y &&
                        newPosition.x < wallPosition.x + wallSize.x * 0.5f &&
                        newPosition.x > wallPosition.x - wallSize.x * 0.5f)
            {
                newPosition.y = wallPosition.y + wallSize.y * 0.5f + radius;
                RotateAutomatedRobot();
            }
        }
    }

    // New angle for automated robot
    float newAngleDegrees = _angleDegrees;

    // Check map boundaries
    if (newPosition.x - radius < 0)
    {
        newPosition.x = radius;
        newAngleDegrees = 180 - newAngleDegrees;
    }
    if (newPosition.x + radius > map_width)
    {
        newPosition.x = map_width - radius;
        newAngleDegrees = 180 - newAngleDegrees;
    }
    if (newPosition.y - radius < 0)
    {
        newPosition.y = radius;
        newAngleDegrees = -newAngleDegrees;
    }
    if (newPosition.y + radius > map_height)
    {
        newPosition.y = map_height - radius;
        newAngleDegrees = -newAngleDegrees;
    }

    // New values
    _transform->SetPosition(newPosition);
    SetAngleDegrees(newAngleDegrees + 360);
}
