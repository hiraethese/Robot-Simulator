#include "SimField.h"

SimField::SimField(int width, int height)
{
    _width = width;
    _height = height;
}

IntSize SimField::GetSize()
{
    return {_width, _height};
}
