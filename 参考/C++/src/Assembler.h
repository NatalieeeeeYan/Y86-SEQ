//
// Created by leon on 12/9/16.
//

#ifndef Y86_CORE_ASSEMBLER_H
#define Y86_CORE_ASSEMBLER_H

#include "Memory.h"
#include <fstream>
#include <iostream>

using std::istream;
using std::ostream;

static char SCOLON[] = ":";

static char SPOS[] = ".pos";
static char SALIGN[] = ".align";

static char SINIT[] = "init";
static char SARRAY[] = "array";
static char SMAIN[] = "main";
static char SSTACK[] = "Stack";

static char SCHAR[] = ".char";
static char SINT[] = ".int";
static char SLONG[] = ".long";


static char SHALT[] = "halt";
static char SNOP[] = "nop";

static char SRRMOVL[] = "rrmovl";
static char SIRMOVL[] = "irmovl";
static char SRMMOVL[] = "rmmovl";
static char SMRMOVL[] = "mrmovl";

static char SADDL[] = "addl";
static char SSUBL[] = "subl";
static char SANDL[] = "andl";
static char SXORL[] = "xorl";

static char *SOPL[] ={SADDL,SSUBL,SANDL,SXORL};

static char SJMP[] = "jmp";
static char SJLE[] = "jle";
static char SJL[] = "jl";
static char SJE[] = "je";
static char SJNE[] = "jne";
static char SJGE[] = "jge";
static char SJG[] = "jg";

static char *SJXX[] = {SJMP,SJLE,SJL,SJE,SJNE,SJGE,SJG};

static char SCMOVLE[] = "cmovle";
static char SCMOVL[] = "cmovl";
static char SCMOVE[] = "cmove";
static char SCMOVNE[] = "cmovne";
static char SCMOVGE[] = "cmovge";
static char SCMOVG[] = "cmovg";

static char *SCMOV[] = {SRRMOVL,SCMOVLE,SCMOVL,SCMOVE,SCMOVNE,SCMOVGE,SCMOVG};

static char SCALL[] = "call";

static char SRET[] = "ret";
static char SPUSHL[] = "pushl";
static char SPOPL[] = "popl";

static char SEAX[] = "%eax";
static char SECX[] = "%ecx";
static char SEDX[] = "%edx";
static char SEBX[] = "%ebx";
static char SESP[] = "%esp";
static char SEBP[] = "%ebp";
static char SESI[] = "%esi";
static char SEDI[] = "%edi";

static char *SREG [] = {SEAX,SECX,SEDX,SEBX,SESP,SEBP,SESI,SEDI};

const char CHALT = 0x00;
const char CNOP = 0x10;

const char CRRMOVL = 0x20;
const char CCMOVLE = 0x21;
const char CCMOVL = 0x22;
const char CCMOVE = 0x23;
const char CCMOVNE = 0x24;
const char CCMOVGE = 0x25;
const char CCMOVG = 0x26;


const char CIRMOVL = 0x30;
const char CRMMOVL = 0x40;
const char CMRMOVL = 0x50;

const char COPL = 0x60;
const char CADDL = 0x60;
const char CSUBL = 0x61;
const char CANDL = 0x62;
const char CXORL = 0x63;

const char CJXX = 0x70;
const char CJMP = 0x70;
const char CJLE = 0x71;
const char CJL = 0x72;
const char CJE = 0x73;
const char CJNE = 0x74;
const char CJGE = 0x75;
const char CJG = 0x76;

const char CCALL = 0x80;
const char CRET = 0x90;
const char CPUSHL = 0xa0;
const char CPOPL = 0xb0;

const char AEAX = 0x00;
const char AECX = 0x10;
const char AEDX = 0x20;
const char AEBX = 0x30;
const char AESP = 0x40;
const char AEBP = 0x50;
const char AESI = 0x60;
const char AEDI = 0x70;
const char ANONE = 0xF0;

const char AREG[] = {AEAX,AECX,AEDX,AEBX,AESP,AEBP,AESI,AEDI};

const char BEAX = 0x00;
const char BECX = 0x01;
const char BEDX = 0x02;
const char BEBX = 0x03;
const char BESP = 0x04;
const char BEBP = 0x05;
const char BESI = 0x06;
const char BEDI = 0x07;
const char BNONE = 0x0F;

const char BREG[] = {BEAX,BECX,BEDX,BEBX,BESP,BEBP,BESI,BEDI};


class Assembler
{
public:
    bool compileFile(istream& in, istream& in_cp, Memory& Mem,ostream & out);
    void Y86Read(istream& in,Memory& Mem);

};


#endif //Y86_CORE_ASSEMBLER_H
