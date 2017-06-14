#ifndef EXAMPLETWO_H
#define EXAMPLETWO_H

#include <QDebug>
#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QMessageBox>
#include <QSlider>

#include <time.h>

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

private:
    Ui::ExampleTwo *ui;
    QGraphicsScene *scene;
    QSlider *a;
    QSlider *p;
    void drawLimit();
    void update();
};

#endif // EXAMPLETWO_H
