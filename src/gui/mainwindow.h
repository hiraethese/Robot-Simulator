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
#include "simulationwindow.h"
#include "settingswindow.h"
#include "infonotification.h"
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

    // SIMULATION
    QVBoxLayout* vbl;
    SimulationWindow* simWind;
    bool devflagMapIsSet = false; // should be pulling by core
    int devSimulationSpeed = 50;  // should be pulling by core
    int devSimulationCorner = 45; // should be pulling by core
    QString simulationMap = QString("");

    void createSimulationWindow();
    void deleteSimulationWindow();

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
    void helpTextToolActionFunctional();
    void settingsToolActionFunctional();

    // BARS && ACTIONS PRIVATE SLOTS

    // SETTINGS PRIVATE SLOTS
    void createSettings();
    void deleteSettings();
    void updateSettings();

    // SIMULATIONS PRIVATE SLOTS
    void runSimulationActionFunctional();
    void pauseSimulationActionFunctional();
    void restartSimulationActionFunctional();
};
#endif // MAINWINDOW_H
