//
// Created by aaron on 16-12-6.
//

#include "RegFile.h"

int RegFile::read(char src){
    if(src>=RNONE)
        return 0;
    return reg[src];
}

void RegFile::write(int val, char src){
    if(src<=RNONE)
       reg[src]=val;
}

void RegFile::clear() {
    for(int i=0;i<8;i++)
        reg[i]=0;
}

void RegFile::display(){
    printf("\nEAX %08x | ECX %08x \nEDX %08x | EBX %08x\n"
                   "ESP %08x | EBP %08x\nESI %08x | EDI %08x\n",
           reg[REAX],reg[RECX],reg[REDX],reg[REBX],reg[RESP],reg[REBP],reg[RESI],reg[REDI]);
}

