#ifndef ICPLIB_H
#define ICPLIB_H

#include <math.h>
// Note: I was planning to use cmath instead, but VS Code has problems with it

// 2D vector
typedef struct Vector2d {
    float x; // Vector x component
    float y; // Vector y component

    Vector2d operator-(const Vector2d& other) const {
        return {x - other.x, y - other.y};
    }
    
    Vector2d operator+(const Vector2d& other) const {
        return {x + other.x, y + other.y};
    }

    Vector2d operator*(float scalar) const {
        return {x * scalar, y * scalar};
    }

    Vector2d operator/(float scalar) const {
        return {x / scalar, y / scalar};
    }

    float getLength() {
        return sqrt(x*x + y*y);
    }

    Vector2d Normalize() {
        Vector2d result;
        float length = result.getLength();

        if (length > 0) {
            float ilength = 1.0f/length;
            result.x = x*ilength;
            result.y = y*ilength;
        }

        return result;
    }
} Vector2d;

// Rectangle structure
typedef struct Rectangle {
    float x; // Rectangle x component
    float y; // Rectangle y component
    float w; // Rectangle width component
    float h; // Rectangle height component
} Rectangle;

#endif // ICPLIB_H
