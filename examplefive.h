#ifndef EXAMPLEFIVE_H
#define EXAMPLEFIVE_H

#include <QDebug>
#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QMessageBox>

#include <time.h>

namespace Ui {
class ExampleFive;
}

class ExampleFive : public QDialog
{
    Q_OBJECT

public:
    explicit ExampleFive(QWidget *parent = 0);
    ~ExampleFive();

private:
    Ui::ExampleFive *ui;
};

#endif // EXAMPLEFIVE_H
