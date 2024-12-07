#include "train.h"

// Конструктор по умолчанию
train::train()
{
    cout << "Конструктор по умолчанию train вызван" << endl;
    nextPtr = nullptr;
}

// Конструктор с параметрами
train::train(string name, string number, string time)
{
    cout << "Конструктор с параметрами train вызван" << endl;
    prop[NAME] = name;
    prop[NUMBER] = number;
    prop[TIME] = time;
    nextPtr = nullptr;
}

// Конструктор копирования
train::train(const train& other)
{
    cout << "Конструктор копирования train вызван" << endl;
    for (int i = 0; i < 3; i++)
        prop[i] = other.prop[i];
    nextPtr = nullptr; // Указатель не копируем для избежания дублирующих ссылок
}

// Деструктор
train::~train()
{
    cout << "Деструктор train вызван" << endl;
}

string train::getName()
{
    return prop[NAME];
}
string train::getNumber()
{
    return prop[NUMBER];
}
string train::getType()
{
    return prop[TIME];
}
train* train::getNextPtr()
{
    return nextPtr;
}

void train::setName(string str)
{
    prop[NAME] = str;
}
void train::setNumber(string str)
{
    prop[NUMBER] = str;
}
void train::setType(string str)
{
    prop[TIME] = str;
}
void train::setNextPtr(train* p)
{
    nextPtr = p;
}
