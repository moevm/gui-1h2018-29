#ifndef THEME_H
#define THEME_H

//#include <QList>
#include <QObject>

#include "taskelement.h"

class Theme:public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString theme_name READ getThemeName WRITE setThemeName NOTIFY nameChanged)
    Q_PROPERTY(QString task_description READ getTaskDesc WRITE setTaskDesc NOTIFY descChanged)



public:
    explicit Theme(QObject *parent=0);
    Theme(const QString &name, const QString &taskDesc, int number, QObject *parent=0);

    Theme(const Theme &other);
    Theme& operator=(const Theme &other);

    //getters
    QString getThemeName() const;
    QString getTaskDesc() const;
    Q_INVOKABLE QObject* getTaskElement(int num);
    //setters
    void setThemeName(const QString &themeName);
    //void setTaskList(QList<Task> taskList);
    void setTaskDesc(const QString &taskDesc);
    void setListOfTasks(QList<QObject*> tasks);
    Q_INVOKABLE QList<QObject*> getListOfTasks();

    Q_INVOKABLE int getNumber();
    Q_INVOKABLE void setNumber(int num);
signals:
    void nameChanged();
    void descChanged();
private:
    //List of task to this theme
    QList<QObject*> tasks;
    //theme name
    QString theme_name ;
    //Task description
    QString task_description;

    int m_number = 0;
};

#endif // THEME_H
