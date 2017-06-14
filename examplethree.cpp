#include "examplethree.h"
#include "ui_examplethree.h"

ExampleThree::ExampleThree(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExampleThree)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(ui->graphicsView);
    ui->graphicsView->setScene(scene);
    a = ui->horizontalSlider;
    b = ui->horizontalSlider_3;
    p1 = ui->horizontalSlider_2;
    p2 = ui->horizontalSlider_4;
    rand = new Random();
    update();
    drawLimit();
}

ExampleThree::~ExampleThree()
{
    delete ui;
}

void ExampleThree::update(){
    scene->clear();
    QPen pen(Qt::black,3);//Просто выбираем цвет для карандашика
    scene->addLine(0,0,180,0,QPen(Qt::blue,3));//x
    scene->addLine(-3,-1,-3,1,pen);
    scene->addLine(183,-1,183,1,pen);
    scene->addText("0\t\t  1");
}

void ExampleThree::drawLimit(){
    update();
    scene->addLine(180*a->value()/100,0,180*p1->value()/100,0,QPen(Qt::green,3));
    scene->addLine(180*b->value()/100,0,180*p2->value()/100,0,QPen(Qt::yellow,3));
    ui->l_a->setNum(a->value()/100.0);
    ui->l_p->setNum((p1->value()-a->value())/100.0);
    ui->l_b->setNum(b->value()/100.0);
    ui->l_p2->setNum((p2->value()-b->value())/100.0);
}

void ExampleThree::on_horizontalSlider_valueChanged(int value)
{
    if(p1->value() < value){
        p1->setValue(a->value());
    }
    drawLimit();
}

void ExampleThree::on_horizontalSlider_2_valueChanged(int value)
{
    if(a->value() > value){
        a->setValue(p1->value());
    }
    if(b->value()< value){
        b->setValue(value);
    }
    drawLimit();
}

void ExampleThree::on_horizontalSlider_3_valueChanged(int value)
{
    if(p2->value() < value){
        p2->setValue(b->value());
    }
    if(p1->value()> value){
        p1->setValue(value);
    }
    drawLimit();
}

void ExampleThree::on_horizontalSlider_4_valueChanged(int value)
{
    if(b->value() > value){
        b->setValue(p2->value());
    }
    if(p1->value() > p2->value()){
        p1->setValue(p2->value());
    }
    drawLimit();
}

void ExampleThree::on_pushButton_clicked()
{
    double point = rand->getRandomDouble();
    drawLimit();
    scene->addLine(180*point,-1,180*point,1,QPen(Qt::red,4));
    int pt = point * 100;
    if(pt>=a->value()&&pt<=p1->value()){
        QMessageBox::information(this,"Повідомлення","A");
    }
    else if(pt>=b->value()&&pt<=p2->value()){
        QMessageBox::information(this,"Повідомлення","B");
    }
    else{
        QMessageBox::information(this,"Повідомлення","None");
    }
}

void ExampleThree::on_pushButton_2_clicked()
{
    double point;
    int count = ui->spinBox->value();
    stat[0] = 0; // None
    stat[1] = 0; // A
    stat[2] = 0; // B
    drawLimit();
    for(int i=0;i<count;i++){
        point = rand->getRandomDouble();
        scene->addLine(180*point,-1,180*point,1,QPen(Qt::red,4));
        int pt = point * 100;
        if(pt>=a->value()&&pt<=p1->value()){
            stat[1]+=1;
        }
        else if(pt>=b->value()&&pt<=p2->value()){
            stat[2]+=1;
        }
        else{
            stat[0]+=1;
        }
    }
    QMessageBox::information(this,"Повідомлення",QString("Проведено { %1 } випробувань!\n").arg(count)+
                             "0 = "+QString::number(stat[0])+" = "+QString::number(1.0*stat[0]/count*100)+"%\n"
                             "A = "+QString::number(stat[1])+" = "+QString::number(1.0*stat[1]/count*100)+"%\n"
                             "B = "+QString::number(stat[2])+" = "+QString::number(1.0*stat[2]/count*100)+"%\n");
}
