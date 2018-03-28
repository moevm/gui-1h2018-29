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
    Q_INVOKABLE QList<QObject*> getTasksList(QString themeName);
    Q_INVOKABLE ThemesModel* getThemesModel();//Получить модель
    Q_INVOKABLE void setTextTheme(QString txt);
    Q_INVOKABLE QString getTextTheme();
    Q_INVOKABLE int getChosenTask();
    Q_INVOKABLE void setChosenTask(int task);


    void setEngine(QQmlApplicationEngine *engine, QQmlContext *ctxt);
    void setThemesModel(ThemesModel *themesModel);//Установить модель

signals:
    // Сигнал для передачи данных в qml-интерфейс
    void sendToQml(int s);
private:
    QQmlApplicationEngine *m_engine;
    QQmlContext *m_ctxt;
    QList<Theme*> m_list;

    ThemesModel *model;//Указатель на модель
    Theme *m_chosen;
    QString m_chosen_theme = "Практикуйся в переводе слов";
    int m_chosen_task;
public slots:
    //void cppSlot(QString s);
    void findTheme(QString theme);
};

#endif // CONTROLLER_H
