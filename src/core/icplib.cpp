#include "icplib.h"

bool CircRectCollision(Vector2d circPos, float circRadius, Vector2d rectPos, Vector2d rectSize)
{
    // temporary variables to set edges for testing
    float testX = circPos.x;
    float testY = circPos.y;

    // which edge is closest?
    if (circPos.x < rectPos.x - rectSize.x * 0.5) {
        // test left edge
        testX = rectPos.x - rectSize.x * 0.5;
    } else if (circPos.x > rectPos.x + rectSize.x * 0.5) {
        // right edge
        testX = rectPos.x + rectSize.x * 0.5;
    }

    if (circPos.y < rectPos.y - rectSize.y * 0.5) {
        // top edge
        testY = rectPos.y - rectSize.y * 0.5;
    } else if (circPos.y > rectPos.y + rectSize.y * 0.5) {
        // bottom edge
        testY = rectPos.y + rectSize.y * 0.5;
    }

    // get distance from closest edges
    Vector2d distance = {circPos.x - testX, circPos.y - testY};

    // if the distance is less than the radius, collision!
    if (distance.getLength() < circRadius) {
        return true;
    }
    return false;
}

bool CircCircCollision(Vector2d firstCircPos, float firstCircRadius, Vector2d secondCircPos, float secondCircRadius)
{
    // get distance between the circle's centers
    // use the Pythagorean Theorem to compute the distance
    float distX = firstCircPos.x - secondCircPos.x;
    float distY = firstCircPos.y - secondCircPos.y;
    float distance = sqrt((distX * distX) + (distY * distY));

    // if the distance is less than the sum of the circle's
    // radii, the circles are touching!
    if (distance < firstCircRadius + secondCircRadius) {
        return true;
    }
    return false;
}

float ConvertDegreesToRadians(float angleDegrees)
{
    return angleDegrees * ( M_PI / 180.0f );
}
