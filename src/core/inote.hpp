#pragma once
#include <sstream>

/**
 * @brief Note Interface
 * 
 */
class INote
{
public:
    virtual std::string stringify() const = 0;
    virtual std::string load(std::stringstream& ss) = 0;
};
