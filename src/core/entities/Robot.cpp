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

SimObjView Robot::GetSimObjView(){
    return {GetTransform()->GetRect().h,GetTransform()->GetRect().w, _color, true, _isControlled, int(_movement->GetSpeed()), _movement->GetAngleDegrees(), 0};
}
