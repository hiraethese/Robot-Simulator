#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QLabel>

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
    bool crutchMenuWindowFlag;
    bool crutchSimulationWindowFlag;

    QLabel *l;

    QPushButton* startMenuButton;
    QPushButton* settingsMenuButton;

    QPushButton* startSimulationButton;
    QPushButton* stopSimulationButton;
    QPushButton* continueSimulationButton;

    QPushButton* settingsSimulationButton;

    QPushButton* forwardMoveSimulationButton;
    QPushButton* moveRotateLeftSimulationButton;
    QPushButton* moveRotateRightSimulationButton;
    QPushButton* movestopSimulationButton;

    void createSimulationWindowButtons();
    void deleteSimulationWindowButtons();

    void createMenuWindowButtons();
    void deleteMenuWindowButtons();

    Ui::MainWindow *ui;

public slots:
    void createMenuWindow();
    void deleteMenuWindow();
    void createSimulationWindow();
    void deleteSimulationWindow();
    void createLabel();
    void deleteLabel();
};
#endif // MAINWINDOW_H
