/**
 * @file ASettings.h
 * @author Baturov Illia (xbatur00@stud.fit.vutbr.cz)
 * @author Kukhta Myron (xkukht01@stud.fit.vutbr.cz)
 * @brief Header of abstract class for sim obj settings 
 */
#ifndef ASETTINGS_H
#define ASETTINGS_H

#include <QWidget>
#include <QDialog>
#include <QString>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QSpinBox>
#include <QComboBox>

#include "../../core/icplib.h"
#include "../style.h"

/**
 * @brief Abstract class for settings window of simulations objects (robot/wall)
 * Describes the basic behavior of the settings window of simulation objects
 */
class ASettings : public QDialog
{
    Q_OBJECT
public:
    /**
     * @brief Abstract method for loading data from simulations objects view for subsequent data display
     * 
     * @param view information about internal abilities of simulations object
     * @param orderIndex index of simulations object
     */
    virtual void DownloadDataFromView(SimObjView view, int orderIndex) = 0;

    /**
     * @brief Abstract method for getting actual information of simulation object after users editing
     */
    virtual SimObjView GetSimObjView() = 0;
    /**
     * @brief Abstract method for changing enabling of smth windows items for user actions
     * 
     * @param flag set on enabled (true) or not (false)
     */
    virtual void ChangeEnablingOfSettingsObjects(bool flag);

protected:
    /**
     * @brief Construct a new ASettings object
     * 
     * @param parent parents widget
     * @param title actual title of window
     */
    ASettings(QWidget* parent, QString title);


    bool _isRobot;  // TODO: delete

    /**
     * @brief index of displayed simualtions object
     */
    int _orderIndex;

    /**
     * @brief button for saving new information about displayed robot
     */
    QPushButton* _setPushButton;

    /**
     * @brief button for del displayed robot 
     */
    QPushButton* _deletePushButton;

    /**
     * @brief frame for location internal items
     */
    QGridLayout* _settingGridLayot;

    /**
     * @brief string with colors type name
     */
    QLabel* _colorLable;

    /**
     * @brief place for choosing new color of simulation object
     * 
     */
    QComboBox* _colorComboBox;

    /**
     * @brief Creating part for colors setting
     * 
     * @param row number of row for location 
     */
    void _CreateColorsSettings(int row);

    /**
     * @brief Creating part for buttons
     * 
     * @param row number of row location
     */
    void _CreateButtonsSettings(int row);
signals:
    
    /**
     * @brief Signal for sending to core internal abilities of simulations object
     * 
     * @param view new internal abilites
     */
    void SetSig(SimObjView view);
    
    /**
     * @brief Signal for del from core simulations object
     * 
     * @param view internal abilites
     */
    void DeleteSig(SimObjView view);

};

#endif // ASETTINGS_H
