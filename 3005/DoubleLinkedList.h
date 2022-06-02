#include <iostream>

using namespace std;

typedef struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
} node;

class List {
    Node* head, * tail;
    int count;

public:
    List() :head(NULL), tail(NULL), count(NULL) {}; //заполнение переменных

    ~List(); //деструктор
    void PushBack(int x); // вставка в конец списка
    void PushFront(int x); // вставка в начало списка
    bool ShowFromBegin(); // вывод с начала списка
    bool ShowFromEnd(); // вывод списка наоборот
    bool Remove(int index); // удалить элемент по индексу
    void Insert(int index, int value); // вставить элемент без замены
    int GetCount(); // кол-во элементов в списке
};


