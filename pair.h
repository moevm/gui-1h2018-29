#ifndef PAIR_H
#define PAIR_H

#include <QObject>

class Pair : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString word READ getWord WRITE setWord NOTIFY wordChanged)
    Q_PROPERTY(QString meaning READ getMeaning WRITE setMeaning NOTIFY meaningChanged)
private:
    QString word;
    QString meaning;
public:
    explicit Pair(QObject *parent = nullptr);
    Pair(QString word, QString meaning, QObject *parent = nullptr);
//setters
    void setWord(QString word);
    void setMeaning(QString meaning);
    void setPair(QString word, QString meaning);
//getters
    QString getMeaning();
    QString getWord();
signals:
    void wordChanged();
    void meaningChanged();
public slots:
};

#endif // PAIR_H
