#include "theme.h"
#include <QDebug>

Theme::Theme(QObject *parent): QObject(parent){

}
Theme::Theme(const QString &theme, const QString &taskDesc, int number, QObject *parent)
    : QObject(parent), theme_name(theme), task_description(taskDesc), m_number(number){

}

Theme::Theme(const Theme &other):
        QObject(other.parent()),
        theme_name(other.theme_name),
        task_description(other.task_description),
        m_number(other.m_number){

}

Theme& Theme::operator=(const Theme &other){
    theme_name = other.theme_name;
    task_description = other.task_description;
    m_number = other.m_number;
}

//getters

QString Theme::getThemeName() const{
    return this->theme_name;
}
QString Theme::getTaskDesc()const{
    return this->task_description;
}
//setters
void Theme::setThemeName(const QString &themeName){
    if (this->theme_name != themeName) {
            theme_name = themeName;
            emit nameChanged();
        }
}

void Theme::setTaskDesc(const QString &taskDesc){
    if (this->task_description != taskDesc) {
            task_description = taskDesc;
            emit descChanged();
     }
}

void Theme::setListOfTasks(QList<QObject*> tasks){
    this->tasks = tasks;
}

QList<QObject*> Theme::getListOfTasks(){

    return this->tasks;
//    for(int i = 0; i<this->tasks.size(); i++){

//       return this->tasks[num];
//    }

}
QObject* Theme::getTaskElement(int num){
        qDebug() <<  num;
    if(this->tasks.at(num) != NULL){
        return this->tasks.at(num);
    } else {

        qDebug()<< "Something gone wrong!!! Num: " + num ;
    }
}

int Theme::getNumber(){
    return this->m_number;
}
void Theme::setNumber(int num){
    this->m_number = num;
}
