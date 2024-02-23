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

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:

    // BAR && ACTIONS
    QToolBar* helpToolBar;
    QAction* helpToolAction;

    QToolBar* mapToolBar;
    QAction* newMapToolAction;
    /*QMenu* newMapMenu;
    QAction* newMapDownload;
    QAction* newMapCreate;
    */
    QAction* listMapToolAction;

    QToolBar* settingsToolBar;
    QAction* settingsToolAction;

    // inside attribute
    QString absolutePathToTextMapFile;
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
     * @brief functional for widget with creating new map
     * @param void
     * @return void
    */
    void newMapToolActionFunctional();

    /**
     * @brief functional for widget with list of all maps (can choose one like actula or delete old map)
     * @param void
     * @return void
    */
    void listMapToolActionFunctional();

    /**
     * @brief functional for widget with settings
     * @param void
     * @return void
    */
    void settingsToolActionFunctional();
};
#endif // MAINWINDOW_H
