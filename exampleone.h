#ifndef EXAMPLEONE_H
#define EXAMPLEONE_H

#include <QDebug>
#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QMessageBox>

#include "random.h"

namespace Ui {
class ExampleOne;
}

class ExampleOne : public QDialog
{
    Q_OBJECT

public:
    explicit ExampleOne(QWidget *parent = 0);
    ~ExampleOne();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ExampleOne *ui;
    QGraphicsScene *scene;
    Random *rand;
    int stat[4];
    void update();
};

#endif // EXAMPLEONE_H
