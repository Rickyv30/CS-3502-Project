//
// Created by User on 2019-03-08.
//

#include "PCB.h"
#include <iostream>

namespace Project_Phase_One {
    // GETTER
    bool PCB::getIsIO(){return isIO; }
    int PCB::get_CUP_ID(){return cupID; }
    int PCB::getProgramCounter(){return programCounter; }
    int PCB::getCodeSize(){return codeSize; }
    PCB::Process_States PCB::getProcessStatus(){return processStatus; }
    int PCB::getPriority(){return priority; }
    int* PCB::getRegisters(){return registers; }
    int PCB::getInputBuffer(){return inputBuffer;}
    int PCB::getOutputBuffer(){return outputBuffer;}
    int PCB::getBurstTIme(){return burstTime; }
    int PCB::getTimeSlice(){return timeSlice; }
    int PCB::getTimeRemaining(){return timeRemaining; }
    std::string PCB::getQueueType(){return queueType; }
    int PCB::getPageTableBase(){return pageTableBase; }
    int PCB::getPages(){return pages; }
    int PCB::getPageSize(){return pageSize; }
    int PCB::getChildProcessID(){return childProcessID; }
    PCB* PCB::getChildLeft(){return childLeft_ptr; }
    PCB* PCB::getChildRight(){return childRight_ptr; }
    PCB* PCB::getParent(){return parent_ptr; }
    int* PCB::getCache(){return cache; }
    //SETTER
    void PCB::setIsIO(){this->isIO = isIO; }
    void PCB::set_CUP_ID(int cupID){this->cupID = cupID; }
    void PCB::setProgramCounter(int programCounter){this->programCounter = programCounter; }
    void PCB::setCodeSize(int codeSize){this->codeSize = codeSize; }
    void PCB::setProcessStatus(Process_States processStatus){this->processStatus = processStatus; }
    void PCB::setPriority(int priority){this->priority = priority; }
    void PCB::setInputBuffer(int inputBuffer){this->inputBuffer = inputBuffer;}
    void PCB::setOutputBuffer(int outputBuffer){this->outputBuffer = outputBuffer; }
    void PCB::setBurstTIme(int burstTime){this->burstTime = burstTime; }
    void PCB::setTimeSlice(int timeSlice){this->timeSlice = timeSlice; }
    void PCB::setTimeRemaining(int timeRemaining){this->timeRemaining = timeRemaining; }
    void PCB::setQueueType(std::string queueType){this->queueType = queueType; }
    void PCB::setPageTableBase(int pageTableBase){this->pageTableBase = pageTableBase; }
    void PCB::setPages(int pages){this->pages = pages; }
    void PCB::setPageSize(int pageSize){this->pageSize = pageSize; }
    void PCB::setChildProcessID(int childProcessID){this->childProcessID = childProcessID; }
    void PCB::setChildCodePointerLeft(PCB* childLeft_ptr){this->childLeft_ptr = childLeft_ptr; }
    void PCB::setChildCodePointerRight(PCB* childRight_ptr){this->childRight_ptr = childRight_ptr; }
    void PCB::setParent(PCB* parent_ptr){this->parent_ptr = parent_ptr; }

}