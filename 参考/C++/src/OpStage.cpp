//
// Created by aaron on 16-12-6.
//

#include "OpStage.h"

/*** for f_stage  ***/

void f_stage::sel_PC(int M_icode, bool M_Cnd ,char W_icode,int M_valA,int W_valM,int F_predPC){
    if(M_icode == IJXX&&!M_Cnd)
        pc=M_valA;
    else if(W_icode==IRET)
        pc=W_valM;
    else pc=F_predPC;
    printf("pc=%x\n",pc);
}

void f_stage::fetch(Memory &read){
    bool imem_error=false;
    if(pc>M_MAX) imem_error=true;

    char temp_icode_ifun;
    char temp_icode;
    char temp_ifun;

    if(!imem_error){
        temp_icode_ifun=read.fetchChar(pc);
        temp_icode=(temp_icode_ifun&0xF0)>>4;
        temp_ifun=temp_icode_ifun&0xF;
        icode=imem_error?INOP:temp_icode;
        ifun=imem_error?FNONE:temp_ifun;
    }
    instr_valid=true;
    if((icode<IHALT||icode>IPOPL)||(icode==IOPL&&(ifun<FNONE||ifun>XORL))||((icode==IJXX||icode==IRRMOVL)&&(ifun<JMP||ifun>JG))) instr_valid=false;

    if(imem_error) {
        stat=SADR;
        icode=INOP;
        ifun=FNONE;
        rA=rA=RNONE;
        valC=0;
        valP=pc+1;
        return;
    }
    else if(!instr_valid)
        stat=SINS;
    else if(icode==IHALT)
        stat=SHLT;
    else stat=SAOK;

    need_regids=((icode>=IRRMOVL&&icode<=IOPL)||(icode>=IPUSHL&&icode<=IPOPL));
    need_valC=(icode>=IIRMOVL&&icode<=ICALL&&icode!=IOPL);

    valP=pc;

    if(need_regids){
        char rA_rB=read.fetchChar(pc+1);
        rA=(rA_rB&0xF0)>>4;
        rB=rA_rB&0xF;
        if(rA<0||rB<0||rA>8||rB>8) instr_valid=false;
        if(!need_valC) {
            valC=0;
            valP+=2;
        }
        else{
            valC=read.fetchInt(pc+2);
            valP+=6;
        }
    }

    else {
        if(!need_valC) {
            rA=rB=RNONE;
            valC=0;
            valP+=1;
        }
        else {
            rA=rB=RNONE;
            valC=read.fetchInt(pc+1);
            valP+=5;
        }
        }

}

void f_stage::pred_PC(){
    if(icode==IJXX||icode==ICALL) predPC=valC;
    else predPC=valP;
}


void f_stage::initialize()
{
    stat=SBUB;
    icode=INOP;
    ifun=FNONE;
    rA=rB=RNONE;
    instr_valid=need_regids=need_valC=0;
    pc=predPC=valC=valP=0;
}

void f_stage::display() {
    printf("\n");

    printf("  f_stat = %02x\n", stat);
    printf("  f_icode= %02x\n", icode);
    printf("  f_ifun = %02x\n", ifun);
    printf("  f_rA   = %02x\n", rA);
    printf("  f_rB   = %02x\n", rB);
    printf("  f_valC = %08x\n", valC);
    printf("  f_valP = %08x\n", valP);
    printf("  predPC = %08x\n", predPC);

    printf("\n");

    printf("  instr_valid = %01x\n", instr_valid);
    printf("  need_regids = %01x\n", need_regids);
    printf("  need_valC   = %01x\n", need_valC);
}


/***for d_stage ***/

void d_stage::regFile_write(int w_valE,char w_dstE,int w_valM,char w_dstM, RegFile &a)
{

    a.write(w_valE,w_dstE);
    a.write(w_valM,w_dstM);
    a.display();
}

void d_stage::ID(char D_icode,char D_rA,char D_rB){
    if(D_icode==IRRMOVL||D_icode==IRMMOVL||D_icode==IOPL||D_icode==IPUSHL)
        srcA=D_rA;
    else if(D_icode==IPOPL||D_icode==IRET)
        srcA=RESP;
    else srcA=RNONE;

    if(D_icode==IOPL||D_icode==IRMMOVL||D_icode==IMRMOVL)
        srcB=D_rB;
    else if(D_icode==IPUSHL||D_icode==IPOPL||D_icode==ICALL||D_icode==IRET)
        srcB=RESP;
    else srcB=RNONE;

    if(D_icode==IRRMOVL||D_icode==IIRMOVL||D_icode==IOPL)
        dstE=D_rB;
    else if(D_icode==IPUSHL||D_icode==IPOPL||D_icode==ICALL||D_icode==IRET)
        dstE=RESP;
    else dstE=RNONE;

    if(D_icode==IMRMOVL||D_icode==IPOPL)
        dstM=D_rA;
    else dstM=RNONE;
}

void d_stage::regFile_read(RegFile &a){
        rvalA=a.read(srcA);
        rvalB=a.read(srcB);
}

void d_stage::sel_fwdA(char D_icode,int D_valP,char e_dstE,int e_valE,char M_dstM, int m_valM,
                       char M_dstE,int M_valE, char W_dstM,int W_valM,char W_dstE, int W_valE){
    if(D_icode == ICALL || D_icode == IJXX) valA=D_valP;
    else if(srcA==e_dstE) {valA=e_valE;printf("\n111\n");}
    else if(srcA==M_dstM) valA=m_valM;
    else if(srcA==M_dstE) valA=M_valE;
    else if(srcA==W_dstM) valA=W_valM;
    else if(srcA==W_dstE) valA=W_valE;
    else valA=rvalA;
}

void d_stage::fwdB(char e_dstE,int e_valE,char M_dstM, int m_valM,
                       char M_dstE,int M_valE, char W_dstM,int W_valM, char W_dstE, int W_valE){
    if(srcB==e_dstE) valB=e_valE;
    else if(srcB==M_dstM) valB=m_valM;
    else if(srcB==M_dstE) valB=M_valE;
    else if(srcB==W_dstM) valB=W_valM;
    else if(srcB==W_dstE) valB=W_valE;
    else valB=rvalB;
}


void d_stage::initialize()
{
    dstE=dstM=srcA=srcB=RNONE;
    valA=valB=rvalA=rvalB=0;
}

void d_stage::display(){
    printf("\n");

    printf("  d_dstE = %02x\n", dstE);
    printf("  d_dstM = %02x\n", dstM);
    printf("  d_srcA = %02x\n", srcA);
    printf("  d_srcB = %02x\n", srcB);
    printf("\n");
    printf("  d_rvalA= %08x\n",rvalA);
    printf("  d_rvalB= %08x\n",rvalB);
    printf("  d_valA = %08x\n", valA);
    printf("  d_valB = %08x\n", valB);

}

/*** for e_stage ***/
void e_stage::aluAB(char E_icode,int E_valA,int E_valB,int E_valC){
    if(E_icode==IRRMOVL||E_icode==IOPL)
        aluA=E_valA;
    else if(E_icode==IIRMOVL||E_icode==IRMMOVL||E_icode==IMRMOVL)
        aluA=E_valC;
    else if(E_icode==ICALL||E_icode==IPUSHL)
        aluA=-4;
    else if(E_icode==IRET||E_icode==IPOPL)
        aluA=4;
    else aluA=0;

    if(E_icode==IRMMOVL||E_icode==IMRMOVL||E_icode==IOPL||E_icode==ICALL
        ||E_icode==IPUSHL||E_icode==IRET||E_icode==IPOPL)
        aluB=E_valB;
    else aluB=0;
}

void e_stage::alu(char E_icode, char E_ifun,char m_stat, char W_stat,ALU &a ){
    alufun=E_icode==IOPL?E_ifun:ALUADD;
    set_cc=(E_icode==IOPL);
    valE=a.op(set_cc,aluA,alufun,aluB);
    a.cc(CC);
}

void e_stage::set_Cnd(char E_stat,char E_icode,char E_ifun){
    if(E_stat!=SAOK) return;
    if(E_icode == IJXX||E_icode==IRRMOVL){
        switch(E_ifun) {
            case JMP:
                Cnd = true;;
                break;
            case JLE:
                Cnd=(CC[SF]^CC[OVF])|CC[ZF];
                break;
            case JL:
                Cnd=CC[SF]^CC[OVF];
                break;
            case JE:
                Cnd=CC[ZF];
                break;
            case JNE:
                Cnd=!CC[ZF];
                break;
            case JGE:
                Cnd=~(CC[SF]^CC[OVF]);
                break;
            case JG:
                Cnd=(!(CC[SF]^CC[OVF]))&&(!CC[ZF]);
                break;
        }
    }
    else Cnd=false;
}

void e_stage::set_dstE(char E_icode,char E_dstE){
    dstE=(E_icode==IRRMOVL&&!Cnd)?RNONE:E_dstE;
}


void e_stage::initialize()
{
    alufun=ADDL;
    dstE=RNONE;
    valE=aluA=aluB=0;
    Cnd=set_cc=CC[1]=CC[2]=false;
    CC[0]=true;
}

void e_stage::display() {
    printf("\n");
    printf("  alufun = %02x\n", alufun);
    printf("  e_aluA = %08x\n", aluA);
    printf("  e_aluB = %08x\n", aluB);
    printf("  e_valE = %08x\n", valE);
    printf("  e_dstE = %02x\n", dstE);
    printf("\n");
    printf("  e_Cnd  = %01x\n", Cnd);
    printf("  set_cc = %01x\n", set_cc);
    printf("\n  ZF = %01x\n  SF = %01x\n  OF = %01x\n",CC[0],CC[1],CC[2]);
}

/*** for m_stage ***/

void m_stage::mem(char M_stat,char M_icode, int M_valE, int M_valA, Memory &m) {
    int mem_addr;
    bool mem_read= false,mem_write= false;

    if(M_icode==IRMMOVL||M_icode==IPUSHL||M_icode==ICALL||M_icode==IMRMOVL)
        mem_addr=M_valE;
    else if(M_icode==IPOPL||M_icode==IRET) mem_addr=M_valA;

    dmem_error=(mem_addr<0)||(mem_addr>=M_MAX);
    stat=dmem_error?SADR:M_stat;

    if(M_icode==IMRMOVL||M_icode==IPOPL||M_icode==IRET)
        mem_read=true;
    else if(M_icode==IRMMOVL||M_icode==IPUSHL||M_icode==ICALL)
        mem_write=true;

    if((!dmem_error)&&mem_read) valM=m.fetchInt(mem_addr);  else valM=0;
    if((!dmem_error)&&mem_write) m.write(M_valA,mem_addr);
}

void m_stage::initialize()
{
    stat=SBUB;
    valM=0;
    dmem_error=false;
}

void m_stage::display(){
    printf("\n");
    printf("  m_stat = %02x\n", stat);
    printf("  m_valM = %08x\n", valM);
    printf("  dmem_error = %01x\n", dmem_error);
}

/*** for w_stage ***/
void w_stage::initialize()
{
    stat=SBUB;
    dstE=dstM=RNONE;
    valE=valM=0;
}

void w_stage::update(char W_dstE, int W_valE, char W_dstM, int W_valM,char W_stat) {
    dstE=W_dstE;valE=W_valE;dstM=W_dstM;valM=W_valM;
    stat=W_stat==SBUB?SAOK:W_stat;
}
