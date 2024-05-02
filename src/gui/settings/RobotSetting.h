/**
 * @file RobotSetting.h
 * @author Baturov Illia (xbatur00@stud.fit.vutbr.cz)
 * @author Kukhta Myron (xkukht01@stud.fit.vutbr.cz)
 * @brief Header of class for display settings robot simulations object
 */
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

/**
 * @brief Class for specification ASettings to display information about simulation object with type "Robot"
 * Give functional for editing internal abilities or deleting simulation object
 */
class RobotSetting : public ASettings
{

public:
    /**
     * @brief Construct a new Robot Setting object
     * 
     * @param parent parents widget
     * @param title  actual window title
     */
    RobotSetting(QWidget* parent, QString title);

    /**
     * @brief Overrided absracts method by base class for storing and display information about simulation object
     * 
     * @param view information about internal abilities of simulations object
     * @param orderIndex index of simulations object
     */
    void DownloadDataFromView(SimObjView view, int orderIndex) override;
    
    /**
     * @brief Overrided absracts method by base class for changing enabling of smth windows items for user actions
     * 
     * @param flag set on enabled (true) or not (false)
     */
    void ChangeEnablingOfSettingsObjects(bool flag) override;
    
    /**
     * @brief Overrided absracts method by base class for getting actual information of simulation object after users editing
     */
    SimObjView GetSimObjView();

private:
    /**
     * @brief subtype of robots simulation object (contolled/automatics)
     */
    bool _isControlled = false;

    /**
     * @brief subtype label of robots simulation object (controlled) 
     * 
     */
    const QString _contrRobotString = "Controlled";
    
    /**
     * @brief subtype label of robots simulation object (Autometic) 
     * 
     */
    const QString _autoRobotString = "Autometic";

    /**
     * @brief direction in clockwise (counterclockwise)
     * 
     */
    const QString _leftClockW = "Counterclockwise";
    
    /**
     * @brief direction in clockwise (clockwise)
     * 
     */
    const QString _rightClockW = "Clockwise";

    /**
     * @brief label with type of information about robots subtype
     */
    QLabel* _typeRobotLabel;

    /**
     * @brief place for changing robots subtype
     */
    QComboBox* _typeRobotComboBox;

    /**
     * @brief label with type of information about robots diameter
     * 
     */
    QLabel* _diameterLabel;

    /**
     * @brief place for changing robots diameter
     * 
     */
    QSpinBox* _diameterSpinBox;

    /**
     * @brief label with type of infromation about robots speed
     * 
     */
    QLabel* _speedLabel;

    /**
     * @brief place for changing robots speed
     * 
     */
    QSpinBox* _speedSpinBox;

    /**
     * @brief label with type of information about robots angle step 
     */
    QLabel* _angleStepLabel;

    /**
     * @brief place for chaning robots angle step
     */
    QSpinBox* _angleStepSpinBox;


    /**
     * @brief label with type of information about robots angle degree 
     */
    QLabel* _angleDegreesLable;

    /**
     * @brief place for chaning robots angle degree
     */
    QSpinBox* _angleDegreesSpinBox;

    /**
     * @brief label with type of information about robots collision distance
     */
    QLabel* _collisionDistanceLabel;

    /**
     * @brief place for chaning robots collision distance
     */
    QSpinBox* _collisionDistanceSpinBox;


    /**
     * @brief label with type of information about robots clockwise direction
     */
    QLabel* _rotateClockwiseLabel;

    /**
     * @brief place for chaning robots clockwise direction
     */
    QComboBox* _rotateClockwiseComboBox;


};

#endif // ROBOTSETTING_H
