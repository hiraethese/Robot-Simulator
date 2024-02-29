#ifndef SIMULATIONWINDOW_H
#define SIMULATIONWINDOW_H

#include <QWidget>
#include <QPalette>
#include <QPainter>
#include <QRectF>
#include <QPushButton>
#include <QColor>
class SimulationWindow : public QWidget
{
    Q_OBJECT
public:
    explicit SimulationWindow(QWidget *parent = nullptr);
    ~SimulationWindow();
protected:
    void paintEvent(QPaintEvent *event);
private:
    QPalette pal;
    QPainter* painter;
    QRectF* rect;
signals:
};

#endif // SIMULATIONWINDOW_H
