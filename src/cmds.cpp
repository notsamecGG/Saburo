#include <iostream>

#define PRINT_NAME(x) const char* PrintName() override { return x; }

struct iCMD
{
    virtual const char* PrintName() = 0;
    virtual void Execute(const char* input) = 0;
};

struct Add : public iCMD 
{
    PRINT_NAME("add");

    void Execute(const char* input) override 
    { 
        std::cout << "Add" << std::endl; 
    }
};
struct Remove : public iCMD 
{
    PRINT_NAME("remove");

    void Execute(const char* input) override 
    { 
        std::cout << "Remove" << std::endl; 
    }
};
struct Show : public iCMD 
{ 
    PRINT_NAME("show");

    void Execute(const char* input) override 
    { 
        std::cout << "Show" << std::endl; 
    }
};
