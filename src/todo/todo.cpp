#include <fstream>
#include <iostream>

#include "cmds.hpp"
#include "args.hpp"
#include "../core/cmd-line.hpp"

#define FILE "todo-cache.txt"


int main(int argc, char** argv)
{
    if (argc <= 1)
    {  
        std::cerr << "You must enter some of the following commands: add, rm, show" << std::endl;
        return 1;
    }

    std::unique_ptr<std::vector<Note>> notes = std::make_unique<std::vector<Note>>();

    gg::ui::terminal::CommandLine cmdl(gg::ui::terminal::todo::basic_cmds);
    std::string command(argv[1]);
    //file man1 - reading
    // TODO: file is rewrtien down bellow
    std::fstream fs(FILE, std::fstream::in);
    std::string line;

    while (std::getline(fs, line))
        cmdl.execute(std::string("add"), Args(line, notes.get()));

    fs.close();

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

    //file man2 - writing
    fs.open(FILE, std::fstream::out /*| std::fstream::app*/);

    for (Note note : *notes)
    {
        // COUT(note.msg());
        fs << note.msg() << std::endl;
    }

    fs.close();
    return 0;
}
