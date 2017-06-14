#ifndef EXAMPLEFIVE_H
#define EXAMPLEFIVE_H

#include <QDebug>
#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QMessageBox>
#include <QSpinBox>

#include "random.h"

namespace Ui {
class ExampleFive;
}

class ExampleFive : public QDialog
{
    Q_OBJECT

public:
    explicit ExampleFive(QWidget *parent = 0);
    ~ExampleFive();

private slots:
    void on_spinBox_valueChanged(int arg1);
    void on_pushButton_clicked();
    void update();


    void on_pushButton_2_clicked();

private:
    QSpinBox *sp;
    Ui::ExampleFive *ui;
    QGraphicsScene *scene;
    Random *rand;
    int stat[26];
    void drawLimit(int n);
};

#endif // EXAMPLEFIVE_H
