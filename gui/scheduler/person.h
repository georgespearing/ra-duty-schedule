#ifndef PERSON_H
#define PERSON_H

#include "shift.h"
#include "scheduler.h"

class Person
{
public:
    Person(QString name, QString building);
    void UpdateFitness(int fit_priamry, int fit_secondary);
    void AddShift(Shift shift);
};

#endif // PERSON_H
