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
#include <QComboBox>
#include "../../core/icplib.h"
#include "../style.h"
#include "ASettings.h"

class RobotSetting : public ASettings
{

public:
    RobotSetting(QWidget* parent, QString title);
    void DownloadDataFromView(SimObjView view, int orderIndex) override;
    SimObjView GetSimObjView();
private:
    bool _isControlled = false;

    QLabel* _typeRobotLabel;  // TODO: COMBOBOX ???
    QLabel* _typeRobotLineEdit;

    QLabel* _diameterLabel;
    QSpinBox* _diameterSpinBox;

    QLabel* _speedLabel;
    QSpinBox* _speedSpinBox;

    QLabel* _angleStepLabel;
    QSpinBox* _angleStepSpinBox;

    QLabel* _angleDegreesLable;
    QSpinBox* _angleDegreesSpinBox;

    QLabel* _collisionDistanceLabel;
    QSpinBox* _collisionDistanceSpinBox;

    QLabel* _rotateClockwiseLabel;
    QComboBox* _rotateClockwiseComboBox;


};

#endif // ROBOTSETTING_H
