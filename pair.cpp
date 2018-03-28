#include "pair.h"

Pair::Pair(QObject *parent) : QObject(parent)
{

}

Pair::Pair(QString word, QString meaning, QObject *parent)
{
    this->word = word;
    this->meaning = meaning;
}

void Pair::setWord(QString word)
{
    this->word = word;
    emit wordChanged();
}

void Pair::setMeaning(QString meaning)
{
    this->meaning;
    emit meaningChanged();
}

void Pair::setPair(QString word, QString meaning)
{
    this->word = word;
    this->meaning = meaning;
}

QString Pair::getMeaning()
{
    return this->meaning;
}

QString Pair::getWord()
{
    return this->word;
}

