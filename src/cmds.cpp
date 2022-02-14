#include <iostream>
#include <vector>

#include "note.hpp"

#define RENDER_LINE() std::cout << "----------------------" << std::endl

struct CMDLine
{
    std::vector<Note> notes;

    void add(std::string input)
    {
        notes.push_back(Note(input));
        COUT("add " << input);
    }

    void rm(std::string input)
    {
        unsigned int index = std::stoi(input);

        if (index <= notes.size())
            notes.erase(notes.begin() + index);

        COUT("remove " << std::stoi(input));
    }

    // void finish(std::string input)
    // {
    //     std::cout << "finish " << std::stoi(input) << std::endl;
    // }

    void show(std::vector<Note>& notes)
    {
        std::cout << "    MY TODO LIST" << std::endl;
        RENDER_LINE();

        for (Note note : notes)
        {
            std::cout << note.msg() << std::endl;
            RENDER_LINE();
        }
        
        COUT("show");
    }
};
