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
#include <QScrollArea>
#include <QString>
#include <QTabBar>
#include <QToolBar>
#include <QToolButton>
#include <QVBoxLayout>
#include <QWidget>
#include "SimulationWindow.h"
#include "SettingsWindow.h"
#include "InfoNotification.h"
#include "../core/Core.h"

#include <iostream>

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
    
    void _CreateAppWindows();
    void _DeleteAppWindows();
    void _CreateTools();
    void _CreateActions();
    void _DeleteTools();
    void _DeleteActions();
    
    QPushButton* _simulationMenuButton;
    QPushButton* _settingsMenuButton;
    QAction* _simulationMenuAction;
    QAction* _settingsMenuAction;
    
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

    SettingsWindow* _settingsWind;
    void _CreateSettings();
    void _DeleteSettings();

    SimulationWindow* _simulationWind;

    void _CreateSimulationWindow();
    
    Ui::MainWindow *ui;

public slots:

private slots:
    void _HelpTextToolActionSlot();
    void _SettingsToolActionSlot();

    void _SimulationMenuActionSlot();
    void _SettingsMenuActionSlot();

    void _UpdateSettingsSlot();

    void _RunSimulationActionSlot();
    void _PauseSimulationActionSlot();
    void _RestartSimulationActionSlot();
};
#endif // MAINWINDOW_H
