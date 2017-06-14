#ifndef STATISTIK_H
#define STATISTIK_H

#include <QFile>
#include <QDialog>
#include <QVector>
#include <QGraphicsScene>

namespace Ui {
class Statistik;
}

class Statistik : public QDialog
{
    Q_OBJECT

public:
    explicit Statistik(QWidget *parent = 0);
    ~Statistik();
public slots:
    void update();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Statistik *ui;
    QGraphicsScene *scene;
    QFile *file;
    QVector<int> *vector;
    QHash<int,int> map;
    QHash<int,int> getHash(QVector<int> *v);
};

#endif // STATISTIK_H
