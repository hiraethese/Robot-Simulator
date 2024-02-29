#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QScrollArea>
#include <QLabel>
#include <QDialog>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>
#include <QSpinBox>
#include <iostream>
class settingsWindow : public QWidget
{
    Q_OBJECT
public:

    settingsWindow();
    ~settingsWindow();
    QPushButton* setPushButton;

    QString getMapValue();
    void setMapValue(QString map);

    int getSpeedValue();
    void setSpeedValue(int speed);

    int getCornerValue();
    void setCornerValue(int corner);
private:
    QGridLayout* settingGridLayot;

    QLabel* newMapLabel;
    QLineEdit* newMapLine;
    QLabel mapValue;

    QLabel* speedLabel;
    QSpinBox* speedSpinBox;
    int speedValue;

    QLabel* cornerLabel;
    QSpinBox* cornerSpinBox;
    int cornerValue;

private slots:
};

#endif // SETTINGSWINDOW_H
