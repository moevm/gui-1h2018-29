#ifndef THEMESMODEL_H
#define THEMESMODEL_H

#include <QObject>

#include "theme.h"

class ThemesModel : public QObject
{
    Q_OBJECT
public:
    explicit ThemesModel(QObject *parent = nullptr);

    Q_INVOKABLE QList<QObject*> getTasksList(QString themeName);
    Q_INVOKABLE QList<QObject*> getThemesList();
    int size();
    Theme *at(int index);
signals:

private:
    QList<QObject*> themesList;

    void fillListThemes();

public slots:

};

#endif // THEMESMODEL_H
