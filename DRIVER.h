//
// Created by User on 2019-03-13.
//

#ifndef C_PROJECT_DRIVER_H
#define C_PROJECT_DRIVER_H

#include <iostream>
#include <list>
#include <thread>
#include "PCB.h"
#include "LOADER.h"
#include "LONG_TERM_SCHEDULER.h"
#include "SHORT_TERM_SCHEDULER.h"
#include "CPU.h"
#include "DISPATCHER.h"

namespace Project_Phase_One{

    class DRIVER {
    private:
        // Mark: Software
        LOADER load;
        LONG_TERM_SCHEDULER longTerm;
        SHORT_TERM_SCHEDULER shortTerm;
        DISPATCHER switcher;

        std::list<Project_Phase_One::PCB> PCBInDISK;
        std::list<Project_Phase_One::PCB> PCBInRAM;
        std::list<Project_Phase_One::PCB> ready_queue;
        std::list<Project_Phase_One::PCB> wait_queue;
        // Mark: Hardware
        std::string RAM[1024];
        std::string DISK[2048];
        CPU cpu;
    public:
        DRIVER();
        void RUN();
        void dumpRAM();

    };

}

#endif //C_PROJECT_DRIVER_H
