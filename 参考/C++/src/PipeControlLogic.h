#ifndef PIPE_CONTROL_LOGIC_H
#define PIPE_CONTROL_LOGIC_H

#include "RegStage.h"
#include "OpStage.h"


bool set_F_stall(char E_icode,char E_dstM,char D_icode,char M_icode, char d_srcA , char d_srcB);

bool set_D_stall(char E_icode, char d_srcA, char d_srcB,char E_dstM);

bool set_D_bubble(char E_icode, char e_Cnd, char d_srcA, char d_srcB, char D_icode, char E_dstM, char M_icode);

bool set_E_bubble(char E_icode,char E_dstM, char d_srcA,char d_srcB, char e_Cnd);


bool set_M_bubble(char m_stat,char W_stat);

bool set_W_stall (char W_stat);

class PipeControlLogic
{
public:

    bool F_stall;
    bool D_stall;
    bool D_bubble;
    bool E_bubble;
    bool M_bubble;
    bool W_stall;

    bool set_logic(char W_stat,char M_icode,char m_stat,\
        char e_Cnd,char E_dstM, char E_icode, char d_srcB,char d_srcA,char D_icode)
    {
        F_stall = set_F_stall(E_icode, E_dstM, D_icode,M_icode,d_srcA , d_srcB);
        D_stall = set_D_stall(E_icode, d_srcA, d_srcB, E_dstM);
        D_bubble = set_D_bubble(E_icode, e_Cnd, d_srcA, d_srcB, D_icode, E_dstM, M_icode);
        E_bubble = set_E_bubble(E_icode, E_dstM, d_srcA, d_srcB, e_Cnd);
        M_bubble = set_M_bubble(m_stat, W_stat);
        W_stall = set_W_stall (W_stat);
    }
};

#endif

