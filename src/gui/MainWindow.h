/**
 * @file MainWindow.h
 * @author Baturov Illia (xbatur00@stud.fit.vutbr.cz)
 * @author Kukhta Myron (xkukht01@stud.fit.vutbr.cz)
 * @brief Header of main GUI class
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QAction>
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <iostream>
#include <QIcon>
#include <QLineEdit>
#include <QMessageBox>
#include <QMenu>
#include <QString>
#include <QInputDialog>
#include <QPainter>
#include <QPalette>
#include <QPointF>
#include <QScrollArea>
#include <QString>
#include <QTabBar>
#include <QToolBar>
#include <QToolButton>
#include <QVBoxLayout>
#include <QWidget>
#include <string>
#include <QDialog>
#include <iostream>

#include "simulation/SimulationWindow.h"
#include "notifications/InfoNotification.h"
#include "settings/RobotSetting.h"
#include "settings/WallSetting.h"
#include "settings/NewMapSetting.h"
#include "../core/Core.h"
#include "style.h"

/**
 * @brief explain diffrenets UI state of application
 * 
 */
enum Page{
    NotSetPage,
    SimulationPage,
    BuildPage
};


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
class SimulationWindow;
class SettinsgWindow;
class Core;
class InfoNotification;
}
QT_END_NAMESPACE

/**
 * @brief Main window class
 * Class inherits Qts embedded class QMainWindow(body of our app) and our implemented class InfoNotification(for show errors notifications)
 * Keeps it in his body all widgets and build communications between them
 */
class MainWindow : public QMainWindow, public InfoNotification
{
    Q_OBJECT

public:
    
    /**
     * @brief Construct a new Main Window object
     * 
     * @param parent his parents widget(=null)
     */
    MainWindow(QWidget *parent = nullptr);
    
    /**
     * @brief Destroy the Main Window object
     */
    ~MainWindow();

private:
    /**
     * @brief Instance of core for synchro internal app process
     * 
     */
    Core* _core;
    /**
     * @brief Actual UI state of application
     * 
     */
    Page _actualPage = NotSetPage;

    /**
     * @brief Initializes all embedded widget
     */
    void _CreateAppWindows();

    /**
     * @brief Remove all embedded widget
     */
    void _DeleteAppWindows();

    /**
     * @brief The tool bar with information about status of simulation running
     * 
     */
    QToolBar* _simRunStatusToolBar;
    
    /**
     * @brief  The part of _simRunStatusToolBar
     */
    QLabel* _labelSimIdToolBar;

    /**
     * @brief The part of _simRunStatusToolBar, with status of simualtion running
     */
    QLineEdit* _lineSimRunStatus;

    /**
     * @brief The tool bar with controlling of simulation launch
     */
    QToolBar* _engineSimRunToolBar;
    
    /**
     * @brief The part of _engineSimRunToolBar, launcher of simulaton
     */
    QAction* _runSimulationAction = nullptr;
    
    /**
     * @brief Remove all tools from 
     * 
     */
    void _DeleteTools();

    /**
     * @brief The menu of app for settings and choosing functionals mode of app
     */
    QMenu* appMenu;

    /**
     * @brief The subMenu for settings simulations objects template
     */
    QMenu* templatesSubMenu;

    /**
     * @brief The action for switching to simulations mode of app
     */
    QAction* simulationModeAction;

    /**
     * @brief The action for switching to loading new map
     */
    QAction* downloadNewModeMapAction;

    /**
     * @brief The action for switching to build mode of app
     */
    QAction* buildMapModeAction;

    /**
     * @brief The action for settings templates of controlled robots 
     */
    QAction* buildControlledRobotTemplate;

    /**
     * @brief  The action for settings templates of auto robots 
     */
    QAction* buildAutoRobotTemplate;

    /**
     * @brief The action for settings templates of wall robots 
     */
    QAction* buildWallTemplate;

    /**
     * @brief Initializes body of app menu
     */
    void _CreateMenu();

    /**
     * @brief Remove body of app menu
     */
    void _DeleteMenu();


    /**
     * @brief The buffer between MainWindow and scene of simulation with items for robots controlling
     */
    SimulationWindow* _simulationWind;
    
    /**
     * @brief Initializes buffer between MainWindow and scene of simulation
     */
    void _CreateSimulationWindow();

    /**
     * @brief The settings pop-up window for robot
     */
    RobotSetting* _robotSetWind;
    
    /**
     * @brief The settings pop-up window for wall
     */
    WallSetting* _wallSetWind;

    /**
     * @brief The settings pop-up window for loading new map from txt file
     */
    NewMapSetting* _newMapWind;

    /**
     * @brief Initializes all settings pop-up windows
     */
    void _CreateSettings();

    /**
     * @brief Initializes all items for simulations mode of app
     */
    void _CreateSimModeTools();

    /**
     * @brief Remove all items for simulations mode of app
     */
    void _DeleteSimModeTools();

    /**
     * @brief The action for set users cursor on creating new controlled robots by template
     */
    QAction* _buildControlRobotAction;
    
    /**
     * @brief The action for set users cursor on creating new automated robots by template
     */
    QAction* _buildAutoRobotAction;

    
    /**
     * @brief The action for set users cursor on creating new walls by template
     */
    QAction* _buildWallAction;
    
    /**
     * @brief The tool bar with information about status of builded mode
     * 
     */
    QToolBar* _statusModeBuildToolBar;

    /**
     * @brief The part of _statusModeBuildToolBar
     */
    QLabel* _statusModeLabel;

    /**
     * @brief The part of _statusModeBuildToolBar, with name of choosed builded mode
     */
    QLineEdit* _statusModeLine;

    /**
     * @brief The tool bar of choosung build modes actions
     */
    QToolBar* _engineBuildToolBar;

    /**
     * @brief The tool bar with infomation about user click
    */
    QToolBar* _engineCursorToolBar;


    /**
     * @brief The part of _engineCursorToolBar (id of OX)
     * 
     */
    QLabel* _xCursorTouchLab;


    /**
     * @brief The part of _engineCursorToolBar (id of OY)
     * 
     */
    QLabel* _yCursorTouchLab;

    
    /**
     * @brief The users clicks point on OX
     * 
     */
    QLineEdit* _xCursorTouchLine;

    
    /**
     * @brief The users clicks point on OY 
     */
    QLineEdit* _yCursorTouchLine;

    /**
     * @brief Initializes all items for build mode of app
     */
    void _CreateBuildModeTools();

    /**
     * @brief Remove all items for simulations mode of app
     */
    void _DeleteBuildModeTools();

    /**
     * @brief Qt embedded UI for modeling interface(not used in porject)
     */
    Ui::MainWindow *ui;

public slots:

private slots:

    /**
     * @brief The slot for launch simulation
     */
    void _RunSimulationActionSlot();

    /**
     * @brief The slot for stoping simulation
     */
    void _PauseSimulationActionSlot();

    /**
     * @brief The slot for switching from simulation mode of app to build mode 
     */
    void _CreateBuildMapModeSlot();

    /**
     * @brief The slot for switching from build mode of app to simulation mode 
     */
    void _CreateSimModeSlot();

    /**
     * @brief Emit loading map by core and displayng on simuation scene
     */
    void _PushNewMapToCoreSlot();

    /**
     * @brief The slot for requesting information about simulation object from CORE app and vizualization this info  
     * 
     * @param orderIndex index of requested simulation object
     * @param isRobot  discriminator of simulations object type (robot/wall)
     */
    void _RequestSimObjSlot(int orderIndex, bool isRobot);

    /**
     * @brief The slot for updating simulation objects with new attributes from view
     * 
     * @param view the new attributes of simualtion object
     */
    void _UpdateSimObjSlot(SimObjView view);

    /**
     * @brief The slot for deleting simualtion object
     * 
     * @param view the attributes of simulation object to deleting
     */
    void _DeleteSimObjSlot(SimObjView view);
};
#endif // MAINWINDOW_H
