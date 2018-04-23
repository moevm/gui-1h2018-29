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


int TaskElement::getNumber(){
    return this->number;
}
QString TaskElement::getName(){
    return this->task_name;
}

void TaskElement::isCompleted(){
//    QSettings settings;
//    QMap<QString, QVariant> currMap;
//    currMap[this->task_name]= QVariant(true);
//    settings.setValue(this->type,currMap);
//    demoPrintProgressInConsole();

}

void TaskElement:: demoPrintProgressInConsole() {
//    QSettings settings;
//              QMap<QString, QVariant> curr = settings.value("sentenses").toMap();
//              qDebug()<<curr.value("Animal");
//              curr = settings.value("check").toMap();
//              qDebug()<<curr;
//              curr = settings.value("words").toMap();
//              qDebug()<<curr;
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
