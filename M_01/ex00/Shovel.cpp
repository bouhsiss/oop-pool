#include "Shovel.hpp"

Shovel::Shovel() : numberOfUses(0), owner(NULL) {
    std::cout << "Shovel default constructor called" << std::endl;
}

Shovel::~Shovel() {
    std::cout << "Shovel destructor called" << std::endl;
}

void Shovel::use() {
    numberOfUses++;
    std::cout << "Shovel used " << numberOfUses << " times" << std::endl;
}