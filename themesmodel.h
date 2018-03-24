#ifndef THEMESMODEL_H
#define THEMESMODEL_H

#include <QObject>

#include "theme.h"

class ThemesModel : public QObject
{
    Q_OBJECT
public:
    explicit ThemesModel(QObject *parent = nullptr);

    QList<QObject*> getTasksList(QString themeName);
    QList<QObject*> getThemesList();

signals:

private:
    QList<QObject*> themesList;

    void fillListThemes();

public slots:

};

#endif // THEMESMODEL_H
