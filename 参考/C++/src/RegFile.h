//
// Created by aaron on 16-12-6.
//

#ifndef Y86_CORE_REGFILE_H
#define Y86_CORE_REGFILE_H

#include "RegStage.h"

class RegFile{

public:
    int reg[8]={0};
    int read(char src);
    void write(int val,char src);
    void clear();
    void display();
};

#endif //Y86_CORE_REGFILE_H
