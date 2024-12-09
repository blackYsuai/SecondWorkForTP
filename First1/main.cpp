#include <iostream>
#include "mylist.h"
#include <locale.h>
#include <iostream>
#include <fstream>
#include<string>

using namespace std;
void menu1() {
    cout << endl << "\tМеню" << endl;
    cout << "0\tВыход" << endl;
    cout << "1\tЗадание 1" << endl;
    cout << "2\tЗадание 2" << endl;
}
void menuPrint()
{
    setlocale(LC_ALL, "Russian");
    cout << endl << "\tМеню" << endl;
    cout << "0\tВыход" << endl;
    cout << "1\tВывод всех записей" << endl;
    cout << "2\tДобавить запись" << endl;
    cout << "3\tРедактировать запись" << endl;
    cout << "4\tУдалить запись" << endl;
    cout << "5\tПоиск по пункту назначения" << endl;
    cout << "6\tСортировка записей" << endl;
}
void task1(myList& obj)
{
    int take = 0;

    while (1)
    {
        menuPrint();
        obj.seeFlag();

        // Временно для тестов вместо mcin
        cin >> take;

        switch (take)
        {
        case 0:
            return;

        case 1:
            obj.print();
            break;

        case 2:
            obj.add();
            break;

        case 3:
            try {
                obj.edit();
            }
            catch (int e)
            {
                if (e == -1)
                    cout << "ИСКЛЮЧЕНИЕ: Неверный индекс" << endl;
                if (e == 0)
                    cout << "ИСКЛЮЧЕНИЕ: Записи отсутствуют" << endl;
            }
            break;

        case 4:
            try {
                obj.del();
            }
            catch (int e)
            {
                if (e == -1)
                    cout << "ИСКЛЮЧЕНИЕ: Неверный индекс" << endl;
                if (e == 0)
                    cout << "ИСКЛЮЧЕНИЕ: Записи отсутствуют" << endl;
            }
            break;

        case 5:
            try {
                obj.findType();
            }
            catch (int e)
            {
                if (e == 0)
                    cout << "ИСКЛЮЧЕНИЕ: Записи отсутствуют" << endl;
            }
            break;
        case 6:
            obj.flipFlag();
            break;

        default:
            cout << "Неизвестная команда" << endl;
        }
    }
}
bool isDevider(string ch)
{
    return (ch == "." || ch == "!" || ch == "?" || ch == "\"");
}

bool isDeviderExt(string ch)
{
    return (ch == "." || ch == "!" || ch == "?" || ch == "\"" || ch == " " || ch == "\t" || ch == "\n");
}

bool check(string a) // проверка на наличие кавычек в строке
{
    if (a.find('<<') != string::npos)
    {
        return 0;
    }
    else return 1;
}

void readFile()
{
    setlocale(LC_ALL, "Russian");

    ifstream fin; // создаем объект класса ifstream
    string filename = "text.txt"; // объявляем название файла

    fin.open(filename); // открываем файл
    if (!fin.is_open()) // если файл не открылся, значит вызываем исключение, что файл не найден
    {
        throw "Исключение: файл " + filename + " не найден";
    }

    string str[100];
    string c;
    char ch;
    int count = 0;

    while (!fin.eof()) // пока файл не пуст
    {
        fin.get(ch); // получаем строку (предложение до знака "." или "?" или "!")
        c = ch;

        if (!isDeviderExt(c)) // пока строка не равна конце предложения (то есть точки и т.д)
        {
            while (!fin.eof()) // пока файл не пуст
            {
                str[count] += c; // добавляем предложение
                fin.get(ch);
                c = ch;
                if (isDevider(c)) // если это конец предложения
                {
                    if (check(str[count])) // проверка на запятую
                    {
                        cout << "" << endl;
                    }
                    else {
                        cout << str[count] << endl; // выводим предложения в кавычках
                    }

                    count++;
                    break;
                }
            }
        }
    }
    fin.close();
}

void menu(myList& obj)
{
    int take = 0;

    while (1)
    {
        menu1();

        cin >> take;

        switch (take)
        {
        case 0:
            return;

        case 1:
            system("cls");
            task1(obj);
            break;
        case 2:
            system("cls");
            readFile();
            break;

        default:
            cout << "Неизвестная команда" << endl;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    myList obj; // Создаем объект здесь
    menu(obj);  // Передаем его в функцию menu
    return 0;   // Деструктор вызовется только здесь
}
