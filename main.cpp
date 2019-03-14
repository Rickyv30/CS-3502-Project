#include <iostream>
#include <iomanip>
#include <sstream>
#include <thread>
#include <list>
#include <ctime>
#include <chrono>
#include <mutex>
#include <array>
#include "PCB.h"
#include "DISK.h"
#include "CPU.h"
#include "LOADER.h"
#include "LONG_TERM_SCHEDULER.h"
#include "RAM.h"
#include "SHORT_TERM_SCHEDULER.h"



int getRandom(int max){
    srand(time(NULL));
    return rand() % max;

}

void executeThread(int id){
    auto currentTime = std::chrono::system_clock::now();
    std::time_t sleepTime = std::chrono::system_clock::to_time_t(currentTime);

    tm myLocalTime = *localtime(&sleepTime);

    std::cout<<"Thread: "<< id <<" sleep time: " << std::ctime(&sleepTime)<<std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(getRandom(10)));
    currentTime = std::chrono::system_clock::now();
    sleepTime = std::chrono::system_clock::to_time_t(currentTime);
    std::cout<<"Thread: "<<id<<"Awake time:"<<std::ctime(&sleepTime)<<std::endl;

}


int main() {
    int processCount = 0;
    Project_Phase_One::LONG_TERM_SCHEDULER longTerm;
    Project_Phase_One::LOADER load;
    load.loading("/Users/testuser/Documents/Operating System/C++Project/Program-File-Wordversion.txt");
    //Project_Phase_One::DISK disk = load.getDisk();
    Project_Phase_One::CPU cpu;
    Project_Phase_One::RAM ram;

    while(processCount <= load.getDisk().getDiskList().size()) {
        for (int i = processCount; i < 30; i++) {
            std::cout<<"Process count at this point is "<<processCount<<std::endl;
            longTerm.fromDiskToRam(load.getDisk().getCurrentPCBFromDisk(i+1), load.getDisk());
        }


        //int startPoint = processCount;
        for (int x = 0; x < longTerm.getRam().getReadyQueue().size(); x++) {
            cpu.loadProcess(longTerm.getRam().getPCBFromRAM(x), longTerm.getRam());
            std::cout<<++processCount<<std::endl;
            for (int i = longTerm.getRam().getPCBFromRAM(x).getJobRamLocation();
                 i < (longTerm.getRam().getPCBFromRAM(x).getJobRamLocation() +
                      longTerm.getRam().getPCBFromRAM(x).getNumberOfInstructions()); i++) {

                cpu.decode(longTerm.getRam().readFromRAM(i));
                cpu.executeProcess();

            }

            cpu.unloadProcess(longTerm.getRam().getPCBFromRAM(x));
            //longTerm.getRam().deallocateRam(longTerm.getRam().getPCBFromRAM(x).getJobRamLocation(), longTerm.getRam().getPCBFromRAM(x).getCacheSize());

        }
        std::cout<<"============\n====="<<processCount<<"=====\n============"<<std::endl;
        longTerm.getRam().ramWipe();
    }
    /*std::thread thread1(executeThread, 1);
    thread1.join();
    std::cout<<"thread ID is "<<thread1.get_id()<<std::endl;
    std::thread thread2(executeThread, 2);
    thread2.join();*/




    return 0;
}