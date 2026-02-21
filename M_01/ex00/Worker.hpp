#ifndef WORKER_HPP
#define WORKER_HPP

#include "Position.hpp"
#include "Statistic.hpp"
#include "Tool.hpp"
#include <iostream>
#include <vector>

class Workshop;

class Worker {
    private:
        Position coordonnee;
        Statistic stat;

        std::vector<Tool*> tools;
        std::vector<Workshop*> workshops;
    public:
        Worker();
        Worker(const Position& position, const Statistic& statistic);
        ~Worker();

        void addTool(Tool* tool);
        void removeTool(Tool* tool);
        void useTools() const;

        void joinWorkshop(Workshop* workshop);
        void leaveWorkshop(Workshop* workshop);

        void onRegisteredToWorkshop(Workshop* workshop);
        void onUnregisteredFromWorkshop(Workshop* workshop);

        void work();

        void print() const;
};

#endif