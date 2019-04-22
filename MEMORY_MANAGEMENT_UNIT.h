//
// Created by User on 2019-04-21.
//

#ifndef C_PROJECT_MEMORY_MANAGEMENT_UNIT_H
#define C_PROJECT_MEMORY_MANAGEMENT_UNIT_H

#include <iostream>


namespace Project_Phase_One {

    class MEMORY_MANAGEMENT_UNIT {
    private:
        const int MAX_DISK_SPACE = 2048;
        const int MAX_RAM_SPACE = 1024;
        std::string *DISK;
        std::string *RAM;

    public:
        MEMORY_MANAGEMENT_UNIT();
        MEMORY_MANAGEMENT_UNIT(std::string *DISK, std::string *RAM);
        void writeToDisk(const int index, const std::string instruction);
        std::string readFromDisk(const int index);
        void writeToRam(const int index, const std::string instruction);
        std::string readFromRam(const int index);



    };

}

#endif //C_PROJECT_MEMORY_MANAGEMENT_UNIT_H
