#pragma once

#include "../core/common.hpp"
#include "note.hpp"


struct Args
{
    Args(const std::string &args, std::vector<Note>* a_notes) : string(args), notes(a_notes) { } 

    std::string string;
    std::vector<Note>* notes;    
};