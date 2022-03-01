#include <fstream>
#include <iostream>
#include <sstream>

#include "cmds.hpp"
#include "note.hpp"
#include "../core/args.hpp"
#include "../core/cmd-line.hpp"

#define FILE "cache/etracker-cache.txt"


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
    //file man1 - reading
    // TODO: file is rewrtien down bellow
    std::fstream fs(FILE, std::fstream::in);
    std::string line;
    std::stringstream ss;

    int cost;
    std::string note;

    while (std::getline(fs, line))
    {
        ss = std::stringstream(line);

        ss >> cost >> note;

        notes->push_back(Note(cost, note));
    }

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
        fs << note.cost() << " " << note.msg() << std::endl;
    }

    fs.close();
    return 0;
}
