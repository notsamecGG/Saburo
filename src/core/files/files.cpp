#include <any>
#include <fstream>
#include <functional>
#include <iostream>
#include <list>
#include <stdexcept>
#include <string>
#include <sstream>
#include <memory>
#include <unordered_map>

#include "../inote.hpp"

template<typename T>
void read(const std::string& path, std::vector<T> const* out)
{
    //file man1 - reading
    // TODO: file is rewrtien down bellow
    std::fstream fs(path, std::fstream::in);
    std::string line;
    std::stringstream ss;

    int cost;
    std::string note;

    while (std::getline(fs, line))
    {
        ss = std::stringstream(line);

        ss >> cost >> note;

        notes->push_back(Note(cost, note));
    }

    fs.close();
}

void save_vector(const std::string& path, INote *vector)
{
    std::fstream fs(path, std::fstream::out /*| std::fstream::app*/);
    fs.open(path);

    for (INote note : *vector)
    {
        // COUT(note.msg());
        fs << note.cost() << " " << note.msg() << std::endl;
    }

    fs.close();
}