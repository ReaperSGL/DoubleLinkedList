#include <iostream>
#include "DoubleLinkedList.h"
#pragma warning(disable:4996)
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    List list;
    short answer = 0;
    int value = 0, size = 0;
    bool temp = 0;
    cout << "\t....::::Создание списка::::....\n";
    cout << "\nВведите размер списка:\n";
    cin >> size;

    for (int i = 0; i < size; i++) {
        list.PushBack(i);
    }
    cout << "\nСписок создан.\n\n";
    while (1) 
    {
        cout << "\t.....:::::Главное Меню:::::.....\n\n";
        cout << "\t1 | Вывести все элементы списка\n\t2 | Добавить элемент в список\n\t3 | Кол-во элементов в списке\n\t4 | Удалить элемент по индексу\n\t5 | Выйти\n\t................................." << endl;
        cin >> answer;
        switch (answer) {
        case 1:
            cout << "\n\t0 | Вывести список с начала\n\t1 | Вывести список наоборот\n";
            cin >> temp;
            cout << endl;
            if (!temp) {
                list.ShowFromBegin();
                cout << "\n\n";
                break;
            }
            else {
                list.ShowFromEnd();
                cout << "\n\n";
                break;
            }
        case 2:
            int temp_value;
            cout << "\n";
            cout << "Введите индекс:\n";
            cin >> value;
            cout << "Введите значение:\n";
            cin >> temp_value;
            list.Insert(value, temp_value);
            break;
        case 3:
            cout << "\n";
            cout << "Элементов в списке: " << list.GetCount() << "\n\n";
            break;
        case 4:
            cout << "Введите индекс:\n";
            cin >> value;
            cout << "\n";
            list.Remove(value);
            break;
        case 5:
            exit(0);
        }
    }
}