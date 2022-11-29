//
// Created by aaron on 16-12-6.
//

#ifndef Y86_CORE_ALU_H
#define Y86_CORE_ALU_H

#include "RegStage.h"

class ALU{
public:
    bool cnd[3]={true,false,false};
    int op(bool set_cc,int aluA,char alufun,int aluB);
    void cc(bool* CC);
};

#endif //Y86_CORE_ALU_H
