//
// Created by User on 2019-03-10.
//

#ifndef C_PROJECT_ADD_PCB_TO_QUEUE_H
#define C_PROJECT_ADD_PCB_TO_QUEUE_H

#include <iostream>
#include <list>
#include "PCB.h"
namespace Project_Phase_One {

    class ADD_PCB_TO_QUEUE {
    private:
        // The Queues
        std::list<PCB> diskList;
        std::list<PCB> readyQueue;
        std::list<PCB> waitQueue;
        // The Current
        int diskCurrent = 0;
        int readyCurrent = 0;
        int waitCurrent = 0;

    public:

        void addToDiskList(PCB job);
        void addToReadyQueue(PCB job);
        void addToWaitQueue(PCB job);
        std::list<Project_Phase_One::PCB>::iterator getDiskListCurrentPCB();
        std::list<PCB> getDiskList();
        std::list<PCB> getReadyQueue();
        std::list<PCB> getWaitQueue();

    };
}

#endif //C_PROJECT_ADD_PCB_TO_QUEUE_H
