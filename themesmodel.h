#ifndef THEMESMODEL_H
#define THEMESMODEL_H

#include <QObject>

#include "theme.h"

class ThemesModel : public QObject
{
    Q_OBJECT
public:
    explicit ThemesModel(QObject *parent = nullptr);

    QList<Theme*> themesList;

signals:

private:



public slots:

};

#endif // THEMESMODEL_H
