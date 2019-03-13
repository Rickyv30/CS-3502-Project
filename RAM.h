//
// Created by ouric on 3/12/2019.
//

#ifndef OS_PROJECT_MEMORY_H
#define OS_PROJECT_MEMORY_H

#include <iostream>

namespace Project_Phase_One {
class RAM {
public:
    int holdInstructions();

    bool isRamFull();

private:
    int counter;


    };
}
#endif //OS_PROJECT_MEMORY_H
