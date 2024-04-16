#include "Robot.h"

Robot::Robot(Vector2d position,
            Vector2d size,
            float speed,
            float collisionDistance,
            int angleStep,
            int angleDegrees,
            int rotateClockwise,
            colors color,
            int orderIndex,
            bool isControlled) : SimObject(position, size, color, orderIndex)
{
    _movement = new Movement(speed, collisionDistance, angleStep, angleDegrees, rotateClockwise, _transform);
    _isControlled = isControlled;
}

Robot::~Robot()
{
    delete _movement;
}

bool Robot::IsControlled()
{
    return _isControlled;
}

Movement* Robot::GetMovement()
{
    return _movement;
}

SimObjView Robot::GetSimObjView()
{
    return {_orderIndex, GetTransform()->GetRect().x, GetTransform()->GetRect().y, GetTransform()->GetRect().h, GetTransform()->GetRect().w, _color, true, _isControlled, int(_movement->GetSpeed()), _movement->GetAngleDegrees(), 0};
}
