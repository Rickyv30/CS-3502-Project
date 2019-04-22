//
// Created by User on 2019-04-21.
//

#include "MEMORY_MANAGEMENT_UNIT.h"


namespace Project_Phase_One{
    MEMORY_MANAGEMENT_UNIT::MEMORY_MANAGEMENT_UNIT() {
        DISK = new std::string[MAX_DISK_SPACE];
        RAM = new std::string[MAX_RAM_SPACE];


    }

    MEMORY_MANAGEMENT_UNIT::MEMORY_MANAGEMENT_UNIT(std::string *DISK, std::string *RAM) {

        this->DISK = DISK;
        this->RAM = RAM;

    }

    void MEMORY_MANAGEMENT_UNIT::writeToDisk(const int index, const std::string instruction) {
        DISK[index] = instruction;

    }

    std::string MEMORY_MANAGEMENT_UNIT::readFromDisk(const int index) {
        return DISK[index];

    }

    void MEMORY_MANAGEMENT_UNIT::writeToRam(const int index, const std::string instruction) {
        RAM[index] = instruction;


    }

    std::string MEMORY_MANAGEMENT_UNIT::readFromRam(const int index) {
        return RAM[index];

    }




}