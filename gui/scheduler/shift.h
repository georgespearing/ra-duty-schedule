#ifndef SHIFT_H
#define SHIFT_H

#include "qstring.h"

class Shift
{
public:
    Shift(QString date, QString dayOfWeek, bool isWeekend, QString building);

    void AddPrimary(QString name);
    void AddSecondary(QString name);
    QString toString();
    QString getDate();
    QString getBuilding();
    QString getPrimary();
    QString getSecondary();
    QString getWeekday();
//    bool operator==(const Shift& rhs);

    QString date;
    QString dayOfWeek;
    bool isWeekend;
    QString building;
    QString primary;
    QString secondary;
bool operator==(const Shift &rhs) const;


private:


};



#endif // SHIFT_H
