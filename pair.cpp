#include "pair.h"

Pair::Pair(QObject *parent) : QObject(parent)
{

}

Pair::Pair(QString word, QString meaning, QObject *parent)
{
    this->word = word;
    this->meaning = meaning;
}

Pair::Pair(QString word, QString meaning,QString fake1,QString fake2,QString fake3, QObject *parent)
{
    this->word = word;
    this->meaning = meaning;
    this->fake1 = fake1;
    this->fake2 = fake2;
    this->fake3 = fake3;
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
QString Pair::getFake1(){
    return this->fake1;
}
QString Pair::getFake2(){
    return this->fake2;
}
QString Pair::getFake3(){
    return this->fake3;
}

void Pair::setFake1(QString fake1){
    this->fake1 = fake1;
}
void Pair::setFake2(QString fake2){
    this->fake2 = fake2;
}
void Pair::setFake3(QString fake3){
    this->fake3 = fake3;
}
