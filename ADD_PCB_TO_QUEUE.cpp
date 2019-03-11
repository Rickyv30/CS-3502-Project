//
// Created by User on 2019-03-10.
//

#include "ADD_PCB_TO_QUEUE.h"
#include <iostream>

namespace Project_Phase_One{
    void ADD_PCB_TO_QUEUE::addToDiskList(Project_Phase_One::PCB job) {
        diskList.push_back(job);
    }

    void ADD_PCB_TO_QUEUE::addToReadyQueue(Project_Phase_One::PCB job) {
        readyQueue.push_back(job);
    }

    void ADD_PCB_TO_QUEUE::addToWaitQueue(Project_Phase_One::PCB job) {
        waitQueue.push_back(job);
    }

    std::list<PCB>::iterator ADD_PCB_TO_QUEUE::getDiskListCurrentPCB() {
        std::list<PCB>::iterator it = diskList.begin();
        return it;
    }

std::list<PCB> ADD_PCB_TO_QUEUE::getDiskList() {
        return this->diskList;

    }

    std::list<PCB> ADD_PCB_TO_QUEUE::getReadyQueue() {
        return this->readyQueue;

    }
    std::list<PCB> ADD_PCB_TO_QUEUE::getWaitQueue() {
        return this->waitQueue;

    }
}

