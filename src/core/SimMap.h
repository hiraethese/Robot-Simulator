/**
 * @file SimMap.h
 * @author Baturov Illia (xbatur00@stud.fit.vutbr.cz)
 * @author Kukhta Myron (xkukht01@stud.fit.vutbr.cz)
 * @brief Simulation map header file
 */

#ifndef SIMMAP_H
#define SIMMAP_H

#include <string>
#include <fstream>
#include <sstream>
#include <QFileInfo>
#include <QString>
#include <vector>
#include <string>
#include "Spawner.h"

/**
 * @brief Class that represents a simulation map object
 */
class SimMap
{

private:
    /**
     * @brief Path to simulation map
     */
    std::string _path {};

    /**
     * @brief Simulation map width
     */
    int _width;

    /**
     * @brief Simulation map height
     */
    int _height;

    /**
     * @brief First unoccupied order index for objects on the simulation map
     */
    int _orderIndex;

    /**
     * @brief Pointer to simulation object spawner
     */
    Spawner* _spawner;

    /**
     * @brief Vector with pointers to all walls of the simulation
     */
    std::vector<Wall*> _walls;

    /**
     * @brief Vector with pointers to all simulation robots
     */
    std::vector<Robot*> _robots;

public:
    /**
     * @brief Construct a new Sim Map object
     * 
     * @param width simulation map width
     * @param height simulation map height
     */
    SimMap(int width, int height);

    /**
     * @brief Destroy the simulation map object
     */
    ~SimMap();

    /**
     * @brief Get path to map
     * 
     * @return std::string
     */
    std::string GetPath();

    /**
     * @brief Get map width
     * 
     * @return int
     */
    int GetWidth();

    /**
     * @brief Get map height
     * 
     * @return int
     */
    int GetHeight();

    /**
     * @brief Set path to map
     * 
     * @param newPath new path to map
     */
    void SetPath(std::string newPath);

    /**
     * @brief Create a new controlled robot from template
     * 
     * @param x X coordinate when clicking
     * @param y Y coordinate when clicking
     * @return ICP_CODE
     * Returns a special code on error or success
     */
    ICP_CODE CreateNewControlledRobotFromTemplate(float x, float y);

    /**
     * @brief Creates a new automated robot from template
     * 
     * @param x X coordinate when clicking
     * @param y Y coordinate when clicking
     * @return ICP_CODE
     * Returns a special code on error or success
     */
    ICP_CODE CreateNewAutomatedRobotFromTemplate(float x, float y);

    /**
     * @brief Creates a new wall from template
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
     * @brief Loads simulation objects from a file
     * 
     * @param path path to file
     * @return ICP_CODE
     * Returns a special code on error or success
     */
    ICP_CODE LoadObjectsFromFile(std::string path);

    /**
     * @brief Checks for collision between the robot and other robots in the simulation
     * 
     * @param position robot position
     * @param radius robot radius
     * @param orderIndex robot order index
     * @return true
     * If there is a collision
     * @return false
     * If there are no collisions
     */
    bool RobotWithRobotsCollision(Vector2d position, float radius, int orderIndex);

    /**
     * @brief Checks for collision between the robot and all walls in the simulation
     * 
     * @param position robot position
     * @param radius robot radius
     * @return true
     * If there is a collision
     * @return false
     * If there are no collisions
     */
    bool RobotWithWallsCollision(Vector2d position, float radius);

    /**
     * @brief Checks for collision between the robot and map boundaries in the simulation
     * 
     * @param position robot position
     * @param radius robot radius
     * @return true
     * If there is a collision
     * @return false
     * If there are no collisions
     */
    bool RobotWithBordersCollision(Vector2d position, float radius);

    /**
     * @brief Checks for collision between the wall and all robots in the simulation
     * 
     * @param position wall position
     * @param size wall size
     * @return true
     * If there is a collision
     * @return false
     * If there are no collisions
     */
    bool WallWithRobotsCollision(Vector2d position, Vector2d size);

    /**
     * @brief Checks for collision between wall and map boundaries in the simulation
     * 
     * @param position wall position
     * @param size wall size
     * @return true
     * If there is a collision
     * @return false
     * If there are no collisions
     */
    bool WallWithBordersCollision(Vector2d position, Vector2d size);

    /**
     * @brief Get a vector with walls
     * 
     * @return const std::vector<Wall*>&
     */
    const std::vector<Wall*>& GetWalls() const;

    /**
     * @brief Get a vector with robots
     * 
     * @return const std::vector<Robot*>&
     */
    const std::vector<Robot*>& GetRobots() const;

    /**
     * @brief Get a vector with wall structures
     * 
     * @return std::vector<SimObjView>
     */
    std::vector<SimObjView> GetVectorWallsView();

    /**
     * @brief Get a vector with robot structures
     * 
     * @return std::vector<SimObjView>
     */
    std::vector<SimObjView> GetVectorRobotsView();

    /**
     * @brief Get the first controlled robot in vector
     * 
     * @return Robot* 
     */
    Robot* GetFirstControlledRobot();

    /**
     * @brief Get the spawner
     * 
     * @return Spawner*
     */
    Spawner* GetSpawner();

    /**
     * @brief Get the robot by order index
     * 
     * @param orderIndex order index of the required robot
     * @return std::vector<Robot*>::iterator
     */
    std::vector<Robot*>::iterator GetRobotByOrderIndex(int orderIndex);

    /**
     * @brief Get the wall by order index
     * 
     * @param orderIndex order index of the required wall
     * @return std::vector<Wall*>::iterator
     */
    std::vector<Wall*>::iterator GetWallByOrderIndex(int orderIndex);

    /**
     * @brief Removes a robot by its order index
     * 
     * @param orderIndex order index of the required robot
     * @return ICP_CODE
     * Returns a special code on error or success
     */
    ICP_CODE RemoveRobotByOrderIndex(int orderIndex);

    /**
     * @brief Removes a wall by its order index
     * 
     * @param orderIndex order index of the required wall
     * @return ICP_CODE
     * Returns a special code on error or success
     */
    ICP_CODE RemoveWallByOrderIndex(int orderIndex);

    /**
     * @brief Removes all objects on the map and clears all vectors with objects
     */
    void DeleteAllObjects();

    /**
     * @brief Get the last order index of an object on the map
     * 
     * @return int
     */
    int GetLastOrderIndex();

    /**
     * @brief Get the robot structure by order index
     * Function to use in GUI
     * 
     * @param view structure goes here
     * @param orderIndex robot order index
     * @return ICP_CODE
     * Returns a special code on error or success
     */
    ICP_CODE GetRobotViewByOrderGUI(SimObjView* view, int orderIndex);

    /**
     * @brief Get the wall structure by order index
     * Function to use in GUI
     * 
     * @param view structure goes here
     * @param orderIndex wall order index
     * @return ICP_CODE
     * Returns a special code on error or success
     */
    ICP_CODE GetWallViewByOrderGUI(SimObjView* view, int orderIndex);
};

#endif // SIMMAP_H
