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
    foreach (QObject* curr, this->m_list) {
        Theme *temp = qobject_cast<Theme *>(curr);
        if(temp->getThemeName() == s){
            m_chosen = temp;
        }

        return curr;
    }
    qDebug() << m_chosen->getListOfTasks() ;



}
