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
#include "simulationbody.h"
#include "settingswindow.h"
#include "infonotification.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
class SimulationBody;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public InfoNotification
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:

    // SIM BODY
    QVBoxLayout* vbl;
    SimulationBody* simBody;
    void createSimulationBody();
    void deleteSimulationBody();


    // simulation
    bool flagMapIsSet = false; // should be pulling by core
    int simulationSpeed = 50;  // should be pulling by core
    int simulationCorner = 45; // should be pulling by core
    QString simulationMap = QString("");

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

    // settings area
    settingsWindow* settingBody = nullptr;

    // inside attribute
    QString absolutePathToTextMapFile = QString("");
    // UI
    Ui::MainWindow *ui;


    // METHODS
    /**
     * @brief creatting default body of applications window
     * @param void
     * @return void
    */
    void createAppWindows();

    /**
     * @brief deleting all defaults widget of applications widnows body
     * @param void
     * @return void
    */
    void deleteAppWindows();

    /**
     * @brief creating all applications windows tools and adding their actions
     * @param void
     * @return void
    */
    void createTools();

    /**
     * @brief creating all tools actions and connect their with functional slots
     * @param void
     * @return void
    */
    void createActions();

    /**
     * @brief clean tools memmory
     * @param void
     * @return void
    */
    void deleteTools();

    /**
     * @brief disconnect actions with slots and clean their memmory
     * @param void
     * @return void
    */
    void deleteActions();

public slots:
    /**
     * @brief functional for widget with help message for user
     * @param void
     * @return void
    */
    void helpTextToolActionFunctional();


    /**
     * @brief functional for widget with settings
     * @param void
     * @return void
    */
    void settingsToolActionFunctional();

    void runSimulationActionFunctional();
    void pauseSimulationActionFunctional();
    void restartSimulationActionFunctional();


    void createSettings();
    void deleteSettings();
private slots:
    void updateSettings();

};
#endif // MAINWINDOW_H
