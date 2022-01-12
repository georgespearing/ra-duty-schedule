#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "shift.h"
#include "person.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Scheduler; }
QT_END_NAMESPACE

class Scheduler : public QMainWindow
{
    Q_OBJECT

public:
    Scheduler(QWidget *parent = nullptr);
    ~Scheduler();
    int selectionFitness(Shift shift, Person* person, int totalShifts);

private slots:
    void on_actionExit_triggered();
    void on_actionExport_triggered();
//    void on_actionImportPeople_triggered();
//    void on_actionClearShifts_triggered();
//    void on_actionClearPeople_triggered();

private:

    int totalShifts;

    Ui::Scheduler *ui;

    void getFitness(Shift shift, Person* person, int totalShifts);
};
#endif // SCHEDULER_H
