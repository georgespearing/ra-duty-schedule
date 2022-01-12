#ifndef PERSON_H
#define PERSON_H

#include "shift.h"
#include "qlist.h"

class Person
{
public:
    Person(QString name, QString building);
    void UpdateFitness(int fit_priamry, int fit_secondary);
    void AddShift(Shift shift);
    void addWeekdayNoGo(QString weekday);
    void addDateNoGo(QString date);
    void addPrimaryCount();
    void addDaysCount();
    void addDaysSinceLastShift();
    void resetDaysSinceLastShift();
    bool dateInList(QString date);
    bool dayOfWeekInList(QString dayOfWeek);
    QString toString();
    QString getName();
    int getDaysActive();
    int getPrimaryCount();
    int getSecondaryCount();
    QStringList getWeekDaysNoGo();
    QStringList getdatesNoGo();
    QStringList getShifts();
    QString getBuilding();
    int getDaysSinceLastDuty();
    int getPrimaryFitness();
    int getSecondaryFitness();



private:
    QString name;
    QString building;
    QStringList shifts;
    QStringList weekdaysNoGo;
    QStringList datesNoGo;
    int fitnessPrimary;
    int fitnessSecondary;
    int daysActive;
    int daysPrimary;
    int daysSinceLastShift;

};

#endif // PERSON_H
