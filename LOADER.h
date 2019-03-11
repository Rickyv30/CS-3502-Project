//
// Created by User on 2019-03-10.
//

#ifndef C_PROJECT_LOADER_H
#define C_PROJECT_LOADER_H

#include <iostream>
#include <list>
#include "PCB.h"
#include "ADD_PCB_TO_QUEUE.h"
#include "DISK.h"
namespace Project_Phase_One{
    class LOADER {
    private:
        DISK disk;
        PCB JOB;
        ADD_PCB_TO_QUEUE diskList;
        int index = 0;

    public:
        void loading(std::string path);
        void testKit();
        void testkit2();

    };

}

#endif //C_PROJECT_LOADER_H
