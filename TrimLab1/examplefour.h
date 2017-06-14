#ifndef EXAMPLEFOUR_H
#define EXAMPLEFOUR_H

#include <QDebug>
#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QMessageBox>

#include <time.h>

namespace Ui {
class ExampleFour;
}

class ExampleFour : public QDialog
{
    Q_OBJECT

public:
    explicit ExampleFour(QWidget *parent = 0);
    ~ExampleFour();

private:
    Ui::ExampleFour *ui;
};

#endif // EXAMPLEFOUR_H
