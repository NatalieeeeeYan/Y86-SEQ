#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QTextStream>
#include <QDebug>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QUrl>
#include <QFile>
#include <fstream>
#include <string>
#include <QString>
#include <stdlib.h>
#include <unistd.h>
#include <QTime>
#include <iostream>

/******/

#include "OpStage.h"
#include "Assembler.h"
#include "RegFile.h"
#include "ALU.h"
#include "Memory.h"
#include "RegStage.h"
#include "qtimer.h"
#include "PipeControlLogic.h"


using namespace std;

bool ini=1;
int clk;
int bub;
int adr[7];
int val[7];
int convey;
int ini_nine;
int msec=1000;

PipeControlLogic Con;
Memory Mem;
RegFile Reg;
ALU Alu;
f_stage f;
d_stage d;
e_stage e;
m_stage m;
w_stage w;
F_register F;
D_register D;
E_register E;
M_register M;
W_register W;
PipelineDiagram tab;


QTimer *timer=new QTimer();



/********To String**********/

QString changeColor(QString temp,QLabel *l){
    if(ini) return "<font color=black>"+temp+"<\font>";
    if("<font color=RoyalBlue><b>"+temp+"<\b><\font>"==l->text()||"<font color=black>"+temp+"<\font>"==l->text())
    return "<font color=black>"+temp+"<\font>";
    return "<font color=RoyalBlue><b>"+temp+"<\b><\font>";
}

QString intToString(int a,QLabel *l){
    QString temp=QString("%1").arg(a,8,16,QChar('0')).toUpper();
    temp=temp.right(8);
    return changeColor(temp,l);
}


QString memIntToString(int a){
    QString temp=QString("%1").arg(a,8,16,QChar('0')).toUpper();
    temp=temp.right(8);
    return temp;
}

QString intToStringDec(int a){
    return QString("%1").arg(a,4,10,QChar('0'));
}

QString icodeToString (char a,bool i=0){
    QString b="NOP";
    switch(a){
    case IHALT:b="HALT";break;
    case INOP:b="NOP";break;
    case IRRMOVL:b="RRMOVL";break;
    case IIRMOVL:b="IRMOVL";break;
    case IRMMOVL:b="RMMVOL";break;
    case IMRMOVL:b="MRMOVL";break;
    case IOPL:b="OPL";break;
    case IJXX:b="JXX";break;
    case ICALL:b="CALL";break;
    case IRET:b="RET";break;
    case IPUSHL:b="PUSHL";break;
    case IPOPL:b="POPL";
    }
    if(i||ini)
    return "<font color=black>"+b+"<\font>";
    return "<font color=RoyalBlue><b>"+b+"<\b><\font>";
}

QString ifunToString (char icode,char a,bool i=0){
    QString b="——";
    if(a==FNONE&&icode!=IJXX&&icode!=IOPL&&icode!=IRRMOVL)
    {
        if(a==FNONE)
        b="——";
        else
        b="ERR";
    }
    else {
        switch(icode){
        case IJXX:switch(a){
                case JMP: b="JMP";break;
                case JLE:b="JLE";break;
                case JL:b="JL";break;
                case JE:b="JE";break;
                case JNE:b="JNE";break;
                case JGE:b="JGE";break;
                case JG:b="JG";break;
            }break;
        case IOPL:switch(a){
                case ADDL:b="ADDL";break;
                case SUBL:b="SUBL";break;
                case ANDL:b="ANDL";break;
                case XORL:b="XORL";break;
            }break;
        case IRRMOVL:switch(a){
                case RRMOVL:b="——";break;
                case CMOVLE:b="CMOVLE";break;
                case CMOVL:b="CMOVL";break;
                case CMOVE:b="CMOVE";break;
                case CMOVNE:b="CMOVNE";break;
                case CMOVGE:b="CMOVGE";break;
                case CMOVG:b="CMOVG";break;
        }
        }
    }
    if(i||ini)
    return "<font color=black>"+b+"<\font>";
    return "<font color=RoyalBlue><b>"+b+"<\b><\font>";
}
QString boolToString(bool Cnd,QLabel *l){
    QString temp;
    if(Cnd) temp="1";
    else temp="0";
    if(ini) return "<font color=black>"+temp+"<\font>";
    if("<font color=RoyalBlue><b>"+temp+"<\b><\font>"==l->text()||"<font color=black>"+temp+"<\font>"==l->text())
        return "<font color=black>"+temp+"<\font>";
    else return "<font color=RoyalBlue><b>"+temp+"<\b><\font>";
}

QString regToString(char a,QLabel *l){
    QString b;
    switch (a){
    case RNONE: b= "——";break;
    case REAX: b= "EAX";break;
    case RECX: b= "ECX";break;
    case REDX: b= "EDX";break;
    case REBX: b= "EBX";break;
    case REBP: b= "EBP";break;
    case RESP: b= "ESP";break;
    case RESI: b= "ESI";break;
    case REDI: b= "EDI";break;
    }
    return changeColor(b,l);
}

QString statToString(char a,bool stall=0){
    QString b;
    switch (a){
    case SBUB: b= "<font color=blue><b>SBUB<\b><\font>" ;break;
    case SAOK: b= "SAOK";break;
    case SADR: b= "<font color=red><b>SADR<\b><\font>";break;
    case SHLT: b= "<font color=purple><b>SHLT<b><\font>";break;
    case SINS: b= "<font color=red><b>SINS<\b><\font>";break;
    }
    return b;
}

QString statToStringPanel(char a){
    QString b;
    switch (a){
    case SAOK: b= "SAOK";break;
    case SADR: b= "SADR";break;
    case SHLT: b= "<font color=RoyalBlue><b>SHLT<\b><\font>";break;
    case SINS: b= "SINS";break;
    }
    return b;
}

/******execution*********/

void initialize(){

    Reg.clear();
    tab.clear();

    ini_nine=0;
    bub=0;
    ini=1;
    clk=0;

    Alu.cnd[0]=true;
    Alu.cnd[1]=Alu.cnd[2]=false;

    f.initialize();
    d.initialize();
    e.initialize();
    m.initialize();
    w.initialize();

    F.initialize();
    D.initialize();
    E.initialize();
    M.initialize();
    W.initialize();

    for(int i=0;i<7;i++)
        adr[i]=i*4;
}

void display(){
    F.display();
    f.display();
    D.display();
    d.display();
    E.display();
    e.display();
    M.display();
    m.display();
    W.display();
    Reg.display();
}

void ini_pipeline(char *file){

    initialize();

    cout<<endl<<"Instruction Memory:"<<endl;
    ifstream in(file);
    ifstream in_temp(file);

    //ofstream out("/home/aaron/build-Y86_1-Desktop_Qt_5_7_0_GCC_64bit-Debug/test code/buff.yo");
    ofstream out("out.yo");
    Assembler asme;
    asme.compileFile(in,in_temp,Mem,out);
    f.predPC=0;

    for(int i=0;i<30;i++)
    {
        printf("  %08x ",Mem.display(8*i));
        printf("%08x\n",Mem.display(8*i+4));
    }

    for(int i=0;i<7;i++)
        adr[i]=i*4;
}

void MainWindow::cycle(){
    Con.set_logic(W.stat,M.icode,m.stat,e.Cnd,E.dstM,E.icode,d.srcB,d.srcA,D.icode);
            //时序逻辑

            bool F_stall = Con.F_stall, D_stall = Con.D_stall, D_bubble = Con.D_bubble,
            E_bubble = Con.E_bubble, M_bubble = Con.M_bubble,  W_stall = Con.W_stall;

            char temp_f_stat=f.stat,temp_f_icode=f.icode,temp_f_ifun=f.ifun,temp_f_rA=f.rA,F_pc=F.predPC;

            //write the register file
            d.regFile_write(w.valE, w.dstE, w.valM, w.dstM, Reg);

            f.stat=temp_f_stat;f.icode=temp_f_icode;f.ifun=temp_f_ifun;f.rA=temp_f_rA,F.predPC=F_pc;

            //update the Write Back stage
            W.update(W_stall, m.stat, M.icode, M.valE, m.valM, M.dstE, M.dstM);
            w.update(W.dstE, W.valE, W.dstM, W.valM, W.stat);

            //update the Memory stage
            M.update(M_bubble, E.stat, E.icode, e.Cnd, e.valE, E.valA, e.dstE, E.dstM);
            m.mem(M.stat, M.icode, M.valE, M.valA, Mem);

            //update the Execute stage
            E.update(E_bubble, D.stat, D.icode, D.ifun, D.valC, d.valA, d.valB,
                 d.dstE, d.dstM, d.srcA, d.srcB);
            e.aluAB(E.icode, E.valA, E.valB, E.valC);
            e.alu(E.icode, E.ifun, 1, 1, Alu);
            e.set_Cnd(E.stat,E.icode, E.ifun);
            e.set_dstE(E.icode, E.dstE);

            //update the Decode stage
            D.update(D_bubble, D_stall, f.stat, f.icode, f.ifun, f.rA, f.rB, f.valC, f.valP);
            d.ID(D.icode, D.rA, D.rB);
            d.regFile_read(Reg);
            d.sel_fwdA(D.icode,D.valP,e.dstE,e.valE,M.dstM,m.valM,M.dstE,M.valE, W.dstM,W.valM,W.dstE,W.valE);
            d.fwdB(e.dstE,e.valE,M.dstM,m.valM,M.dstE,M.valE, W.dstM,W.valM,W.dstE,W.valE);

            //update the Fetch stage
            F.update(F_stall, f.predPC);
            f.sel_PC(M.icode,M.Cnd,W.icode,M.valA,W.valM,F.predPC);
            f.fetch(Mem);
            f.pred_PC();

            //catch some information for Pipeline Diagram
            if(clk) tab.catchCycle(f.icode,D.icode,E.icode,E.ifun,M.icode,W.icode,F_stall,D_stall,W_stall,D.stat,E.stat,M.stat,W.stat,clk);

            printf("\n\n-----  第 %d 周期 -----\n",clk);
            display();
            cout<<endl;
}


/*****UI*****/

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/new/prefix1/cpu.ico"));
    connect(timer,SIGNAL(timeout()),this,SLOT(cycleDisplay()));
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resetPipe()
{
    initialize();
    ui->Ta_instr->clear();
    ui->Ta_Pipe->clear();
    //tab.pipeline.clear();
}

void MainWindow::connectPipe(QString str){
    char*  ch;
    QByteArray ba = str.toLatin1();
    ch=ba.data();
    resetPipe();
    ini_pipeline(ch);
}

void MainWindow::openText(QString f){
    f="out.yo";
    QFile file(f);
    if(!file.open(QFile::ReadOnly | QFile::Text))
        qDebug() << "Can not open";
    QTextStream in(&file);
    ui->textBrowser->setText(in.readAll());
}


void MainWindow::cycleDisplay(){
    if(w.stat==SHLT) {timer->stop();return;}
    clk++;
    cycle();
    ui->AddOneSecond->display(intToStringDec(clk));
    displayPipe();
}

void MainWindow::displayPipelineWatcher(int cycle=1){
    ui->Ta_Pipe->clear();
    int i=0;
    if(cycle<=9){
        for(;tab.Pipe[i][cycle].isEmpty()&&i<N-5;i++);
        if(cycle==1) ini_nine=4;
        for(int j=1;j<=cycle;j++){
            for(int k=0;k<5;k++){
                QTableWidgetItem *item=new QTableWidgetItem(tab.Pipe[ini_nine+k][j].mid(0,1));
                item->setToolTip(tab.Pipe[ini_nine+k][j].mid(1));
                ui->Ta_Pipe->setItem(k,j-1,item);
            }
        }
    }
    else {
        for(;tab.Pipe[i][cycle-8].mid(0,1)!="F"&&i<N-5;i++);

        for(int j=0;j<9;j++){
            for(int k=0;k<5;k++){
                QTableWidgetItem *item=new QTableWidgetItem(tab.Pipe[i+k][j+cycle-8].mid(0,1));
                item->setToolTip(tab.Pipe[i+k][j+cycle-8].mid(1));
                ui->Ta_Pipe->setItem(k,j,item);
            }
        }

    }

}

void MainWindow::displayPipe(){
    if(clk==0) ui->AddOneSecond->display(memIntToString(clk));
    ui->LaF_predPC->setText(intToString(F.predPC,ui->LaF_predPC));
    ui->LaD_icode->setText(icodeToString(D.icode,Con.D_stall||D.stat==SBUB));
    ui->LaE_icode->setText(icodeToString(E.icode,E.stat==SBUB));
    ui->LaM_icode->setText(icodeToString(M.icode,M.stat==SBUB));
    ui->LaW_icode->setText(icodeToString(W.icode,Con.W_stall||W.stat==SBUB));
    ui->LaD_ifun->setText(ifunToString(D.icode,D.ifun,Con.D_stall||D.stat==SBUB));
    ui->LaE_ifun->setText(ifunToString(E.icode,E.ifun,E.stat==SBUB));
    ui->LaM_Cnd->setText(boolToString(M.Cnd,ui->LaM_Cnd));
    ui->LaD_valC->setText(intToString(D.valC,ui->LaD_valC));
    ui->LaD_valP->setText(intToString(D.valP,ui->LaD_valP));
    ui->LaE_valC->setText(intToString(E.valC,ui->LaE_valC));
    ui->LaE_valA->setText(intToString(E.valA,ui->LaE_valA));
    ui->LaE_valB->setText(intToString(E.valB,ui->LaE_valB));
    ui->LaM_valE->setText(intToString(M.valE,ui->LaM_valE));
    ui->LaM_valA->setText(intToString(M.valA,ui->LaM_valA));
    ui->LaW_valE->setText(intToString(W.valE,ui->LaW_valE));
    ui->LaW_valM->setText(intToString(W.valM,ui->LaW_valM));
    ui->LaD_rA->setText(regToString(D.rA,ui->LaD_rA));
    ui->LaD_rB->setText(regToString(D.rB,ui->LaD_rB));
    ui->LaE_dstE->setText(regToString(E.dstE,ui->LaE_dstE));
    ui->LaE_dstM->setText(regToString(E.dstM,ui->LaE_dstM));
    ui->LaE_srcA->setText(regToString(E.srcA,ui->LaE_srcA));
    ui->LaE_srcB->setText(regToString(E.srcB,ui->LaE_srcB));
    ui->LaM_dstE->setText(regToString(M.dstE,ui->LaM_dstE));
    ui->LaM_dstM->setText(regToString(M.dstM,ui->LaM_dstM));
    ui->LaW_dstE->setText(regToString(W.dstE,ui->LaW_dstE));
    ui->LaW_dstM->setText(regToString(W.dstM,ui->LaW_dstM));
    ui->LaW_stat->setText(statToString(W.stat,Con.W_stall));
    ui->LaM_stat->setText(statToString(M.stat));
    ui->LaE_stat->setText(statToString(E.stat));
    ui->LaD_stat->setText(statToString(D.stat,Con.D_stall));
    ui->La_REAX->setText(intToString(Reg.reg[REAX],ui->La_REAX));
    ui->La_RECX->setText(intToString(Reg.reg[RECX],ui->La_RECX));
    ui->La_REDX->setText(intToString(Reg.reg[REDX],ui->La_REDX));
    ui->La_REBX->setText(intToString(Reg.reg[REBX],ui->La_REBX));
    ui->La_RESP->setText(intToString(Reg.reg[RESP],ui->La_RESP));
    ui->La_REBP->setText(intToString(Reg.reg[REBP],ui->La_REBP));
    ui->La_RESI->setText(intToString(Reg.reg[RESI],ui->La_RESI));
    ui->La_REDI->setText(intToString(Reg.reg[REDI],ui->La_REDI));
    ui->La_ADR1->setText(memIntToString(adr[0])+":");
    ui->La_ADR2->setText(memIntToString(adr[1])+":");
    ui->La_ADR3->setText(memIntToString(adr[2])+":");
    ui->La_ADR4->setText(memIntToString(adr[3])+":");
    ui->La_ADR5->setText(memIntToString(adr[4])+":");
    ui->La_ADR6->setText(memIntToString(adr[5])+":");
    ui->La_ADR7->setText(memIntToString(adr[6])+":");
    for(int i=0;i<7;i++)
    {
        if(i>=M_MAX||i<0) break;
        val[i]=Mem.display(adr[i]);
    }
    ui->La_VAL1->setText(memIntToString(val[0]));
    ui->La_VAL2->setText(memIntToString(val[1]));
    ui->La_VAL3->setText(memIntToString(val[2]));
    ui->La_VAL4->setText(memIntToString(val[3]));
    ui->La_VAL5->setText(memIntToString(val[4]));
    ui->La_VAL6->setText(memIntToString(val[5]));
    ui->La_VAL7->setText(memIntToString(val[6]));
    ui->La_ZF->setText(boolToString(e.CC[ZF],ui->La_ZF));
    ui->La_SF->setText(boolToString(e.CC[SF],ui->La_SF));
    ui->La_OF->setText(boolToString(e.CC[OVF],ui->La_OF));
    ui->La_PC->setText(memIntToString(f.pc));
    ui->La_stat->setText(statToStringPanel(w.stat));
    displayPipelineWatcher(clk);
    if(ini) {for(int i=0;i<9;i++){
                 ui->Ta_Pipe->setColumnWidth(i,82);
                }
             for(int i=0;i<5;i++){
                 ui->Ta_Pipe->setRowHeight(i,29);
                 ui->Ta_instr->setRowHeight(i,27);
                }
             ui->Ta_instr->setColumnWidth(1,505);
                ini=0;
    }
    if((w.stat!=SAOK&&w.stat!=SBUB)){
            if(timer->isActive()) timer->stop();
            ui->Bu_START->setText("START");
        }
}

void MainWindow::on_actionOpen_o_triggered()
{
    QString  str=QFileDialog::getOpenFileName(this," ","asm(*.s,*.txt,*.asm)");
    connectPipe(str);
    openText(str);
}

void MainWindow::on_Bu_STEP_clicked()
{
    if(w.stat!=SAOK&&w.stat!=SBUB) return;
    cycleDisplay();
}

void MainWindow::on_Bu_START_clicked()
{
    if(ui->Bu_START->text()=="START"&&(W.stat==SAOK||W.stat==SBUB)){
        timer->start(msec);
        ui->Bu_START->setText("STOP");
    }
    else if(ui->Bu_START->text()=="STOP"||(w.stat!=SAOK&&w.stat!=SBUB)){
        if(timer->isActive()) timer->stop();
        ui->Bu_START->setText("START");
    }
}

void MainWindow::on_Bu_RESET_clicked()
{
    clk=0;
    resetPipe();
    ui->AddOneSecond->display(intToStringDec(clk));
    ui->Bu_START->setText("START");
    timer->stop();
    displayPipe();
}

void MainWindow::on_Sl_speed_valueChanged(int value)
{
    msec=800/value;
    timer->stop();
    if(ui->Bu_START->text()=="STOP")
    timer->start(msec);
}

void MainWindow::on_lineEdit_textEdited(const QString &arg1=0)
{
    int a=arg1.toInt(0,0);
    convey=a;
    for(int i=0;i<7;i++)
    {
        if(i>=M_MAX||i<0) break;
        adr[i]=i*4+a;
        val[i]=Mem.display(adr[i]);
    }
    ui->La_ADR1->setText(memIntToString(adr[0])+":");
    ui->La_ADR2->setText(memIntToString(adr[1])+":");
    ui->La_ADR3->setText(memIntToString(adr[2])+":");
    ui->La_ADR4->setText(memIntToString(adr[3])+":");
    ui->La_ADR5->setText(memIntToString(adr[4])+":");
    ui->La_ADR6->setText(memIntToString(adr[5])+":");
    ui->La_ADR7->setText(memIntToString(adr[6])+":");
    ui->La_VAL1->setText(memIntToString(val[0]));
    ui->La_VAL2->setText(memIntToString(val[1]));
    ui->La_VAL3->setText(memIntToString(val[2]));
    ui->La_VAL4->setText(memIntToString(val[3]));
    ui->La_VAL5->setText(memIntToString(val[4]));
    ui->La_VAL6->setText(memIntToString(val[5]));
    ui->La_VAL7->setText(memIntToString(val[6]));

}

void MainWindow::on_Bu_Next_clicked()
{
    int a=convey;
    convey=a+4;
    for(int i=0;i<7;i++)
    {
        if(i>=M_MAX||i<0) break;
        adr[i]=i*4+a;
        val[i]=Mem.display(adr[i]);
    }
    ui->La_ADR1->setText(memIntToString(adr[0])+":");
    ui->La_ADR2->setText(memIntToString(adr[1])+":");
    ui->La_ADR3->setText(memIntToString(adr[2])+":");
    ui->La_ADR4->setText(memIntToString(adr[3])+":");
    ui->La_ADR5->setText(memIntToString(adr[4])+":");
    ui->La_ADR6->setText(memIntToString(adr[5])+":");
    ui->La_ADR7->setText(memIntToString(adr[6])+":");
    ui->La_VAL1->setText(memIntToString(val[0]));
    ui->La_VAL2->setText(memIntToString(val[1]));
    ui->La_VAL3->setText(memIntToString(val[2]));
    ui->La_VAL4->setText(memIntToString(val[3]));
    ui->La_VAL5->setText(memIntToString(val[4]));
    ui->La_VAL6->setText(memIntToString(val[5]));
    ui->La_VAL7->setText(memIntToString(val[6]));
}

void MainWindow::on_actionOpen_y86_triggered()
{
    QString str=QFileDialog::getOpenFileName(this," ","asm(*.s,*.txt,*.asm)");
    char*  ch;
    QByteArray ba = str.toLatin1();
    ch=ba.data();
    initialize();
    ifstream in(ch);
    Assembler asme;
    asme.Y86Read(in,Mem);
}
