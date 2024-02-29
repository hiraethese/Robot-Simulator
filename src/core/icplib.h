#ifndef ICPLIB_H
#define ICPLIB_H

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

// Integer size
typedef struct IntSize {
    int w; // Size width component
    int h; // Size height component
} IntSize;

#endif // ICPLIB_H
