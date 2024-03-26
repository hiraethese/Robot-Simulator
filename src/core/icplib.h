#ifndef ICPLIB_H
#define ICPLIB_H

#include <math.h>
#include <string>
// Note: I was planning to use cmath instead, but VS Code has problems with it

enum colors{
    WHITE,
    BLACK,
    BLUE,
    RED,
    GREEN,
    YELLOW,
    GRAY
};

// 2D vector
typedef struct Vector2d {
    float x; // Vector x component
    float y; // Vector y component
} Vector2d;

// Rectangle structure
typedef struct Rectangle {
    float x; // Rectangle x component
    float y; // Rectangle y component
    float w; // Rectangle width component
    float h; // Rectangle height component
} Rectangle;

typedef struct SimObjView {
    float h;
    float w;
    colors color;
    bool isRobot;
    bool isControlled;
    int speed;
    int angle;
    int way;
} SimObjView;


#endif // ICPLIB_H
