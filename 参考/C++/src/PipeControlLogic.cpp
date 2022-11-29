//
// Created by aaron on 16-12-6.
//

#include "PipeControlLogic.h"

bool set_F_stall(char E_icode,char E_dstM,char D_icode,char M_icode, char d_srcA , char d_srcB)
{

    if(  (    (E_icode == IMRMOVL || E_icode == IPOPL) && \
    (E_dstM == d_srcA || E_dstM == d_srcB)    ) ||\
        (D_icode == IRET || E_icode == IRET || M_icode == IRET) )
    return true;

    else return false;
}

bool set_D_stall(char E_icode, char d_srcA, char d_srcB,char E_dstM)
{
    if(( E_icode == IMRMOVL || E_icode == IPOPL) && (E_dstM == d_srcA || E_dstM == d_srcB) )
        return true;
    else return false;
}

bool set_D_bubble(char E_icode, char e_Cnd, char d_srcA, char d_srcB, char D_icode, char E_dstM, char M_icode)
{
    if(  ( E_icode == IJXX && !e_Cnd ) || !(  (E_icode == IMRMOVL \
        || E_icode == IPOPL)  && (E_dstM == d_srcA || E_dstM == d_srcB) )  && \
        ( D_icode == IRET || E_icode == IRET || M_icode == IRET)  )
    return true;
    else return false;
}

bool set_E_bubble(char E_icode,char E_dstM, char d_srcA,char d_srcB, char e_Cnd)
{
    if( (E_icode == IJXX && !e_Cnd)  ||   ( (E_icode == IMRMOVL|| E_icode == IPOPL)  &&\
     (E_dstM == d_srcA || E_dstM == d_srcB)  )    )
        return true;
    else return false;
}

bool set_M_bubble(char m_stat,char W_stat)
{
    if( (m_stat == SADR || m_stat == SINS || m_stat == SHLT) ||\
     (W_stat == SADR || W_stat == SINS || W_stat == SHLT)  )
        return true;
    else return false;
}

bool set_W_stall (char W_stat)
{
    if(W_stat == SADR || W_stat == SINS || W_stat == SHLT)
        return true;
    else return false;
}
