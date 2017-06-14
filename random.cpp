#include "random.h"
#include <limits>
#include <QDebug>

Random::Random()
{
    file = new QFile("count.log");
    srand(time(NULL));
}
Random::~Random(){
    delete file;
}

int Random::getRandInt(){
    int val = rand();
    file->open(QFile::Append);
    file->write(QByteArray(QString::number(val%100).toUtf8().data())+"\n");
    file->close();
    return val;
}

double Random::getRandomDouble(){
    return rand()*1.0/RAND_MAX;
}
