/**
 * @file SimulationScene.h
 * @author Baturov Illia (xbatur00@stud.fit.vutbr.cz)
 * @author Kukhta Myron (xkukht01@stud.fit.vutbr.cz)
 * @brief Header of class for simulation scene
 */
#ifndef SIMULATIONSCENE_H
#define SIMULATIONSCENE_H

#include <QGraphicsScene>
#include <QObject>
#include <QPointF>
#include <QGraphicsSceneMouseEvent>
#include <iostream>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QBrush>
#include <QPen>
#include <QPointF>
#include <QTimer>
#include <vector>

#include "../style.h"
#include "../../core/Core.h"
#include "entitiesGUI/RobotGUI.h"
#include "entitiesGUI/WallGUI.h"

/**
 * @brief Class for display simulation process
 * 
 */
class SimulationScene : public QGraphicsScene
{

    Q_OBJECT

public:
    /**
     * @brief Construct a new Simulation Scene object
     * 
     * @param parent parent widget
     */
    explicit SimulationScene(QObject *parent = nullptr);

    /**
     * @brief Delete all simulations object from scene
     * 
     */
    void CleareSimulationScene();

    /**
     * @brief Request from core all actual existed simulation objects and create their GUI display
     */
    void LoadSimObj();

    /**
     * @brief Init simulations running , activate timer for animations frames
     * 
     */
    void InitSimRun();

    /**
     * @brief Stop simulation running, mute timer for animations frames
     * 
     */
    void StopSimRun();

    /**
     * @brief Create new robots display by view and push his on robots displays vector
     * 
     * @param view based on wich created new robots display
     */
    void PushNewRobotToMap(SimObjView view);

    /**
     * @brief Create new walls display by view and push his on walls displays vector
     * 
     * @param view based on wich created new walls display
     */
    void PushNewWallToMap(SimObjView view);

    /**
     * @brief Update simulations object display
     * 
     * @param orderIndex order of simulation object wich displays will be updated
     * @param isRobot discriminator (robot/wall)
     * @return ICP_CODE result of updating
     */
    ICP_CODE UpdateSimObjGuiState(int orderIndex, bool isRobot);

    /**
     * @brief Remove display for robot from simulation scene
     * 
     * @param orderIndex order index of robot wich display will be removed
     * @return ICP_CODE result of removing
     */
    ICP_CODE RemoveRobotByOrderIndex(int orderIndex);
    
    /**
     * @brief Remove display for wall from simulation scene
     * 
     * @param orderIndex order index of wall wich display will be removed
     * @return ICP_CODE result of removing
     */
    ICP_CODE RemoveWallByOrderIndex(int orderIndex);

protected:
    
    /**
     * @brief Override abstract method from base class for catching users click on scene body 
     * 
     * @param event catched users event
     */
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;

private:

    /**
     * @brief Object for connecting differnts simulations object with scene by slot/signals 
     * 
     */
    ConnectorGUI _conn;
    
    /**
     * @brief Instance of core for synchro internal app process
     */
    Core* _core;

    /**
     * @brief Timer for synchro animations frames
     */
    QTimer _simTimer;

    /**
     * @brief Vector for saving all displays of robots from core
     */
    std::vector<RobotGUI*>_robotsGUIVector;
    
    /**
     * @brief Vector for saving all displays of walls from core
     */
    std::vector<WallGUI*>_wallsGUIVector;

    /**
     * @brief Search robots display by order index
     * 
     * @param orderIndex index of searched robot
     * @return std::vector<RobotGUI*>::iterator iterator on vectors position with searched robot 
     */
    std::vector<RobotGUI*>::iterator _GetRobotByOrderIndex(int orderIndex);
    
    /**
     * @brief Search walls display by order index
     * 
     * @param orderIndex index of searched wall
     * @return std::vector<WallGUI*>::iterator iterator on vectors position with searched wall 
     */
    std::vector<WallGUI*>::iterator _GetWallByOrderIndex(int orderIndex);

    /**
     * @brief Create display for robot by view
     * 
     * @param view information about robot for wich will be view created
     * @return RobotGUI* pointer on new robots display
     */
    RobotGUI* _CreateNewRobotGui(SimObjView view);

    /**
     * @brief Create display for wall by view
     * 
     * @param view information about wall for wich will be view created
     * @return WallGUI* pointer on new walls display
     */
    WallGUI* _CreateNewWallGUI(SimObjView view);
    
signals:

    /**
     * @brief Signal for sending actual users click on scene from SimulationScene to SimulationWindow
     * 
     * @param clickPoint users click on OX-OY
     */
    void ClickSig(QPointF clickPoint);

    /**
     * @brief Signal for sending request from SimulationScene to SimulationWindow for displayng settings for clicked simulations object
     * 
     * @param orderIndex order of simulations object
     * @param isRobot discriminator (robot/wall)
     */
    void RequestSimObjSig(int orderIndex, bool isRobot);

private slots:

    /**
     * @brief Slot for make one animations frame
     */
    void _OneSimFrameSlot();
};

#endif // SIMULATIONSCENE_H
