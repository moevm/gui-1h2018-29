#include "task.h"

Task::Task()
{
    this->name = "";
    this->number = 0;
    this->completed = false;
}

Task::Task(QString name, int number)
{
    this->name = name;
    this->number = number;
    this->completed = false;
}

int Task::getNumber(){
    return this->number;
}
QString Task::getName(){
    return this->name;
}

bool Task::isCompleted(){
    return this->completed;
}

void Task::setName(QString name){
    this->name = name;
}
void Task::setNumber(int number){
    this->number = number;
}

