#include "NewMapSetting.h"

NewMapSetting::NewMapSetting(QWidget* parent): QDialog(parent) {

    _newMapGridLayot = new QGridLayout(this);

    _newMapLabel = new QLabel("New map path: ", this);
    _newMapLine = new QLineEdit(this);

    downloadButton = new QPushButton("Download", this);

    _newMapGridLayot->addWidget(_newMapLabel, 0, 0);
    _newMapGridLayot->addWidget(_newMapLine, 0, 1);
    _newMapGridLayot->addWidget(downloadButton, 1, 0);

}


std::string NewMapSetting::GetNewMapPath(){

    return _newMapLine->text().toStdString();

}
