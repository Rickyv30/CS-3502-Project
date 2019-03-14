//
// Created by User on 2019-03-11.
//

#ifndef C_PROJECT_LONG_TERM_SCHEDULER_H
#define C_PROJECT_LONG_TERM_SCHEDULER_H
#include <iostream>
#include "DISK.h"
#include "RAM.h"
#include "LOADER.h"


namespace Project_Phase_One {

    class LONG_TERM_SCHEDULER {
        bool isRamFull = false;
        RAM ram;

    public:
        void fromDiskToRam(PCB process, DISK disk);
        RAM getRam();
    };

}
#endif //C_PROJECT_LONG_TERM_SCHEDULER_H
