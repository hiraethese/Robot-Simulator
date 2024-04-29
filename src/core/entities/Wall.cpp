#include "Wall.h"

Wall::Wall(Vector2d position, Vector2d size, colors color, int orderIndex) : SimObject(position, size, color, orderIndex) {}

// typedef struct SimObjView {
//     float x;
//     float y;
//     float w;
//     float h;
//     float speed;
//     float collisionDistance;
//     int angleStep;
//     int angleDegrees;
//     int rotateClockwise;
//     colors colorCode;
//     int orderIndex;
//     bool isControlled;
//     bool isRobot;
// } SimObjView;

////////////////////////////// TODO - Correct GUI hitboxes !!!
SimObjView Wall::GetSimObjView(){
    // return {_orderIndex, GetTransform()->GetRect().x, GetTransform()->GetRect().y,GetTransform()->GetRect().h,GetTransform()->GetRect().w, _color, false, false, 0, 0, 0};
    return  {
                _transform->GetHitbox().x,
                _transform->GetHitbox().y,
                _transform->GetHitbox().w,
                _transform->GetHitbox().h,
                0.0,
                0.0,
                0,
                0,
                0,
                _color,
                _orderIndex,
                false,
                false
            };
}
