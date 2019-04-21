//
// Created by User on 2019-03-13.
//

#include "DRIVER.h"

namespace Project_Phase_One {
    DRIVER::DRIVER() {
        for (int i = 0; i < 2048; i++){
            DISK[i] = "EMPTY";
        }

        for (int i = 0; i < 1024; i++){
            RAM[i] = "EMPTY";
        }

    }

    void DRIVER::RUN() {
        load.loading("/Users/testuser/Documents/Operating System/C++Project/Program-File-Wordversion.txt", DISK, &PCBInDISK);
        longTerm.LongTermSheduler(DISK, RAM, &PCBInDISK, &PCBInRAM);
        shortTerm.setScheduler(0);
        shortTerm.schedule(&PCBInRAM, &ready_queue);

        /*for (int i = 0; i < 1024; i++){
            std::cout<<i<<" = "<<RAM[i]<<std::endl;

        }*/

        for(auto it = ready_queue.begin(); it != ready_queue.end(); it++){
            std::cout<<"job # "<<it->getJobNumber()
                     <<" ram location# "<<it->getJobRamLocation()
                     <<" number of space "<<it->getNumberOfInstructions()+it->getInputBuffer()+it->getOutputBuffer()+it->getTempBuffer()<<std::endl;
        }


        /*while(!PCBInDISK.empty()){
            std::list<PCB>::iterator it = PCBInDISK.begin();
            std::cout<<"is pcb #"<<it->getJobNumber()<<" is in ram? : "<<it->getIsPCBInRam()<<std::endl;
            *//*std::cout<<it->getNumberOfInstructions()<<"+"<<it->getTempBuffer()
            <<"+"<<+it->getOutputBuffer()<<"+"<<it->getInputBuffer()<<"="<<
            it->getNumberOfInstructions()+it->getTempBuffer()+it->getOutputBuffer()+it->getInputBuffer()<<std::endl;*//*
            PCBInDISK.pop_front();

        }*/

    }

    void DRIVER::dumpRAM() {
        if(ready_queue.empty()){


        }

    }

}