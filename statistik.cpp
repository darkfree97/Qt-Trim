#include "statistik.h"
#include "ui_statistik.h"

#include <QString>
#include <QDebug>
#include <QHash>

Statistik::Statistik(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Statistik)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(ui->graphicsView);
    ui->graphicsView->setScene(scene);
    file = new QFile("count.log");
    vector = new QVector<int>();
}

Statistik::~Statistik()
{
    delete vector;
    delete ui;
}
QHash<int,int> Statistik::getHash(QVector<int> *v){
    QHash<int,int> map;
    for(int i : *v){
        if(map.keys().contains(i)){
            map.insert(i,map.value(i)+1);
        }
        else map.insert(i,1);
    }
    return map;
}

void Statistik::update(){
    int counter = 0;
    vector->clear();
    ui->textEdit->clear();
    file->open(QFile::ReadOnly|QFile::Text);
    while (!file->atEnd()) {
        vector->append(file->readLine(4).split('\n').at(0).toInt());
        counter++;
    }
    file->close();
    qSort(vector->begin(),vector->end());
    map = getHash(vector);
//    qDebug()<<map;
    scene->clear();
    QPen pen(Qt::black,3);//Просто выбираем цвет для карандашика
    scene->addLine(0,0,360,0,QPen(Qt::blue,3));//x
    scene->addLine(-3,-1,-3,1,pen);
    scene->addLine(363,-1,363,1,pen);
    scene->addText("0\t\t\t\t    99");
    QPainterPath path;
    path.moveTo(360*0/100,map.value(0)*(-1));
    for(int i=0;i<100;i++){
        if(map.keys().contains(i)){
            ui->textEdit->append(QString("( %1, %2 )").arg(i).arg(map.value(i)));
           path.lineTo(360*i/100,map.value(i)*(-10));
        }
        else {
            path.lineTo(360*i/100,0);
        }
    }
    path.fillRule();
    scene->addPath(path,QPen(Qt::red,2));
    ui->lineEdit->setText(QString::number(counter));

}

void Statistik::on_pushButton_clicked()
{
    update();
}
