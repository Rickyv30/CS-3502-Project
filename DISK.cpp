//
// Created by User on 2019-03-11.
//

#include "DISK.h"
#include <cassert>
namespace Project_Phase_One{

    void DISK::addPCBToDisk(Project_Phase_One::PCB process) {
        diskList.push_back(process);
    }

    std::string DISK::readFromDisk(int index){
        return instructions[index];
    }

    std::string DISK:: pReader(int index,int size,std::string instructions){
        std::string temp [size];
        for(int i = 0; i < size;i++) {
            temp[i] = instructions[index];
            index++;
        }
        return *temp;
    }

    void DISK::writeToDisk(int index, std::string entry) {
        assert(entry != " ");
        instructions[index] = entry;
    }

    PCB DISK::getCurrentPCBFromRam(int PCBPositionInDisk) {
        std::list<PCB>::iterator it = diskList.begin();
        std::advance(it, PCBPositionInDisk);
        return *it;
    }

    std::list<PCB>::iterator DISK::getDiskIterator() {
        std::list<PCB>::iterator it = diskList.begin();
        return it;

    }

}