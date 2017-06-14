#include "exampleone.h"
#include "ui_exampleone.h"

ExampleOne::ExampleOne(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExampleOne)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(ui->graphicsView);
    ui->graphicsView->setScene(scene);
    rand = new Random();
    update();
}

ExampleOne::~ExampleOne()
{
    delete ui;
}

void ExampleOne::on_pushButton_clicked()
{
    update();
    double rand_point = rand->getRandomDouble()*5;
    scene->addLine(180*(rand_point/5.0),-1,180*(rand_point/5.0),1,QPen(Qt::red,4));
    if(rand_point>3){
        QMessageBox::information(this,"Повідомлення","Відбулася подія B\nx = "+QString::number(rand_point));
    }
    else if(rand_point<3&&rand_point>1){
        QMessageBox::information(this,"Повідомлення","Відбулася подія А\nx = "+QString::number(rand_point));
    }
    else if(rand_point==3){
        QMessageBox::information(this,"Повідомлення","Відбилися обидві події\nx = "+QString::number(rand_point));
    }
    else{
        QMessageBox::information(this,"Повідомлення","Жодна подія не відбулася\nx = "+QString::number(rand_point));
    }
}

void ExampleOne::update(){
    scene->clear();
    QPen pen(Qt::black,3);//Просто выбираем цвет для карандашика
    scene->addLine(0,0,180,0,QPen(Qt::green,3));//x
    scene->addLine(36,1,108,1,QPen(Qt::red,3));
    scene->addLine(108,1,180,1,QPen(Qt::blue,3));
    scene->addLine(0,-1,0,1,pen);
    scene->addLine(36,-1,36,1,pen);
    scene->addLine(72,-1,72,1,pen);
    scene->addLine(108,-1,108,1,pen);
    scene->addLine(144,-1,144,1,pen);
    scene->addLine(180,-1,180,1,pen);
    scene->addText("0\t\t  5");
}

void ExampleOne::on_pushButton_2_clicked()
{
    int count = ui->spinBox->value();
    stat[0] = 0; // None
    stat[1] = 0; // A
    stat[2] = 0; // B
    stat[3] = 0; // A & B
    update();
    for(int i=0;i<count;i++){
        double rand_point = rand->getRandomDouble()*5;
        scene->addLine(180*(rand_point/5.0),-1,180*(rand_point/5.0),1,QPen(Qt::red,4));
        if(rand_point>3){
            stat[2]+=1;
        }
        else if(rand_point<3&&rand_point>1){
            stat[1]+=1;
        }
        else if(rand_point==3){
            stat[3]+=1;
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
