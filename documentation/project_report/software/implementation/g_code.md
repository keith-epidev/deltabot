G code interpreter
==================

A CAD design is saved to a STL file. The STL file is then parsed by a g-code converter such as [Slic3r](http://slic3r.org/). This process basically splits a 3D object into layers and then converts these into instructions that will trace the infill. The G-code is basically a set of Cartesian points. Further processing needs to occur, translating the position points into actuator heights and then into speed descriptions. 

Diagram here

Currently, all processing occurs on the host computer. The speed description is sent across USB and stored in a queue. Each command is validated with a string checksum. If an error occurred, then the board can request the computer to repeat. 

The interpreter is implemented as a console like program. Firstly, a list of programs is stored in array. Each element contains a string to match on and the associated function pointer.

``
typedef struct Program{
        char name[20];
        void (*function)();
}Program;
``

A new line character signals the interpreter to parse the cached string. It runs through the string and assigns pointers to any character following a space. This is turned into an array of arguments that can easily be parse in the actual 'program'. The first token tell the interpreter which program to execute. For instance the command "home" will home the platform. A more complex "aprox 100 1 1 0.5" can signal the speed queue program to parse the arguments and check the checksum.
