#ifndef EXAMPLEFOUR_H
#define EXAMPLEFOUR_H

#include <QDebug>
#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QMessageBox>
#include <QSlider>

#include "random.h"

namespace Ui {
class ExampleFour;
}

class ExampleFour : public QDialog
{
    Q_OBJECT

public:
    explicit ExampleFour(QWidget *parent = 0);
    ~ExampleFour();

private slots:
    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalSlider_2_valueChanged(int value);

    void on_horizontalSlider_3_valueChanged(int value);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ExampleFour *ui;
    QGraphicsScene *scene;
    QSlider *p1;
    QSlider *p2;
    QSlider *p3;
    int stat[4];
    Random *rand;
    void update();
};

#endif // EXAMPLEFOUR_H
