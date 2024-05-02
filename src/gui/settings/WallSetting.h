/**
 * @file WallSetting.h
 * @author Baturov Illia (xbatur00@stud.fit.vutbr.cz)
 * @author Kukhta Myron (xkukht01@stud.fit.vutbr.cz)
 * @brief Header of class for display settings wall simulations object
 */
#ifndef WALLSETTING_H
#define WALLSETTING_H

#include <QWidget>
#include <QDialog>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QSpinBox>
#include <QString>
#include "../../core/icplib.h"
#include "../style.h"
#include "ASettings.h"

/**
 * @brief Class for specification ASettings to display information about simulation object with type "Wall"
 * Give functional for editing internal abilities or deleting simulation object
 */
class WallSetting : public ASettings
{

public:
    /**
     * @brief Construct a new Wall Setting object
     * 
     * @param parent parent widget
     * @param title actual title of window
     */
    WallSetting(QWidget* parent, QString title);

    /**
     * @brief Overrided absracts method by base class for storing and display information about simulation object
     * 
     * @param view information about internal abilities of simulations object
     * @param orderIndex index of simulations object
     */
    void DownloadDataFromView(SimObjView view, int orderIndex) override;
    
    /**
     * @brief Overrided absracts method by base class for getting actual information of simulation object after users editing
     */
    SimObjView GetSimObjView();

private:
    /**
     * @brief label for type information about height
     */
    QLabel* _heightLabel;

    /**
     * @brief place for choosing new heigh of simulation object
     * 
     */
    QSpinBox* _heightSpinBox;

    /**
     * @brief label for type information about width
     */
    QLabel* _widthLabel;
    
    /**
     * @brief place for choosing new width of simulation object
     * 
     */
    QSpinBox* _widthSpinBox;

};

#endif // WALLSETTING_H
