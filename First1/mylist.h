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
    myList();            // �����������
    ~myList();           // ����������

    train* operator[](int idx); // ������ �� �������
    void flipFlag();            // ������������ ����� ����������
    void seeFlag();             // �������� �������� �����
    void add();                 // ���������� ������
    void print();               // ������ ������
    void del();                 // �������� ������
    void edit();                // �������������� ������
    void sort();                // ���������� ������
    void findType();            // ����� �� ������ ����������
};

#endif
