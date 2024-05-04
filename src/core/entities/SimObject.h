/**
 * @file SimObject.h
 * @author Baturov Illia (xbatur00@stud.fit.vutbr.cz)
 * @author Kukhta Myron (xkukht01@stud.fit.vutbr.cz)
 * @brief Header of the simulation object class
 */

#ifndef SIMOBJECT_H
#define SIMOBJECT_H

#include "../properties/MyTransform.h"
#include <iostream>

/**
 * @brief Class that represents any simulation object
 * 
 */
class SimObject
{

protected:
    /**
     * @brief Pointer to an object of the MyTransform class
     * Contains parameters for the position and size of the object
     */
    MyTransform* _transform;

    /**
     * @brief Unique number for an object
     * Order index is set during object creation
     */
    int _orderIndex;

    /**
     * @brief Object color
     * Colors are presented as enumeration
     */
    colors _color;

    /**
     * @brief Structure that contains all the necessary parameters of the simulation object
     * 
     */
    SimObjView _simObjView;

public:
    /**
     * @brief Construct a new Sim Object object
     * 
     * @param position simulation object position
     * @param size simulation object size
     * @param color simulation object color
     * @param orderIndex simulation object unique number
     */
    SimObject(Vector2d position, Vector2d size, colors color, int orderIndex);

    /**
     * @brief Destroy the Sim Object object
     * 
     */
    virtual ~SimObject();

    /**
     * @brief Get the Transform object
     * 
     * @return MyTransform*
     * Returns a pointer to the transformation of simulation object
     */
    MyTransform* GetTransform();

    /**
     * @brief Get the Order Index object
     * 
     * @return int
     * Returns the unique number of the simulation object
     */
    int GetOrderIndex();

    /**
     * @brief Get the Sim Obj View object
     * Virtual method that is implemented differently for classes that inherit simulation object class
     * 
     * @return SimObjView*
     * Returns a pointer to a structure that contains all the necessary information about the simulation object
     */
    virtual SimObjView* GetSimObjView() = 0;

    /**
     * @brief Set the Sim Obj View object
     * Virtual method that is implemented differently for classes that inherit simulation object class
     * 
     * @param view structure that sets new simulation object values
     */
    virtual void SetSimObjView(SimObjView view) = 0;
};

#endif // SIMOBJECT_H
