#include "Position.hpp"

Position::Position() : x(0), y(0), z(0) {
    std::cout << "Position default constructor called" << std::endl;
}
Position::Position(int x, int y, int z) : x(x), y(y), z(z) {
    std::cout << "Position parameterized constructor called" << std::endl;
}
Position::~Position() {
    std::cout << "Position destructor called" << std::endl;
}