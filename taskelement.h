#ifndef TASKELEMENT_H
#define TASKELEMENT_H

#include <QObject>


class TaskElement : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString task_name READ getName WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(int number READ getNumber WRITE setNumber NOTIFY numChanged)
    Q_PROPERTY(QString type READ getType WRITE setType NOTIFY typeChanged)

private:
    //Task number
    int number;
    //Task name
    QList<QObject*> listPairs;
    QString task_name;
    QString type;
    //is Task completed
    bool completed;






public:
    //getters
    int getNumber();
    QString getName();
    QString getType();
    Q_INVOKABLE QList<QObject*> getListPairs();

    bool isCompleted();
    //setters
    void setNumber(int number);
    void setName(QString name);
    void setType(QString type);
    void setListPairs(QList<QObject*> listPairs);
    explicit TaskElement(QObject *parent = nullptr);
    TaskElement(QString name, int number, QString type, QList<QObject*> listPairs, QObject *parent = nullptr);

signals:
    void nameChanged();
    void numChanged();
    void typeChanged();

public slots:
};

#endif // TASKELEMENT_H
