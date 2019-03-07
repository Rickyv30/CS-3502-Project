
#include <iostream>
#include <fstream>
#include "Loader.h"
using namespace std;

    void Loader::instruct() {

        std::ifstream Readfile("C:\\Users\\ouric\\CS3502 OS Project\\ProgramFile-WordVersion.txt");
        std::string content;

        int const size = 4096;
        string instructions[size];
        int count = 0;

        while (std::getline(Readfile, content)) {

            if (content.empty()) {
                cout << "Empty line" << endl;
            } else {
                count++;
                for (int i = 0; i < count; i++)
                    instructions[i] = content;
            }
        }
    };

        string Loader:: reader(int index){

            return instructions[index];
        }

        string Loader:: pReader(int index,int size,string instructions){
            string temp [size];
            for(int i = 0; i < size;i++) {
                temp[i] = instructions[index];
                index++;
            }
            return *temp;
        }

        void Loader::writer(int index, string entry) {

            if(instructions[index] != ""){
                instructions[index] = entry;


            }
        }
