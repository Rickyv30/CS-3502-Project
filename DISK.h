//
// Created by User on 2019-03-11.
//

#ifndef C_PROJECT_DISK_H
#define C_PROJECT_DISK_H

#include <iostream>
#include <list>
#include "PCB.h"

namespace Project_Phase_One {
    class DISK {
    public:

        void writePCBToDisk(PCB process);

        auto removePCBFromDisk(int index);

        void writeToDisk(int index, std::string entry);

        std::string pReader(int index, int size, std::string instructions);

        std::string readFromDisk(int index);

        PCB* getCurrentPCBFromRam(int PCBPositionInDisk);

        std::list<PCB>::iterator getDiskIterator();

    private:
        std::string instructions[4096];
        // This to add the PCB into disk.
        std::list<PCB> diskList;


    };

}
#endif //C_PROJECT_DISK_H
