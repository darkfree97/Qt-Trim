#include "exampleone.h"
#include "ui_exampleone.h"

ExampleOne::ExampleOne(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExampleOne)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(ui->graphicsView);
        //Это как раз создана сцена. Сцена - это класс для работы с 2D графикой.
        //Теперь, раз это график, то построим координатные оси X и Y.
        update();
        ui->graphicsView->setScene(scene);
        srand(time(NULL));
}

ExampleOne::~ExampleOne()
{
    delete ui;
}

void ExampleOne::on_pushButton_clicked()
{
    update();
    double rand_point = rand()%500*0.01;
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
//    qDebug()<<rand_point<<endl;
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
