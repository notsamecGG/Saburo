#pragma once
#include <string>

/**
 * @brief Storage object
 * 
 */
class Note
{
public:
    Note(const int& cost, const std::string& msg) : m_cost(cost), m_msg(msg) { }

    int cost() { return m_cost; }
    std::string msg() { return m_msg; }

private:
    int m_cost;
    std::string m_msg;
};