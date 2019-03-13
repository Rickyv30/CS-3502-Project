//
// Created by User on 2019-03-08.
//

#ifndef C_PROJECT_PCB_H
#define C_PROJECT_PCB_H

#include <iostream>

namespace Project_Phase_One {
    enum Process_States{NEW, READY, RUNNING, WAITING};
    class PCB{
    private:
        int cpuID;
        int programCounter;
        int numberOfInstructions;
        int jobNumber;
        int numberOfJobs;
        int codeSize;
        int jobDiskLocation;
        Process_States processStatus;
        int priority;
        int registers[16];
        bool isIO;
        // Data
        int dataDiskLocation;
        int inputBuffer;
        int outputBuffer;
        int tempBuffer;
        // Schedule
        int burstTime, timeSlice, timeRemaining;
        std::string queueType;
        // Account
        int cupTime, timeLimit, timeDelay, startTime, endTime, ioTime;
        // Memories
        int pageTableBase, pages, pageSize;
        // Progeny
        int childProcessID;
        PCB* childLeft_ptr;
        PCB* childRight_ptr;
        PCB* parent_ptr;
        // Resources
        int unitNumber;
        std::string cache[100];
    public:
        // CONSTRUCTOR
        PCB(int jobNumber, int priority, int numberOfInstrucions, int jobDiskLocation);
        PCB();
        // The Getter will return a private member of this class.
        bool getIsIO();
        int get_CPU_ID();
        int getProgramCounter();
        int getJobNumber();
        int getNumberOfInstructions();
        int getJobDiskLocation();
        int getCodeSize();
        Process_States getProcessStatus();
        int getPriority();
        int* getRegisters();
        int getDataDiskLocation();
        int getInputBuffer();
        int getOutputBuffer();
        int getTempBuffer();
        int getBurstTIme();
        int getTimeSlice();
        int getTimeRemaining();
        std::string getQueueType();
        int getPageTableBase();
        int getPages();
        int getPageSize();
        int getChildProcessID();
        PCB* getChildLeft();
        PCB* getChildRight();
        PCB* getParent();
        std::string* getCache();
        // The Setter will set the member of this class

        void setIsIO(bool isIO);
        void set_CPU_ID(int cupID);
        void setProgramCounter(int programCounter);
        void setJobNumber(int jobNumber);
        void setNumberOfInstructions(int numberOfInstructions);
        void setCodeSize(int codeSize);
        void setProcessStatus(Process_States processStatus);
        void setPriority(int priority);
        void setRegisters(int* registers);
        void setDataDiskLocation(int dataDiskLocation);
        void setInputBuffer(int inputBuffer);
        void setOutputBuffer(int outputBuffer);
        void setTempBuffer(int tempBuffer);
        void setBurstTIme(int burstTime);
        void setTimeSlice(int timeSlice);
        void setTimeRemaining(int timeRemaining);
        void setQueueType(std::string queueType);
        void setPageTableBase(int pageTableBase);
        void setPages(int pages);
        void setPageSize(int pageSize);
        void setChildProcessID(int childProcessID);
        void setChildCodePointerLeft(PCB* childLeft_ptr);
        void setChildCodePointerRight(PCB* childRight_ptr);
        void setParent(PCB* parent_ptr);
        void setCache(std::string cache[], int size);

    };

}



#endif //C_PROJECT_PCB_H
