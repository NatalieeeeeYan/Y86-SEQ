//
// Created by aaron on 16-12-6.
//

#ifndef Y86_CORE_INSTRMEM_H
#define Y86_CORE_INSTRMEM_H
#include <fstream>

#define M_MAX 0xFFFF

class Memory{
public:
    char mem[M_MAX]={0};
    char fetchChar(int addr);
    int fetchInt(int addr);
    int display(int addr);
    bool write(int val,int addr);
    void read(std::ifstream &in);
    void clear();

};

#endif //Y86_CORE_INSTRMEM_H
