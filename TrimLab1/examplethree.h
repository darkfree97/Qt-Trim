#ifndef EXAMPLETHREE_H
#define EXAMPLETHREE_H

#include <QDebug>
#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QMessageBox>

#include <time.h>

namespace Ui {
class ExampleThree;
}

class ExampleThree : public QDialog
{
    Q_OBJECT

public:
    explicit ExampleThree(QWidget *parent = 0);
    ~ExampleThree();

private:
    Ui::ExampleThree *ui;
};

#endif // EXAMPLETHREE_H
