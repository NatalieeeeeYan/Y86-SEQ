#include "PipeDiagram.h"
#include <QDebug>

int pre_row;
int stall_row;

int pre_W_stall;
int pre_D_stall;
int pre_F_stall;

int D_count;
int F_count;

void PipelineDiagram::clear()
{
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            Pipe[i][j].clear();
    pre_row=0;
    stall_row=0;

    pre_W_stall=0;
    pre_D_stall=0;
    pre_F_stall=0;

    D_count=0;
    F_count=0;
}

QString PipelineDiagram::FString(char icode,bool F_stall)
{
    QString stage="F";
    QString temp;
    if(icode==IOPL||icode==IRRMOVL||icode==IPUSHL||icode==IPOPL)
        temp = "\nicode:ifun <-- M1[PC]\n"
               "rA:rB <-- M1[PC+1]\n"
               "valP <-- PC+2\n";
    else if(icode==IIRMOVL||icode==IRMMOVL||icode==IMRMOVL)
        temp = "\nicode:ifun <-- M1[PC]\n"
               "rA:rB <-- M1[PC+1]\n"
               "valC <-- M4[PC+2]\n"
               "valP <-- PC+6\n";
    else if(icode==ICALL||icode==IJXX)
        temp = "\nicode:ifun <-- M1[PC]\n"
               "valC <-- M4[PC+1]\n"
               "valP <-- PC+5\n";
    else if(icode==IRET)
        temp = "\nicode:ifun <-- M1[PC]\n";
    else temp = " ";
    return F_stall?stage + temp +"F_Stall = 1\n":stage + temp;
}

QString PipelineDiagram::DString(char icode,bool D_stall,char D_stat){
    QString stage=D_stat==SBUB?" BUBBLE":"D";
    QString temp;
    if(icode==IOPL||icode==IRMMOVL)
        temp = "\nvalA <-- R[rA]\n"
               "valB <-- R[rB]\n";
    else if(icode==IPUSHL||icode==IPOPL)
        temp = "\nvalA <-- R[rA]\n"
               "valB <-- R[%esp]\n";
    else if(icode==IRRMOVL)
        temp = "\nvalA <-- R[rA]\n";
    else if(icode==IMRMOVL)
        temp = "\nvalB <-- R[rB]\n";
    else if(icode==ICALL)
        temp = "\nvalB <-- R[$esp]\n";
    else if(icode==IRET)
        temp = "\nvalA <-- R[%esp]\n"
               "valB <-- R[%esp]\n";
    else temp = " ";
    return D_stall?stage + temp +"D_Stall = 1\n":stage + temp;
}

QString PipelineDiagram::EString(char icode,char E_stat,char ifun)
{
    QString stage=E_stat==SBUB?" BUBBLE":"E";
    QString temp;
    if(icode==IRMMOVL&&ifun==0||icode==IMRMOVL)
        temp = "\nvalE <-- valB+valC\n";
    else if(icode==IPUSHL||icode==ICALL)
        temp = "\nvalE <-- valB+(-4)\n";
    else if(icode==IPOPL||icode==IRET)
        temp = "\nvalE <-- valB+4\n";
    else if(icode==IRMMOVL&&ifun)
        temp = "\nvalE <-- valB+valC\n"
               "Cnd <-- Cond[CC,ifun]";
    else if(icode==IRRMOVL)
        temp = "\nvalE <-- 0+valA\n";
    else if(icode==IIRMOVL)
        temp = "\nvalE <-- 0+vlaC\n";
    else if(icode==IJXX)
        temp = "\nCnd <-- Conde[CC,ifun]\n";
    else if(icode==IOPL)
        temp = "\nvalE <-- valB OP valA\n"
               "Set CC \n";
    else temp = " ";
    return stage + temp;
}

QString PipelineDiagram::MString(char icode,char M_stat)
{
    QString stage=M_stat==SBUB?" BUBBLE":"M";
    QString temp;
    if(icode==IRMMOVL||icode==IPUSHL)
        temp = "\nM4[valE] <-- valA\n";
    else if(icode==IMRMOVL)
        temp = "\nvalM <-- M4[valE]\n";
    else if(icode==IPOPL||icode==IRET)
        temp = "\nvalM <-- <M4[valA]\n";
    else if(icode==ICALL)
        temp = "\nM4[valE] <-- valP\n";
    else temp = " ";
    return stage + temp;
}

QString PipelineDiagram::WString(char icode,bool W_stall,char W_stat)
{
    QString stage=W_stat==SBUB?" BUBBLE":"W";
    QString temp;
    if(icode==IOPL||icode==IRRMOVL||icode==IIRMOVL)
        temp = "\nR[rB] <-- valE\n";
    else if(icode==IPUSHL||icode==ICALL||icode==IRET)
        temp = "\nR[%esp] <-- valE\n";
    else if(icode==IMRMOVL)
        temp = "\nR[rA] <-- valM\n";
    else if(icode==IPOPL)
        temp = "\nR[%esp] <-- valE\n"
               "R[rA] <-- valM\n";
    else temp = " ";
    return stage + temp;
}

/*
void PipelineDiagram::catchCycle(char f_icode, char D_icode, char E_icode, char E_ifun,char M_icode, char W_icode, char F_stall,
                     char D_stall, char W_stall, char D_stat, char E_stat, char M_stat, char W_stat)
{
    QVector<QString> col;
    QString str;

    if(W_stat==SBUB) str=" ";
    else str="W";
    str+=WString(W_icode);
    if(W_stat!=SBUB||!F_stall&&!D_stall) col.push_back(str);

    str.clear();
    if(M_stat==SBUB) str=" ";
    else str="M";
    str+=MString(M_icode);
    if(M_stat!=SBUB||!F_stall&&!D_stall) col.push_back(str);

    str.clear();
    if(E_stat==SBUB) str=" ";
    else str="E";
    str+=EString(E_icode,E_ifun);
    if(E_stat!=SBUB||!F_stall&&!D_stall) col.push_back(str);

    str.clear();
    if(D_stat==SBUB) str=" ";
    else str="D";
    str+=DString(D_icode);
    if(E_stat!=SBUB||!F_stall) col.push_back(str);

    str.clear();
    str="F";
    str+=FString(f_icode);
    col.push_back(str);
    for(int i=0;i<col.size();i++)
    qDebug()<<col[i];
    column *temp=new column;
    temp->items=col;
    if(W_stall) temp->start=1;
    else if(D_stall) temp->start=4;
    else if(F_stall) temp->start=5;

    pipeline.push_back(temp);
}*/


void PipelineDiagram::catchCycle(char f_icode, char D_icode, char E_icode, char E_ifun,char M_icode, char W_icode, char F_stall,
                     char D_stall, char W_stall, char D_stat, char E_stat, char M_stat, char W_stat,int cycle)
{
    int row2=pre_row+10;
    int row=pre_row+1;
    if(pre_W_stall&&W_stall||cycle==1)
        row=pre_row;
    else if(pre_D_stall&&D_stall)
        row2=pre_D_stall;
    else if(pre_F_stall&&F_stall)
        row2=pre_F_stall;
    pre_row=row;
    qDebug()<<"row:"<<row<<endl;
    int i=0;
    if((!F_stall&&F_count==3)||F_count==2||F_count==1||(!D_stall&&D_count==2)||D_count==1){
        for(;row+i<stall_row&&i<5;i++){
            switch(i){
            case 0:Pipe[row+i][cycle] = WString(W_icode,W_stall,W_stat); pre_W_stall=W_stall?row+i:0;break;
            case 1:Pipe[row+i][cycle] = MString(M_icode,M_stat);break;
            case 2:Pipe[row+i][cycle] = EString(E_icode,E_stat,E_ifun);break;
            case 3:Pipe[row+i][cycle] = DString(D_icode,D_stall,D_stat); pre_D_stall=D_stall?row+i:0;break;
            case 4:Pipe[row+i][cycle] = FString(f_icode,F_stall);pre_F_stall=F_stall?row+i:0;
            }
        }

        int sel;
        if(D_count){
            sel=D_count;D_count--;
        }
        else if(F_count){
            qDebug()<<"F_count:"<<F_count<<"  stall_row:"<<stall_row<<endl;
            sel=F_count;F_count--;
        }
        i=stall_row;
        switch(sel){
        case 0:Pipe[i][cycle] = WString(W_icode,W_stall,W_stat); pre_W_stall=W_stall?i:0;i++;
        case 1:Pipe[i][cycle] = MString(M_icode,M_stat);i++;
        case 2:Pipe[i][cycle] = EString(E_icode,E_stat,E_ifun);i++;
        case 3:Pipe[i][cycle] = DString(D_icode,D_stall,D_stat); pre_D_stall=D_stall?i:0;i++;
        case 4:Pipe[i][cycle] = FString(f_icode,F_stall);pre_F_stall=F_stall?i:0;
        }
        if((!D_count&&!F_count)&&(stall_row-1<pre_row)) pre_row=stall_row-1;

    }
    else{
        for(;i+row<row2&&i<5;i++){
            switch(i){
            case 0:Pipe[row+i][cycle] = WString(W_icode,W_stall,W_stat); pre_W_stall=W_stall?row+i:0;break;
            case 1:Pipe[row+i][cycle] = MString(M_icode,M_stat);break;
            case 2:Pipe[row+i][cycle] = EString(E_icode,E_stat,E_ifun);break;
            case 3:Pipe[row+i][cycle] = DString(D_icode,D_stall,D_stat); pre_D_stall=D_stall?row+i:0;break;
            case 4:Pipe[row+i][cycle] = FString(f_icode,F_stall);pre_F_stall=F_stall?row+i:0;
             }
        }
         if(i!=5){
             if(pre_D_stall&&D_stall) {
                 Pipe[row+i][cycle] = DString(D_icode,D_stall,D_stat);
                 pre_D_stall=D_stall?row+i:0;
                 Pipe[row+i+1][cycle] = FString(f_icode,F_stall);
                 pre_F_stall=F_stall?row+i+1:0;
                 D_count=2;
                 stall_row=pre_D_stall;
                 }
            else if(pre_F_stall&&F_stall){
                Pipe[row+i][cycle] = FString(f_icode,F_stall);
                pre_F_stall=F_stall?row+i:0;
                F_count=3;
                stall_row=pre_F_stall;
            }
        }
    }
}





