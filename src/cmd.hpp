#pragma once

#include "common.hpp"
#include "note.hpp"


// typedef std::tuple<int, std::string> arg_t;
typedef std::function<void(std::any, std::weak_ptr<std::vector<Note>>)> callback_t;

/**
 * @brief Default command type
 * 
 */
struct Command
{
    std::string name;

public:
    Command(const std::string a_name, const callback_t callback) : m_callback(callback), name(a_name) { }
    
    void execute(const std::any args, std::weak_ptr<std::vector<Note>> notes) { m_callback(args, notes); }

private:
    callback_t m_callback;
};

