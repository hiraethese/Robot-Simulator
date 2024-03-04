#include "MainWindow.h"
#include "ui_MainWindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setAttribute(Qt::WA_DeleteOnClose);
    ui->setupUi(this);
    //QApplication::setApplicationDisplayName("ICP2024");
    setWindowTitle("");

    contr_create_core(); // input point: init core

    createAppWindows();
}


MainWindow::~MainWindow()
{
    deleteAppWindows();
    delete ui;
}



// ************************************  APPLICATION    *********************************************************
void MainWindow::createAppWindows(){
    createSimulationWindow();
    createSettings();
    createActions();
    createTools();
}


void MainWindow::deleteAppWindows(){
    deleteActions();
    deleteTools();
    delete settings;
    delete simWind;

    contr_delete_core(); // input point: delete core
}
// **************************************************************************************************************



// ************************************  BAR && ACTIONS *********************************************************
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
    delete labelSimIdToolBar;
    delete lineMapNameSimIdToolBar;
    delete helpToolBar;
    delete settingsToolBar;
    delete engineSimRunToolBar;
    delete simulationIdToolBar;
}

void MainWindow::createActions(){
    helpToolAction = new QAction(QIcon(":/icons/helpTool.jpg"), "&Help", this);
    connect(helpToolAction, SIGNAL(triggered()), this, SLOT(helpTextToolActionSlot()));

    settingsToolAction = new QAction(QIcon(":/icons/settingsTool.png"), "&Settings", this);
    connect(settingsToolAction, SIGNAL(triggered()), this, SLOT(settingsToolActionSlot()));

    runSimulationAction = new QAction(QIcon(":/icons/playTool.png"), "&Run", this);
    connect(runSimulationAction, SIGNAL(triggered()), this, SLOT(runSimulationActionSlot()));

    restartSimulationAction = new QAction(QIcon(":/icons/restartTool.png"), "&Continue", this);
    connect(restartSimulationAction, SIGNAL(triggered()), this, SLOT(restartSimulationActionSlot()));
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
void MainWindow::helpTextToolActionSlot(){
    // !!! need add help text for users interface actions
    QMessageBox::about(this, "Help", "<b>This place will be for help users text!</b>");
}

void MainWindow::runSimulationActionSlot(){
    if(!contr_is_sim_ready()){
        warningMsgSimNotSet();
        return;
    }
    disconnect(runSimulationAction, 0, 0, 0);
    connect(runSimulationAction, SIGNAL(triggered()), this, SLOT(pauseSimulationActionSlot()));
    runSimulationAction->setIcon(QIcon(":/icons/pauseTool.png"));
    lineMapNameSimIdToolBar->setStyleSheet("background-color: lightgreen;");

    contr_run_sim_command();

    simWind->emitRunGUISimSigFromSimWind();
}
void MainWindow::pauseSimulationActionSlot(){

    contr_stop_sim_command();
    simWind->emitStopGUISimSigFromSimWind();
    disconnect(runSimulationAction, 0, 0, 0);
    connect(runSimulationAction, SIGNAL(triggered()), this, SLOT(runSimulationActionSlot()));
    runSimulationAction->setIcon(QIcon(":/icons/playTool.png"));
    runSimulationAction->setText(tr("Run"));
    lineMapNameSimIdToolBar->setStyleSheet("background-color: white;");
}

void MainWindow::restartSimulationActionSlot(){
    //runSimulationActionSlot();
    if(contr_is_sim_ready()){
        warningMsgSimNotSet();
        return;
    }
}
// **************************************************************************************************************



// ************************************  SETTINGS       *********************************************************
void MainWindow::createSettings(){
    settings = new SettingsWindow();
    connect(settings->setPushButton, SIGNAL(clicked()), this, SLOT(updateSettingsSlot()));
    settings->hide();
}

void MainWindow::deleteSettings(){
    disconnect(settings, 0, 0, 0);
    delete settings;
}
void MainWindow::updateSettingsSlot(){

    // !!! try catch filtering errors
    contr_set_new_settings(settings->isSetMapValue(), settings->getMapValue().toStdString(), settings->isSetSpeedValue(), settings->getSpeedValue(), settings->isSetCornerValue(), settings->getCornerValue());
    //
    if(settings->isSetMapValue()){
        lineMapNameSimIdToolBar->setText(settings->getMapValue());
        simWind->emitStoreGUISimSigFromSimWind();
    }
    settings->close();
}
void MainWindow::settingsToolActionSlot(){
    if(contr_is_sim_run()) pauseSimulationActionSlot();
    // *** should be set by core ***
    settings->setMapValue(QString::fromStdString(contr_get_map_value()));
    settings->setSpeedValue(contr_get_speed_value());
    settings->setCornerValue(contr_get_corner_value());
    // *** *** *** *** *** *** *** ***
    settings->show();
}
// **************************************************************************************************************



// ************************************  SIMULATION     *********************************************************
void MainWindow::createSimulationWindow(){

    simWind = new SimulationWindow(this);
    setCentralWidget(simWind);
}

// **************************************************************************************************************





































