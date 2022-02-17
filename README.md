# Simple C++ ToDo list terminal app

## Use:
From `saburo/bin` you can call following:
- `__main__ add "(txt)"` - add new note with _txt_ 
- `__main__ rm (index)` - remove note at _index_
- `__main__ show` - show all notes


## Code: 
### __cmd.hpp__
Whole app is built arround _Command_ class in this file
The command class serves as a prefab for other commands, which you store into list and then load them with _CommandLine_ in __cmd-line.hpp__

### __cmds.hpp__
Double linked list of basic commands.

### ___cmd-line.hpp__
_CommandLine_ serves for command management. At the beggining instantiate this class with list of commands you would like your program to use, then just call them with `.execute(_cmd_name_, _args_)`

### __note.hpp__
Just contains struct _Note_ for storing data about, well... notes.
