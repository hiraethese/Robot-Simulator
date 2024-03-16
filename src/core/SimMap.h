#ifndef SIMMAP_H
#define SIMMAP_H

#include <string>

class SimMap
{
private:
    std::string _path;
    int _width;
    int _height;

public:
    SimMap(std::string path, int width, int height);
    std::string GetPath();
    int GetWidth();
    int GetHeight();
    void SetPath(std::string newPath);
};

#endif // SIMMAP_H
