#include "train.h"

// ����������� �� ���������
train::train()
{
    cout << "����������� �� ��������� train ������" << endl;
    nextPtr = nullptr;
}

// ����������� � �����������
train::train(string name, string number, string time)
{
    cout << "����������� � ����������� train ������" << endl;
    prop[NAME] = name;
    prop[NUMBER] = number;
    prop[TIME] = time;
    nextPtr = nullptr;
}

// ����������� �����������
train::train(const train& other)
{
    cout << "����������� ����������� train ������" << endl;
    for (int i = 0; i < 3; i++)
        prop[i] = other.prop[i];
    nextPtr = nullptr; // ��������� �� �������� ��� ��������� ����������� ������
}

// ����������
train::~train()
{
    cout << "���������� train ������" << endl;
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
