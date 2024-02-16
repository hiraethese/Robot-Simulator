#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QApplication::setApplicationDisplayName("ICP2024");
    setWindowTitle("Menu");
    //setStyleSheet("background-color: #404040;"); 0e1047
    setStyleSheet("background-color: #0e1047;");
    setFixedSize(1000, 1000);
    createButtons();
    //setWindowFlags(windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
}

void MainWindow::createButtons(){
    startButton = new QPushButton("start", this);
    startButton->setGeometry(130, 670, 100, 50);  // 10, 600, 100, 50
    startButton->setStyleSheet("background-color: green;");

    stopButton = new QPushButton("stop", this);
    stopButton->setGeometry(130, 770, 100, 50);
    stopButton->setStyleSheet("background-color: red;");

    continueButton = new QPushButton("continue", this);
    continueButton->setGeometry(780, 670, 100, 50);
    continueButton->setStyleSheet("background-color: orange;");

    settingsButton = new QPushButton("settings", this);
    settingsButton->setGeometry(780, 770, 100, 50);
    settingsButton->setStyleSheet("background-color: blue;");

    forwardMoveButton = new QPushButton("forward", this);
    forwardMoveButton->setGeometry(460, 640, 80, 80);
    forwardMoveButton->setStyleSheet("background-color: purple;");

    moveRotateLeftButton = new QPushButton("left", this);
    moveRotateLeftButton->setGeometry(360, 740, 80, 80);
    moveRotateLeftButton->setStyleSheet("background-color: purple;");

    moveRotateRightButton = new QPushButton("right", this);
    moveRotateRightButton->setGeometry(560, 740, 80, 80);
    moveRotateRightButton->setStyleSheet("background-color: purple;");

    moveStopButton = new QPushButton("stop move", this);
    moveStopButton->setGeometry(460, 740, 80, 80);
    moveStopButton->setStyleSheet("background-color: purple;");
}

void MainWindow::deleteButtons(){
    delete startButton;
    delete stopButton;
    delete continueButton;
    delete settingsButton;
    delete forwardMoveButton;
    delete moveRotateLeftButton;
    delete moveRotateRightButton;
    delete moveStopButton;
}

MainWindow::~MainWindow()
{
    deleteButtons();
    delete ui;
}
