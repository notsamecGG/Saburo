#pragma once

#include "../core/common.hpp"
#include "../core/cmd.hpp"

#include "args.hpp"

#define RENDER_LINE() std::cout << "----------------------" << std::endl


namespace gg::ui::terminal::etracker
{
typedef Command<Args> ExpenseCommand;


const std::list<ExpenseCommand> basic_cmds =
{
    ExpenseCommand(std::string("add"), [](Args args)
    { 
        std::string cost("");
        std::string note("");

        std::cout << "What was the cost? \n>>" << std::flush;
        std::cin >> cost;

        // if(!args.string.empty())
        // {
        std::cout << "Please type down your expense note. \n>> " << std::flush;
        std::cin >> note; 
        // }

        args.notes->push_back(Note(std::stoi(cost), note));
    }),
    // ExpenseCommand(std::string("rm"), [](Args args)
    // {
    //     int index = std::stoi(args.string);
    //     args.notes->erase(args.notes->begin() + index);
    // }),
    ExpenseCommand(std::string("show"), [](Args args)
    {
        std::cout << "    Expense tracker" << std::endl;
        RENDER_LINE();
        RENDER_LINE();

        for (Note note : *args.notes)
        {
            std::cout << note.cost() << "|" << note.msg() << std::endl;
            RENDER_LINE();
        }
    })
};
}

