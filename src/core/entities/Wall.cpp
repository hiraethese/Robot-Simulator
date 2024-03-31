#include "Wall.h"

Wall::Wall(Vector2d position, Vector2d size, colors color) : SimObject(position, size, color) {}

SimObjView Wall::GetSimObjView(){
    return {GetTransform()->GetRect().h,GetTransform()->GetRect().w, _color, false, false, 0, 0, 0};
}

