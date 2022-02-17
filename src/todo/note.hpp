#pragma once
#include <string>

/**
 * @brief Struct for saving note data
 * 
 */
struct Note
{
public:
    Note(std::string& msg) { m_msg = msg; }

    std::string msg() { return m_msg; }

private:
    std::string m_msg;
};