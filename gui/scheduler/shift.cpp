#include "shift.h"
#include "scheduler.h"


Shift::Shift(QString date, QString dayOfWeek, bool isWeekend, QString building)
{

    this->date = date;
    this->dayOfWeek = dayOfWeek;
    this->isWeekend = isWeekend;
    this->building = building;

}

void Shift::AddPrimary(QString name){
    this->primary = name;
}

void Shift::AddSecondary(QString name){
    this->secondary = name;
}

QString Shift::getDate(){
    return date;
}

QString Shift::getBuilding(){
    return building;
}

QString Shift::getPrimary(){
    return primary;
}

QString Shift::getSecondary(){
    return secondary;
}

QString Shift::getWeekday(){
    return dayOfWeek;
}

bool Shift::operator==(const Shift &rhs) const{
    bool dateEqual = QString::compare(building, rhs.date, Qt::CaseInsensitive);
    bool buildingEqual = QString::compare(building, rhs.building, Qt::CaseInsensitive);

    return dateEqual && buildingEqual;
}


QString Shift::toString(){
    QString rtnString;

    rtnString = QString("%1 %2 Primary: %3 Secondary %4").arg(date, building, primary, secondary);

    return rtnString;
}
