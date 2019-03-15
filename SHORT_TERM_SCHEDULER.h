//
// Created by User on 2019-03-13.
//

#ifndef C_PROJECT_SHORT_TERM_SCHEDULER_H
#define C_PROJECT_SHORT_TERM_SCHEDULER_H

#include <iostream>
#include "PCB.h"
#include "RAM.h"


namespace Project_Phase_One {
    class SHORT_TERM_SCHEDULER {
    private:
        /*
         * FIFO = First in First Out
         * SBTF = Shortest Burst Time First
         * PRIORITY = Highest priority first, the lower the number the higher the priority.
         * *
        enum Scheduler_Type {FIFO, SBTF, PRIORITY};
        Scheduler_Type schedule = FIFO; */
    public:


        PCB Dispatcher(RAM* ram,int index);
    };
}
#endif //C_PROJECT_SHORT_TERM_SCHEDULER_H