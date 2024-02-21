#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

#include "simulationwindow.h"
#include "menuwindow.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
class SimulationWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:

    MenuWindow* menuWind;
    SimulationWindow* simWind;
    void initAppWindows();
    void deleteAppWindows();
    void runApp();
    QPushButton* testButton;
    //void runApplication();

    Ui::MainWindow *ui;

public slots:
    void fromMenuToSimulation();
    void fromSimulationToMenu();
};
#endif // MAINWINDOW_H
