//
// Created by aaron on 16-12-6.
//

/****/
#include "mainwindow.h"
#include <QApplication>
#include <QFileDialog>
#include <QString>
#include <QFile>
#include <QDebug>
#include <QWidget>
/****/


int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    MainWindow w;
    w.resetPipe();
    w.displayPipe();
    w.show();
    w.resetPipe();
   return a.exec();
}
