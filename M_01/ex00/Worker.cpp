#include "Worker.hpp"

Worker::Worker(): shovel(NULL) {
    std::cout << "Worker default constructor called" << std::endl;
}

Worker::Worker(const Position& position, const Statistic& statistic) : coordonnee(position), stat(statistic), shovel(NULL) {
    std::cout << "Worker parameterized constructor called" << std::endl;
}

Worker::~Worker() {
    std::cout << "Worker destructor called" << std::endl;
}

void Worker::print() const {
	std::cout << "Worker Position: (" 
            << coordonnee.x << ", " 
            << coordonnee.y << ", " 
            << coordonnee.z << ")" 
            << std::endl;
    
    std::cout << "Worker Statistic: level="
            << stat.level << ", exp="
            << stat.exp << std::endl;
}

void Worker::giveShovel(Shovel* newShovel) {
    if(!newShovel) {
        std::cout << "Shovel is NULL" << std::endl;
        return;
    }

    if(shovel == newShovel) {
        std::cout << "Shovel is already owned by this worker" << std::endl;
        return;
    }

    Worker* oldOwner = newShovel->getOwner();
    if(oldOwner && oldOwner != this) {
        oldOwner->takeShovel();
    }

    if (shovel) {
        shovel->setOwner(NULL);
    }

    shovel = newShovel;
    shovel->setOwner(this);

    std::cout << "Shovel given to worker" << std::endl;
}

void Worker::takeShovel() {
    if(!shovel) {
        std::cout << "Worker has no shovel to give away" << std::endl;
        return;
    }

    shovel->setOwner(NULL);
    shovel = NULL;

    std::cout << "Worker gave away the shovel" << std::endl;
}

void Worker::useShovel() const {
    if(!shovel) {
        std::cout << "Worker has no shovel to use" << std::endl;
        return;
    }

    shovel->use();
}