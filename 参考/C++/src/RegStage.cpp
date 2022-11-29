//
// Created by aaron on 16-12-11.
//

#include "RegStage.h"
#include "PipeControlLogic.h"
#include <iostream>

using namespace std;

void F_register::update(bool F_stall,int f_predPC)
{
    if(F_stall) return;
    predPC=f_predPC;
}

void F_register::initialize()
{
    predPC=0;
}

void F_register::display(){printf("  F_predPC = %08x\n",predPC);}

void D_register::update(bool D_bubble, bool D_stall, char f_stat,char f_icode, char f_ifun,char f_rA,char f_rB,int f_valC,int f_valP)
{
    if(D_stall)
        return;
    if(D_bubble)
        stat = SBUB;
    else
        stat=f_stat;

    if(stat!=SBUB){
        icode=f_icode;
        ifun=f_ifun;
        rA=f_rA;
        rB=f_rB;
        valC=f_valC;
        valP=f_valP;
    }
    else
        {
            icode = INOP;
            ifun=FNONE;
            rA=RNONE;
            rB=RNONE;
            valC=0;
            valP=0;
    }
}

void D_register::initialize()
{
    stat=SBUB;
    icode=INOP;
    ifun=FNONE;
    rA=rB=RNONE;
    valC=valP=0;

}


void D_register::display(){

        printf("\n");

        printf("  D_stat = %02x\n", stat);
        printf("  D_icode= %02x\n", icode);
        printf("  D_ifun = %02x\n", ifun);
        printf("  D_rA   = %02x\n", rA);
        printf("  D_rB   = %02x\n", rB);
        printf("  D_valC = %08x\n", valC);
        printf("  D_valP = %08x\n", valP);

    }


void E_register::update(bool E_bubble,char D_stat,char D_icode,char D_ifun,int D_valC,int d_valA,int d_valB,
            char d_dstE,char d_dstM,char d_srcA,char d_srcB)
{

    if(E_bubble)
        stat = SBUB;

    else
        stat= D_stat;

    if(stat!=SBUB){
        icode=D_icode;
        ifun=D_ifun;
        valC=D_valC;
        valA=d_valA;
        valB=d_valB;
        dstE=d_dstE;
        dstM=d_dstM;
        srcA=d_srcA;
        srcB=d_srcB;
        }
    else {
            icode = INOP;
            ifun=FNONE;
            valC=0;
            valA=0;
            valB=0;
            dstE=RNONE;
            dstM=RNONE;
            srcA=RNONE;
            srcB=RNONE;
    }
}

void E_register::initialize()
{
    stat=SBUB;
    icode=INOP;
    ifun=FNONE;
    valC=valA=valB=0;
    dstE=dstM=srcA=srcB=RNONE;
}


void E_register::display(){
    printf("\n");

    printf("  E_stat = %02x\n", stat);
    printf("  E_icode= %02x\n", icode);
    printf("  E_ifun = %02x\n", ifun);
    printf("\n");
    printf("  E_valC = %08x\n", valC);
    printf("  E_valA = %08x\n", valA);
    printf("  E_valB = %08x\n", valB);
    printf("\n");
    printf("  E_dstE = %02x\n",dstE);
    printf("  E_dstM = %02x\n",dstM);
    printf("  E_srcA = %02x\n",srcA);
    printf("  E_srcB = %02x\n",srcB);

}

void M_register::update(bool M_bubble, char E_stat,char E_icode,bool e_Cnd,
    int e_valE, int E_valA,char e_dstE,char E_dstM) {

    if(M_bubble)
        stat = SBUB;

    else
        stat=E_stat;

    if(stat!=SBUB){
        icode=E_icode;
        Cnd=e_Cnd;
        valE=e_valE;
        valA=E_valA;
        dstE=e_dstE;
        dstM=E_dstM;
        }
     else
        {
            icode = INOP;
            Cnd=0;
            valE=0;
            valA=0;
            dstE=RNONE;
            dstM=RNONE;
        }

}

void M_register::initialize()
{
    stat=SBUB;
    icode=INOP;
    valA=valE=0;
    dstE=dstM=RNONE;
}


void M_register::display(){
    printf("\n");
    printf("  M_stat = %02x\n", stat);
    printf("  M_icode = %02x\n", icode);
    printf("  M_Cnd = %01x\n", Cnd);
    printf("\n");
    printf("  M_valE = %08x\n", valE);
    printf("  M_valA = %08x\n", valA);
    printf("\n");
    printf("  M_dstE = %02x\n",dstE);
    printf("  M_dstM = %02x\n",dstM);

}

void W_register::update(bool W_stall, char m_stat,char M_icode,int M_valE,int m_valM,char M_dstE,char M_dstM){
    if (W_stall) return;
    stat=m_stat;
    if(stat!=SBUB){
    icode=M_icode;
    valE=M_valE;
    valM=m_valM;
    dstE=M_dstE;
    dstM=M_dstM;
    }
    else {
        icode=INOP;
        valE = 0;
        valM = 0;
        dstE = RNONE;
        dstM = RNONE;
    }
}

void W_register::initialize()
{
    stat=SBUB;
    icode=INOP;
    valM=valE=0;
    dstE=dstM=RNONE;
}

void W_register::display(){
    printf("\n");
    printf("  W_stat = %02x\n", stat);
    printf("  W_icode= %02x\n", icode);
    printf("\n");
    printf("  W_valE = %08x\n", valE);
    printf("  W_valM = %08x\n", valM);
    printf("\n");
    printf("  W_dstE = %02x\n",dstE);
    printf("  W_dstM = %02x\n",dstM);
}

