#include "controller.h"

Controller::Controller(QObject *parent) : QObject(parent)
{
    this->m_engine = new QQmlApplicationEngine();
    this->m_chosen = new Theme();
}

Controller::Controller(QList<Theme*> list,QObject *parent) : QObject(parent)
{
    this->m_list = list;
}

Controller::Controller(ThemesModel *themesModel, QObject *parent) : QObject(parent)
{
    this->model=themesModel;
}

void Controller::setEngine(QQmlApplicationEngine *engine, QQmlContext *ctxt){
    this->m_engine = engine;
    this->m_ctxt = ctxt;
}

Controller::Controller(const Controller &other):
        QObject(other.parent()),
        m_list(other.m_list),
        m_engine(other.m_engine),
        m_chosen(other.m_chosen)
{

}

Controller& Controller::operator=(const Controller &other){
    m_list = other.m_list;
    m_engine = other.m_engine;
    m_chosen = other.m_chosen;
}

void Controller::findTheme(QString theme){
    foreach (Theme* curr, this->m_list) {
        if(curr->getThemeName() == theme){
            m_chosen = curr;
        }
    }

}

QObject* Controller::getTheme(QString s) {
    qDebug() << "Try to find theme: " + s ;
    qDebug() << "-------------------------" ;
    int counterS = 0;
    foreach (QObject *curr, this->model->getThemesList()) {
        qDebug() << counterS++;
        Theme *temp = qobject_cast<Theme *>(curr);
        //qDebug() << temp->getThemeName() ;
        if(temp->getThemeName() == s){

                qDebug() <<temp->getThemeName()  +  " - Found.";
                return curr;

        }

    }

}

ThemesModel* Controller::getThemesModel() {
    return this->model;
}

void Controller::setThemesModel(ThemesModel *themesModel)
{
    this->model=themesModel;

}


QList<QObject*> Controller::getTasksList(QString themeName){
    return this->model->getTasksList(themeName);
}

void Controller::setTextTheme(QString txt){
    this->m_chosen_theme = txt;
    qDebug() << m_chosen_theme;
}
QString Controller::getTextTheme(){
    return this->m_chosen_theme;
}

int Controller::getChosenTask(){
    return this->m_chosen_task;
    //this->m_chosen_task = 0;
}

void Controller::setChosenTask(int task){
    m_chosen_task = task;
}
