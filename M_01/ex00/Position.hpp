#ifndef POSITION_HPP
#define POSITION_HPP

#include <iostream>

struct Position {
    int x;
    int y;
    int z;

    Position();
    Position(int x, int y, int z);
    ~Position();
};

#endif