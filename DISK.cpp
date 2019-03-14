//
// Created by User on 2019-03-11.
//

#include "DISK.h"
#include <cassert>
namespace Project_Phase_One{

    DISK::DISK() {
        for (int i=0; i< diskSize; i++){
            disk[i] = empty;
        }

    }

    void DISK::writePCBToDisk(Project_Phase_One::PCB process) {
        diskList.push_back(process);
    }

    auto DISK::removePCBFromDisk(const int index) {
        std::list<PCB>::iterator it = diskList.begin();
        std::advance(it, index);
        it = diskList.erase(it);
        return it;
    }

    std::string DISK::readFromDisk(const int index){
        if((index >= diskSize) || (0 > index)){
            std::cout<<"Index does not exist in this disk."<<std::endl;

        }else if (disk[index].find(empty) != std::string::npos){
            std::cout<<"This box is empty."<<std::endl;

        }else{
            return disk[index];

        }
    }

    std::string DISK:: pReader(int index,int size,std::string instructions){
        std::string temp [size];
        for(int i = 0; i < size;i++) {
            temp[i] = instructions[index];
            index++;
        }
        return *temp;
    }

    void DISK::writeToDisk(const int index, const std::string entry) {
        if((index >= diskSize) || (0 > index)){
            std::cout<<"Index does not exist in this disk."<<std::endl;

        }else if (disk[index].find(empty) == std::string::npos){
            std::cout<<"This index is already in use."<<std::endl;

        }else{
            disk[index] = entry;
            diskCounter++;
        }
    }

    PCB DISK::getCurrentPCBFromDisk(const int PCBPositionInDisk) {
        auto it = diskList.begin();
        std::advance(it, PCBPositionInDisk);
        return (*it);
    }

    std::list<PCB>::iterator DISK::getDiskIterator() {
        std::list<PCB>::iterator it = diskList.begin();
        return it;

    }

}