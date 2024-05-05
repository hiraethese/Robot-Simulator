/**
 * @file SimMap.cpp
 * @author Baturov Illia (xbatur00@stud.fit.vutbr.cz)
 * @author Kukhta Myron (xkukht01@stud.fit.vutbr.cz)
 * @brief Implementation of the simulation map class and its methods
 */

#include "SimMap.h"

SimMap::SimMap(int width, int height)
{
    //_path = path;
    _width = width;
    _height = height;
    _orderIndex = 1;
    _spawner = new Spawner();
}

SimMap::~SimMap()
{
    delete _spawner;
    DeleteAllObjects();
}

std::string SimMap::GetPath()
{
    return _path;
}

int SimMap::GetWidth()
{
    return _width;
}

int SimMap::GetHeight()
{
    return _height;
}

void SimMap::SetPath(std::string newPath)
{
    _path = newPath;
}

// New controlled robot
ICP_CODE SimMap::CreateNewControlledRobotFromTemplate(float x, float y)
{
    // Controlled robot template
    SimObjView controlledRobotTemp = _spawner->GetControlledRobotTemp();
    Vector2d newControlledRobotSize = { controlledRobotTemp.w, controlledRobotTemp.h };
    float newControlledRobotRadius = std::max(newControlledRobotSize.x, newControlledRobotSize.y) * 0.5f;

    // Check for collisions
    if (RobotWithRobotsCollision({x, y}, newControlledRobotRadius, -1) || // no order index
        RobotWithWallsCollision({x, y}, newControlledRobotRadius) ||
        RobotWithBordersCollision({x, y}, newControlledRobotRadius))
    {
        return CODE_NEW_OBJECT_COLLISION_ERROR;
    }

    // Create new controlled robot
    Robot* newControlledRobot = _spawner->GenNewRobot(x, y, _orderIndex, true);
    _robots.push_back(newControlledRobot);
    ++_orderIndex;
    return CODE_OK;
}

// New automated robot
ICP_CODE SimMap::CreateNewAutomatedRobotFromTemplate(float x, float y)
{
    // Automated robot template
    SimObjView automatedRobotTemp = _spawner->GetAutomatedRobotTemp();
    Vector2d newAutomatedRobotSize = { automatedRobotTemp.w, automatedRobotTemp.h };
    float newAutomatedRobotRadius = std::max(newAutomatedRobotSize.x, newAutomatedRobotSize.y) * 0.5f;

    // Check for collisions
    if (RobotWithRobotsCollision({x, y}, newAutomatedRobotRadius, -1) || // no order index
        RobotWithWallsCollision({x, y}, newAutomatedRobotRadius) ||
        RobotWithBordersCollision({x, y}, newAutomatedRobotRadius))
    {
        return CODE_NEW_OBJECT_COLLISION_ERROR;
    }

    // Create new automated robot
    Robot* newAutomatedRobot = _spawner->GenNewRobot(x, y, _orderIndex, false);
    _robots.push_back(newAutomatedRobot);
    ++_orderIndex;
    return CODE_OK;
}

// New wall
ICP_CODE SimMap::CreateNewWallFromTemplate(float x, float y)
{
    // Wall template
    SimObjView wallTemp = _spawner->GetWallTemp();
    Vector2d newWallSize = { wallTemp.w, wallTemp.h };

    // Check for collisions
    if (WallWithRobotsCollision({x, y}, newWallSize) ||
        WallWithBordersCollision({x, y}, newWallSize))
    {
        return CODE_NEW_OBJECT_COLLISION_ERROR;
    }

    // Create new wall
    Wall* newWall = _spawner->GenNewWall(x, y, _orderIndex);
    _walls.push_back(newWall);
    ++_orderIndex;
    return CODE_OK;
}

// Update robot state
ICP_CODE SimMap::UpdateRobotState(SimObjView view)
{
    // Find robot
    auto itRobotToUpd = GetRobotByOrderIndex(view.orderIndex);

    if( itRobotToUpd != _robots.end() )
    {
        Robot* robotToUpd = *itRobotToUpd; // original robot pointer
        Vector2d origRobotPos = robotToUpd->GetTransform()->GetPosition(); // original robot position

        Vector2d newRobotSize = { view.w, view.h }; // new robot size
        float newRobotRadius = std::max(newRobotSize.x, newRobotSize.y) * 0.5f; // new robot radius

        // Check for collisions
        if (RobotWithRobotsCollision(origRobotPos, newRobotRadius, view.orderIndex) ||
            RobotWithWallsCollision(origRobotPos, newRobotRadius) ||
            RobotWithBordersCollision(origRobotPos, newRobotRadius))
        {
            return CODE_NEW_OBJECT_COLLISION_ERROR;
        }

        robotToUpd->SetSimObjView(view);
        return CODE_OK;
    }
    return CODE_ERROR_SIM_OBJ_IS_NOT_FOUND_IN_CORE;
}

// Update wall state
ICP_CODE SimMap::UpdateWallState(SimObjView view)
{
    // Find wall
    auto itWallToUpd = GetWallByOrderIndex(view.orderIndex);

    if( itWallToUpd != _walls.end() )
    {
        Wall* wallToUpd = *itWallToUpd; // original wall pointer
        Vector2d origWallPos = wallToUpd->GetTransform()->GetPosition(); // original wall position

        Vector2d newWallSize = { view.w, view.h }; // new wall size

        // Check for collisions
        if (WallWithRobotsCollision(origWallPos, newWallSize) ||
            WallWithBordersCollision(origWallPos, newWallSize))
        {
            return CODE_NEW_OBJECT_COLLISION_ERROR;
        }

        wallToUpd->SetSimObjView(view);
        return CODE_OK;
    }
    return CODE_ERROR_SIM_OBJ_IS_NOT_FOUND_IN_CORE;
}

// Load objects from file
ICP_CODE SimMap::LoadObjectsFromFile(std::string path)
{
    _orderIndex = 1;
    _path = path;

    // Restart all objects
    DeleteAllObjects();

    // Open the file
    QFileInfo infoAboutPath(QString::fromStdString(path));

    if(!infoAboutPath.exists()){

        std::cout << "file not exist" << std::endl;
        return CODE_ERROR_INPUT_FILE_NOT_EXIST;
    }

    if(!infoAboutPath.isFile()){
        std::cout << "it is not file" << std::endl;
        return CODE_ERROR_INPUT_FILE_NOT_EXIST;
    }

    std::ifstream file(_path);

    // Check if the file is opened
    if (!file.is_open())
    {
        std::cerr << "Error: Unable to open map file\n";
        return CODE_INTERNAL_ERROR; // error openning map file
    }

    // Read each line from the file
    std::string line;

    while (std::getline(file, line))
    {
        // Empty line
        if (line.empty()) continue;
        // Create a stringstream from the line
        std::istringstream iss(line);
        // Read the first token
        std::string token;
        if (!(iss >> token))
        {
            std::cerr << "Error: Unable to read token from line\n";
            return CODE_INTERNAL_ERROR; // Error reading token from line
        }

        // New controlled robot
        if (token == "[ControlledRobot]")
        {
            Robot* newControlledRobot = _spawner->GenNewRobot(iss, _orderIndex, true);

            if (!newControlledRobot)
            {
                DeleteAllObjects();
                return CODE_SYNTAXE_ERROR_INPUT_FILE_CONTR_ROBOT;
            }

            // New controlled robot values
            Vector2d newControlledRobotPos = newControlledRobot->GetTransform()->GetPosition();
            Vector2d newControlledRobotSize = newControlledRobot->GetTransform()->GetSize();
            float newControlledRobotRadius = std::max(newControlledRobotSize.x, newControlledRobotSize.y) * 0.5f;
            int newControlledRobotIndex = newControlledRobot->GetOrderIndex();

            // Check for collisions
            if (RobotWithRobotsCollision(newControlledRobotPos, newControlledRobotRadius, newControlledRobotIndex) ||
                RobotWithWallsCollision(newControlledRobotPos, newControlledRobotRadius) ||
                RobotWithBordersCollision(newControlledRobotPos, newControlledRobotRadius))
            {
                delete newControlledRobot;
                DeleteAllObjects();
                return CODE_NEW_OBJECT_COLLISION_ERROR;
            }

            _robots.push_back(newControlledRobot);
        }

        // New automated robot
        else if (token == "[AutomatedRobot]")
        {
            Robot* newAutomatedRobot = _spawner->GenNewRobot(iss, _orderIndex, false);

            if (!newAutomatedRobot)
            {
                DeleteAllObjects();
                return CODE_SYNTAXE_ERROR_INPUT_FILE_AUTO_ROBOT;
            }

            // New automated robot values
            Vector2d newAutomatedRobotPos = newAutomatedRobot->GetTransform()->GetPosition();
            Vector2d newAutomatedRobotSize = newAutomatedRobot->GetTransform()->GetSize();
            float newAutomatedRobotRadius = std::max(newAutomatedRobotSize.x, newAutomatedRobotSize.y) * 0.5f;
            int newAutomatedRobotIndex = newAutomatedRobot->GetOrderIndex();

            // Check for collisions
            if (RobotWithRobotsCollision(newAutomatedRobotPos, newAutomatedRobotRadius, newAutomatedRobotIndex) ||
                RobotWithWallsCollision(newAutomatedRobotPos, newAutomatedRobotRadius) ||
                RobotWithBordersCollision(newAutomatedRobotPos, newAutomatedRobotRadius))
            {
                delete newAutomatedRobot;
                DeleteAllObjects();
                return CODE_NEW_OBJECT_COLLISION_ERROR;
            }

            _robots.push_back(newAutomatedRobot);
        }

        // New wall
        else if (token == "[Wall]")
        {
            Wall* newWall = _spawner->GenNewWall(iss, _orderIndex);

            if (!newWall)
            {
                DeleteAllObjects();
                return CODE_SYNTAXE_ERROR_INPUT_FILE_WALL;
            }

            // New wall values
            Vector2d newWallPos = newWall->GetTransform()->GetPosition();
            Vector2d newWallSize = newWall->GetTransform()->GetSize();

            // Check for collisions
            if (WallWithRobotsCollision(newWallPos, newWallSize) ||
                WallWithBordersCollision(newWallPos, newWallSize))
            {
                delete newWall;
                DeleteAllObjects();
                return CODE_NEW_OBJECT_COLLISION_ERROR;
            }

            _walls.push_back(newWall);
        }

        // Other
        else
        {
            DeleteAllObjects();
            return CODE_SYNTAXE_ERROR_UNKNOWN_OBJ_TYPE;
        }
        ++_orderIndex;
    }

    return CODE_OK;
}

//////////////////////////////////////////// COLLISION CHECK ////////////////////////////////////////////

// Check for collisions with other robots
bool SimMap::RobotWithRobotsCollision(Vector2d position, float radius, int orderIndex)
{
    for (Robot* robot : _robots)
    {
        // If it is not the same robot
        if ( robot->GetOrderIndex() != orderIndex )
        {
            // bool CircCircCollision(Vector2d firstCircPos, float firstCircRadius, Vector2d secondCircPos, float secondCircRadius);
            Vector2d robotPos = robot->GetTransform()->GetPosition();
            Vector2d robotSize = robot->GetTransform()->GetSize();
            float robotRadius = std::max(robotSize.x, robotSize.y) * 0.5f;
            if ( CircCircCollision( robotPos, robotRadius, position, radius ) )
            {
                return true;
            }
        }
    }
    return false;
}

// Check for collisions with all walls
bool SimMap::RobotWithWallsCollision(Vector2d position, float radius)
{
    for (Wall* wall : _walls)
    {
        // bool CircRectCollision(Vector2d circPos, float circRadius, Vector2d rectPos, Vector2d rectSize);
        Vector2d wallPos = wall->GetTransform()->GetPosition();
        Vector2d wallSize = wall->GetTransform()->GetSize();
        if ( CircRectCollision( position, radius, wallPos, wallSize ) )
        {
            return true;
        }
    }
    return false;
}

// Check for collision with map borders
bool SimMap::RobotWithBordersCollision(Vector2d position, float radius)
{
    if (position.x - radius < 0)
    {
        return true;
    }
    if (position.x + radius > _width)
    {
        return true;
    }
    if (position.y - radius < 0)
    {
        return true;
    }
    if (position.y + radius > _height)
    {
        return true;
    }
    return false;
}

// Check for collisions with all robots
bool SimMap::WallWithRobotsCollision(Vector2d position, Vector2d size)
{
    for (Robot* robot : _robots)
    {
        // bool CircRectCollision(Vector2d circPos, float circRadius, Vector2d rectPos, Vector2d rectSize);
        Vector2d robotPos = robot->GetTransform()->GetPosition();
        Vector2d robotSize = robot->GetTransform()->GetSize();
        float robotRadius = std::max(robotSize.x, robotSize.y) * 0.5f;
        if ( CircRectCollision( robotPos, robotRadius, position, size ) )
        {
            return true;
        }
    }
    return false;
}

// Check for collision with map borders
bool SimMap::WallWithBordersCollision(Vector2d position, Vector2d size)
{
    if (position.x - size.x < 0)
    {
        return true;
    }
    if (position.x + size.x > _width)
    {
        return true;
    }
    if (position.y - size.y < 0)
    {
        return true;
    }
    if (position.y + size.y > _height)
    {
        return true;
    }
    return false;
}

//////////// THE END OF COLLISIONS ////////////

const std::vector<Wall*>& SimMap::GetWalls() const
{
    return _walls;
}

const std::vector<Robot*>& SimMap::GetRobots() const
{
    return _robots;
}

std::vector<SimObjView> SimMap::GetVectorWallsView()
{
    std::vector<SimObjView> wallsView;

    for (Wall* wall : _walls)
    {
        wallsView.push_back(*wall->GetSimObjView());
    }

    return wallsView;
}

std::vector<SimObjView> SimMap::GetVectorRobotsView()
{
    std::vector<SimObjView> robotsView;

    for (Robot* robot : _robots)
    {
        robotsView.push_back(*robot->GetSimObjView());
    }

    return robotsView;
}

Robot* SimMap::GetFirstControlledRobot()
{
    for (Robot* robot : _robots)
    {
        if (robot->IsControlled())
        {
            return robot;
        }
    }

    return nullptr;
}

Spawner *SimMap::GetSpawner()
{
    return _spawner;
}

/////////////////////////////////////////////////// Delete objects here !!!

std::vector<Robot*>::iterator SimMap::GetRobotByOrderIndex(int orderIndex)
{
    auto it = _robots.begin();

    while(it != _robots.end())
    {
        if( (*it)->GetOrderIndex() == orderIndex )
        {
            return it;
        }
        ++it;
    }
    return it;
}

std::vector<Wall*>::iterator SimMap::GetWallByOrderIndex(int orderIndex)
{
    auto it = _walls.begin();

    while(it != _walls.end())
    {
        if( (*it)->GetOrderIndex() == orderIndex )
        {
            return it;
        }
        ++it;
    }
    return it;
}

ICP_CODE SimMap::RemoveRobotByOrderIndex(int orderIndex)
{
    auto itRobotToRemove = GetRobotByOrderIndex(orderIndex);

    if( itRobotToRemove != _robots.end() )
    {
        Robot* robotToRemove = *itRobotToRemove;
        _robots.erase(itRobotToRemove);
        // removeItem(robotToRemove);
        delete robotToRemove;
        return CODE_OK;
    }

    return CODE_ERROR_SIM_OBJ_IS_NOT_FOUND_IN_CORE;
}

ICP_CODE SimMap::RemoveWallByOrderIndex(int orderIndex)
{
    auto itWallToRemove = GetWallByOrderIndex(orderIndex);

    if( itWallToRemove != _walls.end() )
    {
        Wall* wallToRemove = *itWallToRemove;
        _walls.erase(itWallToRemove);
        
        delete wallToRemove;
        return CODE_OK;

    }

    return CODE_ERROR_SIM_OBJ_IS_NOT_FOUND_IN_CORE;
}

void SimMap::DeleteAllObjects()
{
    if (!_robots.empty())
    {
        for (auto& robot : _robots)
        {
            delete robot;
        }
        _robots.clear();
    }
    if (!_walls.empty())
    {
        for (auto& wall : _walls)
        {
            delete wall;
        }
        _walls.clear();
    }
}

int SimMap::GetLastOrderIndex()
{
    return (_orderIndex - 1);
}

ICP_CODE SimMap::GetRobotViewByOrderGUI(SimObjView* view, int orderIndex)
{
    auto itRobot = GetRobotByOrderIndex(orderIndex);
    if(itRobot != _robots.end()){
        Robot* robot = *itRobot;
        *view = *(robot->GetSimObjView());
        return CODE_OK;
    }
    return CODE_ERROR_SIM_OBJ_IS_NOT_FOUND_IN_CORE;
}

ICP_CODE SimMap::GetWallViewByOrderGUI(SimObjView* view, int orderIndex)
{
    auto itWall = GetWallByOrderIndex(orderIndex);
    if(itWall != _walls.end()){
        Wall* wall = *itWall;
        *view = *(wall->GetSimObjView());
        return CODE_OK;
    }
    return CODE_ERROR_SIM_OBJ_IS_NOT_FOUND_IN_CORE;
}
