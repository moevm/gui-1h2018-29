#ifndef PAIR_H
#define PAIR_H

#include <QObject>

class Pair : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString word READ getWord WRITE setWord NOTIFY wordChanged)
    Q_PROPERTY(QString meaning READ getMeaning WRITE setMeaning NOTIFY meaningChanged)
    Q_PROPERTY(QString fake1 READ getFake1 WRITE setFake1 NOTIFY fake1Changed)
    Q_PROPERTY(QString fake2 READ getFake2 WRITE setFake2 NOTIFY fake2Changed)
    Q_PROPERTY(QString fake3 READ getFake3 WRITE setFake3 NOTIFY fake3Changed)

private:
    QString word;
    QString meaning;
    QString fake1;
    QString fake2;
    QString fake3;
public:
    explicit Pair(QObject *parent = nullptr);
    Pair(QString word, QString meaning, QObject *parent = nullptr);
    Pair(QString word, QString meaning,QString fake1,QString fake2,QString fake3, QObject *parent = nullptr);
//setters
    void setWord(QString word);
    void setMeaning(QString meaning);
    void setPair(QString word, QString meaning);
    void setFake1(QString fake1);
    void setFake2(QString fake2);
    void setFake3(QString fake3);
//getters
    QString getMeaning();
    QString getWord();
    QString getFake1();
    QString getFake2();
    QString getFake3();
signals:
    void wordChanged();
    void meaningChanged();
    void fake1Changed();
    void fake2Changed();
    void fake3Changed();

public slots:
};

#endif // PAIR_H
