#ifndef RANDOM_H
#define RANDOM_H

#include <QFile>
#include <time.h>

class Random
{
public:
    Random();
    ~Random();
    int getRandInt();
    double getRandomDouble();
private:
    QFile *file;
};

#endif // RANDOM_H
