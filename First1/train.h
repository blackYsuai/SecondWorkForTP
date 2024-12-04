#ifndef TRAIN_H
#define TRAIN_H

#include <iostream>
#include <string>

#define NAME 0
#define NUMBER 1
#define TIME 2

using namespace std;

class train
{
    string prop[3]; // Поля для хранения данных о поезде
    train* nextPtr; // Указатель на следующий элемент

public:
    // Конструкторы и деструктор
    train(); // Конструктор по умолчанию
    train(string name, string number, string time); // Конструктор с параметрами
    train(const train& other); // Конструктор копирования
    ~train(); // Деструктор

    // Методы доступа
    string getName();
    string getNumber();
    string getType();
    train* getNextPtr();

    // Методы изменения
    void setName(string str);
    void setNumber(string str);
    void setType(string str);
    void setNextPtr(train* p);

    // Перегрузка операторов ввода/вывода
    friend std::ostream& operator<<(std::ostream& os, const train& p)
    {
        return os << "Номер: " << p.prop[NUMBER] << " Пункт назначения: " << p.prop[NAME] << " Время: " << p.prop[TIME] << endl;
    }

    friend std::istream& operator>>(std::istream& in, train& p)
    {
        std::cout << "Номер: ";
        in.clear();
        in.ignore();
        getline(in, p.prop[NUMBER]);

        std::cout << "Пункт назначения: ";
        in.clear();
        getline(in, p.prop[NAME]);

        std::cout << "Время: ";
        in.clear();
        getline(in, p.prop[TIME]);

        in.sync();

        return in;
    }
};

#endif
