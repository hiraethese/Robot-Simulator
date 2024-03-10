#include "SimulationWindow.h"

SimulationWindow::SimulationWindow(QWidget *parent)
    : QWidget{parent}
{

    //simBody = new SimulationBody();
    createSimGUI();
    createSimulattionsButtons();
    createSimulationsLayout();

    connect(&timerOneFrame, &QTimer::timeout, this, &SimulationWindow::oneSimFrameGUI);
    SimStart();
}

SimulationWindow::~SimulationWindow(){
    //for(QBrush* br: brashVector) delete br;  // TODO: SIGMFALL
    //for(QPen* pen: penVector) delete pen;    // TODO: SIGMFALL
    deleteSimGUI();
    deleteSimulationsButtons();
    deleteSimulationsLayout();
}

void SimulationWindow::createSimGUI(){
    simGraphScene = new SimulationScene();
    simGraphView = new QGraphicsView(simGraphScene);

    simGraphView->setFixedSize(SIM_WIN_X, SIM_WIN_Y);
    simGraphView->setSceneRect(0,0,SIM_WIN_X, SIM_WIN_Y);
    simGraphView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    simGraphView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    redBrush = new QBrush(Qt::red);
    yellowBrush = new QBrush(Qt::yellow);
    greanBrush = new QBrush(Qt::green);
    blueBrush = new QBrush(Qt::blue);
    blackBrush = new QBrush(Qt::black);
    whiteBrush = new QBrush(Qt::white);
    blackPen = new QPen(Qt::black);
    whitePen = new QPen(Qt::white);
    brushVector.push_back(redBrush);
    brushVector.push_back(yellowBrush);
    brushVector.push_back(greanBrush);
    brushVector.push_back(greanBrush);
    brushVector.push_back(blueBrush);
    brushVector.push_back(blackBrush);
    brushVector.push_back(whiteBrush);

    penVector.push_back(blackPen);
    penVector.push_back(whitePen);
}

void SimulationWindow::cleanSimGUI(){
    simGraphScene->clear();
    robotsVectorGUI.clear();
}

void SimulationWindow::deleteSimGUI(){
    cleanSimGUI();
    delete simGraphScene;
    delete simGraphView;
}

unsigned SimulationWindow::getActualUserRobotPen(){
    if(actualUserRobotColor != 4) return 0;
    return 1;
}

void SimulationWindow::createSimulationsLayout(){
    simulationsLayot = new QVBoxLayout();

    simBodyowBoxLayout = new QHBoxLayout();
    simBodyowBoxLayout->addStretch();
    simBodyowBoxLayout->addWidget(simGraphView);
    simBodyowBoxLayout->addStretch();

    simulatyonEngineLayout = new QHBoxLayout();
    robotsEngineLayout = new QVBoxLayout();

    highRobotsEngineLayout = new QHBoxLayout();
    highRobotsEngineLayout->addStretch();
    highRobotsEngineLayout->addWidget(forwardMoveButton);
    highRobotsEngineLayout->addStretch();

    lowRobotsEngineLayout = new QHBoxLayout();
    lowRobotsEngineLayout->addStretch();
    lowRobotsEngineLayout->addWidget(leftMoveButton);
    lowRobotsEngineLayout->addWidget(stopMoveButton);
    lowRobotsEngineLayout->addWidget(rightMoveButton);
    lowRobotsEngineLayout->addStretch();

    robotsEngineLayout->addLayout(highRobotsEngineLayout);
    robotsEngineLayout->addLayout(lowRobotsEngineLayout);

    simulatyonEngineLayout->addStretch();
    simulatyonEngineLayout->addLayout(robotsEngineLayout);
    simulatyonEngineLayout->addStretch();

    simulationsLayot->addLayout(simBodyowBoxLayout);
    simulationsLayot->addLayout(simulatyonEngineLayout);
    setLayout(simulationsLayot);
}
void SimulationWindow::deleteSimulationsLayout(){
    delete simBodyowBoxLayout;
    delete highRobotsEngineLayout;
    delete lowRobotsEngineLayout;
    delete robotsEngineLayout;
    delete simulatyonEngineLayout;
    delete simulationsLayot;
}

void SimulationWindow::createSimulattionsButtons(){

    forwardMoveButton = new QPushButton("forward");
    leftMoveButton = new QPushButton("left");
    stopMoveButton = new QPushButton("stop");
    rightMoveButton = new QPushButton("right");

    setUnsetSimButtons(false);

    connect(forwardMoveButton, &QPushButton::clicked, this, [=](){contr_forward_move_sig();});
    connect(leftMoveButton, &QPushButton::clicked, this, [=](){contr_left_rotate_move_sig();});
    connect(stopMoveButton, &QPushButton::clicked, this, [=](){contr_stop_move_sig();});
    connect(rightMoveButton, &QPushButton::clicked, this, [=](){contr_right_rotate_move_sig();});
}

void SimulationWindow::setUnsetSimButtons(bool flagIsSet){
    forwardMoveButton->setEnabled(flagIsSet);
    leftMoveButton->setEnabled(flagIsSet);
    stopMoveButton->setEnabled(flagIsSet);
    rightMoveButton->setEnabled(flagIsSet);
}

void SimulationWindow::deleteSimulationsButtons(){
    delete forwardMoveButton;
    delete leftMoveButton;
    delete stopMoveButton;
    delete rightMoveButton;
}

void SimulationWindow::oneSimFrameGUI(){
    std::cout << "EMIT UPDATING SIM GUI" << std::endl;
    //robotsFromController = controlledRobot->GetTransform()->GetRect();
    for(auto robot: robotsVectorGUI){
        actualPositionOfItem = robot->pos();
        robot->setPos(actualPositionOfItem.x(), actualPositionOfItem.y()+1);
    }
}

void SimulationWindow::storeSimGUI(){
    cleanSimGUI();
    //simGraphScene->setBackgroundBrush(*whiteBrush);
    simGraphScene->setBackgroundBrush(*redBrush);
    std::cout << "EMIT STORING SIM GUI!!!" << std::endl;
    robotsFromController = controlledRobot->GetTransform()->GetRect();
    for(unsigned robot = 0; robot < 1; robot++){
        QGraphicsEllipseItem* newRobot = new QGraphicsEllipseItem(0,0,robotsFromController.w,robotsFromController.h);
        newRobot->setPen(*penVector[getActualUserRobotPen()]);
        newRobot->setBrush(*brushVector[actualUserRobotColor]);
        newRobot->setPos(robotsFromController.x,robotsFromController.y);
        simGraphScene->addItem(newRobot);
        robotsVectorGUI.push_back(newRobot);
    }
}

void SimulationWindow::runSimGUI(){
    std::cout << "EMIT RUNING SIM GUI !!!" << std::endl;
    timerOneFrame.start(16);
    setUnsetSimButtons(true);
}

void SimulationWindow::stopSimGUI(){
    std::cout << "EMIT STOP SIM GUI !!!" << std::endl;
    timerOneFrame.stop();
    setUnsetSimButtons(false);
}


void SimulationWindow::runSettingsMode(){
    createSetNet();
}

void SimulationWindow::stopSettingsMode(){
    deleteSetNet();
}



void SimulationWindow::createSetNet(){
    for(unsigned row = 0; row < SIM_WIN_Y; row += NET_ITEM){
        QGraphicsLineItem* newNetLine = new QGraphicsLineItem(0, row, SIM_WIN_X, row);
        newNetLine->setPen(*blackPen);
        setNetVectorGUI.push_back(newNetLine);
        simGraphScene->addItem(newNetLine);
    }
    for(unsigned col = 0; col < SIM_WIN_X; col += NET_ITEM){
        QGraphicsLineItem* newNetLine = new QGraphicsLineItem(col, 0, col, SIM_WIN_Y);
        newNetLine->setPen(*blackPen);
        setNetVectorGUI.push_back(newNetLine);
        simGraphScene->addItem(newNetLine);
    }
}

void SimulationWindow::deleteSetNet(){
    for(auto setNetLine: setNetVectorGUI){
        simGraphScene->removeItem(setNetLine);
        delete setNetLine;
    }
    setNetVectorGUI.clear();
}
