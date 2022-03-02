#pragma once
#include <string>

#include "../core/inote.hpp"


/**
 * @brief Storage object
 * 
 */
class Note : public INote
{
public:
    Note(const std::string& msg) : m_msg(msg) { }

    std::string msg() { return m_msg; }

private:
    std::string m_msg;
};