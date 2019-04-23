//
// Created by User on 2019-03-13.
//

#include "DRIVER.h"

namespace Project_Phase_One {
    DRIVER::DRIVER() {

    }

    void DRIVER::setFrameWork() {
        load.loading("/Users/testuser/Documents/Operating System/C++Project/Program-File-Wordversion.txt", &mmu, &PCBInDISK);

        while(!PCBInDISK.empty()){

            longTerm.LongTermSheduler(&mmu, &PCBInDISK, &PCBInRAM);
            std::list<Project_Phase_One::PCB>::iterator it = PCBInRAM.begin();
            //std::cout<<"inst: "<<it->getNumberOfInstructions()<<" input: "<<it->getInputBuffer()<<" output"<<it->getOutputBuffer()<<" temp: "<<it->getTempBuffer()<<std::endl;

            //0:fifo, 1: Pri, 2: SJF
            shortTerm.setScheduler(1);


            shortTerm.schedule(&PCBInRAM, &ready_queue);

            while(!ready_queue.empty()){

                try {
                    std::vector<std::thread> threads;

                    for(int i =0; i<1; i++){
                        //std::thread new_thread(&Project_Phase_One::DRIVER::RUN, this);
                        if(ready_queue.empty()){
                            break;
                        }
                            else
                                threads.push_back(std::thread(&Project_Phase_One::DRIVER::RUN, this));
                        //std::cout<<"Thread size is: "<<threads.size()<<"."<<std::endl;


                    }

                    if(ready_queue.empty()){
                        break;
                    }

                    for (auto &thread : threads) {
                        //std::cout<<"Thread_ID: "<<thread.get_id()<<"."<<std::endl;
                        thread.join();

                    }


                    }catch (std::exception& exception ){

                        //std::cout<<"hellow world.\n";
                    }

                }
                dumpRAM();
            }





    }

    void DRIVER::dumpRAM() {
        if(ready_queue.empty()){
            for (int i = 0; i < 1024; i++){
                mmu.writeToRam(i , "EMPTY");
            }

        }

    }

    void DRIVER::RUN() {
        PCB_Lock.lock();
        switcher.loadPCBToCPU(&ready_queue, &cpu1);

        cpu1.runProcess(&mmu);

        switcher.unloadPCBFromCPU(&wait_queue, &cpu1, new PCB());
        PCB_Lock.unlock();

    }


}