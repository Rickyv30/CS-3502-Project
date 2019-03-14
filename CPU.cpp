//
// Created by User on 2019-03-08.
//

#include "CPU.h"
#include <iostream>
#include <sstream>


namespace Project_Phase_One {
    /*
     * @PCB process
     * The load method will take a PCB and load its information onto the cpu.
     * */
    void CPU::loadProcess(Project_Phase_One::PCB process, Project_Phase_One::RAM ram) {
        std::cout<<"===loading PCB # "<<process.getJobNumber()<<" \n";

        processorState = LOADING;

        startTime = clock();

        process.setProcessStatus(READY);
        programCounter = process.getProgramCounter();
        processStates = process.getProcessStatus();
        inputBuffer = process.getInputBuffer();
        outputBuffer = process.getOutputBuffer();
        tempBuffer = process.getTempBuffer();
        registers = process.getRegisters();
        jobCounter = process.getNumberOfInstructions();
        dataAddress = process.getJobDiskLocation()+process.getNumberOfInstructions();
        cpuID = process.get_CPU_ID();
        ioCount = 0;
        cacheSize = inputBuffer + outputBuffer + tempBuffer + jobCounter;

        for (int i = 0; i < cacheSize; i++) {
            cache[i] = ram.readFromRAM(i+process.getJobRamLocation());
        }
        std::cout<<(cacheSize/100.0)*100<<"% of the cache is being used."<<std::endl;


    }

    void CPU::unloadProcess(Project_Phase_One::PCB process) {
        endTime = clock();
        std::cout<<"===Unloading Job #"<<process.getJobNumber()<<std::endl;

        processorState = UNLOADING;
        process.setBurstTIme(endTime-startTime);
        process.setNumberOfInstructions(jobNumber);
        process.setRegisters(registers);
        process.setOutputBuffer(outputBuffer);
        process.setInputBuffer(inputBuffer);
        process.setTempBuffer(tempBuffer);
        process.setProgramCounter(programCounter);
        process.setCache(cache);
        process.setCacheSize(cacheSize);
        //process.set

        if(jobCounter>programCounter){
            process.setProcessStatus(WAITING);
            std::cout<<"===This PCB is going into the wait queue"<<std::endl;
        }
        else {
            process.setProcessStatus(TERMINATE);
            std::cout<<"===This PCB is going to TERMINATE."<<std::endl;
            std::cout<<"===There was "<<ioCount<<" I/O counts."<<std::endl;
            std::cout<<"===This process spend "<<(endTime-startTime)/double(CLOCKS_PER_SEC)<<" seconds on the CPU."<<std::endl;
            totalTime += (endTime-startTime);
            std::cout<<"===The total time was "<<totalTime/double(CLOCKS_PER_SEC)<<std::endl;
        }

    }

    void CPU::setRegisters(std::string instruction) {
        std::string instructionType = instruction.substr(0, 2);

        if (instructionType == "00") {
            //Arithmetic instruction format
            s_reg1 = std::stoi(instruction.substr(8, 4), nullptr, 2);
            s_reg2 = std::stoi(instruction.substr(12, 4), nullptr, 2);
            d_reg = std::stoi(instruction.substr(16, 4), nullptr, 2);

        } else if (instructionType == "01") {
            //Conditional Branch and Immediate format
            b_reg = std::stoi(instruction.substr(8, 4), nullptr, 2);
            d_reg = std::stoi(instruction.substr(12, 4), nullptr, 2);
            instuctionAddress = std::stoi(instruction.substr(16), nullptr, 2);

        } else if (instructionType == "10") {
            //Unconditional Jump format
            instuctionAddress = std::stoi(instruction.substr(8), nullptr, 2);

        } else /*opCode == 11*/ {
            //Input and Output instruction format
            ioCount++;
            reg1 = std::stoi(instruction.substr(8, 4), nullptr, 2);
            reg2 = std::stoi(instruction.substr(12, 4), nullptr, 2);
            instuctionAddress = std::stoi(instruction.substr(16), nullptr, 2);

        }

    }


    void CPU::decode(std::string instruction) {

        std::string binary = hexToBinary(instruction);

        setRegisters(binary);

        opCode = std::stoi(binary.substr(2,6), nullptr, 2);

    }

    void CPU::executeProcess() {
        processorState = EXECUTING;
        std::stringstream stream;
        int temp = 0;
        switch(opCode){
            case 0:// RD: Reads content of I/P into a accumulator.
                if(reg2 > 0){
                    std::cout << "Reading " << std::stoi(cache[(registers[reg2])/4].substr(2), nullptr, 16) << " to registers [" << reg1 <<"]"<< std::endl;
                    registers[reg1] = std::stoi(cache[(registers[reg2])/4].substr(2), nullptr, 16);
                }
                else{
                    std::cout << "Reading " << std::stoi(cache[instuctionAddress/4].substr(2), nullptr, 16) << " to registers [" << reg1 <<"]"<< std::endl;
                    registers[reg1] = std::stoi(cache[instuctionAddress/4].substr(2), nullptr, 16);

                }

                break;
            case 1:// WR: Write the content of accumulator in to O/P buffer.

                if(reg2 > 0) {
                    std::cout << "Write " << registers[reg1] << " to registers [" << reg2 <<"]"<< std::endl;
                    registers[reg2] = registers[reg1];
                }
                else {
                    std::cout << "Write " << registers[reg1] << " to cache[" << instuctionAddress/4<<"]." << std::endl;
                    stream << "0x" << std::hex << registers[reg1];
                    cache[instuctionAddress/4] = stream.str();
                }
                break;
            case 2://ST: Stores content of a reg. into a address.
                std::cout<<"Storing "<<stream.str()<<" to cache["<<registers[d_reg]/4<<"]."<<std::endl;
                stream << "0x" <<std::hex << registers[b_reg];
                cache[registers[d_reg]/4] = stream.str();
                break;
            case 3:// LW: Loads the content of an address into a reg.

                registers[d_reg] = std::stoi(cache[(registers[b_reg]/4+instuctionAddress)].substr(2), nullptr, 16);
                break;
            case 4:// MOV: Transfers the content of one register into another.
                std::cout << "Move register[" << b_reg << "] to registers[" << d_reg << "]"<<std::endl;
                registers[d_reg] = registers[b_reg];
                break;
            case 5:// ADD: Adds content of two S-regs into D-reg.
                std::cout << "Add " << registers[s_reg1] << " to "<< registers[s_reg2] <<" and store it in register["<< d_reg << "]"<<std::endl;
                temp = registers[s_reg1] + registers[s_reg2];
                registers[d_reg] = temp;
                break;
            case 6:// SUB: subtract content of two S-reg into D-reg.
                std::cout << "Sub " << registers[s_reg1] << " to "<< registers[s_reg2] <<" and store it in register["<< d_reg <<"]"<< std::endl;
                temp = registers[s_reg1] - registers[s_reg2];
                registers[d_reg] = temp;
                break;
            case 7:// MUL: Multiplies content of two s-reg into D-reg.
                std::cout << "MUL " << registers[s_reg1] << " to "<< registers[s_reg2] <<" and store it in register["<< d_reg <<"]"<< std::endl;
                temp = registers[s_reg1] * registers[s_reg2];
                registers[d_reg] = temp;
                break;
            case 8:// DIV: Divides content of two S-reg into D-reg;
                std::cout << "DIV " << registers[s_reg1] << " to "<< registers[s_reg2] <<" and store it in register["<< d_reg << "]"<<std::endl;
                temp = registers[s_reg1] / registers[s_reg2];
                registers[d_reg] = temp;
                break;
            case 9:// AND: Logical AND of two S-reg into D-reg.
                std::cout<<registers[s_reg1]<<" AND "<< registers[s_reg2] << " in register["<<d_reg<<"]"<<std::endl;
                registers[d_reg] = registers[s_reg1]&&registers[s_reg2];
                break;
            case 10:// OR: Logical OR of two S-reg into D-reg.
                std::cout<<registers[s_reg1]<<" OR "<< registers[s_reg2] << " in register["<<d_reg<<"]"<<std::endl;
                registers[d_reg] = registers[s_reg1]||registers[s_reg2];
                break;
            case 11:// MOVI: Transfers address/data directly into a register.
                std::cout<<"MOVI "<<instuctionAddress<<" to register["<<d_reg<<"]"<<std::endl;
                registers[d_reg] = instuctionAddress;
                break;
            case 12://ADDI: Adds a data value directly with the content of a register.
                std::cout<<"ADDI "<<instuctionAddress<<" to register["<<d_reg<<"]"<<std::endl;
                registers[d_reg] += instuctionAddress;
                break;
            case 13://MULI: Multiplies a data value directly with the content of a register.
                std::cout<<"MULI "<<instuctionAddress<<" to register["<<d_reg<<"]"<<std::endl;
                registers[d_reg] *= instuctionAddress;
                break;
            case 14://DIVI: Divides a data directly with the content of a register.
                std::cout<<"DIVI "<<instuctionAddress<<" to register["<<d_reg<<"]"<<std::endl;
                registers[d_reg] /= instuctionAddress;
                break;
            case 15://LDI: Loads a data/address directly to the content of a register.
                std::cout<<"LDI "<<instuctionAddress<<" to register["<<d_reg<<"]"<<std::endl;
                registers[d_reg] = instuctionAddress;
                break;
            case 16://SLT: Set the D-reg to 1 if first S-reg is less then the B-reg; 0 otherwise.
                if(registers[b_reg]>registers[s_reg1]){
                    std::cout<<registers[b_reg]<<" is GREATER THAN "<<registers[s_reg1]<<std::endl;
                    registers[d_reg] = 1;

                }
                else {
                    std::cout<<registers[b_reg]<<" is LESS THAN "<<registers[s_reg1]<<std::endl;
                    registers[d_reg] = 0;
                }
                break;
            case 17://SLT: Set the D-reg to 1 if first S-reg is less then a data; 0 otherwise.
                if(instuctionAddress/4 > registers[s_reg1]){
                    std::cout<<instuctionAddress/4<<" is GREATER THAN "<<registers[s_reg1]<<std::endl;
                    registers[d_reg] = 1;
                }
                else {
                    std::cout<<instuctionAddress/4<<" is LESS THAN "<<registers[s_reg1]<<std::endl;
                    registers[d_reg]  = 0;
                }
                break;
            case 18://HLT: Logical end of program.
                programCounter = jobCounter;
                std::cout<<"Program counter: "<<programCounter<<" = Job Counter: "<<jobCounter<<std::endl;
                break;
            case 19://NOP: Does nothing and moves to the next instruction.
                std::cout<<"DO NOTHING "<<std::endl;
                ;
                break;
            case 20://JMP: Jumps to a specified location.
                std::cout<<"Program Counter = "<<instuctionAddress/4<<std::endl;
                programCounter = instuctionAddress/4;
                break;
            case 21://Branches to an address when content of B-reg = D-reg.

                if(registers[b_reg] == registers[d_reg]){
                    std::cout<<"register "<<b_reg<<" == register"<<d_reg<<std::endl;
                    programCounter = instuctionAddress/4;
                }
                break;
            case 22://Branches to an address when content of B-reg <> D-reg.std::cout<<"executing "<<opCode<<std::endl;
                if(registers[b_reg] != registers[d_reg]){
                    std::cout<<"register "<<b_reg<<" != register"<<d_reg<<std::endl;
                    programCounter = instuctionAddress/4;

                }
                break;
            case 23://Branches to an address when content of B-reg = 0.

                if(registers[b_reg] == 0)
                    std::cout<<"register["<<b_reg<<"] == 0 "<<std::endl;
                    programCounter = instuctionAddress/4;
                break;
            case 24://Branches to an address when content of B-reg <> 0.
                if(registers[b_reg] != 0)
                    std::cout<<"register["<<b_reg<<"] != 0 "<<std::endl;
                    programCounter = instuctionAddress/4;
                break;
            case 25://Branches to an address when content of B-reg > 0.
                if(registers[b_reg] > 0)
                    std::cout<<"register["<<b_reg<<"] > 0 "<<std::endl;
                    programCounter = instuctionAddress/4;
                break;
            case 26://Branches to an address when content of B-reg < 0.
                if(registers[b_reg] < 0)
                    std::cout<<"register["<<b_reg<<"] < 0 "<<std::endl;
                    programCounter = instuctionAddress/4;
                break;
            default:std::cout<<"INVALID OPCODE."<<std::endl;


        }

    }

    std::string CPU::fetchInstruction(int programCounter) {
        return cache[programCounter];
    }


    std::string CPU::hexToBinary(std::string hex) {

        std::string binary = "";

        for (int i = 2; i < (hex.length()-1); i++) {

            switch (hex[i]) {
                case '0':
                    binary += "0000";
                    break;
                case '1':
                    binary += "0001";
                    break;
                case '2':
                    binary += "0010";
                    break;
                case '3':
                    binary += "0011";
                    break;
                case '4':
                    binary += "0100";
                    break;
                case '5':
                    binary += "0101";
                    break;
                case '6':
                    binary += "0110";
                    break;
                case '7':
                    binary += "0111";
                    break;
                case '8':
                    binary += "1000";
                    break;
                case '9':
                    binary += "1001";
                    break;
                case 'A':
                    binary += "1010";
                    break;
                case 'B':
                    binary += "1011";
                    break;
                case 'C':
                    binary += "1100";
                    break;
                case 'D':
                    binary += "1101";
                    break;
                case 'E':
                    binary += "1110";
                    break;
                case 'F':
                    binary += "1111";
                    break;
                default:
                    std::cout << "invalid hex character. "<<hex[i]<< std::endl;


            }

        }

        return binary;

    }



}