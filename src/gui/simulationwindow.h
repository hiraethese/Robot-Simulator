#ifndef SIMULATIONWINDOW_H
#define SIMULATIONWINDOW_H

#include <QWidget>
#include <QPushButton>

class SimulationWindow : public QWidget
{
    Q_OBJECT
public:
    explicit SimulationWindow(QWidget *parent = nullptr);
    ~SimulationWindow();
    QPushButton* startButton;

private:
    void initSimulationWindowButtons();
    void deleteSimulationWindowButtons();
signals:
};

#endif // SIMULATIONWINDOW_H
