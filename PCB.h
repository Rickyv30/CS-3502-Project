//
// Created by User on 2019-03-08.
//

#ifndef C_PROJECT_PCB_H
#define C_PROJECT_PCB_H

#include <iostream>

namespace Project_Phase_One {
    enum Process_States{NEW, READY, RUNNING, WAITING};
    class PCB{
    public:
        enum Process_States{NEW, READY, RUNNING, WAITING};
    private:
        int cupID;
        int programCounter;
        int codeSize;
        Process_States processStatus;
        int priority;
        int registers[16];
        bool isIO;
        int inputBuffer;
        int outputBuffer;
        // Schedule
        int burstTime, timeSlice, timeRemaining;
        std::string queueType;
        // Account
        int cupTime, timeLimit, timeDelay, stateTime, endTime, ioTime;
        // Memories
        int pageTableBase, pages, pageSize;
        // Progeny
        int childProcessID;
        PCB* childLeft_ptr;
        PCB* childRight_ptr;
        PCB* parent_ptr;
        // Resources
        int unitNumber;
        int cache[16];
    public:
        // The Getter will return a private member of this class.
        bool getIsIO();
        int get_CUP_ID();
        int getProgramCounter();
        int getCodeSize();
        Process_States getProcessStatus();
        int getPriority();
        int* getRegisters();
        int getInputBuffer();
        int getOutputBuffer();
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
        int* getCache();
        // The Setter will set the member of this class
        void setIsIO();
        void set_CUP_ID(int cupID);
        void setProgramCounter(int programCounter);
        void setCodeSize(int codeSize);
        void setProcessStatus(Process_States processStatus);
        void setPriority(int priority);
        void setRegisters(int* registers);
        void setInputBuffer(int inputBuffer);
        void setOutputBuffer(int outputBuffer);
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
        void setCache(int* cache);

    };

}



#endif //C_PROJECT_PCB_H
