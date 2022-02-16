#pragma once

#include "common.hpp"
#include "cmd.hpp"


std::list<Command> basic_cmds =
{
    Command(std::string("add"), [&](std::any x){ std::cout << "add" << std::endl; }),
    Command(std::string("rm"), [&](std::any x){ std::cout << "rm" << std::endl; }),
    Command(std::string("show"), [&](std::any x){ std::cout << "show" << std::endl; })
};