//
// Created by User on 2019-03-11.
//

#include "DISK.h"
#include <cassert>
namespace Project_Phase_One{

    DISK::DISK() {
        for (int i=0; i< diskSize; i++){
            disk[i] = empty;
        }

    }


    /*std::string DISK::readFromDisk(const int index){
        if((index >= diskSize) || (0 > index)){
            std::cout<<"Index does not exist in this disk."<<std::endl;

        }else if (disk[index].find(empty) != std::string::npos){
            std::cout<<"This box is empty."<<std::endl;

        }else{
            return disk[index];

        }
    }*/


    /*void DISK::writeToDisk(const int index, const std::string entry) {
        if((index >= diskSize) || (0 > index)){

            std::cout<<"Out of rage, Page does not exist."<<std::endl;

        }else if (disk[index].find(empty) != std::string::npos){

            std::cout<<"This Page is FULL."<<std::endl;

        }else{
            disk[index] = entry;
            diskCounter++;
        }
    }*/

}