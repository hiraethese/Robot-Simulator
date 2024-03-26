#include "Robot.h"

Robot::Robot(Vector2d position, Vector2d size, float speed, int angleStep, int angleDegrees, colors color, bool isControlled) : SimObject(position, size, color)
{
    _movement = new Movement(speed, angleStep, angleDegrees, _transform);
    _isControlled = isControlled;
}

Robot::~Robot()
{
    delete _movement;
}

Movement* Robot::GetMovement()
{
    return _movement;
}

RobotView Robot::GetRobotView(){
    return {GetTransform()->GetRect(), int(_movement->GetSpeed()), int(_movement->GetAngleDegrees()), 0, _color, _isControlled};
}
