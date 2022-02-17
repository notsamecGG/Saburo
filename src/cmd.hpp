#pragma once

#include "common.hpp"


// typedef std::tuple<int, std::string> arg_t;
typedef std::function<void(std::string, std::vector<Note>*)> callback_t;

struct Command
{
    std::string name;

public:
    Command(const std::string& a_name, const callback_t& callback) : m_callback(callback), name(a_name) { }
    
    void execute(const std::string args, std::vector<Note>* notes) { m_callback(args, notes); }

private:
    callback_t m_callback;
};

