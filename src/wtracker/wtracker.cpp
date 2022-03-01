#include <fstream>
#include <iostream>
#include <sstream>

#include "cmds.hpp"
#include "note.hpp"
#include "../core/cmd-line.hpp"

#define FILE "cache/wtracker-cache.txt"


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

    std::string weight;
    std::string date;

    while (std::getline(fs, line))
    {
        if(line.empty())
            break;

        ss = std::stringstream(line);

        std::getline(ss, weight, ';');
        std::getline(ss, date);

        notes->push_back(Note(std::stoi(weight), date));
    }

    fs.close();

    // command resolver
    try
    {
        std::string args = "";
        
        if (argc >= 3)
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
        fs << note.weight() << ";" << note.date() << std::endl;
    }

    fs.close();
    return 0;
}
