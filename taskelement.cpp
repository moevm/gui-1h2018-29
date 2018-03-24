#include "taskelement.h"

TaskElement::TaskElement(QObject *parent) : QObject(parent)
{
    this->task_name = "";
    this->number = 0;
    this->completed = false;
}

TaskElement::TaskElement(QString name, int number, QObject *parent){

    this->task_name = name;
    this->number = number;
    this->completed = false;
}

int TaskElement::getNumber(){
    return this->number;
}
QString TaskElement::getName(){
    return this->task_name;
}

bool TaskElement::isCompleted(){
    return this->completed;
}

void TaskElement::setName(QString name){
    this->task_name = name;
}
void TaskElement::setNumber(int number){
    this->number = number;
}
