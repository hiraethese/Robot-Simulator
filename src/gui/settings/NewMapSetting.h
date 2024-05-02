/**
 * @file NeMapSetting.h
 * @author Baturov Illia (xbatur00@stud.fit.vutbr.cz)
 * @author Kukhta Myron (xkukht01@stud.fit.vutbr.cz)
 * @brief Header of class for stroing users input file name in GUI 
 */
#ifndef NEWMAPSETTING_H
#define NEWMAPSETTING_H

#include <QDialog>
#include <QWidget>
#include <string>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <algorithm>
#include <cctype>
#include "../style.h"

/**
 * @brief Class of settings window for storing path to specification txt path with location of simualtion object and their descriptions
 * Give path to core for parsing and creating new simulation object
 */
class NewMapSetting : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Construct a new New Map Setting object
     * 
     * @param parent parents widget
     */
    NewMapSetting(QWidget* parent);

    /**
     * @brief Get the path to specification file from users input place
     * 
     * @return std::string path
     */
    std::string GetNewMapPath();

private:
    /**
     * @brief location frame for settings items
     * 
     */
    QGridLayout* _newMapGridLayot;

    /**
     * @brief label of informations type
     */
    QLabel* _newMapLabel;

    /**
     * @brief place for user input
     */
    QLineEdit* _newMapLine;

    /**
     * @brief button for activate sending path to core
     * 
     */
    QPushButton* _downloadButton;

signals:

    /**
     * @brief signal for connection with MainWindow for controlled sending new path
     * 
     */
    void DownloadSig();

};

#endif // NEWMAPSETTING_H
