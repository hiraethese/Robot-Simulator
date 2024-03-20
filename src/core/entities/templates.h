#ifndef TEMPLATES_H
#define TEMPLATES_H
#include <string>

typedef struct{
    int diameter;
    int speed;
    int angle;
    int way;
    std::string color;
}RobotTemlate;

typedef struct{
    int w;
    int h;
    std::string color;
}WallTemplate;

#endif // TEMPLATES_H
