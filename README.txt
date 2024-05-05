##ICP 2024 project.
A simple 2D mobile robot simulator.

## Authors:
Baturov Illia (xbatur00@stud.fit.vutbr.cz),
Kukhta Myron (xkukht01@stud.fit.vutbr.cz).

## Building

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


## Implementation 
The project was implemented in C++ using the Qt framework to solve the graphical interface and logic of user interaction with the application
Our main idea was the division of responsibilities between the core and the GUI, where core was responsible for the behavior of the simulation
and the GUI played the role of an intermediary between the user and the core, displaying the simulation graphics and passing user requests to
the cornel.

## License 
MIT