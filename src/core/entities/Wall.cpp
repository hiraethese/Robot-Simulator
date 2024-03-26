#include "Wall.h"

Wall::Wall(Vector2d position, Vector2d size, colors color) : SimObject(position, size, color) {}

WallView Wall::GetWallView(){
    return {GetTransform()->GetRect(), _color};
}
