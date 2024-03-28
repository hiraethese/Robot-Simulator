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

#include "SimulationWindow.h"
#include "InfoNotification.h"
#include "RobotSetting.h"
#include "WallSetting.h"
#include "NewMapSetting.h"
#include "../core/Core.h"
#include "style.h"


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

    QDialog* modalDialog;
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
    QAction* _runSimulationAction = nullptr;
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
    QAction* buildUserRobotTemplate;
    QAction* buildBotRobotTemplate;
    QAction* buildWallLayout;

    void _CreateMenu();
    void _DeleteMenu();


    SimulationWindow* _simulationWind;
    void _CreateSimulationWindow();

    RobotSetting* _robotSetWind;
    WallSetting* _wallSetWind;
    NewMapSetting* _newMapWind;

    void _CreateSettings();

    void _CreateSimModeTools();
    void _DeleteSimModeTools();


    QAction* _cursorAction;
    QAction* _buildUserRobotAction;
    QAction* _buildBotRobotAction;
    QAction* _buildWallAction;
    QAction* _hummerAction;
    QLabel* _statusModeLabel;
    QLineEdit* _statusModeLine;
    QToolBar* _settingsBuildToolBar;
    QToolBar* _engineBuildToolBar;
    QToolBar* _statusModeBuildToolBar;

    void _CreateBuildModeTools();
    void _DeleteBuildModeTools();


    Ui::MainWindow *ui;

public slots:

private slots:
    void _SettingSlot(){}

    void _HelpTextToolActionSlot();

    void _RunSimulationActionSlot();
    void _PauseSimulationActionSlot();
    void _RestartSimulationActionSlot();

    void _CreateBuildMapModeSlot();
    void _CreateSimModeSlot();

    void _CursorActionSlot();
    void _BuildUserRobotActionSlot();
    void _BuildBotRobotActionSlot();
    void _BuildWallActionSlot();
    void _HummerActionSlot();

    void _PushNewMapToCoreSlot();

    void _UserClickSimSceneLogicSlot();

    void test();
};
#endif // MAINWINDOW_H
