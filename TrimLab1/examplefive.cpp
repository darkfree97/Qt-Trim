#include "examplefive.h"
#include "ui_examplefive.h"

ExampleFive::ExampleFive(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExampleFive)
{
    ui->setupUi(this);
}

ExampleFive::~ExampleFive()
{
    delete ui;
}
