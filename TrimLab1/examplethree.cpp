#include "examplethree.h"
#include "ui_examplethree.h"

ExampleThree::ExampleThree(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExampleThree)
{
    ui->setupUi(this);
}

ExampleThree::~ExampleThree()
{
    delete ui;
}
