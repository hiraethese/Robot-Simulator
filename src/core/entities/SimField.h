#ifndef SIMFIELD_H
#define SIMFIELD_H

#include "../icplib.h"

class SimField
{
private:
    int _width;
    int _height;

public:
    SimField(int width, int height);
    IntSize GetSize();
};

#endif // SIMFIELD_H
