#include "person.h"
//#include "scheduler.h"

//#include "qlist.h"

// class variables
QString /*name;
QString building;
Shift shifts [25]; // default max size, do something better.
int daysActive;
int daysPrimary;
int fitnessPrimary;
int fit*/nessSecondary;



Person::Person(QString name, QString building)
{
    this->name = name;
    this->building = building;

    daysActive = 0;
    daysPrimary = 0;
    daysSinceLastShift = 0;
    fitnessPrimary = 0;
    fitnessSecondary = 0;


}

void Person::UpdateFitness(int fit_primary, int fit_secondary){

    fitnessPrimary = fit_primary;
    fitnessSecondary = fit_secondary;
}

void Person::AddShift(Shift shift){

    shifts.append(shift.getDate());
}

void Person::addWeekdayNoGo(QString weekday){
    weekdaysNoGo.append(weekday);
}

void Person::addDateNoGo(QString date){
    datesNoGo.append(date);
}

//bool Person::dateInList(QString date){
//    int i=0;
//    for(i=0; i<datesNoGo->size(); ++i){
//        if (date == datesNoGo[i]){
//            return true;
//        }
//    }
//    return false;
//}

QString Person::getName(){
    return name;
}

int Person::getDaysActive(){
    return daysActive;
}

int Person::getPrimaryCount(){
    return daysPrimary;
}

int Person::getSecondaryCount(){
    return daysActive - daysPrimary;
}

QStringList Person::getWeekDaysNoGo(){
    return weekdaysNoGo;
}

QStringList Person::getdatesNoGo(){
    return datesNoGo;
}

QStringList Person::getShifts(){
    return shifts;
}

QString Person::getBuilding(){
    return building;
}

int Person::getDaysSinceLastDuty(){
    return daysSinceLastShift;
}

int Person::getPrimaryFitness(){
    return fitnessPrimary;
}

int Person::getSecondaryFitness(){
    return fitnessSecondary;
}

void Person::addDaysCount(){
    daysActive += 1;
}

void Person::addPrimaryCount(){
    daysPrimary += 1;
}

void Person::addDaysSinceLastShift(){
    daysSinceLastShift += 1;
}

void Person::resetDaysSinceLastShift(){
    daysSinceLastShift = 0;
}

QString Person::toString(){

    QString rtnString;
    int daysSecondary;
    daysSecondary = daysActive - daysPrimary;
    rtnString = QString("%1: Primary: %2, Secondary: %3").arg(name,QString::number(daysPrimary),QString::number(daysSecondary));

    return rtnString;
}

