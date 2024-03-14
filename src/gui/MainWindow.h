#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QToolBar>
#include <QToolButton>
#include <QAction>
#include <iostream>
#include <QIcon>
#include <QMessageBox>
#include <QMenu>
#include <QString>
#include <QInputDialog>
#include <QPainter>
#include <QLineEdit>
#include <QScrollArea>
#include <QString>
#include "SimulationWindow.h"
#include "SettingsWindow.h"
#include "InfoNotification.h"
#include "../core/Core.h"

#include <iostream>
enum stateGUI{
    SILENCE_MODE,
    SIM_RUN_MODE,
    SETTING_MODE
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
    // APPLICATION
    void createAppWindows();
    void deleteAppWindows();
    void createTools();
    void createActions();
    void deleteTools();
    void deleteActions();

    // BAR && ACTIONS
    QToolBar* simulationIdToolBar;
    QLabel* labelSimIdToolBar;
    QLineEdit* lineMapNameSimIdToolBar;
    QToolBar* helpToolBar;
    QAction* helpToolAction;

    QToolBar* settingsToolBar;
    QAction* settingsToolAction;

    QToolBar* engineSimRunToolBar;
    QAction* runSimulationAction;
    QAction* restartSimulationAction;

    // SETTINGS
    SettingsWindow* settings;
    void createSettings();
    void deleteSettings();

    // SIMULATION
    QVBoxLayout* vbl;
    SimulationWindow* simWind;

    void createSimulationWindow();

    // settings area

    // inside attribute
    QString absolutePathToTextMapFile = QString("");
    // UI
    Ui::MainWindow *ui;

public slots:
    // APPLICATION PUBLIC SLOTS

    // BARS && ACTIONS PUBLIC SLOTS

    // SETTINGS PUBLIC SLOTS

    // SIMULATIONS PUBLIC SLOTS

private slots:
    // APPLICATION PRIVATE SLOTS
    void helpTextToolActionSlot();
    void settingsToolActionSlot();

    // BARS && ACTIONS PRIVATE SLOTS

    // SETTINGS PRIVATE SLOTS
    void updateSettingsSlot();

    // SIMULATIONS PRIVATE SLOTS
    void runSimulationActionSlot();
    void pauseSimulationActionSlot();
    void restartSimulationActionSlot();
};
#endif // MAINWINDOW_H
