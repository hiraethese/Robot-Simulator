#include "Wall.h"

Wall::Wall(Vector2d position, Vector2d size, colors color, int orderIndex) : SimObject(position, size, color, orderIndex) {}

SimObjView Wall::GetSimObjView(){
    return {_orderIndex, GetTransform()->GetRect().x, GetTransform()->GetRect().y,GetTransform()->GetRect().h,GetTransform()->GetRect().w, _color, false, false, 0, 0, 0};
}

