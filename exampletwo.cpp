#include "exampletwo.h"
#include "ui_exampletwo.h"

ExampleTwo::ExampleTwo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExampleTwo)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(ui->graphicsView);
    ui->graphicsView->setScene(scene);
    a = ui->horizontalSlider;
    p = ui->horizontalSlider_2;
    rand = new Random();
    update();
    drawLimit();
}

ExampleTwo::~ExampleTwo()
{
    delete rand;
    delete ui;
}

void ExampleTwo::update(){
    scene->clear();
    QPen pen(Qt::black,3);//Просто выбираем цвет для карандашика
    scene->addLine(0,0,180,0,QPen(Qt::blue,3));//x
    scene->addLine(-3,-1,-3,1,pen);
    scene->addLine(183,-1,183,1,pen);
    scene->addText("0\t\t  1");

}

void ExampleTwo::drawLimit(){
    update();
    ui->l_a->setNum(a->value()/100.0);
    ui->l_p->setNum((p->value()-a->value())/100.0);
    scene->addLine(180*a->value()/100,0,180*p->value()/100,0,QPen(Qt::green,3));

}

void ExampleTwo::on_horizontalSlider_valueChanged(int value)
{
    if(p->value() < value){
        p->setValue(a->value());
    }
    drawLimit();
}

void ExampleTwo::on_horizontalSlider_2_valueChanged(int value)
{
    if(value < a->value()){
        a->setValue(p->value());
    }
    drawLimit();
}

void ExampleTwo::on_pushButton_clicked()
{
    double point = rand->getRandomDouble();
    double _a = ui->l_a->text().toDouble();
    double _b = _a + ui->l_p->text().toDouble();
    drawLimit();
    scene->addLine(180*point,-1,180*point,1,QPen(Qt::red,4));
    if(_a<=point&&_b>=point){
        QMessageBox::information(this,"Повідомлення",QString("Подія відбулася.\nТочка x=%1\nналежить проміжку [a,a+p]").arg(point));
    }
    else {
        QMessageBox::information(this,"Повідомлення",QString("Подія не відбулася.\nТочка x=%1\nне належить проміжку [a,a+p]").arg(point));
    }
}

void ExampleTwo::on_pushButton_2_clicked()
{
    double point;
    stat[0] = 0; // Event did't take place
    stat[1] = 0; // Event take place
    int count = ui->spinBox->value();
    double _a = ui->l_a->text().toDouble();
    double _b = _a + ui->l_p->text().toDouble();
    drawLimit();
    for (int i=0; i<count;i++){
        point = rand->getRandomDouble();
        scene->addLine(180*point,-1,180*point,1,QPen(Qt::red,4));
        if(_a<=point&&_b>=point){
            stat[1]+=1;
        }
        else {
            stat[0]+=1;
        }
    }
    QMessageBox::information(this,"Повідомлення",QString("Проведено { %1 } випробувань!\n").arg(count)+
                             "Подія не відбулася = "+QString::number(stat[0])+" = "+QString::number(1.0*stat[0]/count*100)+"%\n"
                             "Подія відбулася    = "+QString::number(stat[1])+" = "+QString::number(1.0*stat[1]/count*100)+"%\n");
}
