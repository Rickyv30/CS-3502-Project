//
// Created by User on 2019-03-11.
//

#include "RAM.h"
#include <iostream>

Project_Phase_One::RAM::RAM(){
    for(int i = 0; i < ramSize; i++)
        ram[i] = empty;

}

std::string Project_Phase_One::RAM::readFromRAM(int index) {

    if((index >= ramSize) || (0 > index))
        std::cout<<"This index does not exist in RAM."<<std::endl;
    else if(ram[index].find(empty) != std::string::npos)
        std::cout<<"this index is not is "<<empty<<std::endl;
    else
        return ram[index];
}

void Project_Phase_One::RAM::writeToRAM(int index, std::string entry) {

    if(!ramIsFull() && (ram[index].find(empty) != std::string::npos)) {
        ram[index] = entry;
        ramCount++;
    }
    else
        std::cout<<"Ram is full."<<std::endl;

}

void Project_Phase_One::RAM::addPCBToRam(Project_Phase_One::PCB process) {

    process.setProcessStatus(READY);
    int loadAmount = process.getInputBuffer()+
                     process.getOutputBuffer()+
                     process.getTempBuffer()+
                     process.getNumberOfInstructions();

    if((loadAmount+ramCount) <= ramSize){
        for(int i = process.getDataDiskLocation(); i < loadAmount; i++){
            ram[ramCount] = disk.readFromDisk(i);
        }
    } else std::cout<<"This list is full, begin execution."<<std::endl;


}

Project_Phase_One::PCB Project_Phase_One::RAM::getPCBFromRAM(int index) {

    auto it = readyQueue.begin();
    std::advance(it, index);

    return *it;

}

void Project_Phase_One::RAM::allocateRam(int start, int end) {
    for(int i = start; i < end; i++)
        ram[i] = empty;

}

bool Project_Phase_One::RAM::ramIsFull() {
    if (ramCount >= ramSize)
        return true;
    else return false;

}

