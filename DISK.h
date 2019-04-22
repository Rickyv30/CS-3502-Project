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
        DISK();

        void writePCBToDisk(const PCB process);

        auto removePCBFromDisk(const int index);

        void writeToDisk(const int index, const std::string entry);

        std::string pReader(int index, int size, std::string instructions);

        std::string readFromDisk(const int index);

        PCB getCurrentPCBFromDisk(const int PCBPositionInDisk);

        std::list<PCB> getDiskList();

    private:
        // Disk management
        std::string empty = "EMPTY";
        const int diskSize = 4096;
        int diskCounter = 0;
        // Disk
        std::string disk[4096];
        // This to add the PCB into disk.
        std::list<PCB> diskList;


    };

}
#endif //C_PROJECT_DISK_H
