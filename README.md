# Simple C++ UI terminal app

TODO: command arguments

This is simple ui terminal engine, aka command handler. See __todo__ app and __etracker__ examples

## Code: 
All of these files are in `saburo/src/core/` directory

### __cmd.hpp__
Whole app is built arround _Command_ class in this file
The command class serves as a prefab for other commands, which you store into list and then load them with _CommandLine_ in __cmd-line.hpp__

### __cmds.hpp__
Double linked list of basic commands.

### __cmd-line.hpp__
_CommandLine_ serves for command management. At the beggining instantiate this class with list of commands you would like your program to use, then just call them with `.execute(_cmd_name_, _args_)`
