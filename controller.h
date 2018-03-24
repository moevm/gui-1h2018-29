#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QtQuick>
#include <QQuickView>
#include <themesmodel.h>

#include "theme.h"

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr);
    Controller(QList<Theme*> list,QObject *parent = nullptr);
    Controller(ThemesModel *themesModel,QObject *parent = nullptr);
    Controller(const Controller &other);
    Controller& operator=(const Controller &other);

    Q_INVOKABLE QObject* getTheme(QString s);

    void setEngine(QQmlApplicationEngine *engine, QQmlContext *ctxt);
    void setThemesModel(ThemesModel *themesModel);//Установить модель
    ThemesModel* getThemesModel();//Получить модель
signals:
    // Сигнал для передачи данных в qml-интерфейс
    void sendToQml(int s);
private:
    QQmlApplicationEngine *m_engine;
    QQmlContext *m_ctxt;
    QList<Theme*> m_list;

    ThemesModel *model;//Указатель на модель
    Theme *m_chosen;
public slots:
    //void cppSlot(QString s);
    void findTheme(QString theme);
};

#endif // CONTROLLER_H
