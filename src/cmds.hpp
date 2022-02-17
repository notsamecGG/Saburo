#pragma once

#include "common.hpp"
#include "cmd.hpp"


const std::list<Command> basic_cmds =
{
    Command(std::string("add"), [](std::string args, std::vector<Note>* notes)
    { 

        notes->emplace_back(Note(args));
        std::cout << notes->size();
        std::cout << "add" << std::endl; 
    }),
    Command(std::string("rm"), [](std::string args, std::vector<Note>* notes)
    {
        std::cout << "rm" << std::endl; 
    }),
    Command(std::string("show"), [](std::string args, std::vector<Note>* notes)
    { 
        std::cout << "show" << std::endl; 
    })
};