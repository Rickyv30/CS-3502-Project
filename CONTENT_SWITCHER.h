//
// Created by User on 2019-04-16.
//

#ifndef C_PROJECT_CONTENT_SWITCHER_H
#define C_PROJECT_CONTENT_SWITCHER_H
#include <iostream>
#include <list>
#include "PCB.h"
#include "CPU.h"

namespace Project_Phase_One{

    class CONTENT_SWITCHER {
    public:
        void loadPCBToCPU(std::list<Project_Phase_One::PCB> *ready_queue, CPU *cpu);
        void unloadPCBFromCPU(std::list<Project_Phase_One::PCB> *wait_queue, CPU *cpu);
    private:
    };


}


#endif //C_PROJECT_CONTENT_SWITCHER_H
