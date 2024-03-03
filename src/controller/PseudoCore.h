#ifndef PSEUDOCORE_H
#define PSEUDOCORE_H

#include <string>

class PseudoCore{
public:
    PseudoCore();
    static const int DEFAULT_SPEED = 50;
    static const int DEFAULT_CORNER = 45;
    int speed = DEFAULT_SPEED;
    int corner = DEFAULT_CORNER;
    std::string map {};
    bool simIsRun = false;
    bool simIsReady = false;
};

extern PseudoCore* ps_core;
#endif // PSEUDOCORE_H
