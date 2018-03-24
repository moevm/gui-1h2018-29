#include "themesmodel.h"

ThemesModel::ThemesModel(QObject *parent) : QObject(parent)
{
    this->fillListThemes();
}

QList<QObject*> ThemesModel::getThemesList()
{
    return this->themesList;
}

void ThemesModel::fillListThemes()
{
    QObject *theme=NULL;
    theme = new Theme("Практикуйся в переводе слов", "Переводи с английского языка на русский и обратно слова!");
    this->themesList.append(theme);
    theme = new Theme("Практикуйся в переводе предложений", "Переводи с английского языка на русский и обратно целые предложения!");
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
