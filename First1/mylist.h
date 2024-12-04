#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>
#include "train.h"

class myList
{
    train* HEAD;
    train* LAST;
    int size;
    bool a_to_z_flag;

public:
    myList();            // Конструктор
    ~myList();           // Деструктор

    train* operator[](int idx); // Доступ по индексу
    void flipFlag();            // Переключение флага сортировки
    void seeFlag();             // Просмотр текущего флага
    void add();                 // Добавление записи
    void print();               // Печать списка
    void del();                 // Удаление записи
    void edit();                // Редактирование записи
    void sort();                // Сортировка списка
    void findType();            // Поиск по пункту назначения
};

#endif
