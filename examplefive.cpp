#include "examplefive.h"
#include "ui_examplefive.h"

ExampleFive::ExampleFive(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExampleFive)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(ui->graphicsView);
    ui->graphicsView->setScene(scene);
    sp = ui->spinBox;
    rand = new Random();
}

ExampleFive::~ExampleFive()
{
    delete ui;
}

void ExampleFive::on_spinBox_valueChanged(int arg1)
{
    update();
}

void ExampleFive::drawLimit(int n){
    int j = 180/n;
    for(int i=0;i<180;i+=j){
        scene->addLine(i,0,i+j,0,QPen(QColor(rand->getRandInt()%255,rand->getRandInt()%255,rand->getRandInt()%255),3));
        if(i!=0)scene->addLine(i,-1,i,1,QPen(Qt::black,2));
    }
}

void ExampleFive::update(){
    scene->clear();
    QPen pen(Qt::black,3);//Просто выбираем цвет для карандашика
    drawLimit(sp->value());
    scene->addLine(-3,-1,-3,1,pen);
    scene->addLine(183,-1,183,1,pen);
    scene->addText("0\t\t  1");
}

void ExampleFive::on_pushButton_clicked()
{
    char count = 'A';
    double point = rand->getRandomDouble();
    double j = 1.0/sp->value();
    update();
    scene->addLine(180*point,-1,180*point,1,QPen(Qt::red,4));
    for(double i=0;i<1;i+=j){
        if(point>=i&&point<i+j){
            QMessageBox::information(this,"",QString("Відбулася подія %1.\n"
                                                     "x=%2").arg(count).arg(point));
            break;
        }
        count++;
    }
}

void ExampleFive::on_pushButton_2_clicked()
{
    QString message = "";
    int count = ui->spinBox_2->value();
    int temp_count;
    double point;
    for(int i=0;i<26;i++){
        stat[i] = 0;
    }
    update();
    double j = 1.0/sp->value();
    for(int i=0;i<count;i++){
        point = rand->getRandomDouble();
        scene->addLine(180*point,-1,180*point,1,QPen(Qt::red,4));
        temp_count = 0;
        for(double i=0;i<1;i+=j){
            if(point>=i&&point<i+j){
                stat[temp_count]+=1;
                break;
            }
            temp_count++;
        }
    }

    // Message formation
    message+=QString("Проведено { %1 } дослідів.\n").arg(count);
    for(int i=0;i<sp->value();i++){
        char startChar = 'A';
        message+=QString("%1 = %2 = %3\n").arg((char)(startChar+i)).arg(stat[i]).arg(1.0*stat[i]/count);
    }
    QMessageBox::information(this,"Повідомлення",message);
}
