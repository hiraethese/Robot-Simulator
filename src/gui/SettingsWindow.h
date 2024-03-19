#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QScrollArea>
#include <QLabel>
#include <QDialog>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>
#include <QSpinBox>
#include <QCheckBox>
#include <iostream>
class SettingsWindow : public QWidget
{
    Q_OBJECT
public:

    SettingsWindow();
    ~SettingsWindow();
    QPushButton* setPushButton;


    bool isSetMapValue();
    QString getMapValue();
    void setMapValue(QString map);

    bool isSetSpeedValue();
    int getSpeedValue();
    void setSpeedValue(int speed);

    bool isSetAngleValue();
    int getAngleValue();
    void setAngleValue(int angle);
private:
    QGridLayout* settingGridLayot;

    QLabel* newMapLabel;
    QLineEdit* newMapLine;
    QLabel mapValue;
    QCheckBox* newMapCheckBox;

    QLabel* speedLabel;
    QSpinBox* speedSpinBox;
    QCheckBox* speedCheckBox;
    int speedValue;

    QLabel* angleLabel;
    QSpinBox* angleSpinBox;
    QCheckBox* angleCheckBox;
    int angleValue;

private slots:
    void blockNewMapLineSlot();
    void blockSpeedSpinBoxSlot();
    void blockAngleSpinBoxSlot();
};

#endif // SETTINGSWINDOW_H
