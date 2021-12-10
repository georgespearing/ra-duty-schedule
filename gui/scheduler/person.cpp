#include "person.h"
#include "scheduler.h"

// class variables
QString name;
QString building;
Shift shifts [25]; // default max size, do something better.
int days_active;
int days_primary;
int fitness_primary;
int fitness_secondary;



Person::Person(QString name, QString building)
{

}

void Person::UpdateFitness(int fit_primary, int fit_secondary){

    fitness_primary = fit_primary;
    fitness_secondary = fit_secondary;
}

void Person::AddShift(Shift shift){

}

