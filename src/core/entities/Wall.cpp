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
SimObjView* Wall::GetSimObjView()
{
    _simObjView = {
                _transform->GetPosition().x,
                _transform->GetPosition().y,
                _transform->GetSize().x,
                _transform->GetSize().y,
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

    return &(_simObjView);
}

SimObjView *Wall::GetSimObjViewGUI()
{
    GetSimObjView();
    _simObjView = _simObjView.toGUI();
    return &(_simObjView);
}

void Wall::SetSimObjView(SimObjView view)
{
    _transform->SetSize({view.w, view.h});
    _color = view.color;
}
