#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "exampleone.h"
#include "exampletwo.h"
#include "examplethree.h"
#include "examplefour.h"
#include "examplefive.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_exempl_1_clicked();

    void on_exempl_2_clicked();

    void on_exempl_3_clicked();

    void on_exempl_4_clicked();

    void on_exempl_5_clicked();

private:
    Ui::MainWindow *ui;
    ExampleOne *ex_1;
    ExampleTwo *ex_2;
    ExampleThree *ex_3;
    ExampleFour *ex_4;
    ExampleFive *ex_5;
};

#endif // MAINWINDOW_H
