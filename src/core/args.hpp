#pragma once

#include "common.hpp"


template <typename NoteType>
struct Args
{
    Args(const std::string &args, std::vector<NoteType>* a_notes) : string(args), notes(a_notes) { } 

    std::string string;
    std::vector<NoteType>* notes;    
};