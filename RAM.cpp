
#include "RAM.h"
#include <iostream>
#include "LongTermScheduler.h"
#include "DISK.h"
using namespace std;
namespace Project_Phase_One {

    Project_Phase_One::LongTermScheduler lts;

    int RAM:: holdInstruction() {
        int ramSize = 1024;
        counter = 0;
        string holdInstruction = new string[ramSize];


        for (int i = 0; i < ramSize; i++) {
            lts.giveRamInstruction(i) = holdInstruction[i];
            counter++;

        }
        return counter;
    }
    bool RAM:: isRamFull(int counter) {
        if(counter >= ramSize) {
            return true;
        }
    }

}
