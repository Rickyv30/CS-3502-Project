//
// Created by User on 2019-03-08.
//

#include "PCB.h"
#include <iostream>

namespace Project_Phase_One {
    // CONSTRUCTOR
    PCB::PCB(int jobNumber, int priority, int numberOfInstrucions, int jobDiskLocation) {
        this->jobNumber = jobNumber;
        this->priority = priority;
        this->numberOfInstructions = numberOfInstrucions;
        this->jobDiskLocation = jobDiskLocation;
        registers[1] = 0;
        processStatus = NEW;

    }
    PCB::PCB(){


    }
    // GETTER
    bool PCB::getIsIO(){return isIO; }
    int PCB::get_CPU_ID(){return cpuID; }
    int PCB::getProgramCounter(){return programCounter; }
    int PCB::getJobDiskLocation() {return jobDiskLocation; }
    int PCB::getJobNumber() {return jobNumber; }
    int PCB::getNumberOfInstructions() {return numberOfInstructions; }
    int PCB::getCodeSize(){return codeSize; }
    Project_Phase_One::Process_States PCB::getProcessStatus(){return processStatus; }
    int PCB::getPriority(){return priority; }
    int* PCB::getRegisters(){return registers; }
    int PCB::getDataDiskLocation() {return dataDiskLocation; }
    int PCB::getInputBuffer(){return inputBuffer;}
    int PCB::getOutputBuffer(){return outputBuffer;}
    int PCB::getTempBuffer() {return tempBuffer; }
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
    std::string* PCB::getCache(){return cache; }
    //SETTER
    void PCB::setIsIO(bool isIO){this->isIO = isIO; }
    void PCB::set_CPU_ID(int cpuID){this->cpuID = cpuID; }
    void PCB::setRegisters(int registers[]) {
        for(int i = 0; i< 16; i++)
        this->registers[i] = registers[i];
    }
    void PCB::setProgramCounter(int programCounter){this->programCounter = programCounter; }
    void PCB::setJobNumber(int jobNumber) {this->jobNumber = jobNumber;}
    void PCB::setNumberOfInstructions(int numberOfInstructions) {this->numberOfJobs = numberOfInstructions; }
    void PCB::setCodeSize(int codeSize){this->codeSize = codeSize; }
    void PCB::setProcessStatus(Process_States processStatus){this->processStatus = processStatus; }
    void PCB::setPriority(int priority){this->priority = priority; }
    void PCB::setDataDiskLocation(int dataDiskLocation) {this->dataDiskLocation = dataDiskLocation;}
    void PCB::setInputBuffer(int inputBuffer){this->inputBuffer = inputBuffer;}
    void PCB::setOutputBuffer(int outputBuffer){this->outputBuffer = outputBuffer; }
    void PCB::setTempBuffer(int tempBuffer) {this->tempBuffer = tempBuffer;}
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
    void PCB::setCache(std::string cache[], int size) {
        cache = new std::string[size];
        for(int i=0; i<size; i++)
            this->cache[i] = cache[i];
    }

}