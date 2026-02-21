#include "Worker.hpp"
#include "Workshop.hpp"

Worker::Worker() {
    std::cout << "Worker default constructor called" << std::endl;
}

Worker::Worker(const Position& position, const Statistic& statistic) : coordonnee(position), stat(statistic) {
    std::cout << "Worker parameterized constructor called" << std::endl;
}

Worker::~Worker() {
    std::cout << "Worker destructor called" << std::endl;
}

void Worker::addTool(Tool* tool) {
    if(!tool) {
        std::cout << "addTool: NULL tool ignored" << std::endl;
        return;
    }

    Worker *oldOwner = tool->getOwner();
    if(oldOwner && oldOwner != this) {
        oldOwner->removeTool(tool);
    }

    for(std::vector<Tool*>::iterator it = tools.begin(); it != tools.end(); ++it) {
        if(*it == tool) {
            std::cout << "addTool: too already in this worker" << std::endl;
            return;
        }
    }

    tools.push_back(tool);
    tool->setOwner(this);
    std::cout << "Tool added to worker" << std::endl;
}

void Worker::removeTool(Tool* tool) {
    if(!tool) {
        std::cout << "removeTool: NULL tool ignored" << std::endl;
        return;
    }

    for(std::vector<Tool*>::iterator it = tools.begin(); it != tools.end(); ++it) {
        if(*it == tool) {
            tool->setOwner(NULL);
            tools.erase(it);
            std::cout << "Tool removed from worker" << std::endl;
            return;
        }
    }
}

void Worker::useTools() const {
    if(tools.empty()) {
        std::cout << "Worker has no tools to use" << std::endl;
        return;
    }

    for (size_t i = 0; i < tools.size(); ++i) {
        tools[i]->use();
    }
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

void Worker::joinWorkshop(Workshop *ws) {
    if (!ws) {
        std::cout << "Worker: cannot join NULL workshop" << std::endl;
        return;
    }
    ws->registerWorker(this);
}

void Worker::leaveWorkshop(Workshop *ws) {
    if (!ws) {
        std::cout << "Worker: cannot leave NULL workshop" << std::endl;
        return;
    }
    ws->releaseWorker(this);
}

void Worker::onRegisteredToWorkshop(Workshop *ws) {
    for(std::vector<Workshop*>::iterator it = workshops.begin(); it != workshops.end(); ++it) {
        if(*it == ws) {
            return;
        }
    }
    workshops.push_back(ws);
}

void Worker::onUnregisteredFromWorkshop(Workshop *ws) {
    for(std::vector<Workshop*>::iterator it = workshops.begin(); it != workshops.end(); ++it) {
        if(*it == ws) {
            workshops.erase(it);
            return;
        }
    }
}

void Worker::work()
{
    if (workshops.empty()) {
        std::cout << "Worker: not registered to any workshop, cannot work" << std::endl;
        return;
    }
    std::cout << "Worker: working" << std::endl;
}