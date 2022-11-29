#ifndef TOOLTIP_H
#define TOOLTIP_H


#include <QString>
#include <QTableWidgetItem>
#include "RegFile.h"


#define N 1000


class PipelineDiagram{
public:

    QString Pipe[N][N];

    void clear();

    QString FString(char icode,bool F_stall);
    QString DString(char icode,bool D_stall,char D_stat);
    QString EString(char icode,char E_stat,char ifun=0);
    QString MString(char icode,char M_stat);
    QString WString(char icode,bool W_stall,char W_stat);

    void catchCycle(char f_icode,char D_icode,char E_icode,char E_ifun,char M_icode,char W_icode,
                     char F_stall,char D_stall,char W_stall,char D_stat,char E_stat,char M_stat,char W_stat,int cycle);
};


#endif // TOOLTIP_H
