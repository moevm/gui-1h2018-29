#include "theme.h"
#include <QDebug>

Theme::Theme(QObject *parent): QObject(parent){

}
Theme::Theme(const QString &theme, const QString &taskDesc, QObject *parent)
    : QObject(parent), theme_name(theme), task_description(taskDesc){

}

Theme::Theme(const Theme &other):
        QObject(other.parent()),
        theme_name(other.theme_name),
        task_description(other.task_description){

}

Theme& Theme::operator=(const Theme &other){
    theme_name = other.theme_name;
    task_description = other.task_description;
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
    //if(num <= this->tasks.size()-1 && num>=0){
        return this->tasks.at(num);
    //} else {
        //qDebug()<< "Something gone wrong!!! Num: " + num ;
    //}
}
