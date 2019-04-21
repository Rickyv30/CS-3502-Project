//
// Created by User on 2019-04-16.
//

#include "CONTENT_SWITCHER.h"

namespace Project_Phase_One{
    void CONTENT_SWITCHER::loadPCBToCPU(std::list<Project_Phase_One::PCB> *ready_queue, CPU *cpu) {
        std::cout<<"===loading PCB # "<<cpu->getTempBuffer()<<" \n";

        cpu->setProcessorState(LOADING);

        startTime = clock();

        process.setProcessStatus(READY);
        programCounter = process.getProgramCounter();
        processStates = process.getProcessStatus();
        inputBuffer = process.getInputBuffer();
        outputBuffer = process.getOutputBuffer();
        tempBuffer = process.getTempBuffer();
        registers = process.getRegisters();
        jobCounter = process.getNumberOfInstructions();
        dataAddress = process.getJobDiskLocation()+process.getNumberOfInstructions();
        cpuID = process.get_CPU_ID();
        ioCount = 0;
        cacheSize = inputBuffer + outputBuffer + tempBuffer + jobCounter;
        process.setCacheSize(cacheSize);
        for (int i = 0; i < cacheSize; i++) {
            //std::cout<<"this the cache location: "<<(i+process.getJobRamLocation())% ram.getRamSize() <<std::endl;
            cache[i] = ram.readFromRAM((i+process.getJobRamLocation()));
        }

    }

    void CONTENT_SWITCHER::unloadPCBFromCPU(std::list<Project_Phase_One::PCB> *wait_queue, CPU *cpu) {
        endTime = clock();
        std::cout<<"===Unloading Job #"<<process.getJobNumber()<<std::endl;

        processorState = UNLOADING;
        process.setBurstTIme(endTime-startTime);
        process.setNumberOfInstructions(jobNumber);
        process.setRegisters(registers);
        process.setOutputBuffer(outputBuffer);
        process.setInputBuffer(inputBuffer);
        process.setTempBuffer(tempBuffer);
        process.setProgramCounter(programCounter);
        process.setCache(cache);
        process.setCacheSize(cacheSize);
        //process.set

        if(jobCounter>programCounter){
            process.setProcessStatus(WAITING);
            std::cout<<"===This PCB is going into the wait queue"<<std::endl;
        }
        else {
            process.setProcessStatus(TERMINATE);
            std::cout<<"===This PCB is going to TERMINATE."<<std::endl;
            std::cout<<"===There was "<<ioCount<<" I/O counts."<<std::endl;
            std::cout<<"===This process spend "<<(endTime-startTime)/double(CLOCKS_PER_SEC)<<" seconds on the CPU."<<std::endl;
            totalTime += (endTime-startTime);
            std::cout<<"===The total time was "<<totalTime/double(CLOCKS_PER_SEC)<<std::endl;
        }


    }

}