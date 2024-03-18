#include "NewMapWindow.h"

NewMapWindow::NewMapWindow(QWidget *parent)
    : QWidget{parent}
{

    setWindowFlags(Qt::WindowTitleHint);
    setWindowTitle("Download new map");
    _newMapGridLayot = new QGridLayout();

    _newMapLabel = new QLabel("New map path: ");
    _newMapLine = new QLineEdit();
    downloadButton = new QPushButton("Download");
    _newMapGridLayot->addWidget(_newMapLabel, 0, 0);
    _newMapGridLayot->addWidget(_newMapLine, 0, 1);
    _newMapGridLayot->addWidget(downloadButton, 1, 0);

    setLayout(_newMapGridLayot);
}

NewMapWindow::~NewMapWindow(){
    delete downloadButton;
    delete _newMapLine;
    delete _newMapLabel;
    delete _newMapGridLayot;
}

std::string NewMapWindow::GetNewMapPath(){
    return _newMapLine->text().toStdString();
}
