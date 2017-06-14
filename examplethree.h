#ifndef EXAMPLETHREE_H
#define EXAMPLETHREE_H

#include <QDebug>
#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QMessageBox>
#include <QSlider>

#include "random.h"

namespace Ui {
class ExampleThree;
}

class ExampleThree : public QDialog
{
    Q_OBJECT

public:
    explicit ExampleThree(QWidget *parent = 0);
    ~ExampleThree();

private slots:
    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalSlider_2_valueChanged(int value);

    void on_horizontalSlider_3_valueChanged(int value);

    void on_horizontalSlider_4_valueChanged(int value);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ExampleThree *ui;
    QGraphicsScene *scene;
    QSlider *a;
    QSlider *b;
    QSlider *p1;
    QSlider *p2;
    Random *rand;
    int stat[3];
    void drawLimit();
    void update();
};

#endif // EXAMPLETHREE_H
