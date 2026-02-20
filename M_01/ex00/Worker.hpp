#ifndef WORKER_HPP
#define WORKER_HPP

#include "Position.hpp"
#include "Statistic.hpp"
#include "Tool.hpp"
#include <iostream>
#include <vector>

class Worker {
    private:
        Position coordonnee;
        Statistic stat;
        std::vector<Tool*> tools;

    public:
        Worker();
        Worker(const Position& position, const Statistic& statistic);
        ~Worker();

        void addTool(Tool* tool);
        void removeTool(Tool* tool);
        void useTools() const;


        void print() const;
};

#endif