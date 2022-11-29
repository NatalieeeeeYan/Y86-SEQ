//
// Created by aaron on 16-12-6.
//

#include <zconf.h>

#ifndef Y86_CORE_REGSTAGE_H

#include <iostream>  //tempo

const char IHALT=0x0;
const char INOP=0x1;
const char IRRMOVL=0x2;
const char IIRMOVL=0x3;
const char IRMMOVL=0x4;
const char IMRMOVL=0x5;
const char IOPL=0x6;
const char IJXX=0x7;
const char ICALL=0x8;
const char IRET=0x9;
const char IPUSHL=0xA;
const char IPOPL=0xB;
const char FNONE=0x0;

const char REAX=0x0;
const char RECX=0x1;
const char REDX=0x2;
const char REBX=0x3;
const char RESP=0x4;
const char REBP=0x5;
const char RESI=0x6;
const char REDI=0x7;
const char RNONE=0xF;

const char ALUADD=0x0;
const int  SIZE=2048;

const char SBUB=0x0;
const char SAOK=0x1;
const char SADR=0x2;
const char SINS=0x3;
const char SHLT=0x4;

const char JMP=0x0;
const char JLE=0x1;
const char JL =0x2;
const char JE =0x3;
const char JNE=0x4;
const char JGE=0x5;
const char JG =0x6;

const char RRMOVL=0x0;
const char CMOVLE=0x1;
const char CMOVL =0x2;
const char CMOVE =0x3;
const char CMOVNE=0x4;
const char CMOVGE=0x5;
const char CMOVG =0x6;

const int ZF=0x0;
const int SF=0x1;
const int OVF=0x2;

const char ADDL=0x0;
const char SUBL=0x1;
const char ANDL=0x2;
const char XORL=0x3;

class F_register{
public:
    int predPC;
    void update(bool F_stall, int f_predPC);
    void initialize();
    void display();
} ;

class D_register{
public:
    char stat;
    char icode;
    char ifun;
    char rA;
    char rB;
    int valC;
    int valP;
    void update(bool D_bubble, bool D_stall, char f_stat,char f_icode, char f_ifun,
                 char f_rA,char f_rB,int f_valC,int f_valP);
    void initialize();
    void display();
};

class E_register{
public:
    char stat;
    char icode;
    char ifun;
    int valC;
    int valA;
    int valB;
    char dstE;
    char dstM;
    char srcA;
    char srcB;
    void update(bool E_bubble, char D_stat,char D_icode,char D_ifun,int D_valC,int d_valA,int d_valB,
                char d_dstE,char d_dstM,char d_srcA,char d_srcB);
    void initialize();
    void display();
};

class M_register{
public:
    char stat;
    char icode;
    bool Cnd;
    int  valE;
    int  valA;
    char dstE;
    char dstM;
    void update(bool M_bubble, char E_stat,char E_icode,bool e_Cnd,int e_valE,
                int E_valA,char e_dstE,char E_dstM);
    void initialize();
    void display();
};

class W_register{
public:
    char stat;
    char icode;
    int  valE;
    int  valM;
    char dstE=0x8;
    char dstM=0x8;
    void update(bool W_stall, char m_stat,char M_icode,int M_valE,int m_valM,char M_dstE,char M_dstM);
    void initialize();
    void display();
};

#define Y86_CORE_REGSTAGE_H

#endif //Y86_CORE_REGSTAGE_H
