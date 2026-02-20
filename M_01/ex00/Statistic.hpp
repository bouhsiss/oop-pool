#ifndef STATISTIC_HPP
#define STATISTIC_HPP

#include <iostream>

struct Statistic {
    int level;
    int exp;

    Statistic();
    Statistic(int level, int exp);
    ~Statistic();
};

#endif