/**
 * @file Wall.h
 * @author Baturov Illia (xbatur00@stud.fit.vutbr.cz)
 * @author Kukhta Myron (xkukht01@stud.fit.vutbr.cz)
 * @brief Header of the wall class, which inherits from the simulation object class
 */

#ifndef WALL_H
#define WALL_H

#include "SimObject.h"

/**
 * @brief Class that represents a wall simulation object
 * Wall is a stationary simulation object
 */
class Wall : public SimObject
{

public:
    /**
     * @brief Construct a new Wall object
     * 
     * @param position wall position
     * @param size wall size
     * @param color wall color
     * @param orderIndex wall unique number
     */
    Wall(Vector2d position, Vector2d size, colors color, int orderIndex);

    /**
     * @brief Get the Sim Obj View object
     * 
     * @return SimObjView*
     * Returns a pointer to a structure that contains all the necessary information about the wall
     */
    SimObjView *GetSimObjView() override;

    /**
     * @brief Set the Sim Obj View object
     * 
     * @param view structure that sets new wall values
     */
    void SetSimObjView(SimObjView view) override;
};

#endif // WALL_H
