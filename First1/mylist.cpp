#include "mylist.h"

// Шаблон для ввода данных
template <typename T>
void mcin(T* _x)
{
    while (true)
    {
        setlocale(LC_ALL, "Russian");
        cin >> *_x;
        if (std::cin.good())
            break;

        cout << "Неверный ввод" << std::endl;
        cin.clear();
        cin.ignore();
    }
}

train* myList::operator[](int idx)
{
    setlocale(LC_ALL, "Russian");
    if (idx < 0 || idx > size)
    {
        return nullptr;
    }

    train* ptr = HEAD;

    int count = 0;
    while (count != idx)
    {
        ptr = ptr->getNextPtr();
        count++;
    }

    return ptr;
}

void myList::sort()
{
    setlocale(LC_ALL, "Russian");
    if (size <= 1)
        return;

    train* p = HEAD->getNextPtr();
    int count = 1;
    while (count < size)
    {
        int state = strcmp(p->getName().c_str(), p->getNextPtr()->getName().c_str());
        bool isToSort = (a_to_z_flag == true) ? (state > 0) : (state < 0);

        if (isToSort)
        {
            train* ptr0 = (*this)[count - 1];
            train* ptr1 = (*this)[count];
            train* ptr2 = (*this)[count + 1];
            train* ptr3 = (*this)[count + 2];

            ptr0->setNextPtr(ptr2);
            ptr1->setNextPtr(ptr3);
            ptr2->setNextPtr(ptr1);

            if (LAST == ptr2)
                LAST = ptr1;

            count = 1;
            p = HEAD->getNextPtr();
        }
        else
        {
            p = p->getNextPtr();
            count++;
        }
    }
}

myList::myList()
{
    setlocale(LC_ALL, "Russian");
    cout << "Конструктор myList вызван" << endl;
    size = 0;
    HEAD = new train;
    LAST = HEAD;
    a_to_z_flag = true;
}

// Деструктор
myList::~myList()
{
    setlocale(LC_ALL, "Russian");
    cout << "Деструктор myList вызван" << endl;

    train* current = HEAD;
    while (current != nullptr)
    {
        train* next = current->getNextPtr();
        delete current;
        current = next;
    }
}

void myList::flipFlag()
{
    setlocale(LC_ALL, "Russian");
    a_to_z_flag = !a_to_z_flag;
    if (size > 0)
        sort();
}

void myList::seeFlag()
{
    setlocale(LC_ALL, "Russian");
    cout << "\tТекущая сортировка: ";
    if (a_to_z_flag)
        cout << "\tA до Z" << endl;
    else
        cout << "\tZ до A" << endl;
}

void myList::add()
{
    setlocale(LC_ALL, "Russian");
    cout << "\tДобавление новой записи" << endl;
    train* add_obj = new train;
    cin >> *add_obj;
    LAST->setNextPtr(add_obj);
    LAST = add_obj;
    size++;
    sort();
    cout << "\tЗапись добавлена" << endl;
}

void myList::print()
{
    setlocale(LC_ALL, "Russian");
    if (size == 0)
        cout << endl << "\tОбъекты отсутствуют" << endl;
    else
        cout << endl << "\tСПИСОК ВСЕХ ОБЪЕКТОВ" << endl;

    train* p = HEAD->getNextPtr();
    while (p != nullptr)
    {
        cout << *p << endl;
        p = p->getNextPtr();
    }
}

void myList::del()
{
    setlocale(LC_ALL, "Russian");
    cout << "\tУдаление" << endl;
    if (size == 0)
        throw 0;

    cout << "\tВыберите запись для удаления (от 1 до " << size << "): ";

    int idx;
    mcin(&idx);
    if (idx < 1 || idx > size)
        throw - 1;

    train* prev = (*this)[idx - 1];

    if (idx == size)
    {
        delete LAST;
        LAST = prev;
        LAST->setNextPtr(nullptr);
        size--;
        return;
    }

    train* curr = (*this)[idx];
    train* next = (*this)[idx + 1];

    delete curr;
    prev->setNextPtr(next);

    cout << "\tЗапись удалена" << endl;
    size--;
    sort();
}

void myList::edit()
{
    setlocale(LC_ALL, "Russian");
    cout << "\tРедактирование" << endl;
    if (size == 0)
        throw 0;

    cout << "\tВыберите запись для редактирования (от 1 до " << size << "): ";

    int idx;
    mcin(&idx);
    if (idx < 1 || idx > size)
        throw - 1;

    train* curr = (*this)[idx];
    cout << "\tВведите новые значения для записи:" << endl;
    cin >> *curr;

    cout << "\tЗапись отредактирована" << endl;
    sort();
}

void myList::findType()
{
    setlocale(LC_ALL, "Russian");
    cout << "\tПоиск" << endl;
    if (size == 0)
        throw 0;

    string searchValue;

    cout << "\tВведите пункт назначения для поиска: ";
    cin.clear();
    cin.ignore();
    getline(cin, searchValue);

    train* p = HEAD->getNextPtr();
    while (p != nullptr)
    {
        if (p->getName() == searchValue)
        {
            cout << "Номер: " << p->getNumber() << " Пункт назначения: " << p->getName() << " Время: " << p->getType() << endl;
        }
        p = p->getNextPtr();
    }
    cout << "\tПоиск завершен" << endl;
}
