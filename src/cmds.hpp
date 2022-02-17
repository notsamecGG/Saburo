#pragma once

#include "common.hpp"
#include "cmd.hpp"

#define RENDER_LINE() std::cout << "----------------------" << std::endl


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

/**
 * @brief list of basic commands
 * 
 */
const std::list<Command> basic_cmds =
{
    Command(std::string("add"), [](std::string args, std::vector<Note>* notes)
    { 
        emptyCheck(args);

        notes->emplace_back(Note(args));

        std::cout << "Added" << std::endl;
    }),
    Command(std::string("rm"), [](std::string args, std::vector<Note>* notes)
    {
        emptyCheck(args);

        int index = std::stoi(args);
        notes->erase(notes->begin() + index);

        std::cout << "Removed" << std::endl;
    }),
    Command(std::string("show"), [](std::string args, std::vector<Note>* notes)
    {

        std::cout << "    MY TODO LIST" << std::endl;
        RENDER_LINE();

        for (Note note : *notes)
        {
            std::cout << note.msg() << std::endl;
            RENDER_LINE();
        }
    })
};