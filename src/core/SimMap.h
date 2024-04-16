#ifndef SIMMAP_H
#define SIMMAP_H

#include <string>
#include <fstream>
#include <sstream>
#include <QFileInfo>
#include <QString>
#include "SimFactory.h"

class SimMap
{
    // TODO: return 0 if i give path "/mnt"
private:
    std::string _path {};
    int _width;
    int _height;
    SimFactory* _factory;
    int _orderIndex = 1;
public:
    SimMap(int width, int height);
    std::string GetPath();
    int GetWidth();
    int GetHeight();
    SimFactory* GetFactory();
    void SetPath(std::string newPath);
    int LoadObjectsFromFile(std::string path);
    bool ProcessControlledRobotLine(std::istringstream& iss);
    bool ProcessWallLine(std::istringstream& iss);
};

#endif // SIMMAP_H
