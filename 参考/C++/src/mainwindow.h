#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QThread>
#include "PipeDiagram.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

    void connectPipe(QString str);
    void displayPipe();
    void resetPipe();
    void displayPipelineWatcher(int clk);

protected:
    void openText(QString f);

    void timerEvent(QTimerEvent *e){cycleDisplay();}

protected slots:
    void cycle();

    void cycleDisplay();

private slots:
    void on_actionOpen_o_triggered();

    void on_Bu_STEP_clicked();

    void on_Bu_START_clicked();

    void on_Bu_RESET_clicked();

    void on_Sl_speed_valueChanged(int value);

    void on_lineEdit_textEdited(const QString &arg1);

    void on_Bu_Next_clicked();

    void on_actionOpen_y86_triggered();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
