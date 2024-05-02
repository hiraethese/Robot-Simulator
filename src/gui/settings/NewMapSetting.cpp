/**
 * @file NewMapSetting.h
 * @author Baturov Illia (xbatur00@stud.fit.vutbr.cz)
 * @author Kukhta Myron (xkukht01@stud.fit.vutbr.cz)
 * @brief Implementation class for stroing users input file name in GUI 
 */
#include "NewMapSetting.h"

NewMapSetting::NewMapSetting(QWidget* parent): QDialog(parent) {

    setStyleSheet("background-color: lightgray;");

    _newMapGridLayot = new QGridLayout(this);

    _newMapLabel = new QLabel("New map path: ", this);
    _newMapLine = new QLineEdit(this);

    // connect button action with signal for sending
    _downloadButton = new QPushButton("Download", this);
    connect(_downloadButton, &QPushButton::clicked, this, [=](){emit DownloadSig();});

    _newMapGridLayot->addWidget(_newMapLabel, 0, 0);
    _newMapGridLayot->addWidget(_newMapLine, 0, 1);
    _newMapGridLayot->addWidget(_downloadButton, 1, 0);

}


std::string NewMapSetting::GetNewMapPath(){
    // store actual new path to map specification
    std::string pathToMap = _newMapLine->text().toStdString();
    
    // cut white spaces from start and end of path line
    pathToMap.erase(pathToMap.begin(), std::find_if(pathToMap.begin(), pathToMap.end(), [](unsigned char ch) {return !std::isspace(ch);}));
    pathToMap.erase(std::find_if(pathToMap.rbegin(), pathToMap.rend(), [](unsigned char ch) {return !std::isspace(ch);}).base(), pathToMap.end());

    return pathToMap;

}
