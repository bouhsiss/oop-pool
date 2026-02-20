#ifndef TOOL_HPP
#define TOOL_HPP

#include <iostream>

class Worker;

class Tool {
    protected:
        int numberOfUses;
        Worker* owner;

    public:
        Tool();
        virtual ~Tool();

        virtual void use() = 0;

        Worker* getOwner() const;
        void setOwner(Worker* newOwner);
};

#endif