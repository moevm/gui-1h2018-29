#ifndef TASK_H
#define TASK_H

#include <QString>

class Task
{
private:
    //Task number
    int number;
    //Task name
    QString name;

    //is Task completed
    bool completed;
public:
    //getters
    int getNumber();
    QString getName();
    bool isCompleted();
    //setters
    void setNumber(int number);
    void setName(QString name);


    Task();
    Task(QString name, int number);
};

#endif // TASK_H
