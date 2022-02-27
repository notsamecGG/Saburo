#pragma once
#include <string>
#include <chrono>
#include <ctime>


std::time_t get_now()
{
    return std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
}

/**
 * @brief Storage object
 * 
 */
class Note
{
public:
    Note(const int& weight) : m_weight(weight) 
    { 
        std::time_t t = get_now();
        m_date = std::ctime(&t);
    }

    Note(const int& weight, const std::string& date) : m_weight(weight), m_date(date) { }

    int weight() { return m_weight; }
    std::string date() { return m_date; }

private:
    int m_weight;
    std::string m_date;
};