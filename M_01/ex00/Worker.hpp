#ifndef WORKER_HPP
#define WORKER_HPP

#include "Position.hpp"
#include "Statistic.hpp"
#include "Shovel.hpp"
#include <iostream>

class Worker {
    private:
        Position coordonnee;
        Statistic stat;
        Shovel* shovel;

    public:
        Worker();
        Worker(const Position& position, const Statistic& statistic);
        ~Worker();

        void giveShovel(Shovel* newShovel);
        void takeShovel();
        void useShovel() const;

        void print() const;
};

#endif