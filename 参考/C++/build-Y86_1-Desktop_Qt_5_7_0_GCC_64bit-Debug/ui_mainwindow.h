/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen_o;
    QAction *actionOpen_y86;
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QLabel *LaPipeline;
    QLabel *LaF_predPC;
    QLabel *LaD_icode;
    QLabel *LaE_icode;
    QLabel *LaM_icode;
    QLabel *LaW_icode;
    QLabel *LaD_ifun;
    QLabel *LaE_ifun;
    QLabel *LaM_Cnd;
    QLabel *LaD_rB;
    QLabel *LaD_rA;
    QLabel *LaD_valP;
    QLabel *LaD_valC;
    QLabel *LaE_valB;
    QLabel *LaE_valA;
    QLabel *LaE_valC;
    QLabel *LaW_valM;
    QLabel *LaW_valE;
    QLabel *LaM_valA;
    QLabel *LaM_valE;
    QLabel *LaE_dstE;
    QLabel *LaE_dstM;
    QLabel *LaE_stat;
    QLabel *LaD_stat;
    QLabel *LaM_stat;
    QLabel *LaW_stat;
    QLabel *LaE_srcB;
    QLabel *LaE_srcA;
    QLabel *LaW_dstM;
    QLabel *LaW_dstE;
    QLabel *LaM_dstM;
    QLabel *LaM_dstE;
    QGroupBox *groupBox_5;
    QTableWidget *Ta_Pipe;
    QLabel *label_3;
    QFrame *line_4;
    QFrame *line_3;
    QFrame *line_2;
    QLCDNumber *AddOneSecond;
    QPushButton *Bu_RESET;
    QPushButton *Bu_STEP;
    QPushButton *Bu_START;
    QFrame *line;
    QSlider *Sl_speed;
    QLabel *label_2;
    QGroupBox *Box_Reg;
    QTableView *Ta_Reg;
    QLabel *La_eax;
    QLabel *La_ecx;
    QLabel *La_edx;
    QLabel *La_ebx;
    QLabel *La_esi;
    QLabel *La_esp;
    QLabel *La_edi;
    QLabel *La_ebp;
    QLabel *La_REAX;
    QLabel *La_RECX;
    QLabel *La_REDX;
    QLabel *La_REBX;
    QLabel *La_REDI;
    QLabel *La_RESP;
    QLabel *La_RESI;
    QLabel *La_REBP;
    QGroupBox *groupBox_3;
    QTableView *tableView_2;
    QLabel *La_ADR1;
    QLabel *La_ADR4;
    QLabel *La_ADR6;
    QLabel *La_ADR5;
    QLabel *La_ADR3;
    QLabel *La_ADR2;
    QLabel *La_ADR7;
    QLabel *La_VAL7;
    QLabel *La_VAL1;
    QLabel *La_VAL2;
    QLabel *La_VAL3;
    QLabel *La_VAL5;
    QLabel *La_VAL4;
    QLabel *La_VAL6;
    QLabel *label;
    QPushButton *Bu_Next;
    QLineEdit *lineEdit;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTextBrowser *textBrowser;
    QWidget *tab_2;
    QTableWidget *Ta_instr;
    QGroupBox *groupBox_2;
    QLabel *ZF;
    QLabel *La_ZF;
    QLabel *SF;
    QLabel *La_SF;
    QLabel *OF;
    QLabel *La_OF;
    QTextBrowser *textBrowser_2;
    QGroupBox *groupBox_4;
    QTextBrowser *textBrowser_3;
    QLabel *La_PC;
    QGroupBox *groupBox_6;
    QTextBrowser *textBrowser_4;
    QLabel *La_stat;
    QMenuBar *menuBar;
    QMenu *menuFile_f;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1514, 956);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(9);
        MainWindow->setFont(font);
        MainWindow->setWindowOpacity(1);
        MainWindow->setStyleSheet(QStringLiteral(""));
        actionOpen_o = new QAction(MainWindow);
        actionOpen_o->setObjectName(QStringLiteral("actionOpen_o"));
        actionOpen_y86 = new QAction(MainWindow);
        actionOpen_y86->setObjectName(QStringLiteral("actionOpen_y86"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(30, 10, 941, 681));
        groupBox->setFont(font);
        LaPipeline = new QLabel(groupBox);
        LaPipeline->setObjectName(QStringLiteral("LaPipeline"));
        LaPipeline->setGeometry(QRect(10, 30, 921, 641));
        LaPipeline->setPixmap(QPixmap(QString::fromUtf8(":/image/bg")));
        LaPipeline->setAlignment(Qt::AlignCenter);
        LaF_predPC = new QLabel(groupBox);
        LaF_predPC->setObjectName(QStringLiteral("LaF_predPC"));
        LaF_predPC->setGeometry(QRect(400, 590, 101, 18));
        QFont font1;
        font1.setPointSize(10);
        LaF_predPC->setFont(font1);
        LaD_icode = new QLabel(groupBox);
        LaD_icode->setObjectName(QStringLiteral("LaD_icode"));
        LaD_icode->setGeometry(QRect(240, 490, 91, 41));
        LaD_icode->setFont(font1);
        LaD_icode->setAlignment(Qt::AlignCenter);
        LaE_icode = new QLabel(groupBox);
        LaE_icode->setObjectName(QStringLiteral("LaE_icode"));
        LaE_icode->setGeometry(QRect(240, 350, 91, 41));
        LaE_icode->setFont(font1);
        LaE_icode->setAlignment(Qt::AlignCenter);
        LaM_icode = new QLabel(groupBox);
        LaM_icode->setObjectName(QStringLiteral("LaM_icode"));
        LaM_icode->setGeometry(QRect(240, 180, 91, 41));
        LaM_icode->setFont(font1);
        LaM_icode->setAlignment(Qt::AlignCenter);
        LaW_icode = new QLabel(groupBox);
        LaW_icode->setObjectName(QStringLiteral("LaW_icode"));
        LaW_icode->setGeometry(QRect(240, 50, 91, 41));
        LaW_icode->setFont(font1);
        LaW_icode->setAlignment(Qt::AlignCenter);
        LaD_ifun = new QLabel(groupBox);
        LaD_ifun->setObjectName(QStringLiteral("LaD_ifun"));
        LaD_ifun->setGeometry(QRect(310, 490, 71, 41));
        LaD_ifun->setFont(font1);
        LaD_ifun->setAlignment(Qt::AlignCenter);
        LaE_ifun = new QLabel(groupBox);
        LaE_ifun->setObjectName(QStringLiteral("LaE_ifun"));
        LaE_ifun->setGeometry(QRect(310, 350, 71, 41));
        LaE_ifun->setFont(font1);
        LaE_ifun->setAlignment(Qt::AlignCenter);
        LaM_Cnd = new QLabel(groupBox);
        LaM_Cnd->setObjectName(QStringLiteral("LaM_Cnd"));
        LaM_Cnd->setGeometry(QRect(390, 180, 31, 41));
        LaM_Cnd->setFont(font1);
        LaM_Cnd->setAlignment(Qt::AlignCenter);
        LaD_rB = new QLabel(groupBox);
        LaD_rB->setObjectName(QStringLiteral("LaD_rB"));
        LaD_rB->setGeometry(QRect(470, 490, 51, 41));
        LaD_rB->setFont(font1);
        LaD_rB->setAlignment(Qt::AlignCenter);
        LaD_rA = new QLabel(groupBox);
        LaD_rA->setObjectName(QStringLiteral("LaD_rA"));
        LaD_rA->setGeometry(QRect(420, 490, 51, 41));
        LaD_rA->setFont(font1);
        LaD_rA->setAlignment(Qt::AlignCenter);
        LaD_valP = new QLabel(groupBox);
        LaD_valP->setObjectName(QStringLiteral("LaD_valP"));
        LaD_valP->setGeometry(QRect(620, 490, 101, 41));
        LaD_valP->setFont(font1);
        LaD_valP->setAlignment(Qt::AlignCenter);
        LaD_valC = new QLabel(groupBox);
        LaD_valC->setObjectName(QStringLiteral("LaD_valC"));
        LaD_valC->setGeometry(QRect(520, 490, 101, 41));
        LaD_valC->setFont(font1);
        LaD_valC->setAlignment(Qt::AlignCenter);
        LaE_valB = new QLabel(groupBox);
        LaE_valB->setObjectName(QStringLiteral("LaE_valB"));
        LaE_valB->setGeometry(QRect(620, 350, 101, 41));
        LaE_valB->setFont(font1);
        LaE_valB->setAlignment(Qt::AlignCenter);
        LaE_valA = new QLabel(groupBox);
        LaE_valA->setObjectName(QStringLiteral("LaE_valA"));
        LaE_valA->setGeometry(QRect(520, 350, 101, 41));
        LaE_valA->setFont(font1);
        LaE_valA->setAlignment(Qt::AlignCenter);
        LaE_valC = new QLabel(groupBox);
        LaE_valC->setObjectName(QStringLiteral("LaE_valC"));
        LaE_valC->setGeometry(QRect(420, 350, 101, 41));
        LaE_valC->setFont(font1);
        LaE_valC->setAlignment(Qt::AlignCenter);
        LaW_valM = new QLabel(groupBox);
        LaW_valM->setObjectName(QStringLiteral("LaW_valM"));
        LaW_valM->setGeometry(QRect(580, 50, 101, 41));
        LaW_valM->setFont(font1);
        LaW_valM->setAlignment(Qt::AlignCenter);
        LaW_valE = new QLabel(groupBox);
        LaW_valE->setObjectName(QStringLiteral("LaW_valE"));
        LaW_valE->setGeometry(QRect(480, 50, 101, 41));
        LaW_valE->setFont(font1);
        LaW_valE->setAlignment(Qt::AlignCenter);
        LaM_valA = new QLabel(groupBox);
        LaM_valA->setObjectName(QStringLiteral("LaM_valA"));
        LaM_valA->setGeometry(QRect(580, 180, 101, 41));
        LaM_valA->setFont(font1);
        LaM_valA->setAlignment(Qt::AlignCenter);
        LaM_valE = new QLabel(groupBox);
        LaM_valE->setObjectName(QStringLiteral("LaM_valE"));
        LaM_valE->setGeometry(QRect(480, 180, 101, 41));
        LaM_valE->setFont(font1);
        LaM_valE->setAlignment(Qt::AlignCenter);
        LaE_dstE = new QLabel(groupBox);
        LaE_dstE->setObjectName(QStringLiteral("LaE_dstE"));
        LaE_dstE->setGeometry(QRect(720, 350, 51, 41));
        LaE_dstE->setFont(font1);
        LaE_dstE->setAlignment(Qt::AlignCenter);
        LaE_dstM = new QLabel(groupBox);
        LaE_dstM->setObjectName(QStringLiteral("LaE_dstM"));
        LaE_dstM->setGeometry(QRect(770, 350, 51, 41));
        LaE_dstM->setFont(font1);
        LaE_dstM->setAlignment(Qt::AlignCenter);
        LaE_stat = new QLabel(groupBox);
        LaE_stat->setObjectName(QStringLiteral("LaE_stat"));
        LaE_stat->setGeometry(QRect(30, 390, 51, 41));
        LaE_stat->setFont(font1);
        LaD_stat = new QLabel(groupBox);
        LaD_stat->setObjectName(QStringLiteral("LaD_stat"));
        LaD_stat->setGeometry(QRect(30, 520, 61, 41));
        LaD_stat->setFont(font1);
        LaM_stat = new QLabel(groupBox);
        LaM_stat->setObjectName(QStringLiteral("LaM_stat"));
        LaM_stat->setGeometry(QRect(30, 220, 51, 41));
        LaM_stat->setFont(font1);
        LaW_stat = new QLabel(groupBox);
        LaW_stat->setObjectName(QStringLiteral("LaW_stat"));
        LaW_stat->setGeometry(QRect(30, 90, 51, 41));
        LaW_stat->setFont(font1);
        LaE_srcB = new QLabel(groupBox);
        LaE_srcB->setObjectName(QStringLiteral("LaE_srcB"));
        LaE_srcB->setGeometry(QRect(870, 350, 51, 41));
        LaE_srcB->setFont(font1);
        LaE_srcB->setAlignment(Qt::AlignCenter);
        LaE_srcA = new QLabel(groupBox);
        LaE_srcA->setObjectName(QStringLiteral("LaE_srcA"));
        LaE_srcA->setGeometry(QRect(820, 350, 51, 41));
        LaE_srcA->setFont(font1);
        LaE_srcA->setAlignment(Qt::AlignCenter);
        LaW_dstM = new QLabel(groupBox);
        LaW_dstM->setObjectName(QStringLiteral("LaW_dstM"));
        LaW_dstM->setGeometry(QRect(770, 50, 51, 41));
        LaW_dstM->setFont(font1);
        LaW_dstM->setAlignment(Qt::AlignCenter);
        LaW_dstE = new QLabel(groupBox);
        LaW_dstE->setObjectName(QStringLiteral("LaW_dstE"));
        LaW_dstE->setGeometry(QRect(720, 50, 51, 41));
        LaW_dstE->setFont(font1);
        LaW_dstE->setAlignment(Qt::AlignCenter);
        LaM_dstM = new QLabel(groupBox);
        LaM_dstM->setObjectName(QStringLiteral("LaM_dstM"));
        LaM_dstM->setGeometry(QRect(770, 180, 51, 41));
        LaM_dstM->setFont(font1);
        LaM_dstM->setAlignment(Qt::AlignCenter);
        LaM_dstE = new QLabel(groupBox);
        LaM_dstE->setObjectName(QStringLiteral("LaM_dstE"));
        LaM_dstE->setGeometry(QRect(720, 180, 51, 41));
        LaM_dstE->setFont(font1);
        LaM_dstE->setAlignment(Qt::AlignCenter);
        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(740, 710, 761, 191));
        Ta_Pipe = new QTableWidget(groupBox_5);
        if (Ta_Pipe->columnCount() < 9)
            Ta_Pipe->setColumnCount(9);
        if (Ta_Pipe->rowCount() < 5)
            Ta_Pipe->setRowCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignCenter);
        Ta_Pipe->setItem(0, 0, __qtablewidgetitem);
        Ta_Pipe->setObjectName(QStringLiteral("Ta_Pipe"));
        Ta_Pipe->setGeometry(QRect(10, 30, 741, 151));
        Ta_Pipe->setRowCount(5);
        Ta_Pipe->setColumnCount(9);
        Ta_Pipe->horizontalHeader()->setVisible(false);
        Ta_Pipe->horizontalHeader()->setCascadingSectionResizes(false);
        Ta_Pipe->verticalHeader()->setVisible(false);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(990, 610, 121, 18));
        QFont font2;
        font2.setPointSize(11);
        label_3->setFont(font2);
        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(1470, 500, 20, 201));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(1120, 680, 361, 41));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(1000, 500, 16, 101));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        AddOneSecond = new QLCDNumber(centralWidget);
        AddOneSecond->setObjectName(QStringLiteral("AddOneSecond"));
        AddOneSecond->setGeometry(QRect(990, 630, 111, 71));
        AddOneSecond->setDigitCount(4);
        AddOneSecond->setSegmentStyle(QLCDNumber::Filled);
        AddOneSecond->setProperty("value", QVariant(0));
        AddOneSecond->setProperty("intValue", QVariant(0));
        Bu_RESET = new QPushButton(centralWidget);
        Bu_RESET->setObjectName(QStringLiteral("Bu_RESET"));
        Bu_RESET->setGeometry(QRect(1120, 580, 111, 91));
        QFont font3;
        font3.setPointSize(14);
        Bu_RESET->setFont(font3);
        Bu_STEP = new QPushButton(centralWidget);
        Bu_STEP->setObjectName(QStringLiteral("Bu_STEP"));
        Bu_STEP->setGeometry(QRect(1240, 580, 111, 91));
        Bu_STEP->setFont(font3);
        Bu_START = new QPushButton(centralWidget);
        Bu_START->setObjectName(QStringLiteral("Bu_START"));
        Bu_START->setGeometry(QRect(1360, 580, 101, 91));
        Bu_START->setFont(font3);
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(1010, 490, 471, 21));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        Sl_speed = new QSlider(centralWidget);
        Sl_speed->setObjectName(QStringLiteral("Sl_speed"));
        Sl_speed->setGeometry(QRect(1040, 530, 411, 20));
        Sl_speed->setMinimum(1);
        Sl_speed->setMaximum(100);
        Sl_speed->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(1030, 560, 141, 18));
        label_2->setFont(font2);
        Box_Reg = new QGroupBox(centralWidget);
        Box_Reg->setObjectName(QStringLiteral("Box_Reg"));
        Box_Reg->setGeometry(QRect(990, 10, 211, 361));
        Box_Reg->setContextMenuPolicy(Qt::NoContextMenu);
        Ta_Reg = new QTableView(Box_Reg);
        Ta_Reg->setObjectName(QStringLiteral("Ta_Reg"));
        Ta_Reg->setGeometry(QRect(10, 31, 191, 321));
        Ta_Reg->setFont(font3);
        Ta_Reg->setAutoScrollMargin(16);
        La_eax = new QLabel(Box_Reg);
        La_eax->setObjectName(QStringLiteral("La_eax"));
        La_eax->setGeometry(QRect(30, 40, 51, 18));
        La_eax->setFont(font3);
        La_ecx = new QLabel(Box_Reg);
        La_ecx->setObjectName(QStringLiteral("La_ecx"));
        La_ecx->setGeometry(QRect(30, 80, 51, 18));
        La_ecx->setFont(font3);
        La_edx = new QLabel(Box_Reg);
        La_edx->setObjectName(QStringLiteral("La_edx"));
        La_edx->setGeometry(QRect(30, 120, 51, 18));
        La_edx->setFont(font3);
        La_ebx = new QLabel(Box_Reg);
        La_ebx->setObjectName(QStringLiteral("La_ebx"));
        La_ebx->setGeometry(QRect(30, 160, 51, 18));
        La_ebx->setFont(font3);
        La_esi = new QLabel(Box_Reg);
        La_esi->setObjectName(QStringLiteral("La_esi"));
        La_esi->setGeometry(QRect(30, 280, 51, 18));
        La_esi->setFont(font3);
        La_esp = new QLabel(Box_Reg);
        La_esp->setObjectName(QStringLiteral("La_esp"));
        La_esp->setGeometry(QRect(30, 200, 51, 18));
        La_esp->setFont(font3);
        La_edi = new QLabel(Box_Reg);
        La_edi->setObjectName(QStringLiteral("La_edi"));
        La_edi->setGeometry(QRect(30, 320, 51, 18));
        La_edi->setFont(font3);
        La_ebp = new QLabel(Box_Reg);
        La_ebp->setObjectName(QStringLiteral("La_ebp"));
        La_ebp->setGeometry(QRect(30, 240, 51, 20));
        La_ebp->setFont(font3);
        La_REAX = new QLabel(Box_Reg);
        La_REAX->setObjectName(QStringLiteral("La_REAX"));
        La_REAX->setGeometry(QRect(90, 40, 111, 18));
        La_REAX->setFont(font2);
        La_RECX = new QLabel(Box_Reg);
        La_RECX->setObjectName(QStringLiteral("La_RECX"));
        La_RECX->setGeometry(QRect(90, 80, 111, 18));
        La_RECX->setFont(font2);
        La_REDX = new QLabel(Box_Reg);
        La_REDX->setObjectName(QStringLiteral("La_REDX"));
        La_REDX->setGeometry(QRect(90, 120, 111, 18));
        La_REDX->setFont(font2);
        La_REBX = new QLabel(Box_Reg);
        La_REBX->setObjectName(QStringLiteral("La_REBX"));
        La_REBX->setGeometry(QRect(90, 160, 111, 18));
        La_REBX->setFont(font2);
        La_REDI = new QLabel(Box_Reg);
        La_REDI->setObjectName(QStringLiteral("La_REDI"));
        La_REDI->setGeometry(QRect(90, 320, 111, 18));
        La_REDI->setFont(font2);
        La_RESP = new QLabel(Box_Reg);
        La_RESP->setObjectName(QStringLiteral("La_RESP"));
        La_RESP->setGeometry(QRect(90, 200, 111, 18));
        La_RESP->setFont(font2);
        La_RESI = new QLabel(Box_Reg);
        La_RESI->setObjectName(QStringLiteral("La_RESI"));
        La_RESI->setGeometry(QRect(90, 280, 111, 18));
        La_RESI->setFont(font2);
        La_REBP = new QLabel(Box_Reg);
        La_REBP->setObjectName(QStringLiteral("La_REBP"));
        La_REBP->setGeometry(QRect(90, 240, 111, 18));
        La_REBP->setFont(font2);
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(1220, 10, 281, 361));
        tableView_2 = new QTableView(groupBox_3);
        tableView_2->setObjectName(QStringLiteral("tableView_2"));
        tableView_2->setGeometry(QRect(10, 70, 261, 281));
        La_ADR1 = new QLabel(groupBox_3);
        La_ADR1->setObjectName(QStringLiteral("La_ADR1"));
        La_ADR1->setGeometry(QRect(30, 80, 111, 18));
        La_ADR1->setFont(font2);
        La_ADR4 = new QLabel(groupBox_3);
        La_ADR4->setObjectName(QStringLiteral("La_ADR4"));
        La_ADR4->setGeometry(QRect(30, 200, 111, 18));
        La_ADR4->setFont(font2);
        La_ADR6 = new QLabel(groupBox_3);
        La_ADR6->setObjectName(QStringLiteral("La_ADR6"));
        La_ADR6->setGeometry(QRect(30, 280, 111, 18));
        La_ADR6->setFont(font2);
        La_ADR5 = new QLabel(groupBox_3);
        La_ADR5->setObjectName(QStringLiteral("La_ADR5"));
        La_ADR5->setGeometry(QRect(30, 240, 121, 18));
        La_ADR5->setFont(font2);
        La_ADR3 = new QLabel(groupBox_3);
        La_ADR3->setObjectName(QStringLiteral("La_ADR3"));
        La_ADR3->setGeometry(QRect(30, 160, 121, 18));
        La_ADR3->setFont(font2);
        La_ADR2 = new QLabel(groupBox_3);
        La_ADR2->setObjectName(QStringLiteral("La_ADR2"));
        La_ADR2->setGeometry(QRect(30, 120, 111, 18));
        La_ADR2->setFont(font2);
        La_ADR7 = new QLabel(groupBox_3);
        La_ADR7->setObjectName(QStringLiteral("La_ADR7"));
        La_ADR7->setGeometry(QRect(30, 320, 111, 18));
        La_ADR7->setFont(font2);
        La_VAL7 = new QLabel(groupBox_3);
        La_VAL7->setObjectName(QStringLiteral("La_VAL7"));
        La_VAL7->setGeometry(QRect(160, 320, 101, 18));
        La_VAL7->setFont(font2);
        La_VAL1 = new QLabel(groupBox_3);
        La_VAL1->setObjectName(QStringLiteral("La_VAL1"));
        La_VAL1->setGeometry(QRect(160, 80, 101, 18));
        La_VAL1->setFont(font2);
        La_VAL2 = new QLabel(groupBox_3);
        La_VAL2->setObjectName(QStringLiteral("La_VAL2"));
        La_VAL2->setGeometry(QRect(160, 120, 101, 18));
        La_VAL2->setFont(font2);
        La_VAL3 = new QLabel(groupBox_3);
        La_VAL3->setObjectName(QStringLiteral("La_VAL3"));
        La_VAL3->setGeometry(QRect(160, 160, 101, 18));
        La_VAL3->setFont(font2);
        La_VAL5 = new QLabel(groupBox_3);
        La_VAL5->setObjectName(QStringLiteral("La_VAL5"));
        La_VAL5->setGeometry(QRect(160, 240, 101, 18));
        La_VAL5->setFont(font2);
        La_VAL4 = new QLabel(groupBox_3);
        La_VAL4->setObjectName(QStringLiteral("La_VAL4"));
        La_VAL4->setGeometry(QRect(160, 200, 111, 18));
        La_VAL4->setFont(font2);
        La_VAL6 = new QLabel(groupBox_3);
        La_VAL6->setObjectName(QStringLiteral("La_VAL6"));
        La_VAL6->setGeometry(QRect(160, 280, 101, 18));
        La_VAL6->setFont(font2);
        label = new QLabel(groupBox_3);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 74, 18));
        Bu_Next = new QPushButton(groupBox_3);
        Bu_Next->setObjectName(QStringLiteral("Bu_Next"));
        Bu_Next->setGeometry(QRect(190, 36, 81, 31));
        lineEdit = new QLineEdit(groupBox_3);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 35, 171, 31));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(40, 700, 671, 201));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        textBrowser = new QTextBrowser(tab);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(10, 10, 651, 141));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy1);
        QFont font4;
        font4.setFamily(QStringLiteral("Tlwg Typo"));
        font4.setPointSize(9);
        font4.setBold(true);
        font4.setWeight(75);
        textBrowser->setFont(font4);
        textBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        textBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        textBrowser->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        Ta_instr = new QTableWidget(tab_2);
        if (Ta_instr->columnCount() < 2)
            Ta_instr->setColumnCount(2);
        if (Ta_instr->rowCount() < 5)
            Ta_instr->setRowCount(5);
        Ta_instr->setObjectName(QStringLiteral("Ta_instr"));
        Ta_instr->setGeometry(QRect(10, 10, 651, 141));
        Ta_instr->setRowCount(5);
        Ta_instr->setColumnCount(2);
        Ta_instr->horizontalHeader()->setVisible(false);
        tabWidget->addTab(tab_2, QString());
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(990, 390, 241, 81));
        ZF = new QLabel(groupBox_2);
        ZF->setObjectName(QStringLiteral("ZF"));
        ZF->setGeometry(QRect(20, 40, 31, 21));
        QFont font5;
        font5.setPointSize(12);
        ZF->setFont(font5);
        La_ZF = new QLabel(groupBox_2);
        La_ZF->setObjectName(QStringLiteral("La_ZF"));
        La_ZF->setGeometry(QRect(60, 40, 31, 21));
        La_ZF->setFont(font5);
        SF = new QLabel(groupBox_2);
        SF->setObjectName(QStringLiteral("SF"));
        SF->setGeometry(QRect(90, 40, 31, 21));
        SF->setFont(font5);
        La_SF = new QLabel(groupBox_2);
        La_SF->setObjectName(QStringLiteral("La_SF"));
        La_SF->setGeometry(QRect(130, 40, 21, 21));
        La_SF->setFont(font5);
        OF = new QLabel(groupBox_2);
        OF->setObjectName(QStringLiteral("OF"));
        OF->setGeometry(QRect(160, 40, 31, 21));
        OF->setFont(font5);
        La_OF = new QLabel(groupBox_2);
        La_OF->setObjectName(QStringLiteral("La_OF"));
        La_OF->setGeometry(QRect(200, 40, 21, 21));
        La_OF->setFont(font5);
        textBrowser_2 = new QTextBrowser(groupBox_2);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(10, 30, 221, 41));
        textBrowser_2->raise();
        ZF->raise();
        La_ZF->raise();
        SF->raise();
        La_SF->raise();
        OF->raise();
        La_OF->raise();
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(1240, 390, 151, 80));
        textBrowser_3 = new QTextBrowser(groupBox_4);
        textBrowser_3->setObjectName(QStringLiteral("textBrowser_3"));
        textBrowser_3->setGeometry(QRect(10, 30, 131, 41));
        La_PC = new QLabel(groupBox_4);
        La_PC->setObjectName(QStringLiteral("La_PC"));
        La_PC->setGeometry(QRect(20, 40, 111, 21));
        La_PC->setFont(font5);
        groupBox_6 = new QGroupBox(centralWidget);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(1400, 390, 101, 80));
        textBrowser_4 = new QTextBrowser(groupBox_6);
        textBrowser_4->setObjectName(QStringLiteral("textBrowser_4"));
        textBrowser_4->setGeometry(QRect(10, 30, 81, 41));
        La_stat = new QLabel(groupBox_6);
        La_stat->setObjectName(QStringLiteral("La_stat"));
        La_stat->setGeometry(QRect(20, 30, 71, 41));
        La_stat->setFont(font5);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1514, 26));
        menuBar->setFont(font2);
        menuFile_f = new QMenu(menuBar);
        menuFile_f->setObjectName(QStringLiteral("menuFile_f"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile_f->menuAction());
        menuFile_f->addAction(actionOpen_o);
        menuFile_f->addAction(actionOpen_y86);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Y86 Simulator", 0));
        actionOpen_o->setText(QApplication::translate("MainWindow", ".ys File", 0));
        actionOpen_y86->setText(QApplication::translate("MainWindow", ".y86 File", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Pipeline Logic", 0));
        LaPipeline->setText(QString());
        LaF_predPC->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        LaD_icode->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        LaE_icode->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        LaM_icode->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        LaW_icode->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        LaD_ifun->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        LaE_ifun->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        LaM_Cnd->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        LaD_rB->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        LaD_rA->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        LaD_valP->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        LaD_valC->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        LaE_valB->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        LaE_valA->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        LaE_valC->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        LaW_valM->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        LaW_valE->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        LaM_valA->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        LaM_valE->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        LaE_dstE->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        LaE_dstM->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        LaE_stat->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        LaD_stat->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        LaM_stat->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        LaW_stat->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        LaE_srcB->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        LaE_srcA->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        LaW_dstM->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        LaW_dstE->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        LaM_dstM->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        LaM_dstE->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Pipeline Watcher", 0));

        const bool __sortingEnabled = Ta_Pipe->isSortingEnabled();
        Ta_Pipe->setSortingEnabled(false);
        Ta_Pipe->setSortingEnabled(__sortingEnabled);

        label_3->setText(QApplication::translate("MainWindow", "CLOCK", 0));
        Bu_RESET->setText(QApplication::translate("MainWindow", "RESET", 0));
        Bu_STEP->setText(QApplication::translate("MainWindow", "STEP", 0));
        Bu_START->setText(QApplication::translate("MainWindow", "START", 0));
        label_2->setText(QApplication::translate("MainWindow", "SPEED", 0));
        Box_Reg->setTitle(QApplication::translate("MainWindow", "Register", 0));
        La_eax->setText(QApplication::translate("MainWindow", "eax", 0));
        La_ecx->setText(QApplication::translate("MainWindow", "ecx", 0));
        La_edx->setText(QApplication::translate("MainWindow", "edx", 0));
        La_ebx->setText(QApplication::translate("MainWindow", "ebx", 0));
        La_esi->setText(QApplication::translate("MainWindow", "esi", 0));
        La_esp->setText(QApplication::translate("MainWindow", "esp", 0));
        La_edi->setText(QApplication::translate("MainWindow", "edi", 0));
        La_ebp->setText(QApplication::translate("MainWindow", "ebp", 0));
        La_REAX->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        La_RECX->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        La_REDX->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        La_REBX->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        La_REDI->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        La_RESP->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        La_RESI->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        La_REBP->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        groupBox_3->setTitle(QString());
        La_ADR1->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        La_ADR4->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        La_ADR6->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        La_ADR5->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        La_ADR3->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        La_ADR2->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        La_ADR7->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        La_VAL7->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        La_VAL1->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        La_VAL2->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        La_VAL3->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        La_VAL5->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        La_VAL4->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        La_VAL6->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label->setText(QApplication::translate("MainWindow", "Memory", 0));
        Bu_Next->setText(QApplication::translate("MainWindow", "next", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Code", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Instrctions", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Condition", 0));
        ZF->setText(QApplication::translate("MainWindow", "ZF:", 0));
        La_ZF->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        SF->setText(QApplication::translate("MainWindow", "SF:", 0));
        La_SF->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        OF->setText(QApplication::translate("MainWindow", "OF:", 0));
        La_OF->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "PC", 0));
        La_PC->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "State", 0));
        La_stat->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        menuFile_f->setTitle(QApplication::translate("MainWindow", "Open(&O)", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
