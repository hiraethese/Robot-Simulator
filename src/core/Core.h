/**
 * @file Core.h
 * @author Baturov Illia (xbatur00@stud.fit.vutbr.cz)
 * @author Kukhta Myron (xkukht01@stud.fit.vutbr.cz)
 * @brief Header of the core
 */

#ifndef CORE_H
#define CORE_H

#include <string>
#include <iostream>
#include "SimMap.h"

/**
 * @brief Class that represents core singleton
 * The simulation core is a singleton
 */
class Core
{

private:
    /**
     * @brief Construct a new Core object
     * Also creates a simulation map
     */
    Core();

    /**
     * @brief Pointer to the Core singleton
     * Can be used many times
     */
    static Core* _core;

    /**
     * @brief Pointer to map object
     * The map contains all the information about the simulation
     */
    SimMap* _map = nullptr;

public:
    /**
     * @brief Method that clears all simulation memory
     * Called when the program terminates
     */
    void ClearCoreMemory();

    /**
     * @brief Get the Instance object
     * 
     * @return Core*
     * Returns a pointer to the Core singleton
     */
    static Core* getInstance();

    /**
     * @brief Get the Map Value object
     * 
     * @return std::string
     * Returns the path to the simulation map
     */
    std::string GetMapValue();

    /**
     * @brief Get the Map Width object
     * 
     * @return int
     * Returns the width of the simulation map
     */
    int GetMapWidth();

    /**
     * @brief Get the Map Height object
     * 
     * @return int
     * Returns the height of the simulation map
     */
    int GetMapHeight();

    /**
     * @brief Get the Speed Value object
     * 
     * @return int
     * Returns the speed of the first controlled robot in the robot vector
     */
    int GetSpeedValue();

    /**
     * @brief Get the Angle Value object
     * 
     * @return int
     * Returns the angle step of the first controlled robot in the robot vector
     */
    int GetAngleValue();

    /**
     * @brief Rotates all controlled robots counterclockwise
     * Called when the Left button is pressed
     */
    void LeftRotateMoveSig();

    /**
     * @brief Rotates all controlled robots clockwise
     * Called when the Right button is pressed
     */
    void RightRotateMoveSig();

    /**
     * @brief Allows movement of all controlled robots
     * Called when the Forward button is clicked
     */
    void ForwardMoveSig();

    /**
     * @brief Stops movement of all controlled robots
     * Called when the Stop button is clicked
     */
    void StopMoveSig();

    /**
     * @brief Moves all robots during the simulation every frame
     */
    void MoveAllObjects();

    /**
     * @brief Create a New Controlled Robot From Template object
     * Creates a new controlled robot from a template
     * 
     * @param x X coordinate when clicking
     * @param y Y coordinate when clicking
     * @return ICP_CODE
     * Returns a special code on error or success
     */
    ICP_CODE CreateNewControlledRobotFromTemplate(float x, float y);

    /**
     * @brief Create a New Automated Robot From Template object
     * Creates a new automated robot from a template
     * 
     * @param x X coordinate when clicking
     * @param y Y coordinate when clicking
     * @return ICP_CODE
     * Returns a special code on error or success
     */
    ICP_CODE CreateNewAutomatedRobotFromTemplate(float x, float y);

    /**
     * @brief Create a New Wall From Template object
     * Creates a new wall from a template
     * 
     * @param x X coordinate when clicking
     * @param y Y coordinate when clicking
     * @return ICP_CODE
     * Returns a special code on error or success
     */
    ICP_CODE CreateNewWallFromTemplate(float x, float y);

    /**
     * @brief Changes robot properties
     * 
     * @param view structure with new robot values
     * @return ICP_CODE
     * Returns a special code on error or success
     */
    ICP_CODE UpdateRobotState(SimObjView view);

    /**
     * @brief Changes wall properties
     * 
     * @param view structure with new wall values
     * @return ICP_CODE
     * Returns a special code on error or success
     */
    ICP_CODE UpdateWallState(SimObjView view);

    /**
     * @brief Removes a robot from the simulation
     * 
     * @param orderIndex unique order index of the robot
     * @return ICP_CODE
     * Returns a special code on error or success
     */
    ICP_CODE RemoveRobotByOrderIndex(int orderIndex);

    /**
     * @brief Removes a wall from the simulation
     * 
     * @param orderInex unique order index of the wall
     * @return ICP_CODE
     * Returns a special code on error or success
     */
    ICP_CODE RemoveWallByOrderIndex(int orderInex);

    /**
     * @brief Loads a map file into the simulation
     * 
     * @param path path to map
     * @return ICP_CODE
     * Returns a special code on error or success
     */
    ICP_CODE LoadingMap(std::string path);

    /**
     * @brief Get the Vector Walls object
     * 
     * @return const std::vector<Wall*>&
     * Returns a vector with pointers to the walls in the simulation
     */
    const std::vector<Wall*>& GetVectorWalls() const;

    /**
     * @brief Get the Vector Robots object
     * 
     * @return const std::vector<Robot*>&
     * Returns a vector with pointers to the robots in the simulation
     */
    const std::vector<Robot*>& GetVectorRobots() const;

    /**
     * @brief Get the Vector Walls View object
     * 
     * @return std::vector<SimObjView>
     * Returns a vector with wall parameter structures for use in the GUI
     */
    std::vector<SimObjView> GetVectorWallsView();

    /**
     * @brief Get the Vector Robots View object
     * 
     * @return std::vector<SimObjView>
     * Returns a vector with robot parameter structures for use in the GUI
     */
    std::vector<SimObjView> GetVectorRobotsView();

    /**
     * @brief Get the Controlled Robot Temp object
     * 
     * @return SimObjView
     * Returns the template of the controlled robot
     */
    SimObjView GetControlledRobotTemp();

    /**
     * @brief Get the Automated Robot Temp object
     * 
     * @return SimObjView
     * Returns the template of the automated robot
     */
    SimObjView GetAutomatedRobotTemp();

    /**
     * @brief Get the Wall Temp object
     * 
     * @return SimObjView
     * Returns the template of the wall
     */
    SimObjView GetWallTemp();

    /**
     * @brief Get the view by order for use in the GUI
     * 
     * @param view puts a value into this parameter
     * @param orderIndex unique order index of the object
     * @param IsRobot check if it's a robot or a wall
     * (true is robot, false is wall)
     * @return ICP_CODE
     * Returns a special code on error or success
     */
    ICP_CODE GetViewByOrderGUI(SimObjView* view, int orderIndex, bool IsRobot);

    /**
     * @brief Set the controlled robot template
     * 
     * @param newTemp new controlled robot template
     */
    void SetControlledRobotTemp(SimObjView newTemp);

    /**
     * @brief Set the automated robot template
     * 
     * @param newTemp new automated robot template
     */
    void SetAutomatedRobotTemp(SimObjView newTemp);

    /**
     * @brief Set the wall template
     * 
     * @param newTemp new wall template
     */
    void SetWallTemp(SimObjView newTemp);

    /**
     * @brief Get the last order index of an object on the map
     * 
     * @return int
     */
    int GetLastOrderIndex();
};

#endif // CORE_H
