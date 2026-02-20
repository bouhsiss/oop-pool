#ifndef HAMMER_HPP
#define HAMMER_HPP

#include "Tool.hpp"

class Hammer : public Tool {
    public:
        Hammer();
        virtual ~Hammer();

        virtual void use();
};

#endif