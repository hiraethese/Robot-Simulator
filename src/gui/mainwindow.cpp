#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QApplication::setApplicationDisplayName("ICP2024");
    setWindowTitle("");
    createAppWindows();
}


MainWindow::~MainWindow()
{
    deleteAppWindows();
    delete ui;
}


void MainWindow::createAppWindows(){
    createActions();
    createTools();
    createSimulationBody();
}


void MainWindow::deleteAppWindows(){
    deleteActions();
    deleteTools();
    deleteSimulationBody();
}

void MainWindow::createSimulationBody(){

    simBody = new SimulationBody(this);
    setCentralWidget(simBody);
}

void MainWindow::deleteSimulationBody(){
    //delete simBody;
}

void MainWindow::createActions(){
    helpToolAction = new QAction(QIcon(":/icons/helpTool.jpg"), "&Help", this);
    connect(helpToolAction, SIGNAL(triggered()), this, SLOT(helpTextToolActionFunctional()));

    settingsToolAction = new QAction(QIcon(":/icons/settingsTool.png"), "&Settings", this);
    connect(settingsToolAction, SIGNAL(triggered()), this, SLOT(settingsToolActionFunctional()));

    runSimulationAction = new QAction(QIcon(":/icons/playTool.png"), "&Run", this);
    connect(runSimulationAction, SIGNAL(triggered()), this, SLOT(runSimulationActionFunctional()));

    restartSimulationAction = new QAction(QIcon(":/icons/restartTool.png"), "&Continue", this);
    connect(restartSimulationAction, SIGNAL(triggered()), this, SLOT(restartSimulationActionFunctional()));
}


void MainWindow::deleteActions(){
    disconnect(helpToolAction, 0, 0, 0);
    disconnect(settingsToolAction, 0, 0, 0);
    disconnect(runSimulationAction, 0, 0, 0);
    disconnect(restartSimulationAction, 0, 0, 0);
    delete helpToolAction;
    delete settingsToolAction;
    delete runSimulationAction;
    delete restartSimulationAction;
}


void MainWindow::createTools(){

    settingsToolBar = addToolBar(tr("settings"));
    settingsToolBar->addAction(settingsToolAction);

    engineSimRunToolBar = addToolBar(tr("engineSimRun"));
    engineSimRunToolBar->addAction(runSimulationAction);
    engineSimRunToolBar->addAction(restartSimulationAction);

    simulationIdToolBar = addToolBar(tr("simulationId"));
    labelSimIdToolBar = new QLabel("Simulation: ");
    simulationIdToolBar->addWidget(labelSimIdToolBar);
    lineMapNameSimIdToolBar = new QLineEdit();
    lineMapNameSimIdToolBar->setReadOnly(true);
    lineMapNameSimIdToolBar->setFixedWidth(500);
    simulationIdToolBar->addWidget(lineMapNameSimIdToolBar);

    helpToolBar = addToolBar(tr("help"));
    helpToolBar->addAction(helpToolAction);

}


void MainWindow::deleteTools(){
    if(settingBody != nullptr) delete settingBody;
    delete labelSimIdToolBar;
    delete lineMapNameSimIdToolBar;
    delete helpToolBar;
    delete settingsToolBar;
    delete engineSimRunToolBar;
    delete simulationIdToolBar;
}

void MainWindow::createSettings(){
    settingBody = new settingsWindow();
    connect(settingBody->setPushButton, SIGNAL(clicked()), this, SLOT(updateSettings()));
}

void MainWindow::deleteSettings(){
    disconnect(settingBody, 0, 0, 0);
    delete settingBody;
}

void MainWindow::helpTextToolActionFunctional(){
    // !!! need add help text for users interface actions
    QMessageBox::about(this, "Help", "<b>This place will be for help users text!</b>");
}

void MainWindow::settingsToolActionFunctional(){
    if(settingBody == nullptr){
        createSettings();
    }
    settingBody->setMapValue(simulationMap);
    settingBody->setSpeedValue(simulationSpeed);
    settingBody->setCornerValue(simulationCorner);
    settingBody->show();
}

void MainWindow::updateSettings(){
    simulationMap = settingBody->getMapValue();
    lineMapNameSimIdToolBar->setText(simulationMap);
    simulationSpeed = settingBody->getSpeedValue();
    simulationCorner = settingBody->getCornerValue();
    settingBody->close();
}

void MainWindow::runSimulationActionFunctional(){
    disconnect(runSimulationAction, 0, 0, 0);
    connect(runSimulationAction, SIGNAL(triggered()), this, SLOT(pauseSimulationActionFunctional()));
    runSimulationAction->setIcon(QIcon(":/icons/pauseTool.png"));
    lineMapNameSimIdToolBar->setStyleSheet("background-color: lightgreen;");
}
void MainWindow::pauseSimulationActionFunctional(){
    disconnect(runSimulationAction, 0, 0, 0);
    connect(runSimulationAction, SIGNAL(triggered()), this, SLOT(runSimulationActionFunctional()));
    runSimulationAction->setIcon(QIcon(":/icons/playTool.png"));
    runSimulationAction->setText(tr("Run"));
    lineMapNameSimIdToolBar->setStyleSheet("background-color: white;");
}
void MainWindow::restartSimulationActionFunctional(){
    runSimulationActionFunctional();
}





































