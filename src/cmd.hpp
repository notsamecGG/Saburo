#pragma once

#include "common.hpp"


// typedef std::tuple<int, std::string> arg_t;
typedef std::function<void(std::any)> callback_t;

/**
 * @brief Default command type
 * 
 */
struct Command
{
    std::string name;

public:
    Command(std::string& a_name, callback_t& callback) : m_callback(callback), name(a_name) { }
    void execute(std::any& args) { m_callback(args); }

private:
    callback_t m_callback;
};

