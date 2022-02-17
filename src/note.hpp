#pragma once
#include <string>


struct Note
{
public:
    Note(std::string& msg) { m_msg = msg; }

    std::string msg() { return m_msg; }

private:
    std::string m_msg;
};