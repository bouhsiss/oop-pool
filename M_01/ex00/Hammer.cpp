#include "Hammer.hpp"

Hammer::Hammer()
{
    std::cout << "Hammer default constructor called" << std::endl;
}

Hammer::~Hammer()
{
    std::cout << "Hammer destructor called" << std::endl;
}

void Hammer::use()
{
    numberOfUses++;
    std::cout << "Hammer used " << numberOfUses << " times" << std::endl;
}