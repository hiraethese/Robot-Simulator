#include "SimulationWindow.h"

SimulationWindow::SimulationWindow(QWidget *parent)
    : QWidget{parent}
{

    //simBody = new SimulationBody();
    createSimGUI();
    createSimulattionsButtons();
    createSimulationsLayout();

    connect(&timerSimEmit, &QTimer::timeout, this, &SimulationWindow::updateSimGUI);
    SimStart();
}

SimulationWindow::~SimulationWindow(){
    //delete simBody;
    //for(QBrush* br: brashVector) delete br;
    //for(QPen* pen: penVector) delete pen;
    deleteSimGUI();
    deleteSimulationsButtons();
    deleteSimulationsLayout();
}

void SimulationWindow::createSimGUI(){
    simGraphScene = new QGraphicsScene();
    simGraphView = new QGraphicsView(simGraphScene);
    simGraphView->setFixedSize(1800, 750);
    redBrush = new QBrush(Qt::red);       // 0
    yellowBrush = new QBrush(Qt::yellow); // 1
    greanBrush = new QBrush(Qt::green);   // 2
    blueBrush = new QBrush(Qt::blue);     // 3
    blackBrush = new QBrush(Qt::black);   // 4
    whiteBrush = new QBrush(Qt::white);   // 5
    blackPen = new QPen(Qt::black);       // 0
    whitePen = new QPen(Qt::white);       // 1
    brashVector.push_back(redBrush);
    brashVector.push_back(yellowBrush);
    brashVector.push_back(greanBrush);
    brashVector.push_back(greanBrush);
    brashVector.push_back(blueBrush);
    brashVector.push_back(blackBrush);
    brashVector.push_back(whiteBrush);

    penVector.push_back(blackPen);
    penVector.push_back(whitePen);
}

void SimulationWindow::deleteSimGUI(){
    simGraphScene->clear();
    robotsVectorGUI.clear();
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
    //simulationRunEngineLayout = new QHBoxLayout();

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

void SimulationWindow::updateSimGUI(){
    std::cout << "EMIT UPDATING SIM GUI" << std::endl;
    //Rectangle robotsFromController = controlledRobot->GetTransform()->GetRect();
    for(auto robot: robotsVectorGUI){
        actualPositionOfItem = robot->pos();
        robot->setPos(actualPositionOfItem.x(), actualPositionOfItem.y()+1);
    }
}

void SimulationWindow::storeSimGUI(){
    simGraphScene->setBackgroundBrush(QColor(Qt::blue));
    std::cout << "EMIT STORING SIM GUI!!!" << std::endl;
    Rectangle robotsFromController = controlledRobot->GetTransform()->GetRect();
    for(unsigned robot = 0; robot < 1; robot++){
        QGraphicsEllipseItem* newRobot = new QGraphicsEllipseItem(0,0,robotsFromController.w,robotsFromController.h);
        //std::cout << "position " << robotsFromController.x << " " <<robotsFromController.y << std::endl;
        newRobot->setPen(*penVector[getActualUserRobotPen()]);
        newRobot->setBrush(*brashVector[actualUserRobotColor]);
        simGraphScene->addItem(newRobot);
        newRobot->setTransformOriginPoint(robotsFromController.x, robotsFromController.y);
        robotsVectorGUI.push_back(newRobot);
    }
}

void SimulationWindow::runSimGUI(){
    std::cout << "EMIT RUNING SIM GUI !!!" << std::endl;
    timerSimEmit.start(16);
    setUnsetSimButtons(true);
}

void SimulationWindow::stopSimGUI(){
    std::cout << "EMIT STOP SIM GUI !!!" << std::endl;
    timerSimEmit.stop();
    setUnsetSimButtons(false);
}
