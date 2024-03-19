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
#include <QScrollArea>
#include <QString>
#include <QTabBar>
#include <QToolBar>
#include <QToolButton>
#include <QVBoxLayout>
#include <QWidget>
#include "NewMapWindow.h"
#include "SimulationWindow.h"
#include "SettingsWindow.h"
#include "WallSettingsWindow.h"
#include "InfoNotification.h"
#include "../core/Core.h"
//#include "style.h"
#include <iostream>


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
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public InfoNotification
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Core* _core;
    Page _actualPage = NotSetPage;
    void _CreateAppWindows();
    void _DeleteAppWindows();
    void _SetPallet();
    QPalette palMainWindow;
    QToolBar* _simulationToolBar;
    QAction* _simulationToolAction;

    QToolBar* _simulationIdToolBar;
    QLabel* _labelSimIdToolBar;
    QLineEdit* _lineMapNameSimIdToolBar;
    QToolBar* _helpToolBar;
    QAction* _helpToolAction;

    QToolBar* _settingsToolBar;
    QAction* _settingsToolAction;

    QToolBar* _engineSimRunToolBar;
    QAction* _runSimulationAction;
    QAction* _restartSimulationAction;

    QToolBar* _newSimulationIdToolBar;
    QLabel* _newLabelSimIdToolBar;
    QLineEdit* _newLineMapNameSimIdToolBar;
    QPushButton* _newSimulationButton;

    void _CreateTools();
    void _SetSimulationTool();
    void _UnsetSimulationTool();
    void _SetSettingsTool();
    void _UnsetSettingsTool();
    void _CreateActions();
    void _DeleteTools();
    void _DeleteActions();

    QMenu* appMenu;
    QMenu* buildSubMenu;
    QAction* simulationModeAction;
    QAction* downloadNewModeMapAction;
    QAction* buildMapModeAction;
    QAction* buildUserRobotLayout;
    QAction* buildBotRobotLayout;
    QAction* buildWallLayout;
    void _CreateMenu();
    void _DeleteMenu();

    NewMapWindow* _newMapWind = nullptr;

    SimulationWindow* _simulationWind;
    void _CreateSimulationWindow();

    SettingsWindow* _settingsWind = nullptr;
    WallSettingsWindow* _wallSettingsWindow = nullptr;
    //void _CreateSettings();
    //void _DeleteSettings();

    Ui::MainWindow *ui;

    void _CreateSimModeTools();
    void _DeleteSimModeTools();


    QAction* _cursorAction;
    QAction* _buildUserRobotAction;
    QAction* _buildBotRobotAction;
    QAction* _buildWallAction;
    QAction* _hummerAction;
    QToolBar* _engineBuildToolBar;
    void _CreateBuildModeTools();
    void _DeleteBuildModeTools();
public slots:

private slots:
    void _StoreNewMap();
    void _HelpTextToolActionSlot();
    //void _SettingsToolActionSlot();
    //void _SimulationToolActionSlot();

    //void _UpdateSettingsSlot();

    void _BuildUserRobotLayoutSlot();
    void _BuildBotRobotLayoutSlot();
    void _BuildWallLayoutSlot();

    void _RunSimulationActionSlot();
    void _PauseSimulationActionSlot();
    void _RestartSimulationActionSlot();

    //void _GetNewSimToParserSlot();

    void _CreateNewMapModeSlot();
    void _CreateBuildMapModeSlot();
    void _CreateSimModeSlot();

    void _CursorActionSlot();
    void _BuildUserRobotActionSlot();
    void _BuildBotRobotActionSlot();
    void _BuildWallActionSlot();
    void _HummerActionSlot();
};
#endif // MAINWINDOW_H
