#ifndef WORKSHOP_HPP
#define WORKSHOP_HPP

#include <iostream>
#include <vector>

class Worker;

class Workshop {
    private:
        std::vector<Worker*> workers;
    public:
        Workshop();
        ~Workshop();

        void registerWorker(Worker* worker);
        void releaseWorker(Worker* worker);

        void executeWorkDay();
};

#endif