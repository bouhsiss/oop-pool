#include "Workshop.hpp"
#include "Worker.hpp"

Workshop::Workshop() {
    std::cout << "Workshop constructor called" << std::endl;
}

Workshop::~Workshop() {
    std::cout << "Workshop destructor called" << std::endl;
}

void Workshop::registerWorker(Worker  *worker) {
    if(!worker) {
        std::cout << "Workshop: cannot register NULL worker" << std::endl;
        return;
    }

    for (std::vector<Worker*>::iterator it = workers.begin(); it != workers.end(); ++it) {
        if (*it == worker) {
            std::cout << "Workshop: worker already registered" << std::endl;
            return;
        }
    }

    workers.push_back(worker);
    worker->onRegisteredToWorkshop(this);

    std::cout << "Workshop: worker registered" << std::endl;
}

void Workshop::releaseWorker(Worker *worker) {
    if (!worker) {
        std::cout << "Workshop: cannot release NULL worker" << std::endl;
        return;
    }

    for (std::vector<Worker*>::iterator it = workers.begin(); it != workers.end(); ++it) {
        if (*it == worker) {
            workers.erase(it);
            worker->onUnregisteredFromWorkshop(this);
            std::cout << "Workshop: worker released" << std::endl;
            return;
        }
    }

    std::cout << "Workshop: worker not found" << std::endl;
}

void Workshop::executeWorkDay() {
    std::cout << "Workshop: executing work day with " << workers.size() << " workers" << std::endl;

    for (size_t i = 0; i < workers.size(); ++i) {
        workers[i]->work();
    }
}