//
// Created by User on 2019-03-08.
//

#ifndef C_PROJECT_CPU_H
#define C_PROJECT_CPU_H

#include <iostream>
#include <chrono>
#include <ctime>
#include <thread>
#include <mutex>
#include <algorithm>
#include <fstream>
#include "LOADER.h"
#include "DISK.h"
#include "PCB.h"
#include "RAM.h"


namespace Project_Phase_One {
    enum ProcessorState{IDLE, UNLOADING, LOADING, EXECUTING};
    class CPU {
    private:
        int testing = 0;
        // The Jobs.
        int jobNumber, jobCounter, dataAddress;

        // There's 16 registers.
        std::array<int, 16> registers;

        // These will be the registers for execution.
        int s_reg1, s_reg2, d_reg, b_reg, reg1, reg2, instuctionAddress;

        // The buffers.
        int inputBuffer, outputBuffer, tempBuffer;

        // The cache.
        int cacheSize;
        std::array<std::string, 1024> cache;
        // The time spent one the CPU.
        int startTime, endTime, totalTime = 0;
        // The Instructions.
        int opCode;
        std::string* instructionCache;
        int programCounter;
        int ioCount;
        ProcessorState processorState;
        int cpuID;
        Project_Phase_One::Process_States processStates;
        bool isIO;
        std::ofstream myfile();
    public:
        CPU();
        void loadProcess(Project_Phase_One::PCB process, Project_Phase_One::RAM ram);
        void unloadProcess(Project_Phase_One::PCB process);
        void executeProcess();
        void runProcess();
        std::string fetchInstruction(int programCounter);
        void decode(std::string instruction);
        void setRegisters(std::string opCode);
        std::string hexToBinary(std::string hex);

        //MARK: Setter
        void setJobNumber(const int jobNumber){ this->jobNumber = jobNumber; }
        void setJobCounter(const int jobCounter){ this->jobCounter = jobCounter; }
        void setInputBuffer(const int inputBuffer){ this->inputBuffer = inputBuffer; }
        void setOutputBuffer(const int outputBuffer){ this->outputBuffer = outputBuffer; }
        void setTempBuffer(const int tempBuffer){ this->tempBuffer = tempBuffer; }
        void setRegister(const std::array<int, 16> registers){this->registers = registers; }
        void setProcessorState( ProcessorState processorState){ this->processorState = processorState; }


        //MARK: Getter
        int getJobNumber(){ return jobNumber; }
        int getJobCounter(){ return jobCounter; }
        int getInputBuffer(){ return inputBuffer; }
        int getOutputBuffer(){ return outputBuffer; }
        int getTempBuffer(){ return tempBuffer; }
        std::array<int, 16> getRegister(){ return registers; }
        ProcessorState getProcessorState(){ return processorState; }

    };

}

#endif //C_PROJECT_CPU_H
