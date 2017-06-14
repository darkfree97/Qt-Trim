#include "mainwindow.h"
#include <QApplication>
#include <QFile>

void SetStyleTo(QString file_name,QWidget *widget){
    QFile file(file_name);
    file.open(QFile::ReadOnly);
    widget->setStyleSheet(QString(file.readAll()));
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w; w.show();
    SetStyleTo(":/style.qss",&w);
    return a.exec();
}
