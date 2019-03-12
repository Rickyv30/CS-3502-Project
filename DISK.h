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

        void addPCBToDisk(PCB process);

        void writeToDisk(int index, std::string entry);

        std::string pReader(int index, int size, std::string instructions);

        std::string readFromDisk(int index);

        PCB getCurrentPCBFromRam(int PCBPositionInDisk);

        std::list<PCB>::iterator getDiskIterator();

    private:
        std::string instructions[2048];
        std::list<PCB> diskList;


    };

}
#endif //C_PROJECT_DISK_H
