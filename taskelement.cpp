#include "taskelement.h"

TaskElement::TaskElement(QObject *parent) : QObject(parent)
{
    this->task_name = "";
    this->number = 0;
    this->completed = false;
}

TaskElement::TaskElement(QString name, int number, QString type,QList<QObject*> listPairs, QObject *parent){

    this->task_name = name;
    this->number = number;
    this->type = type;
    this->listPairs = listPairs;
    this->completed = false;
}

bool TaskElement::isCompleted() {

    QSettings settings("MySoft", "Star Runner");
    QString key = this->type + this->task_name;

    if(settings.value(key).toString()=="true") {
        return true;
    } else {
        return false;
    }
}

int TaskElement::getNumber(){
    return this->number;
}
QString TaskElement::getName(){
    return this->task_name;
}

void TaskElement::setCompleted(){
    QSettings settings("MySoft", "Star Runner");
    QString key = this->type + this->task_name;
    settings.setValue(key,"true");
    settings.sync();
}

void TaskElement::setName(QString name){
    this->task_name = name;
}
void TaskElement::setNumber(int number){
    this->number = number;
}

QString TaskElement::getType(){
    return this->type;
}

void TaskElement::setType(QString type){
    this->type = type;
}

void TaskElement::setListPairs(QList<QObject *> listPairs) {
    this->listPairs=listPairs;
}



QList<QObject*> TaskElement:: getListPairs() {
    return this->listPairs;
}
