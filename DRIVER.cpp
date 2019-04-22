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

        while(!PCBInDISK.empty()){
            std::cout<<"calling longTerm"<<std::endl;
            longTerm.LongTermSheduler(DISK, RAM, &PCBInDISK, &PCBInRAM);
            std::list<Project_Phase_One::PCB>::iterator it = PCBInRAM.begin();
            std::cout<<"inst: "<<it->getNumberOfInstructions()<<" input: "<<it->getInputBuffer()<<" output"<<it->getOutputBuffer()<<" temp: "<<it->getTempBuffer()<<std::endl;
            shortTerm.setScheduler(0);
            shortTerm.schedule(&PCBInRAM, &ready_queue);

            while(!ready_queue.empty()){

                switcher.loadPCBToCPU(&ready_queue, &cpu);

                cpu.runProcess(RAM);

                switcher.unloadPCBFromCPU(&wait_queue, &cpu, new PCB());

            }

            dumpRAM();
            std::cout<<"existing longTerm"<<std::endl;
            std::cout<<"pcb disk size is "<<PCBInDISK.size()
                     <<"\nPCB in Ram size is "<<PCBInRAM.size()
                     <<"\nPCB ready_queue size is "<<ready_queue.size()
                     <<"\nPCB wait_queue size is "<<wait_queue.size()<<std::endl;
        }

    }

    void DRIVER::dumpRAM() {
        if(ready_queue.empty()){
            for (int i = 0; i < 1024; i++){
                RAM[i] = "EMPTY";
            }

        }

    }

}