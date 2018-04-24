#include "controller.h"
#include "fstream"
#include "string"

Controller::Controller(QObject *parent) : QObject(parent)
{
    this->m_engine = new QQmlApplicationEngine();

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

int Controller::getNumberDoneTasks(){
    int count = 0;
    int i = 0;
    foreach (QObject *curr, this->model->getThemesList()) {
        Theme *temp = qobject_cast<Theme *>(curr);
        QList<QObject*> list = temp->getListOfTasks();
        int k = 0;
        if(i==0) k = 3;
        if(i==1) k = 2;
        if(i==2) k = 1;
        for(int j = 0; j < k; j++) {
           TaskElement *task = qobject_cast<TaskElement *>(list.at(j));
           if(task->isCompleted()) count++;
        }
        i++;
    }
    return count;
}

Controller::Controller(const Controller &other):
        QObject(other.parent()),
        m_list(other.m_list),
        m_engine(other.m_engine)
{

}

Controller& Controller::operator=(const Controller &other){
    m_list = other.m_list;
    m_engine = other.m_engine;

}

void Controller::readFile(){
//    QString FileURL = "C:\Projects\gui-1h2018-29-backend\src\completed.txt";
//    std::ifstream file(FileURL.toStdString());
//    int buff = 0;

//    while(file >> buff){

//    }

//    qDebug() << buff + " - read from file";
//    this->percent = buff;

//    file.close();

    QSettings settings("data.dat", QSettings::IniFormat);
    //settings.setValue();

    QFile file(":/src/completed.txt"); // создаем объект класса QFile
      QByteArray data; // Создаем объект класса QByteArray, куда мы будем считывать данные
      if (!file.open(QIODevice::ReadOnly )) {
         qDebug() << "NOT OPENED !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
        return;
      }// Проверяем, возможно ли открыть наш файл для чтения
           // если это сделать невозможно, то завершаем функцию
      qDebug() <<"DATA: ";
      data = file.readAll();
      qDebug() <<data;

      this->percent = data.toInt();
      qDebug() << this->percent;
     //считываем все данные с файла в объект data
       // qDebug() <<"DATA: "+data.length();
      //this->percent = data.toInt();

      //qDebug() << this->percent;

}

QObject* Controller::getTheme(int s) {
    qDebug() << "Try to find theme: " + s ;
    qDebug() << "-------------------------" ;
    //int counterS = 0;
    foreach (QObject *curr, this->model->getThemesList()) {
        //qDebug() << counterS++;
        Theme *temp = qobject_cast<Theme *>(curr);
        //qDebug() << temp->getThemeName() ;
        if(temp->getNumber() == s && temp != NULL){

                qDebug() <<temp;

                if(temp != NULL) return temp;

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


QList<QObject*> Controller::getTasksList(int themeNum){
    return this->model->getTasksList(themeNum);
}

void Controller::setTextTheme(int num){
    this->m_chosen_theme = num;
    qDebug() << m_chosen_theme;
}


int Controller::getTextTheme(){
    return this->m_chosen_theme;
}


int Controller::getChosenTask(){
    return this->m_chosen_task;
    //this->m_chosen_task = 0;
}

void Controller::setChosenTask(int task){
    this->m_chosen_task = task;
}

int Controller::getCompleted(){
    return this->percent;
}
void Controller::setCompleted(int q){
    this->percent = q;
}

void Controller::addCompleted(){
    this->percent++;
}

Controller::~Controller(){

    this->percent = 7;

    QFile fileOut("qrc:/src/completed.txt"); // Связываем объект с файлом fileout.txt
        if(fileOut.open(QIODevice::WriteOnly | QIODevice::Text))
        { // Если файл успешно открыт для записи в текстовом режиме
            QTextStream writeStream(&fileOut); // Создаем объект класса QTextStream
    // и передаем ему адрес объекта fileOut
            writeStream << this->percent; // Посылаем строку в поток для записи
            fileOut.close(); // Закрываем файл
        }
}
