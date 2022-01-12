#include "scheduler.h"
#include "person.h"
#include "ui_scheduler.h"
#include <QTextStream>

#include "qfile.h"
#include "qmessagebox.h"

Scheduler::Scheduler(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Scheduler)
{
    ui->setupUi(this);


    QList<Person> people;
    QList<Shift> shifts;

    QStringList buildings = {"MSH", "WDW"};

    QTextStream out(stdout);

    // load in the people

    // create a bunch of shifts

    // initialize total shifts variable tracker
    totalShifts = 0;

    // go through all the shifts and assign people
//    QTextStream out(stdout);

    // Read and Add People
    QFile file("../../data/people.txt");
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream in(&file);


    while(!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split("; ");

        // create a new person
        Person person = Person(fields[0], fields[1]);

        // add weekday no go
        QStringList weekdays = fields[2].split(", ");
        for(int i=0; i<weekdays.length(); ++i){
            person.addWeekdayNoGo(weekdays[i]);
        }

        // add date no go
        QStringList dates = fields[3].split(", ");
        for(int i=0; i<dates.length(); ++i){
            person.addDateNoGo(dates[i]);
        }

        // add person to list
        people.append(person);

    }

    file.close();

    // Read and Add shifts
    QFile file2("../../data/days-to-cover.csv");
    if(!file2.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file2.errorString());
    }

    QTextStream in2(&file2);


    while(!in2.atEnd()) {
        QString line = in2.readLine();
        QStringList fields = line.split(",");

        for (int i=0; i<buildings.length(); ++i){
            // create a new shift

            Shift shift = Shift(fields[0], fields[1], bool(fields[2].toInt()), buildings[i]);

            // add shift to list
            shifts.append(shift);

        }

    }

    file2.close();

    // assigning fitness

    // Assign Shifts
    for (int i=0; i<shifts.length(); ++i){

        if (!shifts[i].isWeekend){

            // go through all the people and assign fitness
            for (int j=0; j<people.length(); ++j){

                selectionFitness(shifts[i], &people[j], totalShifts);
                people[j].addDaysSinceLastShift();
//                out << people[j].getName() << QString(", ") << people[j].getPrimaryFitness() << QString(", ") << people[j].getSecondaryFitness() << QString("\n");
            }


            // sort by primary fitness
            int primaryIndex = 0;
            for (int j=1; j<people.length(); ++j){

                if (people[j].getPrimaryFitness() > people[primaryIndex].getPrimaryFitness()){

                    primaryIndex = j;
                }
            }

            // schedule that person by putting them on the shift
            shifts[i].AddPrimary(people[primaryIndex].getName());
            people[primaryIndex].AddShift(shifts[i]);
            people[primaryIndex].addPrimaryCount();
            people[primaryIndex].addDaysCount();

            // update fitness for that person
            selectionFitness(shifts[i], &people[primaryIndex], totalShifts);

            // sort by secondary
            int secondaryIndex = 0;
            for (int j=1; j<people.length(); ++j){

                if (people[j].getSecondaryFitness() >= people[secondaryIndex].getSecondaryFitness()){
    //                people[secondaryIndex] = people[j];
                    secondaryIndex = j;
                }
            }

            // schedule that person by putting them on the shift
            shifts[i].AddSecondary(people[secondaryIndex].getName());
            people[secondaryIndex].AddShift(shifts[i]);
            people[secondaryIndex].addDaysCount();

            // update both people for days since last duty
            people[primaryIndex].resetDaysSinceLastShift();
            people[secondaryIndex].resetDaysSinceLastShift();

            // update total shift tracker
            totalShifts += 1;

        }

    }



    // write to console and to table widget
    for (int i=0; i<people.length(); ++i){
//        out << people[i].toString() << QString("\n");

        // add person to table
        ui->table_people_view->insertRow(i);

        ui->table_people_view->setItem(i,0, new QTableWidgetItem(people[i].getName()));
        ui->table_people_view->setItem(i,1, new QTableWidgetItem(QString::number(people[i].getPrimaryCount())));
        ui->table_people_view->setItem(i,2, new QTableWidgetItem(QString::number(people[i].getSecondaryCount())));

    }

    // Print Shifts
    for (int i=0; i<shifts.length(); ++i){

//        out << shifts[i].toString() << QString("\n");

        // add person to table
        ui->table_shift_view->insertRow(i);

        ui->table_shift_view->setItem(i,0, new QTableWidgetItem(shifts[i].getDate()));
        ui->table_shift_view->setItem(i,1, new QTableWidgetItem(shifts[i].getBuilding()));
        ui->table_shift_view->setItem(i,2, new QTableWidgetItem(shifts[i].getPrimary()));
        ui->table_shift_view->setItem(i,3, new QTableWidgetItem(shifts[i].getSecondary()));
    }






}

Scheduler::~Scheduler()
{
    delete ui;
}


int Scheduler::selectionFitness(Shift shift, Person *person, int totalShifts){

    QTextStream out(stdout);

    int primary_fitness = 0;
    int secondary_fitness = 0;

    // if the days don't match, zero fitness.
    if (person->getWeekDaysNoGo().contains(shift.getWeekday()) ||
            person->getdatesNoGo().contains(shift.getDate()) ||
            person->getShifts().contains(shift.getDate())){

//        out << QString("%1 %2 %3 nothing \n").arg(person->getWeekDaysNoGo().contains(shift.getWeekday())).arg(person->getdatesNoGo().contains(shift.getDate())).arg(person->getShifts().contains(shift));
        // don't make a match if person don't want this day or is already scheduled
        person->UpdateFitness(primary_fitness, secondary_fitness);
        return 0;

    }

//    out << QString("%1 everything  \n").arg(shift.date);


    // take into account building match, large weighting
    int buildingMatch = int(person->getBuilding().compare(shift.getBuilding(), Qt::CaseInsensitive)); // returns int less than zero if less than or greather than 0 if greater than

    if (buildingMatch == int(0) ){
        primary_fitness += 10;
    }

    else{
        primary_fitness += 0;
    }

//    out << person->getBuilding().compare(shift.getBuilding(), Qt::CaseInsensitive) << QString(", ") << secondary_fitness << QString("\n");

    primary_fitness += (person->getDaysActive() - person->getPrimaryCount());
    secondary_fitness += person->getDaysActive() - (person->getDaysActive() - person->getPrimaryCount());


    // average days on duty so far
    primary_fitness += 1 - (person->getDaysActive() / (totalShifts+1));
    secondary_fitness += 1 - (person->getDaysActive() / (totalShifts+1));


    // also take into account days since last duty, add some weight to it
    primary_fitness += (person->getDaysSinceLastDuty());
    secondary_fitness += (person->getDaysSinceLastDuty());

    person->UpdateFitness(primary_fitness, secondary_fitness);

//    out << primary_fitness << QString(", ") << secondary_fitness << QString("\n");

    return 1;
}

void Scheduler::on_actionExit_triggered(){

    QApplication::quit();
}

void Scheduler::on_actionExport_triggered(){

    QTextStream out(stdout);

    out << QString("Exporting... \n");

    QFile f("shifts.csv");

    if (f.open(QFile::WriteOnly)){
        QTextStream data(&f);
        QStringList strList;


        for(int i=0; i<ui->table_shift_view->rowCount(); ++i){
            strList.clear();
            for (int j=0; j<ui->table_shift_view->columnCount(); ++j){
//                strList << "\" "+ui->table_shift_view->item(i,j) ->text()+"\" ";
                strList << "123";
            }

            data << strList.join(";")+"\n";

        }

        f.close();
    }

}
