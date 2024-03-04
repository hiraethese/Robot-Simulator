#ifndef SIMOBJECT_H
#define SIMOBJECT_H

#include "../properties/MyTransform.h"
#include "../properties/Movement.h"

// SimObject

class SimObject
{
protected:
    MyTransform* _transform;

public:
    SimObject(Vector2d position, Vector2d size);
    ~SimObject();
    MyTransform* GetTransform();
};

// Wall

class Wall : public SimObject
{
public:
    Wall(Vector2d position, Vector2d size);
};

// Robot

class Robot : public SimObject
{
private:
    Movement* _movement;

public:
    Robot(Vector2d position, Vector2d size, float speed, float angle);
    ~Robot();
};

#endif // SIMOBJECT_H
