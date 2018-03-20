#ifndef THEME_H
#define THEME_H

//#include <QList>
#include <QObject>

//#include "task.h"

class Theme:public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString theme_name READ name WRITE setThemeName NOTIFY nameChanged)
    Q_PROPERTY(QString task_description READ desc WRITE setTaskDesc NOTIFY descChanged)



public:
    explicit Theme(QObject *parent=0);
    Theme(const QString &name, const QString &taskDesc, QObject *parent=0);
    Theme(const Theme &other);
    Theme& operator=(const Theme &other);

    //getters
    //QList<Task> *getTaskList();
    QString getThemeName() const;
    QString getTaskDesc() const;
    //setters
    void setThemeName(const QString &themeName);
    //void setTaskList(QList<Task> taskList);
    void setTaskDesc(const QString &taskDesc);
signals:
    void nameChanged();
    void descChanged();
private:
    //List of task to this theme
    //QList<Task> *lessons;
    //theme name
    QString theme_name ;
    //Task description
    QString task_description;
};

#endif // THEME_H