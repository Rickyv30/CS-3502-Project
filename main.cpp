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
#include "DRIVER.h"


int getRandom(int max){
    srand(time(NULL));
    return rand() % max;

}

void executeThread(int id/*Project_Phase_One::CPU cpu, Project_Phase_One::LONG_TERM_SCHEDULER longTerm, Project_Phase_One::LOADER load, Project_Phase_One::RAM ram*/){
    //auto currentTime = std::chrono::system_clock::now();

    /*std::time_t sleepTime = std::chrono::system_clock::to_time_t(currentTime);

    tm myLocalTime = *localtime(&sleepTime);

    std::cout<<"Thread: "<< id <<" sleep time: " << std::ctime(&sleepTime)<<std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(getRandom(10)));
    currentTime = std::chrono::system_clock::now();
    sleepTime = std::chrono::system_clock::to_time_t(currentTime);
    std::cout<<"Thread: "<<id<<"Awake time:"<<std::ctime(&sleepTime)<<std::endl;
    std::cout<<"this thread is number"<<id<<std::endl;*/
    /*int listSize = load.getDisk().getDiskList().size();

    for (int i = 0; i < listSize; i++) {
        if(ram.ramIsFull()){
            break;
        }

        longTerm.fromDiskToRam(load.getDisk().getCurrentPCBFromDisk(i), load.getDisk(), &ram);
        std::cout<<load.getDisk().getCurrentPCBFromDisk(i).getJobNumber()<<" is being added to ram"<<std::endl;
    }

    int processSize = ram.getReadyQueue().size();
    std::cout<<"ram: "<<processSize<<std::endl;
    for (int j = 0; j < processSize; j++) {
        cpu.loadProcess(ram.getPCBFromRAM(j), ram);
        for (int i = ram.getPCBFromRAM(j).getJobRamLocation();
             i < (ram.getPCBFromRAM(j).getJobRamLocation() +
                  ram.getPCBFromRAM(j).getNumberOfInstructions()); i++) {

            cpu.decode(ram.readFromRAM(i));

            cpu.executeProcess();
        }

        cpu.unloadProcess(ram.getPCBFromRAM(j));



    }*/

}


int main() {
    Project_Phase_One::DRIVER driver;
    driver.RUN();



    /*std::thread thread1(executeThread, 1);
    thread1.join();
    std::cout<<"\nthread ID is "<<thread1.get_id()<<std::endl;
    std::thread thread2(executeThread, 2);
    thread2.join();*/



    return 0;
}