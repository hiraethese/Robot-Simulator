#ifndef SIMMAP_H
#define SIMMAP_H

#include <string>
#include "SimFactory.h"

class SimMap
{
private:
    std::string _path;
    int _width;
    int _height;
    SimFactory* _factory;

public:
    SimMap(std::string path, int width, int height);
    std::string GetPath();
    int GetWidth();
    int GetHeight();
    SimFactory* GetFactory();
    void SetPath(std::string newPath);
    void LoadObjects();
};

#endif // SIMMAP_H
