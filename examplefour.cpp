#include "examplefour.h"
#include "ui_examplefour.h"

#include <QGraphicsScene>

ExampleFour::ExampleFour(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExampleFour)
{
    ui->setupUi(this);
    rand = new Random();
    scene = new QGraphicsScene(ui->graphicsView);
    ui->graphicsView->setScene(scene);
    p1 = ui->horizontalSlider;
    p2 = ui->horizontalSlider_2;
    p3 = ui->horizontalSlider_3;
    update();
}

ExampleFour::~ExampleFour()
{
    delete ui;
}

void ExampleFour::on_horizontalSlider_valueChanged(int value)
{
    if(value+p2->value()>100){
        p2->setValue(p2->value()-1);
    }
    if(p3->value()>value){
        p3->setValue(value);
    }
    update();
}

void ExampleFour::on_horizontalSlider_2_valueChanged(int value)
{
    if(value+p1->value()>100){
        p1->setValue(p1->value()-1);
    }
    if(p3->value()>value){
        p3->setValue(value);
    }
    update();
}

void ExampleFour::on_horizontalSlider_3_valueChanged(int value)
{
    if(p1->value()<value){
        p1->setValue(value);
    }
    if(p2->value()<value){
        p2->setValue(value);
    }
    update();
}

void ExampleFour::update(){
    scene->clear();
    QPen pen(Qt::black,3);
    scene->addLine(0,0,180,0,QPen(Qt::red,3));
    scene->addLine(0,0,(p1->value()-p3->value())/100.0*180,0,QPen(Qt::blue,3));
    scene->addLine((p1->value()-p3->value())/100.0*180,0,p1->value()/100.0*180,0,QPen(Qt::yellow,3));
    scene->addLine(p1->value()/100.0*180,0,(p1->value()+p2->value()-p3->value())/100.0*180,0,QPen(Qt::green,3));
    scene->addLine(0,-1,0,1,pen);
    scene->addLine(180,-1,180,1,pen);
    scene->addText("0\t\t  1");
    ui->l_1->setNum((p1->value()-p3->value())/100.0);
    ui->l_2->setNum((p2->value()-p3->value())/100.0);
    ui->l_3->setNum(p3->value()/100.0);
}

void ExampleFour::on_pushButton_clicked()
{
    int point = rand->getRandInt()%101;
    update();
    scene->addLine(point/100.0*180,-1,point/100.0*180,1,QPen(Qt::black,3));
    if(point>0&&point<p1->value()-p3->value()){
        QMessageBox::information(this,"A1","");
    }
    else if (point>p1->value()&&point<p1->value()+p2->value()-p3->value()) {
        QMessageBox::information(this,"A2","");
    }
    else if (point>p1->value()-p3->value()&&point<p1->value()) {
        QMessageBox::information(this,"A1-A2","");
    }
    else{
        QMessageBox::information(this,"None","");
    }
}

void ExampleFour::on_pushButton_2_clicked()
{
    double point;
    int count = ui->spinBox->value();
    stat[0] = 0; // None
    stat[1] = 0; // A
    stat[2] = 0; // B
    stat[3] = 0; // A & B
    update();
    for(int i=0;i<count;i++){
        point = rand->getRandomDouble();
        scene->addLine(point*180,-1,point*180,1,QPen(Qt::black,3));
        int pt = (int)(point*100.0);
        if (pt>p1->value()-p3->value()&&pt<p1->value()) {
            stat[3]+=1;
        }
        else if(pt>0&&pt<p1->value()-p3->value()){
            stat[1]+=1;
        }
        else if (pt>p1->value()&&pt<p1->value()+p2->value()-p3->value()) {
            stat[2]+=1;
        }
        else{
            stat[0]+=1;
        }

    }
    QMessageBox::information(this,"Повідомлення",QString("Проведено { %1 } випробувань!\n").arg(count)+
                             "0 = "+QString::number(stat[0])+" = "+QString::number(1.0*stat[0]/count*100)+"%\n"
                             "A = "+QString::number(stat[1])+" = "+QString::number(1.0*stat[1]/count*100)+"%\n"
                             "B = "+QString::number(stat[2])+" = "+QString::number(1.0*stat[2]/count*100)+"%\n"
                         "A & B = "+QString::number(stat[3])+" = "+QString::number(1.0*stat[3]/count*100)+"%\n");
}
