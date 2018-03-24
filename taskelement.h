#ifndef TASKELEMENT_H
#define TASKELEMENT_H

#include <QObject>

class TaskElement : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString task_name READ getName WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(int number READ getNumber WRITE setNumber NOTIFY numChanged)

private:
    //Task number
    int number;
    //Task name
    QString task_name;

    //is Task completed
    bool completed;
public:
    //getters
    int getNumber();
    QString getName();
    bool isCompleted();
    //setters
    void setNumber(int number);
    void setName(QString name);

    explicit TaskElement(QObject *parent = nullptr);
    TaskElement(QString name, int number, QObject *parent = nullptr);

signals:
    void nameChanged();
    void numChanged();

public slots:
};

#endif // TASKELEMENT_H
