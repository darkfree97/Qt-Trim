#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ex_1 = new ExampleOne(this);
    ex_2 = new ExampleTwo(this);
    ex_3 = new ExampleThree(this);
    ex_4 = new ExampleFour(this);
    ex_5 = new ExampleFive(this);

    ex_1->setModal(true);
    ex_2->setModal(true);
    ex_3->setModal(true);
    ex_4->setModal(true);
    ex_5->setModal(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_exempl_1_clicked()
{
    ex_1->show();
}

void MainWindow::on_exempl_2_clicked()
{
    ex_2->show();
}

void MainWindow::on_exempl_3_clicked()
{
    ex_3->show();
}

void MainWindow::on_exempl_4_clicked()
{
    ex_4->show();
}

void MainWindow::on_exempl_5_clicked()
{
    ex_5->show();
}
