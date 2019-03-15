#include "RAM.h"
#include "SHORT_TERM_SCHEDULER.h"
#include "PCB.h"
#include <iostream>
using namespace std;


namespace Project_Phase_One{

    PCB SHORT_TERM_SCHEDULER:: Dispatcher(RAM* ram,int index){

        return ram->getPCBFromRAM(index);

    }


    /*
    void SHORT_TERM_SCHEDULER:: Dispatcher (int programCounter,int jobNumber,Process_States processStatus,int inputBuffer,int outputBuffer
            ,int tempBuffer,std::array<int,16> registers, int numberOfInstructions) {

        pcb.setInputBuffer(inputBuffer);
        pcb.setProgramCounter(programCounter);
        pcb.setProcessStatus(processStatus);
        pcb.setOutputBuffer(outputBuffer);
        pcb.setTempBuffer(tempBuffer);
        pcb.setRegisters(registers);
        pcb.setNumberOfInstructions(numberOfInstructions);*/



    }