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
    //Theme *theme=NULL;
    Theme *theme1 = new Theme("Практикуйся в переводе слов", "Переводи с английского языка на русский и обратно слова!", 0);

    QList<QObject*> listPairs_animals;
    listPairs_animals.append(new Pair("Сat", "кот"));
    listPairs_animals.append(new Pair("Dog", "собака"));
    listPairs_animals.append(new Pair("Partridge", "куропатка"));
    listPairs_animals.append(new Pair("Titmouse", "синица"));
    listPairs_animals.append(new Pair("Elephant", "слон"));


    QList<QObject*> listPairs_house;
    listPairs_house.append(new Pair("Kitchen", "кухня"));
    listPairs_house.append(new Pair("Bathroom", "ванная"));
    listPairs_house.append(new Pair("Window", "окно"));
    listPairs_house.append(new Pair("Door", "дверь"));
    listPairs_house.append(new Pair("Floor", "этаж"));


    QList<QObject*> listPairs_directions;
    listPairs_directions.append(new Pair("Right", "право"));
    listPairs_directions.append(new Pair("Left", "лево"));
    listPairs_directions.append(new Pair("Forward", "вперед"));
    listPairs_directions.append(new Pair("Back", "назад"));
    listPairs_directions.append(new Pair("Above", "вверх"));



    QList<QObject*> listPairsCheck;
    listPairsCheck.append(new Pair("Cat is a ...", "animal", "insect", "bird", "bug"));

    listPairsCheck.append(new Pair("Dog's ... funny", "are", "is", "has", "were"));

    listPairsCheck.append(new Pair("Partridge is ...", "small", "big", "most", "bird"));

    listPairsCheck.append(new Pair("Titmouse live in a ...", "wood", "town", "penthouse", "hood"));

    listPairsCheck.append(new Pair("Elephant is ...", "big", "small", "red", "atomic"));


    TaskElement *te1 = new TaskElement("Animals", 1, "words",listPairs_animals);
    TaskElement *te2 = new TaskElement("House", 2, "words",listPairs_house);
    TaskElement *te3 = new TaskElement("Directions", 3, "words",listPairs_directions);


    QList<QObject*> temp_lst = {te1, te2, te3};



//    QList<QObject*> temp_lst;
//    listPairs.append(new TranslateTask("Animals", 1, "words",listPairs));
//    listPairs.append(new TranslateTask("Community", 2, "sentenses",listPairsSent));
//    listPairs.append(new TranslateTask("Games", 3, "check",listPairs));
//    listPairs.append(new TranslateTask("Animals", 4, "words",listPairs));


    theme1->setListOfTasks(temp_lst);

    this->themesList.append(theme1);

    Theme *theme2 = new Theme("Практикуйся в переводе предложений", "Переводи с английского языка на русский и обратно целые предложения!", 1);

    QList<QObject*> listPairsSent_1;
    listPairsSent_1.append(new Pair("Cat is a animal", "кот это животное"));
    listPairsSent_1.append(new Pair("Dog's are cute", "собаки милые"));
    listPairsSent_1.append(new Pair("Partridge is small", "куропатка маленькая"));
    listPairsSent_1.append(new Pair("Titmouse live in town's", "синица живет в городе"));
    listPairsSent_1.append(new Pair("Elephant is big", "слон большой"));

    QList<QObject*> listPairsSent_2;
    listPairsSent_2.append(new Pair("I love programming", "я люблю программирование"));
    listPairsSent_2.append(new Pair("Computers are usefull", "компьютеры полезные"));
    listPairsSent_2.append(new Pair("Programs do our life better", "программы делают нашу жизнь лучше"));
    listPairsSent_2.append(new Pair("First computer was released 80 years ago", "первый компьютер был выпущен 80 лет назад"));
    listPairsSent_2.append(new Pair("Your 'Windows' is updating", "ваш 'windows' обновляется"));


    te1 = new TaskElement("Animals", 1, "sentenses",listPairsSent_1);
    te2 = new TaskElement("Computers", 2, "sentenses",listPairsSent_2);


    temp_lst = {te1, te2, te3};

    theme2->setListOfTasks(temp_lst);

    this->themesList.append(theme2);


    Theme *theme3 = new Theme("Выбери 1 правильный вариант", "Улучшай знание грамматики!", 2);

    te3 = new TaskElement("Animals", 3, "check",listPairsCheck);

    temp_lst = {te3};

    theme3->setListOfTasks(temp_lst);

    this->themesList.append(theme3);
}

QList<QObject*> ThemesModel::getTasksList(int themeNum)
{
    foreach (QObject* currThemeObject, this->themesList) {
        Theme *theme = qobject_cast<Theme*>(currThemeObject);
        if(theme->getNumber() == themeNum){
           return theme->getListOfTasks();
        }
    }
}

int ThemesModel::size(){
    return this->themesList.size();
}

//Theme* ThemesModel::at(int index){
//    return qobject_cast<Theme*>(this->themesList.at(index));
//}
