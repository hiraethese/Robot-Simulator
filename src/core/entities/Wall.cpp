/**
 * @file Wall.cpp
 * @author Baturov Illia (xbatur00@stud.fit.vutbr.cz)
 * @author Kukhta Myron (xkukht01@stud.fit.vutbr.cz)
 * @brief Implementation of the wall class and its methods
 */

#include "Wall.h"

Wall::Wall(Vector2d position, Vector2d size, colors color, int orderIndex) : SimObject(position, size, color, orderIndex) {}

SimObjView* Wall::GetSimObjView()
{
    _simObjView = {
        _transform->GetPosition().x - 0.5f * _transform->GetSize().x,
        _transform->GetPosition().y - 0.5f * _transform->GetSize().y,
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

void Wall::SetSimObjView(SimObjView view)
{
    _transform->SetSize({view.w, view.h});
    _color = view.color;
}
