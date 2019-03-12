//
// Created by User on 2019-03-10.
//

#ifndef C_PROJECT_LOADER_H
#define C_PROJECT_LOADER_H

#include <iostream>
#include <list>
#include "PCB.h"
#include "DISK.h"
namespace Project_Phase_One{
    class LOADER {
    private:
        DISK disk;
        PCB JOB;
        int index = 0;

    public:
        void loading(std::string path);
        void testKit();
        void testkit2();

    };

}

#endif //C_PROJECT_LOADER_H
