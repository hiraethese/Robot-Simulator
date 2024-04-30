#include "SimMap.h"

SimMap::SimMap(int width, int height)
{
    //_path = path;
    _width = width;
    _height = height;
    _orderIndex = 1;
    _spawner = new Spawner();
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

    // Check for collisions with other robots
    for (Robot* robot : _robots)
    {
        // bool CircCircCollision(Vector2d firstCircPos, float firstCircRadius, Vector2d secondCircPos, float secondCircRadius);
        Vector2d robotPos = robot->GetTransform()->GetPosition();
        Vector2d robotSize = robot->GetTransform()->GetSize();
        float robotRadius = std::max(robotSize.x, robotSize.y) * 0.5f;

        if ( CircCircCollision( robotPos, robotRadius, { x, y }, newControlledRobotRadius ) )
        {
            return CODE_NEW_OBJECT_COLLISION_ERROR;
        }
    }

    // Check for collisions with all walls
    for (Wall* wall : _walls)
    {
        // bool CircRectCollision(Vector2d circPos, float circRadius, Vector2d rectPos, Vector2d rectSize);
        Vector2d wallPos = wall->GetTransform()->GetPosition();
        Vector2d wallSize = wall->GetTransform()->GetSize();

        if ( CircRectCollision( { x, y }, newControlledRobotRadius, wallPos, wallSize ) )
        {
            return CODE_NEW_OBJECT_COLLISION_ERROR;
        }
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

    // Check for collisions with other robots
    for (Robot* robot : _robots)
    {
        // bool CircCircCollision(Vector2d firstCircPos, float firstCircRadius, Vector2d secondCircPos, float secondCircRadius);
        Vector2d robotPos = robot->GetTransform()->GetPosition();
        Vector2d robotSize = robot->GetTransform()->GetSize();
        float robotRadius = std::max(robotSize.x, robotSize.y) * 0.5f;

        if ( CircCircCollision( robotPos, robotRadius, { x, y }, newAutomatedRobotRadius ) )
        {
            return CODE_NEW_OBJECT_COLLISION_ERROR;
        }
    }

    // Check for collisions with all walls
    for (Wall* wall : _walls)
    {
        // bool CircRectCollision(Vector2d circPos, float circRadius, Vector2d rectPos, Vector2d rectSize);
        Vector2d wallPos = wall->GetTransform()->GetPosition();
        Vector2d wallSize = wall->GetTransform()->GetSize();

        if ( CircRectCollision( { x, y }, newAutomatedRobotRadius, wallPos, wallSize ) )
        {
            return CODE_NEW_OBJECT_COLLISION_ERROR;
        }
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

    // Check for collisions with all robots
    for (Robot* robot : _robots)
    {
        // bool CircRectCollision(Vector2d circPos, float circRadius, Vector2d rectPos, Vector2d rectSize);
        Vector2d robotPos = robot->GetTransform()->GetPosition();
        Vector2d robotSize = robot->GetTransform()->GetSize();
        float robotRadius = std::max(robotSize.x, robotSize.y) * 0.5f;

        if ( CircRectCollision( robotPos, robotRadius, { x, y }, newWallSize ) )
        {
            return CODE_NEW_OBJECT_COLLISION_ERROR;
        }
    }

    // Create new wall
    Wall* newWall = _spawner->GenNewWall(x, y, _orderIndex);
    _walls.push_back(newWall);
    ++_orderIndex;
    return CODE_OK;
}

ICP_CODE SimMap::UpdateRobotState(SimObjView view)
{
    auto itRobotToUpd = GetRobotByOrderIndex(view.orderIndex);  // find robot
    if( itRobotToUpd != _robots.end() )  // TODO from Myron to all: maybe better this all cycles move to another independet method ???
    {
        Robot* robotToUpd = *itRobotToUpd;        
        Vector2d newRobotSize = { view.w, view.h };
        float newRobotRadius = std::max(newRobotSize.x, newRobotSize.y) * 0.5f;
        // Check for collisions with other robots
        for (Robot* robot : _robots)
        {
            if(robot->GetOrderIndex() != view.orderIndex){  // if it is not the same robot
                // bool CircCircCollision(Vector2d firstCircPos, float firstCircRadius, Vector2d secondCircPos, float secondCircRadius);
                Vector2d robotPos = robot->GetTransform()->GetPosition();
                Vector2d robotSize = robot->GetTransform()->GetSize();
                float robotRadius = std::max(robotSize.x, robotSize.y) * 0.5f;

                if ( CircCircCollision( robotPos, robotRadius, robotToUpd->GetTransform()->GetPosition(), newRobotRadius ) )
                {
                    return CODE_NEW_OBJECT_COLLISION_ERROR;
                }
            }
        }

        // Check for collisions with all walls
        for (Wall* wall : _walls)
        {
            // bool CircRectCollision(Vector2d circPos, float circRadius, Vector2d rectPos, Vector2d rectSize);
            Vector2d wallPos = wall->GetTransform()->GetPosition();
            Vector2d wallSize = wall->GetTransform()->GetSize();

            if ( CircRectCollision( robotToUpd->GetTransform()->GetPosition(), newRobotRadius, wallPos, wallSize ) )
            {
                return CODE_NEW_OBJECT_COLLISION_ERROR;
            }
        }

        robotToUpd->SetSimObjView(view);
        return CODE_OK;
    }

    return CODE_ERROR_SIM_OBJ_IS_NOT_FOUND_IN_CORE;

}

ICP_CODE SimMap::UpdateWallState(SimObjView view)
{
    auto itWallToUpd = GetWallByOrderIndex(view.orderIndex);
    if( itWallToUpd != _walls.end() )
    {
        Wall* wallToUpd = *itWallToUpd;
        Vector2d newWallSize = { view.w, view.h };

        // Check for collisions with all robots
        for (Robot* robot : _robots)
        {
            // bool CircRectCollision(Vector2d circPos, float circRadius, Vector2d rectPos, Vector2d rectSize);
            Vector2d robotPos = robot->GetTransform()->GetPosition();
            Vector2d robotSize = robot->GetTransform()->GetSize();
            float robotRadius = std::max(robotSize.x, robotSize.y) * 0.5f;

            if ( CircRectCollision( robotPos, robotRadius, wallToUpd->GetTransform()->GetPosition(), newWallSize ) )
            {
                return CODE_NEW_OBJECT_COLLISION_ERROR;
            }
        }

        wallToUpd->SetSimObjView(view);
        return CODE_OK;
    }
    return CODE_ERROR_SIM_OBJ_IS_NOT_FOUND_IN_CORE;
}

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
        return CODE_INTERNAL_ERROR; // Error openning map file
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
        // Controlled robot
        if (token == "[ControlledRobot]")
        {
            Robot* newRobot = _spawner->GenNewRobot(iss, _orderIndex, true);
            if (!newRobot)
            {
                DeleteAllObjects();
                return CODE_SYNTAXE_ERROR_INPUT_FILE_CONTR_ROBOT;
            }
            _robots.push_back(newRobot);
        }
        // Automated robot
        else if (token == "[AutomatedRobot]")
        {
            Robot* newRobot = _spawner->GenNewRobot(iss, _orderIndex, false);
            if (!newRobot)
            {
                DeleteAllObjects();
                return CODE_SYNTAXE_ERROR_INPUT_FILE_AUTO_ROBOT;
            }
            _robots.push_back(newRobot);
        }
        // Wall
        else if (token == "[Wall]")
        {
            Wall* newWall = _spawner->GenNewWall(iss, _orderIndex);
            if (!newWall)
            {
                DeleteAllObjects();
                return CODE_SYNTAXE_ERROR_INPUT_FILE_WALL;
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

const std::vector<Wall*>& SimMap::GetWalls() const
{
    return _walls;
}

const std::vector<Robot*>& SimMap::GetRobots() const
{
    return _robots;
}

std::vector<SimObjView> SimMap::GetVectorWallsViewGUI()
{
    std::vector<SimObjView> wallsView;

    for (Wall* wall : _walls)
    {
        wallsView.push_back(*wall->GetSimObjViewGUI());
    }

    return wallsView;
}

std::vector<SimObjView> SimMap::GetVectorRobotsViewGUI()
{
    std::vector<SimObjView> robotsView;

    for (Robot* robot : _robots)
    {
        robotsView.push_back(*robot->GetSimObjViewGUI());
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
        // removeItem(wallToRemove);
        delete wallToRemove;
        return CODE_OK;

    }  // TODO: obj not found ret
    
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

int SimMap::GetLastOrderIndex(){
    return (_orderIndex - 1);
}


ICP_CODE SimMap::GetRobotViewByOrderGUI(SimObjView* view, int orderIndex)
{
    auto itRobot = GetRobotByOrderIndex(orderIndex);
    if(itRobot != _robots.end()){
        Robot* robot = *itRobot;
        *view = *(robot->GetSimObjViewGUI());
        return CODE_OK;
    }
    return CODE_ERROR_SIM_OBJ_IS_NOT_FOUND_IN_CORE;
}

ICP_CODE SimMap::GetWallViewByOrderGUI(SimObjView* view, int orderIndex)
{
    auto itWall = GetWallByOrderIndex(orderIndex);
    if(itWall != _walls.end()){
        Wall* wall = *itWall;
        *view = *(wall->GetSimObjViewGUI());
        return CODE_OK;
    }
    return CODE_ERROR_SIM_OBJ_IS_NOT_FOUND_IN_CORE;

}
