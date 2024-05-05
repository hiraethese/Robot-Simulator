## ICP 2024 project (VUT FIT) ###
A simple 2D mobile robot simulator.

### AUTHORS ###
Baturov Illia (xbatur00@stud.fit.vutbr.cz),
Kukhta Myron (xkukht01@stud.fit.vutbr.cz).

### BUILDING ###

1. Build project: Clean previuse compiling and create new executive file from soucre code. 

    $ make

2. Run project: Start the program execution.

    $make run

3. Clean result of compile: Delete all makefiles, object and moc files which created by compyling.
    
    $make clean

4. Creating documentation: Create documentation by doxyhen in /doc folder  

    $make doxygen


5. Project packing: Clean previuse compiling and make zip file with projct body

    $make pack 

### USERS TUTORIAL ###

The application consists of a simulation scene, buttons for controlling robots, a toolbar and a menu button.
The user can start and stop the simulation, download simulation objects from a file, create manually, delete, change internal settings.

** MENU
After click on menu button user has several actions to choose from:
    -- TEMPLATES
    -- SIMULATION
    -- BUILD MAP
    -- DOWNLOAD MAP

Their description:

** TEMPLATES is precess where the user can create templates for each type of simulation object.
   These templates will be used to manually create objects on the scene.

** SIMULATION is process where user can observe the movement of robots on the field you have created.
-- To start the simulation, press the upper left "Run" button.
-- To moving a controlled robot user can use or the keys "W/A/S/D" (Move/Rotate Left/Stop/Rotate right) or graphical interface buttons 
-- To stop the simulation, press the upper left "Stop button".

** BUILD MAP is process where the user can manually create simulation objects and change their settings.
-- MANUALY CREATING BY TEMPLATES: press upper left buttons "Controlled robot"/"Automatic robot"/"Wall" (type of simulation object).
   After that user must  click on simulation scene by left mouse button and in this playce will be create simulation object from template.
-- CHANGE SETTINGS: user can click 2 time by right mouse button on object on simulation scene.
   After on settings window user can make changes and save them by clicking on the "Set" button.
-- DELETE: user can click 2 time by right mouse button on object on simulation scene.
   After that user must click on the "Delete button" on settings window .

** DOWNLOAD MAP is process where user can load simulations object and positions on scene from configure file.
   The user must enter the absolute path to the file in the pop-up window and click on the "Download" button.
   After that, all objects from the file will be displayed on the scene.

### CONFIGURE FILE ###

Example have on /examples/example.txt

Robot syntaxe rules:
[TYPE_OF_OBJECT] X_COORDINATE Y_COORDINATE DIAGONAL SPEED COLLISION_DISTANCE ANGLE_STEP ANGLE_DEGREE CLOCK_WISE COLOR

-- TYPE_OF_OBJECT       : string : "ControlledRobot"/"AutomatedRobot"
-- X_COORDINATE         : float  :
-- Y_COORDINATE         : float  :
-- DIAGONAL             : float  :
-- SPEED                : float  : < 0.0 - 50.0 >
-- COLLISION_DISTANCE   : float  : < 0.0 - 1000.0 > 
-- ANGLE_STEP           : int    :  
-- ANGLE_DEGREE         : int    :  
-- CLOCK_WISE           : int    : [-1, 1]
-- COLOR                : string : "red"/"green"/"yellow"/"black"/"blue"/"gray" 

Wall syntaxe rules:
[TYPE_OF_WALL] X_COORDINATE Y_COORDINATE WIDTH HEIGTH COLOR

-- TYPE_OF_OBJECT       : string : "Wall"
-- X_COORDINATE         : float  :
-- Y_COORDINATE         : float  :
-- WIDTH                : float  : 
-- HEIGTH               : float  :
-- COLOR                : string :  "red"/"green"/"yellow"/"black"/"blue"/"gray"


### BEHAVIOR OF SIMULATIONS OBJECTS ###

Controlled robot:
    -- Сollision with a wall : stop moving (right angles)  / sliding (another angles)
    -- Collision with a robot : stop moving (right angles)  / sliding (another angles)
    -- collision with the boundaries of the map : stop moving (right angles)  / sliding (another angles)

Atomated robot:
    -- Detected collision: make one rotate and move
    -- Сollision with a wall : make one rotate and move
    -- Collision with a robot : make one rotate and move
    -- Collision with the boundaries of the map : bounces at an angle of collision

Wall : 
    -- only static existing without collision with a wall (for the possibility of generating irregular shape)

    


### IMPLEMENTATION  ### 
The project was implemented in C++ using the Qt framework to solve the graphical interface and logic of user
interaction with the application.

The application is divided into two parts: Core and GUI.
-- Core is the back part of the application for controlling the behavior of the simulation.
-- GUI is responsible for the graphical display of the simulation and user interaction.

### Design patterns usage  ###

-- Singelton: Used to simplify the communication of different parts of the GUI with the core
-- Factory method: free implementation of the pattern for creating simulation objects on the core side

## License 
MIT