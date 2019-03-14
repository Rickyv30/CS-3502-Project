//
// Created by User on 2019-03-11.
//

#ifndef C_PROJECT_RAM_H
#define C_PROJECT_RAM_H
#include <iostream>
#include <cassert>
#include <list>
#include <array>
#include "PCB.h"
#include "DISK.h"
#include "LOADER.h"

namespace Project_Phase_One {

    class RAM {
    private:
        LOADER load;
        int ramCount = 0, freeFrameStart = 0, freeFameEnd = 1024;
        const int ramSize = 1024;
        std::string ram[1024], empty = "EMPTY";
        std::list<Project_Phase_One::PCB> readyQueue;
    public:

        RAM();

        void ramWipe();

        bool ramIsFull();

        void deallocateRam(const int start, const int end);

        void writeToRAM(const int index, const std::string entry);

        bool addPCBToRam(Project_Phase_One::PCB process);

        Project_Phase_One::PCB getPCBFromRAM(const int index);

        std::list<Project_Phase_One::PCB> getReadyQueue();

        std::string readFromRAM(const int index);

        void testRam();

    };

}

#endif //C_PROJECT_RAM_H
