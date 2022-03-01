#pragma once

#include "note.hpp"
#include "../core/args.hpp"
#include "../core/common.hpp"
#include "../core/cmd.hpp"


#define RENDER_LINE() std::cout << "----------------------" << std::endl


namespace gg::ui::terminal::etracker
{
typedef Args<Note> ExpenseArgs;
typedef Command<ExpenseArgs> ExpenseCommand;


const std::list<ExpenseCommand> basic_cmds =
{
    ExpenseCommand(std::string("add"), [](ExpenseArgs args)
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
    ExpenseCommand(std::string("show"), [](ExpenseArgs args)
    {
        std::cout << "    Expense tracker" << std::endl;
        RENDER_LINE();
        RENDER_LINE();

        int sum(0);

        for (Note note : *args.notes)
        {
            std::cout << note.cost() << "|" << note.msg() << std::endl;
            
            sum += note.cost();
            
            RENDER_LINE();
        }

        RENDER_LINE();

        std::cout << "SUM: " << sum << std::endl;
    })
};
}

