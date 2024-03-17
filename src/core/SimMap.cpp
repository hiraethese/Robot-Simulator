#include "SimMap.h"

SimMap::SimMap(std::string path, int width, int height)
{
    _path = path;
    _width = width;
    _height = height;
    _factory = new SimFactory();
}

std::string SimMap::GetPath()
{
    return _path;
}

int SimMap::GetWidth()
{
    return _width;
}

int SimMap::GetHeight()
{
    return _height;
}

SimFactory *SimMap::GetFactory()
{
    return _factory;
}

void SimMap::SetPath(std::string newPath)
{
    _path = newPath;
}

void SimMap::LoadObjects() {}
