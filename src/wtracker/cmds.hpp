#pragma once

#include "note.hpp"
#include "../core/args.hpp"
#include "../core/common.hpp"
#include "../core/cmd.hpp"

#define RENDER_LINE() std::cout << "----------------------" << std::endl


namespace gg::ui::terminal::etracker
{
typedef Args<Note> WArgs;
typedef Command<WArgs> WeightCommand;


const std::list<WeightCommand> basic_cmds =
{
    WeightCommand(std::string("add"), [](WArgs args)
    { 
        std::string weight("");

        std::cout << "What's your weight? \n>>" << std::flush;
        std::cin >> weight;

        args.notes->push_back(Note(std::stoi(weight)));
    }),
    WeightCommand(std::string("show"), [](WArgs args)
    {
        std::cout << "    Weight tracker" << std::endl;
        RENDER_LINE();
        RENDER_LINE();

        for (Note note : *args.notes)
        {
            std::cout << note.weight() << "|" << note.date() << std::endl;
            
            RENDER_LINE();
        }

        RENDER_LINE();
    })
};
}

