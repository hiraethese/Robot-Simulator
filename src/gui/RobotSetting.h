#ifndef ROBOTSETTING_H
#define ROBOTSETTING_H

#include <QDialog>
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QComboBox>
#include <QPushButton>
#include <iostream>
#include <QString>
#include "../core/icplib.h"
#include "style.h"
class RobotSetting : public QDialog
{
    Q_OBJECT

public:
    RobotSetting(QWidget* parent, bool isControlledRobot);
    QPushButton* setPushButton;
    QPushButton* deletePushButton;
    void DownloadDataFromView(RobotView robot);
private:
    bool flagIsUserRobot;
    QGridLayout* _settingGridLayot;


    QLabel* _typeRobotLabel;
    QLineEdit* _typeRobotLineEdit;

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
