#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QScrollArea>
#include <QLabel>
#include <QDialog>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>
#include <QSpinBox>
#include <QComboBox>
#include <iostream>
class SettingsWindow : public QWidget
{
    Q_OBJECT
public:

    SettingsWindow();
    ~SettingsWindow();
    QPushButton* setPushButton;

    int GetSpeedValue();
    void SetSpeedValue(int speed);

    int GetAngleValue();
    void SetAngleValue(int angle);
private:
    QGridLayout* _settingGridLayot;

    QLabel* _speedLabel;
    QSpinBox* _speedSpinBox;

    QLabel* _angleLabel;
    QSpinBox* _angleSpinBox;

    QLabel* _directionLable;
    QSpinBox* _directionSpinBox;

    QLabel* _colorLable;
    QComboBox* _colorComboBox;

private slots:
    void _BlockNewMapLineSlot();
    void _BlockSpeedSpinBoxSlot();
    void _BlockAngleSpinBoxSlot();
};

#endif // SETTINGSWINDOW_H
