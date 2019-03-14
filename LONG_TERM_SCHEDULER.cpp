//
// Created by User on 2019-03-11.
//

#include "LONG_TERM_SCHEDULER.h"

namespace Project_Phase_One {
    void LONG_TERM_SCHEDULER::fromDiskToRam(PCB process, DISK disk) {

        if(isRamFull)
            ;
        else {std::cout<<"i'm trying to add this PCB into ram for you."<<std::endl;
            int loadAmount = process.getInputBuffer()+
                             process.getOutputBuffer()+
                             process.getTempBuffer()+
                             process.getNumberOfInstructions();
            for(int i = process.getJobDiskLocation(); i < (process.getJobDiskLocation()+loadAmount); i++){
                ram.writeToRAM(i, disk.readFromDisk(i));
            }
            isRamFull = ram.addPCBToRam(process);
        }

    }

    RAM LONG_TERM_SCHEDULER::getRam() {
        return ram;
    }


}