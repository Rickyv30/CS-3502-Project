//
// Created by User on 2019-03-10.
//

#include "LOADER.h"
#include "PCB.h"
#include "ADD_PCB_TO_QUEUE.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>


namespace Project_Phase_One{
    void LOADER::loading(std::string path) {
        std::ifstream fileReader(path);
        std::string content;
        std::string findJob = "JOB";
        std::string findData = "Data";
        std::string findEND = "END";

        if(!fileReader){
            std::cerr<<"Unable to open file: "<<path<<std::endl;
            exit(1);

        }

        while(std::getline(fileReader, content)){


            if(content.find(findJob) != std::string::npos){
                std::vector<std::string> jobToken;
                std::stringstream lookThrough(content);
                std::string intermediate;

                while(std::getline(lookThrough, intermediate, ' ')){
                    jobToken.push_back(intermediate);
                }

                int jobNumber = atoi(jobToken[2].c_str());
                int numberOfInstructions = std::stoi(jobToken[3], nullptr, 16);
                int priority = atoi(jobToken[4].c_str());

                JOB = Project_Phase_One::PCB(jobNumber, priority, numberOfInstructions, index);
                diskList.addToDiskList(JOB);

            }else if (content.find(findData) != std::string::npos){
                std::vector<std::string> dataToken;
                std::stringstream lookThrough(content);
                std::string intermediate;

                while(std::getline(lookThrough, intermediate,' ')){
                    dataToken.push_back(intermediate);
                }

                std::list<PCB>::iterator it = diskList.getDiskListCurrentPCB();
                int inputBuffer = std::stoi(dataToken[2], nullptr, 16);
                int outputBuffer = std::stoi(dataToken[3], nullptr, 16);
                int tempBuffer = std::stoi(dataToken[4], nullptr, 16);

                std::advance(it, (JOB.getJobNumber() - 1));
                it->setDataDiskLocation(index);
                it->setInputBuffer(inputBuffer);
                it->setOutputBuffer(outputBuffer);
                it->setTempBuffer(tempBuffer);


            }else if (content.find(findEND) != std::string::npos){
                // Don't do anything and continue.
                continue;

            }else {
                std::cout<<"index is: "<<index<<": "<<content<<"\n";
                disk.writeToDisk(index, content);
                index++;

            }


        }
        fileReader.close();

    }

    void LOADER::testKit() {
        for(int i =0; i< 15; i++)
            std::cout<<disk.readFromDisk(i)<<"\n";

    }

    void LOADER::testkit2() {
        std::list<Project_Phase_One::PCB>::iterator it = diskList.getDiskListCurrentPCB();
        int i = 6;
        std::advance(it, i-1);
        std::cout<<it->getJobNumber()<<" "<<it->getInputBuffer()<<" "<<it->getProcessStatus()<<"\n";

    }



}