//
// Created by User on 2019-03-11.
//

#include "RAM.h"
#include <iostream>

Project_Phase_One::RAM::RAM(){
    for(int i = 0; i < ramSize; i++) {
        ram[i] = empty;
    }
}

void Project_Phase_One::RAM::ramWipe() {
    for (int i = 0; i < ramSize; ++i) {
        ram[i] = empty;
    }
    ramCount=0;
    readyQueue.clear();

}

std::string Project_Phase_One::RAM::readFromRAM(int index) {

    if((index >= ramSize) || (0 > index))
        std::cout<<index<<" index does not exist in RAM."<<std::endl;
    else if(ram[index].find(empty) != std::string::npos)
        std::cout<<"this index is not is "<<empty<<std::endl;
    else
        return ram[index];
}

void Project_Phase_One::RAM::writeToRAM(int index, std::string entry) {
    //int freeSpace =
    if(!ramIsFull() && (ram[index].find(empty) != std::string::npos)) {
        ram[index] = entry;
        ramCount++;
        //std::cout<<"ramCount"<<ramCount<<std::endl;
    }
    //else
        //std::cout<<ramCount<<" Ram is full."<<std::endl;

}

 void Project_Phase_One::RAM::addPCBToRam(Project_Phase_One::PCB process) {

    /*std::cout<<"======adding PCB # "<<process.getJobNumber()
             <<"\ninput: "<<process.getInputBuffer()
             <<"\noutput: "<<process.getOutputBuffer()
             <<"\ntemp: "<<process.getTempBuffer()
             <<"\nnumber of instuctions: "<<process.getNumberOfInstructions()<<std::endl;*/

    process.setProcessStatus(READY);
    int loadAmount = process.getInputBuffer()+
                     process.getOutputBuffer()+
                     process.getTempBuffer()+
                     process.getNumberOfInstructions();
    //std::cout<<"this is the ram "<<loadAmount<<" + "<<ramCount<<" <= "<<ramSize<<std::endl;
    if((loadAmount+ramCount) <= ramSize){
        process.setJobRamLocation(process.getJobDiskLocation());
        readyQueue.push_back(process);
    }


}

Project_Phase_One::PCB Project_Phase_One::RAM::getPCBFromRAM(int index) {

    auto it = readyQueue.begin();
    std::advance(it, index);

    return *it;

}

std::list<Project_Phase_One::PCB> Project_Phase_One::RAM::getReadyQueue() {
    return readyQueue;

}

void Project_Phase_One::RAM::deallocateRam(int start, int end) {

    for(int i = start; i < end; i++){
        ram[i] = empty;
        ramCount--;
    }

}

bool Project_Phase_One::RAM::ramIsFull() {
    if (ramCount >= ramSize)
        return true;
    else return false;

}

int Project_Phase_One::RAM::getRamSize() {
    return ramSize;
}

int Project_Phase_One::RAM::getRamCount() {
    return ramCount;
}

void Project_Phase_One::RAM::testRam() {
    for(int i =0; i< ramSize; i++)
        std::cout<<"ram["<<i<<"] = "<<ram[i]<<std::endl;

}

