#ifndef ROBOTSETTING_H
#define ROBOTSETTING_H

#include <QDialog>
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QGraphicsLineItem>
#include <QSpinBox>
#include <QPushButton>
#include <iostream>
#include <QString>
#include "../core/icplib.h"
#include "style.h"
#include "ASettings.h"

class RobotSetting : public ASettings
{

public:
    RobotSetting(QWidget* parent, QString title);
    void DownloadDataFromView(SimObjView view) override;

private:
    bool flagIsUserRobot;


    QLabel* _typeRobotLabel;
    QLabel* _typeRobotLineEdit;

    QLabel* _diameterLabel;
    QSpinBox* _diameterSpinBox;

    QLabel* _speedLabel;
    QSpinBox* _speedSpinBox;

    QLabel* _angleLabel;
    QSpinBox* _angleSpinBox;

    QLabel* _wayLable;
    QSpinBox* _waySpinBox;

};

#endif // ROBOTSETTING_H
