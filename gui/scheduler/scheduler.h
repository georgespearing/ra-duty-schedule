#ifndef SCHEDULER_H
#define SCHEDULER_H

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

private:
    Ui::Scheduler *ui;
};
#endif // SCHEDULER_H
