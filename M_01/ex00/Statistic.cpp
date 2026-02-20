#include "Statistic.hpp"

Statistic::Statistic() : level(0), exp(0) {
    std::cout << "Statistic default constructor called" << std::endl;
}
Statistic::Statistic(int level, int exp) : level(level), exp(exp) {
    std::cout << "Statistic parameterized constructor called" << std::endl;
}
Statistic::~Statistic() {
    std::cout << "Statistic destructor called" << std::endl;
}