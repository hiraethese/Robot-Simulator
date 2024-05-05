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
     * 
     */
    Core();

    /**
     * @brief 
     * 
     */
    static Core* _core;

    /**
     * @brief 
     * 
     */
    SimMap* _map = nullptr;

public:
    /**
     * @brief 
     * 
     */
    void ClearCoreMemory();

    /**
     * @brief Get the Instance object
     * 
     * @return Core* 
     */
    static Core* getInstance();

    /**
     * @brief Get the Map Value object
     * 
     * @return std::string 
     */
    std::string GetMapValue();

    /**
     * @brief Get the Map Width object
     * 
     * @return int 
     */
    int GetMapWidth();

    /**
     * @brief Get the Map Height object
     * 
     * @return int 
     */
    int GetMapHeight();

    /**
     * @brief Get the Speed Value object
     * 
     * @return int 
     */
    int GetSpeedValue();

    /**
     * @brief Get the Angle Value object
     * 
     * @return int 
     */
    int GetAngleValue();

    /**
     * @brief 
     * 
     */
    void LeftRotateMoveSig();

    /**
     * @brief 
     * 
     */
    void RightRotateMoveSig();

    /**
     * @brief 
     * 
     */
    void ForwardMoveSig();

    /**
     * @brief 
     * 
     */
    void StopMoveSig();

    /**
     * @brief 
     * 
     */
    void MoveAllObjects();

    /**
     * @brief Create a New Controlled Robot From Template object
     * 
     * @param x 
     * @param y 
     * @return ICP_CODE 
     */
    ICP_CODE CreateNewControlledRobotFromTemplate(float x, float y);

    /**
     * @brief Create a New Automated Robot From Template object
     * 
     * @param x 
     * @param y 
     * @return ICP_CODE 
     */
    ICP_CODE CreateNewAutomatedRobotFromTemplate(float x, float y);

    /**
     * @brief Create a New Wall From Template object
     * 
     * @param x 
     * @param y 
     * @return ICP_CODE 
     */
    ICP_CODE CreateNewWallFromTemplate(float x, float y);

    /**
     * @brief 
     * 
     * @param view 
     * @return ICP_CODE 
     */
    ICP_CODE UpdateRobotState(SimObjView view);

    /**
     * @brief 
     * 
     * @param view 
     * @return ICP_CODE 
     */
    ICP_CODE UpdateWallState(SimObjView view);

    /**
     * @brief 
     * 
     * @param orderIndex 
     * @return ICP_CODE 
     */
    ICP_CODE RemoveRobotByOrderIndex(int orderIndex);

    /**
     * @brief 
     * 
     * @param orderInex 
     * @return ICP_CODE 
     */
    ICP_CODE RemoveWallByOrderIndex(int orderInex);

    /**
     * @brief 
     * 
     * @param path 
     * @return ICP_CODE 
     */
    ICP_CODE LoadingMap(std::string path);

    /**
     * @brief Get the Vector Walls object
     * 
     * @return const std::vector<Wall*>& 
     */
    const std::vector<Wall*>& GetVectorWalls() const;

    /**
     * @brief Get the Vector Robots object
     * 
     * @return const std::vector<Robot*>& 
     */
    const std::vector<Robot*>& GetVectorRobots() const;

    /**
     * @brief Get the Vector Walls View object
     * 
     * @return std::vector<SimObjView> 
     */
    std::vector<SimObjView> GetVectorWallsView();

    /**
     * @brief Get the Vector Robots View object
     * 
     * @return std::vector<SimObjView> 
     */
    std::vector<SimObjView> GetVectorRobotsView();

    /**
     * @brief Get the Controlled Robot Temp object
     * 
     * @return SimObjView 
     */
    SimObjView GetControlledRobotTemp();

    /**
     * @brief Get the Automated Robot Temp object
     * 
     * @return SimObjView 
     */
    SimObjView GetAutomatedRobotTemp();

    /**
     * @brief Get the Wall Temp object
     * 
     * @return SimObjView 
     */
    SimObjView GetWallTemp();

    /**
     * @brief Get the View By Order G U I object
     * 
     * @param view 
     * @param orderIndex 
     * @param IsRobot 
     * @return ICP_CODE 
     */
    ICP_CODE GetViewByOrderGUI(SimObjView* view, int orderIndex, bool IsRobot);

    /**
     * @brief Set the Controlled Robot Temp object
     * 
     * @param newTemp 
     */
    void SetControlledRobotTemp(SimObjView newTemp);

    /**
     * @brief Set the Automated Robot Temp object
     * 
     * @param newTemp 
     */
    void SetAutomatedRobotTemp(SimObjView newTemp);

    /**
     * @brief Set the Wall Temp object
     * 
     * @param newTemp 
     */
    void SetWallTemp(SimObjView newTemp);

    /**
     * @brief Get the Last Order Index object
     * 
     * @return int 
     */
    int GetLastOrderIndex();
};

#endif // CORE_H
