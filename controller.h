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

    ~Controller();

    Q_INVOKABLE QObject* getTheme(int s);
    Q_INVOKABLE QList<QObject*> getTasksList(int themeNum);
    Q_INVOKABLE ThemesModel* getThemesModel();//Получить модель
    Q_INVOKABLE void setTextTheme(int num);
    Q_INVOKABLE int getTextTheme();
    Q_INVOKABLE int getChosenTask();
    Q_INVOKABLE void setChosenTask(int task);
    Q_INVOKABLE int getCompleted();
    Q_INVOKABLE void setCompleted(int q);
    Q_INVOKABLE void addCompleted();
    Q_INVOKABLE int getNumberDoneTasks();
    Q_INVOKABLE void setProfile(QString Name, QString File);
    Q_INVOKABLE QString getSettingsItem(QString key);
    //Q_INVOKABLE void getProfile();

    void readFile();
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
    int m_chosen_theme = 0;
    int m_chosen_task = 0;

    int percent;

public slots:

};

#endif // CONTROLLER_H
