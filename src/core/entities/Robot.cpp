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

SimObjView* Robot::GetSimObjView()
{
    _simObjView =   {

                _transform->GetPosition().x - 0.5f * _transform->GetSize().x,
                _transform->GetPosition().y - 0.5f * _transform->GetSize().y,
                _transform->GetPosition().x,
                _transform->GetPosition().y,
                _transform->GetSize().x,
                _transform->GetSize().y,
                _movement->GetSpeed(),
                _movement->GetCollisionDistance(),
                _movement->GetAngleStep(),
                _movement->GetAngleDegrees(),
                _movement->GetRotateClockwise(),
                _color,
                _orderIndex,
                _isControlled,
                true
            };
    return &(_simObjView);
}


void Robot::SetSimObjView(SimObjView view)
{
    _isControlled = view.isControlled;
    _transform->SetSize({view.w, view.h});
    _color = view.color;
    _movement->SetSpeed(view.speed);
    _movement->SetCollisionDistance(view.collisionDistance);
    _movement->SetAngleDegrees(view.angleDegrees);
    _movement->SetAngleStep(view.angleStep);
    _movement->SetRotateClockwise(view.rotateClockwise);
}
