//
// Created by aaron on 16-12-6.
//

#include "ALU.h"
#include <iostream>

int ALU::op(bool set_cc,int aluA, char alufun, int aluB) {
    int temp;
    switch(alufun){
        case ADDL:
            temp=aluA+aluB;
            if(set_cc){
                cnd[0]=(temp==0);
                cnd[1]=(temp<0);
                cnd[2]=((temp>=0&&aluA<0&&aluB<0)||(temp<0&&(aluA>0&&aluB>0)));
            }
            return temp;
        case SUBL:
            temp=aluB-aluA;
            if(set_cc){
                cnd[0]=(temp==0);
                cnd[1]=(temp<0);
                cnd[2]=((aluB!=aluA+temp)||(aluA!=aluB-temp));
            }
            return temp;
        case ANDL:
            temp=aluA&aluB;
            if(set_cc){
                cnd[0]=(temp==0);
                cnd[1]=(temp<0);
                cnd[2]=false;
            }
            return temp;
        case XORL:
            temp=aluA^aluB;
            if(set_cc){
                cnd[0]=(temp==0);
                cnd[1]=(temp<0);
                cnd[2]=false;
            }
            return temp;
    }
}

void ALU::cc(bool* CC) {
    CC[0]=cnd[0];
    CC[1]=cnd[1];
    CC[2]=cnd[2];
}
