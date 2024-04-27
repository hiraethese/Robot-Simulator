#ifndef ICPLIB_H
#define ICPLIB_H

#include <math.h>
#include <string>
// Note: I was planning to use cmath instead, but VS Code has problems with it

enum ICP_CODE{
    CODE_OK,
    CODE_EMPYT_SIMULATION,
    CODE_INTERNAL_ERROR,
    CODE_ERROR_INPUT_FILE_NOT_EXIST,
    CODE_SYNTAXE_ERROR_UNKNOWN_OBJ_TYPE,
    CODE_SYNTAXE_ERROR_INPUT_FILE_CONTR_ROBOT,
    CODE_SYNTAXE_ERROR_INPUT_FILE_AUTO_ROBOT,
    CODE_SYNTAXE_ERROR_INPUT_FILE_WALL,
    CODE_NEWOBJ_COLLISION // collision between a new object and an existing one
};

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

// Hitbox structure
typedef struct Hitbox {
    float x; // Hitbox x component
    float y; // Hitbox y component
    float w; // Hitbox width component
    float h; // Hitbox height component
} Hitbox;

typedef struct SimObjView {
    float x;
    float y;
    float w;
    float h;
    float speed;
    float collisionDistance;
    int angleStep;
    int angleDegrees;
    int rotateClockwise;
    colors color;
    int orderIndex;
    bool isControlled;
    bool isRobot;
} SimObjView;

bool CircRectCollision(Vector2d circPos, float circRadius, Vector2d rectPos, Vector2d rectSize);
bool CircCircCollision(Vector2d firstCircPos, float firstCircRadius, Vector2d secondCircPos, float secondCircRadius);

#endif // ICPLIB_H
