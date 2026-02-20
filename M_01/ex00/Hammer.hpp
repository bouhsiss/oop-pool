#ifndef HAMMER_HPP
#define HAMMER_HPP

#include "Tool.hpp"

class Hammer : public Tool {
    public:
        Hammer();
        ~Hammer();

        void use();
};

#endif