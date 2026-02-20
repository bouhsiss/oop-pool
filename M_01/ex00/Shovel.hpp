#ifndef SHOVEL_HPP
#define SHOVEL_HPP

#include "Tool.hpp"


class Shovel : public Tool {
    public:
        Shovel();
        virtual ~Shovel();

        virtual void use();
};

#endif