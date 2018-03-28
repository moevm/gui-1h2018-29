#include "themesmodel.h"
#include "pair.h"

#include <QDebug>

ThemesModel::ThemesModel(QObject *parent) : QObject(parent)
{
    this->fillListThemes();

//    QList<QObject*>* tmp;

//    for (int i =0; i< themesList->size(); i++) {
////            Theme* curr = new Theme();
////            curr = qobject_cast<Theme*>(model->at(i));
////            QString tmp_str = "ctxList_"+i;
//            tmp = &((qobject_cast<Theme*>(model->at(i)))->getListOfTasks());
//            context_list.append(tmp);

//        }

}

QList<QObject*> ThemesModel::getThemesList()
{
    return this->themesList;
}

void ThemesModel::fillListThemes()
{
    Theme *theme=NULL;
    theme = new Theme("Практикуйся в переводе слов", "Переводи с английского языка на русский и обратно слова!");

    QList<QObject*> listPairs;
    listPairs.append(new Pair("cat", "кот"));
    listPairs.append(new Pair("dog", "собака"));
    listPairs.append(new Pair("partridge", "куропатка"));
    listPairs.append(new Pair("titmouse", "синица"));
    listPairs.append(new Pair("elephant", "слон"));

    TaskElement *te1 = new TaskElement("Animals", 1, "words",listPairs);
    TaskElement *te2 = new TaskElement("Community", 2, "sentenses", listPairs);
    TaskElement *te3 = new TaskElement("Games", 3, "text", listPairs);
    TaskElement *te4 = new TaskElement("Animals", 4, "words", listPairs);
    QList<QObject*> temp_lst = {te1, te2, te3, te4};

    foreach(QObject* temp, temp_lst){
        TaskElement* tmp = qobject_cast<TaskElement *>(temp);
         qDebug() << tmp->getType();
    }


    theme->setListOfTasks(temp_lst);

    this->themesList.append(theme);
    theme = new Theme("Практикуйся в переводе предложений", "Переводи с английского языка на русский и обратно целые предложения!");

//    te1 = new TaskElement("qwerty", 1);
//    te2 = new TaskElement("asdfgh", 2);
//    te3 = new TaskElement("zxcvbn", 3);
    temp_lst = {te1, te2, te3};

    theme->setListOfTasks(temp_lst);

    this->themesList.append(theme);
}

QList<QObject*> ThemesModel::getTasksList(QString themeName)
{
    foreach (QObject* currThemeObject, this->themesList) {
        Theme *theme = qobject_cast<Theme*>(currThemeObject);
        if(theme->getThemeName() == themeName){
           return theme->getListOfTasks();
        }
    }
}

int ThemesModel::size(){
    return this->themesList.size();
}

Theme* ThemesModel::at(int index){
    return qobject_cast<Theme*>(this->themesList.at(index));
}
