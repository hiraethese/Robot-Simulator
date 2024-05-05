/**
 * @file icplib.h
 * @author Baturov Illia (xbatur00@stud.fit.vutbr.cz)
 * @author Kukhta Myron (xkukht01@stud.fit.vutbr.cz)
 * @brief Header file with useful structures for the project
 */

#ifndef ICPLIB_H
#define ICPLIB_H

#include <math.h>
#include <string>

/**
 * @brief Enumeration of all returned error or success codes in a program
 */
enum ICP_CODE {
    CODE_OK,
    CODE_INTERNAL_ERROR,
    CODE_ERROR_INPUT_FILE_NOT_EXIST,
    CODE_SYNTAXE_ERROR_UNKNOWN_OBJ_TYPE,
    CODE_SYNTAXE_ERROR_INPUT_FILE_CONTR_ROBOT,
    CODE_SYNTAXE_ERROR_INPUT_FILE_AUTO_ROBOT,
    CODE_SYNTAXE_ERROR_INPUT_FILE_WALL,
    CODE_NEW_OBJECT_COLLISION_ERROR,
    CODE_ERROR_SIM_OBJ_IS_NOT_FOUND_IN_CORE,
    CODE_ERROR_SIM_OBJ_IS_NOT_FOUND_IN_GUI
};

/**
 * @brief Enumeration of all colors in a program
 */
enum colors {
    WHITE,
    BLACK,
    BLUE,
    RED,
    GREEN,
    YELLOW,
    GRAY
};

/**
 * @brief 2D vector
 */
typedef struct Vector2d {
    /**
     * @brief Vector x component
     */
    float x;

    /**
     * @brief Vector y component
     */
    float y;

    /**
     * @brief Vector subtraction operation
     * 
     * @param other second vector
     * @return Vector2d
     */
    Vector2d operator-(const Vector2d& other) const {
        return {x - other.x, y - other.y};
    }

    /**
     * @brief Vector addition operation
     * 
     * @param other second vector
     * @return Vector2d
     */
    Vector2d operator+(const Vector2d& other) const {
        return {x + other.x, y + other.y};
    }

    /**
     * @brief Operation of multiplying a vector by a constant
     * 
     * @param scalar constant value
     * @return Vector2d
     */
    Vector2d operator*(float scalar) const {
        return {x * scalar, y * scalar};
    }

    /**
     * @brief Operation of dividing a vector by a constant
     * 
     * @param scalar constant value
     * @return Vector2d
     */
    Vector2d operator/(float scalar) const {
        return {x / scalar, y / scalar};
    }

    /**
     * @brief Get vector length
     * 
     * @return float
     */
    float getLength() {
        return sqrt(x*x + y*y);
    }

    /**
     * @brief Vector normalization
     */
    void Normalize() {
        float length = getLength();
        if (length > 0)
        {
            float ilength = 1.0f / length;
            x = x * ilength;
            y = y * ilength;
        }
    }
} Vector2d;

/**
 * @brief Hitbox structure
 */
typedef struct Hitbox {
    /**
     * @brief Hitbox x component
     */
    float x;

    /**
     * @brief Hitbox y component
     */
    float y;

    /**
     * @brief Hitbox width component
     */
    float w;

    /**
     * @brief Hitbox height component
     */
    float h;
} Hitbox;

/**
 * @brief Function to check for collision between circle and rectangle
 * 
 * @param circPos circle position
 * @param circRadius circle radius
 * @param rectPos rectangle position
 * @param rectSize rectangle size
 * @return true
 * If there is a collision
 * @return false
 * If there is no collision
 */
bool CircRectCollision(Vector2d circPos, float circRadius, Vector2d rectPos, Vector2d rectSize);

/**
 * @brief Function to check for collision between circle and circle
 * 
 * @param firstCircPos first circle postion
 * @param firstCircRadius first circle radius
 * @param secondCircPos second circle position
 * @param secondCircRadius second circle radius
 * @return true
 * If there is a collision
 * @return false
 * If there is no collision
 */
bool CircCircCollision(Vector2d firstCircPos, float firstCircRadius, Vector2d secondCircPos, float secondCircRadius);

/**
 * @brief Function to convert degrees to radians
 * 
 * @param angleDegrees angle in degrees to convert
 * @return float
 * Returns the angle in radians
 */
float ConvertDegreesToRadians(float angleDegrees);

/**
 * @brief Basic structure with all parameters of simulation objects
 */
typedef struct SimObjView {
    /**
     * @brief X coordinate of the upper left corner of the object
     */
    float x_GUI;

    /**
     * @brief Y coordinate of the upper left corner of the object
     */
    float y_GUI;

    /**
     * @brief X coordinate of the object
     */
    float x;

    /**
     * @brief Y coordinate of the object
     */
    float y;

    /**
     * @brief Object width
     */
    float w;

    /**
     * @brief Object height
     */
    float h;

    /**
     * @brief Object speed
     */
    float speed;

    /**
     * @brief Object detection zone
     */
    float collisionDistance;

    /**
     * @brief Object rotation step
     */
    int angleStep;

    /**
     * @brief Object direction angle
     */
    int angleDegrees;

    /**
     * @brief Object rotation direction
     */
    int rotateClockwise;

    /**
     * @brief Object color
     */
    colors color;

    /**
     * @brief Object unique number
     */
    int orderIndex;

    /**
     * @brief Object is controlled or automated
     */
    bool isControlled;

    /**
     * @brief Object is a robot or a wall
     */
    bool isRobot;

    /**
     * @brief Get the upper left corner of the detection zone
     * 
     * @return Vector2d
     */
    Vector2d getDetectedZonePos() {
        return { x_GUI - collisionDistance, y_GUI - collisionDistance };
    }

    /**
     * @brief Get the detection zone size
     * 
     * @return Vector2d 
     */
    Vector2d getDetectedZoneSize() {
        return { w + collisionDistance * 2, h + collisionDistance * 2 };
    }

    /**
     * @brief Get a point on a circle by direction of movement
     * 
     * @return Vector2d
     */
    Vector2d getPointOnCircleByDirection() {
        float pointX = x + cos( ConvertDegreesToRadians(angleDegrees) ) * std::max(w, h) * 0.5f;
        float pointY = y + sin( ConvertDegreesToRadians(angleDegrees) ) * std::max(w, h) * 0.5f;
        return {pointX, pointY};
    }
} SimObjView;

#endif // ICPLIB_H
