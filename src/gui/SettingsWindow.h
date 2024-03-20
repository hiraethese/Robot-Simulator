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

    SettingsWindow(bool isUserRobot);
    ~SettingsWindow();
    QPushButton* setPushButton;

private:
    bool flagIsUserRobot;
    QGridLayout* _settingGridLayot;

    QLabel* _diameterLabel;
    QSpinBox* _diameterSpinBox;

    QLabel* _speedLabel;
    QSpinBox* _speedSpinBox;

    QLabel* _angleLabel;
    QSpinBox* _angleSpinBox;

    QLabel* _wayLable;
    QSpinBox* _waySpinBox;

    QLabel* _colorLable;
    QComboBox* _colorComboBox;

private slots:
};

#endif // SETTINGSWINDOW_H
