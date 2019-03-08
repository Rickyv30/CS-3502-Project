
#ifndef OS_PROJECT_LOADER_H
#define OS_PROJECT_LOADER_H
#endif //OS_PROJECT_LOADER_H

#include <iostream>

class Disk {
public:
    void instruct();
    std::string reader(int index);
    void writer(int index,std::string entry);
    std::string pReader(int index,int size,std::string instructions);

private:
    std::string* instructions;

};
