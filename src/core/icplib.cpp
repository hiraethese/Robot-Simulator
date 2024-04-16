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
    if (distance.getLength() <= circRadius) {
        return true;
    }
    return false;
}
