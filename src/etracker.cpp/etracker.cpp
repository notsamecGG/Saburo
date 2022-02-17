#include <fstream>
#include <iostream>

#include "cmds.hpp"
#include "args.hpp"
#include "../core/cmd-line.hpp"

#define FILE "etracker-cache.txt"


int main(int argc, char** argv)
{
    if (argc <= 1)
    {  
        std::cerr << "You must enter some of the following commands: add, show" << std::endl;
        return 1;
    }

    std::unique_ptr<std::vector<Note>> notes = std::make_unique<std::vector<Note>>();

    gg::ui::terminal::CommandLine cmdl(gg::ui::terminal::etracker::basic_cmds);
    std::string command(argv[1]);

    // command resolver
    try
    {
        std::string args = "";
        
        if (argc >=3)
            args.assign(argv[2]);

        cmdl.execute(std::string(argv[1]), Args(args, notes.get()));
    }
    catch(std::invalid_argument e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    // No file support :), so.... it's pointless

    return 0;
}
