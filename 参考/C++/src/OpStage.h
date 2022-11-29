//
// Created by aaron on 16-12-6.
//

#ifndef Y86_CORE_OPSTAGE_H
#define Y86_CORE_OPSTAGE_H

#include "RegStage.h"

#include "Memory.h"
#include "RegFile.h"
#include "ALU.h"

class f_stage{
public:
    char stat,icode,ifun,rA,rB;
    int pc,predPC,valC,valP;
    bool instr_valid,need_regids,need_valC;

    void sel_PC(int M_icode, bool M_Cnd ,char W_icode,int M_valA,int W_valM,int F_predPC);
    void fetch(Memory &read);
    void pred_PC();

    void initialize();
    void display();
};

class d_stage{
public:
    char dstE,dstM,srcA,srcB;
    int valA,valB,rvalA,rvalB;

    void regFile_write(int w_valE,char w_dstE,int w_valM,char w_dstM, RegFile &a);
    void ID(char D_icode,char D_rA,char D_rB);
    void regFile_read(RegFile &a);
    void sel_fwdA(char D_icode,int D_valP,char e_dstE,int e_valE,
                  char M_dstM, int m_valM,char M_dstE,
                  int M_valE, char W_dstM,int W_valM,
                  char W_dstE, int W_valE);
    void fwdB(char e_dstE,int e_valE,
              char M_dstM, int m_valM,char M_dstE,
              int M_valE, char W_dstM,int W_valM,
              char W_dstE, int W_valE);

    void initialize();
    void display();
};

class e_stage{
public:
    char alufun,dstE;
    int  valE,aluA,aluB;
    bool Cnd,set_cc;
    bool CC[3];
    void aluAB(char E_icode,int E_valA,int E_valB,int E_valC);
    void alu(char E_icode,char E_ifun,char m_stat,char W_stat,ALU &a);  //merge ALU&ALU fun.
    void set_Cnd(char E_stat,char E_icode,char E_ifun);
    void set_dstE(char E_icode,char E_dstE);

    void initialize();
    void display();
};

class m_stage{
public:
    char stat;
    int  valM;
    bool dmem_error;
    void mem(char M_stat,char M_icode,int M_valE,int M_valA,Memory &m);
    void initialize();
    void display();
};

class w_stage{
public:
    char stat,dstE,dstM;
    int  valE,valM;
    void initialize();
    void update(char W_dstE,int W_valE,char W_dstM,int W_valM,char W_stat);
};


#endif //Y86_CORE_OPSTAGE_H
