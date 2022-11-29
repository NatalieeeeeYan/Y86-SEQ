//
// Created by leon on 12/9/16.
//

#include "Assembler.h"
#include <fstream>
#include <iostream>
#include <cstdio>
#include <iomanip>
#define LENGTH 100
#define fo(i,a,b) for(int i = a;i < b;i++)
#define ex(a) exist(line,a)

#define FUNLENGTH 50
#define SPACELENGTH 20
using namespace std;
//using std::istream;
//using std::ifstream;
//using std::cout;
//using std::endl;

struct node
{
    int temp_adr;
    char TAG[FUNLENGTH];
};


node TAG_ADR[50];
int TagLength = 0;

int StackAdr; //the stack starts here and grows to lower addresses
int StackAdrStart;

void resetAssembler(){
    for(int i=0;i<50;i++){
        for(int j=0;j<FUNLENGTH;j++)
        TAG_ADR[i].TAG[j]=0;
        TAG_ADR[i].temp_adr=0;
    }
    TagLength=StackAdr=0;
}


bool exist(char *target, char *pattern)
{
    char *tar_ptr,*pat_ptr;
    for(tar_ptr = target;*tar_ptr != '#' && *tar_ptr != '\0';tar_ptr++) // # menas the notes.
    {
        for(pat_ptr = pattern;*pat_ptr != '\0';pat_ptr++)
        {
            if(*tar_ptr != *pat_ptr) break;
            else tar_ptr++;
        }
        if(*pat_ptr == '\0') return true;
    }
    return false;
}



char twoReg(char line[])
{
    char a,b;
    char rA[5], rB[5];
    int i = 0;

    char *ptr = line;

    while(*ptr != '%') ptr++;

    while(*ptr != ',')
    {
        if(i == 5) break;
        rA[i++] = *ptr;
        ptr++;
    }

    rA[i] = '\0';
    i = 0;

    while(*ptr != '%') ptr++;

    while(*ptr != ' ' && *ptr != '\0')
    {
        if(i == 5) break;
        rB[i++] = *ptr;
        ptr++;
    }

    rB[i] = '\0';

    if(ex(SMRMOVL))
    {
        fo(i,0,8)
        {
            if(exist(rA,SREG[i]))
                a = BREG[i];
        }
        fo(i,0,8)
        {
            if(exist(rB,SREG[i]))
                b = AREG[i];
        }
    }
    else
    {
        fo(i,0,8)
        {
            if(exist(rA,SREG[i]))
                a = AREG[i];
        }
        fo(i,0,8)
        {
            if(exist(rB,SREG[i]))
                b = BREG[i];
        }
    }

    return a | b;
}


int getNumber(char line[])
{

    if(ex(SSTACK))
        return StackAdr;

    if(ex(" ("))
        return 0;

    fo(j,0,TagLength)
       if(ex(TAG_ADR[j].TAG)  && !(ex(":")))
            return TAG_ADR[j].temp_adr;

    char *ptr = line;

    if(ex(SCOLON))
        while(*ptr != ':') ptr++;

    while(*ptr > '9' || *ptr < '0' && *ptr != '-')  ptr++;

    char s_num[50];
    int i = 0;
    while(*ptr != ',' && *ptr != ' ' && *ptr != '(' && *ptr != '\0')
    {
        s_num[i++] = *ptr;
        ptr++;
    }
    s_num[i] = '\0';
    int num  = 0;
    if(ex("0x"))
        sscanf(s_num,"%x",&num);
    else
        sscanf(s_num,"%d",&num);

    return num;
}


bool Adr(istream& in)
{
    char line[LENGTH];
    int temp_PC = 0;
    int key = 0; // record the times about file reading
    int TAG_index = 0;

    while( key != 2 && in.getline(line,LENGTH) )
    {

        if( ex(SALIGN) )
        {
            char * ptr = line;
            int alignNum = 0;
            int flag = 0;
            while( *ptr != '#' && *ptr != '\0')
            {
                while(*ptr <= '9' && *ptr >= '0' )
                {
                    alignNum = alignNum*10 + *ptr-'0';
                    ptr++;
                    flag = 1;
                }
                if(flag) break;
                ptr++;
            }
            while(temp_PC % alignNum)   temp_PC++;

        }


        if( ex(SCOLON) )//set tag and its address
        {
            char *ptr = line;
            int i = 0;
            while( *ptr != ':' && *ptr != '#' && *ptr != '\0')
            {
                if( (*ptr <= 'Z' && *ptr >= 'A' )|| (*ptr <= 'z' && *ptr >= 'a')\
                        || (*ptr <= '9' && *ptr >= '0' ))
                    TAG_ADR[TAG_index].TAG[i++] = *ptr;
                ptr++;
            }
            TAG_ADR[TAG_index].temp_adr = temp_PC;
            TAG_index++;
        }


        if( ex(SHALT) || ex(SNOP) || ex(SRET) || ex(SCHAR) )
            temp_PC += 1;
        else if( ex(SRRMOVL) || ex(SADDL) || ex( SSUBL) || ex( SANDL)\
         || ex(SXORL) || ex(SPUSHL) || ex(SPOPL) || ex(SCMOVLE)\
         || ex(SCMOVLE) || ex( SCMOVL) || ex(SCMOVE) || ex(SCMOVNE)\
         || ex(SCMOVGE) || ex(SCMOVG) )
            temp_PC += 2;
        else if( ex(SINT) || ex(SLONG) )
            temp_PC += 4;
        else if( ex(SJNE) || ex(SJMP) || ex(SJLE) || ex(SJL)\
            || ex(SJGE) || ex(SJG) || ex(SJE) || ex(SCALL) )
            temp_PC += 5;
        else if( ex(SIRMOVL) || ex(SRMMOVL) || ex(SMRMOVL))
            temp_PC += 6;

        if( ex(SPOS) )
         {
            key++;
            if(key == 1)
            {
                char *ptr = line;

                while(*ptr != '\0')
                {
                    if(*ptr == 'x')
                    {
                        ptr++;
                        while(*ptr <= '9' && *ptr >= '0')
                        {
                            int temp = *ptr - '0';
                            StackAdrStart = StackAdrStart*16 + temp;
                            ptr++;
                        }
                        break;
                    }
                    ptr++;
                }

                while(temp_PC != StackAdrStart) temp_PC++;
            }
         }

    }

    char *ptr = line;

    while(*ptr != '\0')
    {
        if(*ptr == 'x')
        {
            ptr++;
            while(*ptr <= '9' && *ptr >= '0')
            {
                int temp = *ptr - '0';
                StackAdr = StackAdr*16 + temp;
                ptr++;
            }
            break;
        }
        ptr++;
    }

    TagLength = TAG_index;

}


bool Assembler::compileFile(istream& in, istream&in_cp,Memory &Mem ,ostream &out)
{
    resetAssembler();
    Mem.clear();
    Adr(in_cp);
    // fo(i,0,TagLength)
    //     cout << TAG_ADR[i].temp_adr<< ":  "<< TAG_ADR[i].TAG<<endl;

    char line[LENGTH];
    int Mem_index = 0;
    int pre_index = 0;
    int pos_flag = 0;
    int init_flag =0;

//     while(in.getline(line,LENGTH))
//     {
//         if( ex(SPOS))
//         {
//             init_flag = 1;
//             break;
//         }
//         out << string(SPACELENGTH,' ')<< "| "<< line<<endl;
//     }// read to the beginning
//     if(init_flag == 1)
//         out <<"0x000: "<< string(SPACELENGTH -7 ,' ')<< "| "<< line<<endl;

    while(in.getline(line,LENGTH))
    {
        pre_index = Mem_index;

        if(ex(SHALT))   Mem.mem[Mem_index++] = CHALT;
        else if(ex(SNOP))   Mem.mem[Mem_index++] = CNOP;
        else if(ex(SRET))   Mem.mem[Mem_index++] = CRET;
        else if(ex(SRRMOVL) || ex(SCMOVLE) || ex(SCMOVL) || ex(SCMOVE)\
        || ex(SCMOVNE) || ex(SCMOVGE) || ex(SCMOVG) || ex(SADDL)\
        || ex(SSUBL) || ex(SANDL) || ex(SXORL) )
        {

            fo(i,0,7)
                if(ex(SCMOV[i]))
                {
                    Mem.mem[Mem_index++] = CRRMOVL + i;
                    break;
                }
            fo(i,0,4)
                if(ex(SOPL[i]))
                {
                    Mem.mem[Mem_index++] = COPL + i;
                }
            char a_b = twoReg(line);
            Mem.mem[Mem_index++] = a_b;
        }
        else if(ex(SIRMOVL) || ex(SRMMOVL) || ex(SMRMOVL))
        {
            if(ex(SIRMOVL))
            {
                Mem.mem[Mem_index++] = CIRMOVL;

                char a = ANONE,b;
                fo(i,0,8)
                {
                    if(ex(SREG[i]))
                        b = BREG[i];
                }
                char a_b = a|b;
                Mem.mem[Mem_index++] = a_b;

            }
            else
            {
                if(ex(SRMMOVL))
                    Mem.mem[Mem_index++] = CRMMOVL;
                else
                    Mem.mem[Mem_index++] = CMRMOVL;

                char a_b = twoReg(line);
                Mem.mem[Mem_index++] = a_b;
            }



            int num = getNumber(line);
            char v_1,v_2,v_3,v_4;
            v_1 = num;v_2 = num >> 8;v_3 = num >> 16; v_4 = num >> 24;

            Mem.mem[Mem_index++] = v_1;
            Mem.mem[Mem_index++] = v_2;
            Mem.mem[Mem_index++] = v_3;
            Mem.mem[Mem_index++] = v_4;
        }
        else if(ex(SPUSHL) || ex(SPOPL))
        {
            if(ex(SPUSHL))  Mem.mem[Mem_index++] = CPUSHL;
            else Mem.mem[Mem_index++] = CPOPL;

            char b = BNONE,a;
            fo(i,0,8)
            {
                if(ex(SREG[i]))
                    a = AREG[i];
            }
            char a_b = a|b;
            Mem.mem[Mem_index++] = a_b;
        }
        else if(ex(SJMP) || ex(SJLE)  || ex(SJL)|| ex(SJE)\
            || ex(SJNE)|| ex(SJGE)|| ex(SJG) || ex(SCALL))
        {
            if(ex(SCALL))
                Mem.mem[Mem_index++] = CCALL;
            else
            {
                fo(i,0,7)
                    if(ex(SJXX[i]))
                    {
                        Mem.mem[Mem_index++] = CJXX + i;
                        break;
                    }
            }

            char *ptr = line;

            char word[30];
            int i = 0;
            int Dest;
            while(*ptr == ' ') ptr++;
            while(*ptr != ' ') ptr++;
            while(*ptr == ' ') ptr++;

            while(*ptr != ' ')
            {
                word[i++] = *ptr;
                ptr++;
            }
            word[i] = '\0';

            fo(j,0,TagLength)
            {
                if(exist(word,TAG_ADR[j].TAG))
                {
                    Dest = TAG_ADR[j].temp_adr;
                    break;
                }
            }
            char v_1,v_2,v_3,v_4;
            v_1 = Dest;v_2 = Dest >> 8;v_3 = Dest >> 16; v_4 = Dest >> 24;
            Mem.mem[Mem_index++] = v_1;
            Mem.mem[Mem_index++] = v_2;
            Mem.mem[Mem_index++] = v_3;
            Mem.mem[Mem_index++] = v_4;
        }

        else if(ex(SALIGN))
        {
            int alignNum = getNumber(line);
            while(Mem_index % alignNum) Mem.mem[Mem_index++] = 0x00;
        }

        else if(ex(SCHAR))
        {
            int num = getNumber(line);
            char v_1 = num;
            Mem.mem[Mem_index++] = v_1;
        }
        else if(ex(SINT) || ex(SLONG))
        {
            int num = getNumber(line);
            char v_1,v_2,v_3,v_4;
            v_1 = num;v_2 = num >> 8;v_3 = num >> 16; v_4 = num >> 24;
            Mem.mem[Mem_index++] = v_1;
            Mem.mem[Mem_index++] = v_2;
            Mem.mem[Mem_index++] = v_3;
            Mem.mem[Mem_index++] = v_4;
        }




        int space_cnt = 0;
        unsigned int out_ch;

        if(ex(".align"))
            pre_index = Mem_index;

        if(ex(".pos"))
        {
            pos_flag++;
            if(pos_flag == 1)
            {
                pre_index = StackAdrStart;
                while(Mem_index != pre_index) Mem.mem[Mem_index++] = 0x00;
            }

            else if(pos_flag == 2)
            pre_index = StackAdr;
        }

        if( ex("Stack") && pos_flag == 2)
            pre_index = StackAdr;


        if( ex("/*") || (pre_index == Mem_index && !ex(".align") && !ex(".pos") && !ex("Stack") ) )
            out << string(SPACELENGTH,' ')<< "| "<< line<<endl;
        else
        {
            out << "0x";
            out << hex <<setfill('0') << setw(3)<< pre_index;
            out <<": ";
            fo(i,pre_index,Mem_index)
            {
                out_ch = Mem.mem[i] & 0x000000ff;
                out << setfill('0') << setw(2) << hex << out_ch;
                space_cnt++;
            }
            out << string(SPACELENGTH - 7 - 2*space_cnt,' ') << "| "<<line<<endl;
        }
    }

    return true;
}


void Assembler::Y86Read(istream& in,Memory& Mem)
{
    char num;
    int index = 0;
    while(in >> num)
        Mem.mem[index++] = num;
}
