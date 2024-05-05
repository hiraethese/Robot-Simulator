/**
 * @file MyTransform.h
 * @author Baturov Illia (xbatur00@stud.fit.vutbr.cz)
 * @author Kukhta Myron (xkukht01@stud.fit.vutbr.cz)
 * @brief Header of the transform class
 */

#ifndef MYTRANSFORM_H
#define MYTRANSFORM_H

#include "../icplib.h"

/**
 * @brief Class that represents an object that contains position and size
 * Note: The class name was chosen for convenience and to avoid the possibility of name conflicts
 */
class MyTransform {

private:
    /**
     * @brief Object position during simulation
     * 2D vector for X and Y
     */
    Vector2d _position;

    /**
     * @brief Object size during simulation
     * 2D vector for width and height
     */
    Vector2d _size;

public:
    /**
     * @brief Construct a new My Transform object
     * 
     * @param position object position
     * @param size object size
     */
    MyTransform(Vector2d position, Vector2d size);

    /**
     * @brief Set the Position object
     * 
     * @param newPosition new object position
     */
    void SetPosition(Vector2d newPosition);

    /**
     * @brief Set the Size object
     * 
     * @param newSize new object size
     */
    void SetSize(Vector2d newSize);

    /**
     * @brief Get the Position object
     * 
     * @return Vector2d
     * Returns the current position of an object
     */
    Vector2d GetPosition();

    /**
     * @brief Get the Size object
     * 
     * @return Vector2d
     * Returns the current size of an object
     */
    Vector2d GetSize();
};

#endif // MYTRANSFORM_H
