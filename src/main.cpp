#include <fstream>
#include <iostream>
#include <string>

#include "common.hpp"
#include "cmds.hpp"
#include "cmd-line.hpp"


int main(int argc, char** argv)
{
    if (argc <= 1)
    {  
        std::cerr << "You must enter some of the following commands: add, rm, show" << std::endl;
        return 1;
    }

    CommandLine cmdl(basic_cmds);
    std::string command(argv[1]);
    //file man1 - reading
    // TODO: file is rewrtien down bellow
    std::fstream fs("cache.txt", std::fstream::in);
    std::string line;

    while (std::getline(fs, line))
        cmdl.execute(std::string("add"), line);

    fs.close();

    // command resolver
    try
    {
        std::string args = "";
        
        if (argc >=3)
            args.assign(argv[2]);

        cmdl.execute(std::string(argv[1]), args);
    }
    catch(std::invalid_argument e)
    {
        std::cerr << e.what() << std::endl;
    }

    //file man2 - writing
    fs.open("cache.txt", std::fstream::out /*| std::fstream::app*/);

    for (Note note : *cmdl.notes())
    {
        // COUT(note.msg());
        fs << note.msg() << std::endl;
    }

    fs.close();
}
