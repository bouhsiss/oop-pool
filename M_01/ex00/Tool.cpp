#include "Tool.hpp"

Tool::Tool() : numberOfUses(0), owner(NULL) {
    std::cout << "Tool default constructor called" << std::endl;
}

Tool::~Tool() {
    std::cout << "Tool destructor called" << std::endl;
}

Worker* Tool::getOwner() const { return owner; }

void Tool::setOwner(Worker* newOwner) { owner = newOwner; }