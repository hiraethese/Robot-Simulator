#ifndef ROBOTSETTING_H
#define ROBOTSETTING_H

#include <QDialog>
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QSpinBox>
#include <QComboBox>
#include <QPushButton>
#include <iostream>
class RobotSetting : public QDialog
{
    Q_OBJECT
public:
    RobotSetting(QWidget* parent, bool isControlRobot);
    QPushButton* setPushButton;
    QPushButton* deletePushButton;

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

};

#endif // ROBOTSETTING_H
