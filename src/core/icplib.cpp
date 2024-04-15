#include "icplib.h"

bool CircRectCollision(Vector2d circPos, float circRadius, Vector2d rectPos, Vector2d rectSize)
{
    // temporary variables to set edges for testing

    float testX = circPos.x;
    float testY = circPos.y;

    // which edge is closest?

    if (circPos.x < rectPos.x) {
        // test left edge
        testX = rectPos.x;
    } else if (circPos.x > rectPos.x+rectSize.x) {
        // right edge
        testX = rectPos.x+rectSize.x;
    }

    if (circPos.y < rectPos.y) {
        // top edge
        testY = rectPos.y;
    } else if (circPos.y > rectPos.y+rectSize.y) {
        // bottom edge
        testY = rectPos.y+rectSize.y;
    }

    // get distance from closest edges

    float distX = circPos.x-testX;
    float distY = circPos.y-testY;
    float distance = sqrt( (distX*distX) + (distY*distY) );

    // if the distance is less than the radius, collision!

    if (distance <= circRadius) {
        return true;
    }
    return false;
}
