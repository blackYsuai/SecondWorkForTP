#include <iostream>
#include "mylist.h"
#include <locale.h>
#include <iostream>
#include <fstream>
#include<string>

using namespace std;
void menu1() {
    cout << endl << "\t����" << endl;
    cout << "0\t�����" << endl;
    cout << "1\t������� 1" << endl;
    cout << "2\t������� 2" << endl;
}
void menuPrint()
{
    setlocale(LC_ALL, "Russian");
    cout << endl << "\t����" << endl;
    cout << "0\t�����" << endl;
    cout << "1\t����� ���� �������" << endl;
    cout << "2\t�������� ������" << endl;
    cout << "3\t������������� ������" << endl;
    cout << "4\t������� ������" << endl;
    cout << "5\t����� �� ������ ����������" << endl;
    cout << "6\t���������� �������" << endl;
}
void task1(myList& obj)
{
    int take = 0;

    while (1)
    {
        menuPrint();
        obj.seeFlag();

        // �������� ��� ������ ������ mcin
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
                    cout << "����������: �������� ������" << endl;
                if (e == 0)
                    cout << "����������: ������ �����������" << endl;
            }
            break;

        case 4:
            try {
                obj.del();
            }
            catch (int e)
            {
                if (e == -1)
                    cout << "����������: �������� ������" << endl;
                if (e == 0)
                    cout << "����������: ������ �����������" << endl;
            }
            break;

        case 5:
            try {
                obj.findType();
            }
            catch (int e)
            {
                if (e == 0)
                    cout << "����������: ������ �����������" << endl;
            }
            break;
        case 6:
            obj.flipFlag();
            break;

        default:
            cout << "����������� �������" << endl;
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

bool check(string a) // �������� �� ������� ������� � ������
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

    ifstream fin; // ������� ������ ������ ifstream
    string filename = "text.txt"; // ��������� �������� �����

    fin.open(filename); // ��������� ����
    if (!fin.is_open()) // ���� ���� �� ��������, ������ �������� ����������, ��� ���� �� ������
    {
        throw "����������: ���� " + filename + " �� ������";
    }

    string str[100];
    string c;
    char ch;
    int count = 0;

    while (!fin.eof()) // ���� ���� �� ����
    {
        fin.get(ch); // �������� ������ (����������� �� ����� "." ��� "?" ��� "!")
        c = ch;

        if (!isDeviderExt(c)) // ���� ������ �� ����� ����� ����������� (�� ���� ����� � �.�)
        {
            while (!fin.eof()) // ���� ���� �� ����
            {
                str[count] += c; // ��������� �����������
                fin.get(ch);
                c = ch;
                if (isDevider(c)) // ���� ��� ����� �����������
                {
                    if (check(str[count])) // �������� �� �������
                    {
                        cout << "" << endl;
                    }
                    else {
                        cout << str[count] << endl; // ������� ����������� � ��������
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
            cout << "����������� �������" << endl;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    myList obj; // ������� ������ �����
    menu(obj);  // �������� ��� � ������� menu
    return 0;   // ���������� ��������� ������ �����
}
