#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
class QPushButton;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QPushButton* startButton;
    QPushButton* stopButton;
    QPushButton* continueButton;

    QPushButton* settingsButton;

    QPushButton* forwardMoveButton;
    QPushButton* moveRotateLeftButton;
    QPushButton* moveRotateRightButton;
    QPushButton* moveStopButton;

    void createButtons();
    void deleteButtons();
    void createSimulationsWindow();

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
