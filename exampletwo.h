#ifndef EXAMPLETWO_H
#define EXAMPLETWO_H

#include <QDebug>
#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QMessageBox>
#include <QSlider>
#include <QFile>

#include "random.h"

namespace Ui {
class ExampleTwo;
}

class ExampleTwo : public QDialog
{
    Q_OBJECT

public:
    explicit ExampleTwo(QWidget *parent = 0);
    ~ExampleTwo();

private slots:

    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalSlider_2_valueChanged(int value);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ExampleTwo *ui;
    QGraphicsScene *scene;
    QSlider *a;
    QSlider *p;
    Random *rand;
    void drawLimit();
    void update();
    int stat[2];
};

#endif // EXAMPLETWO_H
