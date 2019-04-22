//
// Created by User on 2019-04-16.
//

#include "DISPATCHER.h"

namespace Project_Phase_One{
    void DISPATCHER::loadPCBToCPU(std::list<Project_Phase_One::PCB> *ready_queue, CPU *cpu) {
        std::list<Project_Phase_One::PCB>::iterator it = ready_queue->begin();
        std::cout<<" === loading PCB # "<<it->getJobNumber()<<" === \n";

        cpu->setProcessorState(LOADING);

        cpu->setStartTime(clock());

        cpu->setJobRamIndex(it->getJobRamIndex());
        cpu->setJobNumber(it->getJobNumber());
        cpu->setProgramCounter(it->getProgramCounter());
        cpu->setProcessState(READY);
        cpu->setInputBuffer(it->getInputBuffer());
        cpu->setOutputBuffer(it->getOutputBuffer());
        cpu->setTempBuffer(it->getTempBuffer());
        cpu->setRegister(it->getRegisters());
        cpu->setNumberOfInstructions(it->getNumberOfInstructions());
        cpu->setCPUID(it->get_CPU_ID());
        cpu->setIOCount(0);

        //cpu->setCacheSize(cpu->getInputBuffer() + cpu->getOutputBuffer() + cpu->getTempBuffer() + cpu->getJobCounter());
        //it->setCacheSize(cpu->getInputBuffer() + cpu->getOutputBuffer() + cpu->getTempBuffer() + cpu->getJobCounter());

        ready_queue->pop_front();

    }

    void DISPATCHER::unloadPCBFromCPU(std::list<Project_Phase_One::PCB> *wait_queue, CPU *cpu, Project_Phase_One::PCB *pcb) {
        cpu->setEndTime(clock());
        std::cout<<"=== Unloading Job ==="<<std::endl;

        cpu->setProcessorState(UNLOADING);

        pcb->setJobNumber(cpu->getJobNumber());
        pcb->setBurstTIme(cpu->getEndTime() - cpu->getStartTime());
        pcb->setNumberOfInstructions(cpu->getNumberOfInstructions());
        pcb->setRegisters(cpu->getRegister());
        pcb->setOutputBuffer(cpu->getOutputBuffer());
        pcb->setInputBuffer(cpu->getInputBuffer());
        pcb->setTempBuffer(cpu->getTempBuffer());
        pcb->setProgramCounter(cpu->getProgramCounter());
        pcb->setCacheSize(cpu->getCacheSize());


        std::cout<<"job counter: "<<cpu->getNumberOfInstructions()
                 <<"\nprogram COunter: "<<cpu->getProgramCounter()<<std::endl;

        if(cpu->getNumberOfInstructions() > cpu->getProgramCounter()){
            pcb->setProcessStatus(WAITING);
            std::cout<<"=== This PCB is going into the wait queue=== \n"<<std::endl;
            wait_queue->push_back(*pcb);
        }
        else {
            pcb->setProcessStatus(TERMINATE);
            std::cout<<"===This PCB is going to TERMINATE."<<std::endl;
            std::cout<<"===There was "<<cpu->getIOCount()<<" I/O counts."<<std::endl;
            std::cout<<"===This process spend "<<(cpu->getEndTime()-cpu->getStartTime())/double(CLOCKS_PER_SEC)<<" seconds on the CPU."<<std::endl;
            cpu->setTotalTime(cpu->getEndTime() - cpu->getStartTime());
            std::cout<<"===The total time was "<<cpu->getTotalTime()/double(CLOCKS_PER_SEC)<<std::endl;
        }


    }

}