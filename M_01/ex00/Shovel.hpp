#ifndef SHOVEL_HPP
#define SHOVEL_HPP

#include <iostream>

class Worker;

class Shovel {
    private:
        int numberOfUses;
        Worker* owner;
    
    public:
        Shovel();
        ~Shovel();

        void use();
        int getUses() const;

        Worker* getOwner() const;
        void setOwner(Worker* newOwner);
};

#endif