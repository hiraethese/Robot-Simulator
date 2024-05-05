/**
 * @file icplib.cpp
 * @author Baturov Illia (xbatur00@stud.fit.vutbr.cz)
 * @author Kukhta Myron (xkukht01@stud.fit.vutbr.cz)
 * @brief Implementation of useful functions for the project
 */

#include "icplib.h"

bool CircRectCollision(Vector2d circPos, float circRadius, Vector2d rectPos, Vector2d rectSize)
{
    // Temporary variables to set edges for testing
    float testX = circPos.x;
    float testY = circPos.y;

    // Which edge is closest
    if (circPos.x < rectPos.x - rectSize.x * 0.5) {
        // Test left edge
        testX = rectPos.x - rectSize.x * 0.5;
    } else if (circPos.x > rectPos.x + rectSize.x * 0.5) {
        // Right edge
        testX = rectPos.x + rectSize.x * 0.5;
    }

    if (circPos.y < rectPos.y - rectSize.y * 0.5) {
        // Top edge
        testY = rectPos.y - rectSize.y * 0.5;
    } else if (circPos.y > rectPos.y + rectSize.y * 0.5) {
        // Bottom edge
        testY = rectPos.y + rectSize.y * 0.5;
    }

    // Get distance from closest edges
    Vector2d distance = {circPos.x - testX, circPos.y - testY};

    // If the distance is less than the radius, collision
    if (distance.getLength() < circRadius) {
        return true;
    }

    return false;
}

bool CircCircCollision(Vector2d firstCircPos, float firstCircRadius, Vector2d secondCircPos, float secondCircRadius)
{
    // Get distance between the circle's centers
    // Use the Pythagorean Theorem to compute the distance
    float distX = firstCircPos.x - secondCircPos.x;
    float distY = firstCircPos.y - secondCircPos.y;
    float distance = sqrt((distX * distX) + (distY * distY));

    // If the distance is less than the sum of the circle's radii, the circles are touching
    if (distance < firstCircRadius + secondCircRadius) {
        return true;
    }

    return false;
}

float ConvertDegreesToRadians(float angleDegrees)
{
    return angleDegrees * ( M_PI / 180.0f );
}
