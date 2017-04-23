#include "examplefour.h"
#include "ui_examplefour.h"

ExampleFour::ExampleFour(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExampleFour)
{
    ui->setupUi(this);
}

ExampleFour::~ExampleFour()
{
    delete ui;
}
