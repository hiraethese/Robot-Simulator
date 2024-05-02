/**
 * @file SimulationWindow.h
 * @author Baturov Illia (xbatur00@stud.fit.vutbr.cz)
 * @author Kukhta Myron (xkukht01@stud.fit.vutbr.cz)
 * @brief Header of class for buffer between main window and simulation scene
 */
#ifndef SIMULATIONWINDOW_H
#define SIMULATIONWINDOW_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <vector>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPalette>
#include <QTimer>
#include <QBrush>
#include <QPen>
#include <QPointF>
#include <QColor>
#include <QPointF>
#include <iostream>
#include <QKeyEvent>

#include "../../core/Core.h"
#include "SimulationScene.h"

/**
 * @brief type of build mode states
 */
enum BuildModeStatus{
    NotSetStatus,
    CursorStatus,
    ControllRobotStatus,
    AutoRobotStatus,
    WallStatus
};

/**
 * @brief Class for buffer between main window and simulations scene with engine for controlled robots moving
 * 
 */
class SimulationWindow : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief Construct a new Simulation Window object
     * 
     * @param parent parents widget
     */
    explicit SimulationWindow(QWidget *parent = nullptr);

    /**
     * @brief Destroy the Simulation Window object
     */
    ~SimulationWindow();

    /**
     * @brief switch widget functional between simulation and build mode 
     * 
     * @param flagIsBuild discriminator (simulation/build mode)
     */
    void SwitchBetweenSimAndBuild(bool flagIsBuild);

    /**
     * @brief call init simulations running from simulations scene
     */
    void RunSimScene();

    /**
     * @brief call stop simulations runnig from simulations scene
     * 
     */
    void StopSimScene();

    /**
     * @brief subtype of build mode
     * 
     */
    BuildModeStatus buildModeStatus = NotSetStatus;

    /**
     * @brief call removing simulations object from simulation scene
     * 
     * @param orderIndex index of removed simulations object
     * @param isRobot descriminator (robot/wall)
     * @return ICP_CODE result of removing
     */
    ICP_CODE RemoveSimObjByOrderIndexSlot(int orderIndex, bool isRobot);

    /**
     * @brief call updating simualtions object from simulation scene
     * 
     * @param orderIndex index of updated simualtions object
     * @param isRobot  descriminator (robot/wall)
     * @return ICP_CODE  result of updating
     */
    ICP_CODE UpdateSimObjGuiState(int orderIndex, bool isRobot);

protected:
    /**
     * @brief Overrided abstract method from base class for controlling user press on W/A/S/D buttons which connected to conterolled robots moving engine
     * 
     * @param event catched users event
     */
    void keyPressEvent(QKeyEvent *event) override;

private:

    /**
     * @brief Instance of core for synchro internal app process
     */
    Core* _core;

    /**
     * @brief View for simulation scene 
     */
    QGraphicsView* _simulationView = nullptr;

    /**
     * @brief Simulation scene for display simulations running
     * 
     */
    SimulationScene* _simulationScene = nullptr;

    /**
     * @brief Create simualtion scene
     */
    void _CreateSimGUI();

    /**
     * @brief Delete simulation scene
     */
    void _DeleteSimGUI();
    
    /**
     * @brief Place for location simualtion scene and engine controlled robots moving
     */
    QVBoxLayout* _simulationsLayot;

    /**
     * @brief Place for location simulation scene
     */
    QHBoxLayout* _simBodyowBoxLayout;
    
    /**
     * @brief Frame for location engine controlled robots moving place 
     */
    QHBoxLayout* _simulatyonEngineLayout;

    /**
     * @brief Place for location engine controlled robots moving
     * 
     */
    QVBoxLayout* _robotsEngineLayout;

    /**
     * @brief Place for location forward moving button (engine)
     */
    QHBoxLayout* _highRobotsEngineLayout;

    /**
     * @brief Place for location rotates/stop buttons (engine)
     * 
     */
    QHBoxLayout* _lowRobotsEngineLayout;

    /**
     * @brief Button for controlled robot forward moving
     */
    QPushButton* _forwardMoveButton = nullptr;

    
    /**
     * @brief Button for controlled robot rotate counterclockwise
     */
    QPushButton* _leftMoveButton = nullptr;

    
    /**
     * @brief Button for controlled robot stop moving
     */
    QPushButton* _stopMoveButton = nullptr;

    
    /**
     * @brief Button for controlled robot rotate clockwise
     */
    QPushButton* _rightMoveButton = nullptr;

    /**
     * @brief Create place for location simulation scene and controlled robots moving engine
     * 
     */
    void _CreateSimulationsLayout();

    /**
     * @brief Delete place for location simulation scene and controlled robots moving engine
     * 
     */
    void _DeleteSimulationsLayout();

    /**
     * @brief Change enabling controlled robots moving engine 
     * 
     * @param flagIsSet 
     */
    void _SetUnsetSimButtons(bool flagIsSet);


signals:

    /**
     * @brief Signal for sending to main window location of user click on OX-OY
     * 
     * @param clickPoint 
     */
    void UperClickSig(QPointF clickPoint);

    /**
     * @brief Signal for sending request information about simulation object
     * 
     * @param orderIndex index of simulations scene
     * @param isRobot discriminator (simulation/build mode)
     */
    void RequestSimObjSig(int orderIndex, bool isRobot);

    /**
     * @brief Signal for sending loading new map action from main window to simualtions scene
     */
    void LoadSimSceneSig();

    /**
     * @brief Signal for sending creating new simualtion object action by user click from simulation scene to main window
     * 
     * @param view information about new simualtions object
     * @param x position on OX for new simulation object
     * @param y position on OY for new simulation object 
     */
    void CreateNewSimObjSig(SimObjView view, float x, float y);

    /**
     * @brief Signal for sending deleting all simulation object action from main window to simulations scene 
     * 
     */
    void CleareSimulationSceneSig();

    /**
     * @brief Signal for sending error code from simualtion window/scene to main window
     * 
     * @param err_code 
     */
    void UperErrorCodeSig(ICP_CODE err_code);

private slots:
    /**
     * @brief slot for controlling creating new simualtions object in simulation scene
     * 
     * @param clickPoint 
     */
    void _CreateNewSimObjGUISlot(QPointF clickPoint);
};

#endif // SIMULATIONWINDOW_H
