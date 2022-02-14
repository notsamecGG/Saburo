#define DEBUG false

#if DEBUG
#define COUT(x) std::cout << x << std::endl
#else
#define COUT(x)
#endif

#include <fstream>
#include <iostream>
#include <string>

#include "cmds.cpp"
#include "note.hpp"


int main(int argc, char** argv)
{
    if (argc <= 1)
    {  
        std::cerr << "You must enter some of the following commands: add, rm, show" << std::endl;
        return 1;
    }

    CMDLine cmd;
    std::string command(argv[1]);
    //file man1 - reading
    // TODO: file is rewrtien down bellow
    std::fstream fs("cache.txt", std::fstream::in);
    std::string line;

    while (std::getline(fs, line))
        cmd.add(line);

    fs.close();

    // command resolver
    if (command.compare("add") == 0)
        cmd.add(argv[2]);
    else if (command.compare("rm") == 0)
        cmd.rm(argv[2]);
    else if (command.compare("show") == 0)
        cmd.show(cmd.notes);
    else
    {
        std::cerr << argv[1] << " is not recognized command" << std::endl;
        return 2;
    }

    //file man2 - writing
    fs.open("cache.txt", std::fstream::out /*| std::fstream::app*/);

    for (Note note : cmd.notes)
    {
        COUT(note.msg());
        fs << note.msg() << std::endl;
    }

    fs.close();

    COUT("end");
}
