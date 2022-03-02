#pragma once

#include "../core/args.hpp" 
#include "../core/common.hpp"
#include "../core/cmd.hpp"
#include "../core/inote.hpp"

#define RENDER_LINE() std::cout << "----------------------" << std::endl


namespace gg::ui::terminal::todo
{
/**
 * @brief check if argument string isn't empty
 * 
 * @param str - argument string
 */
void emptyCheck(std::string& str)
{
    if (str.empty())
    {
        throw std::invalid_argument("No arguments");
    }
}

typedef Args<INote> TodoArgs;
typedef Command<TodoArgs> TodoCommand;

/**
 * @brief list of basic commands
 * 
 */
const std::list<TodoCommand> basic_cmds =
{
    TodoCommand(std::string("add"), [](TodoArgs args)
    { 
        emptyCheck(args.string);

        args.notes->push_back(INote(args.string));
    }),
    TodoCommand(std::string("rm"), [](TodoArgs args)
    {
        emptyCheck(args.string);

        int index = std::stoi(args.string);
        args.notes->erase(args.notes->begin() + index);
    }),
    TodoCommand(std::string("show"), [](TodoArgs args)
    {
        std::cout << "    MY TODO LIST" << std::endl;
        RENDER_LINE();

        for (INote note : *args.notes)
        {
            std::cout << note.msg() << std::endl;
            RENDER_LINE();
        }
    })
};
}
