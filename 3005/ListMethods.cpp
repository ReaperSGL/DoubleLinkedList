#include "DoubleLinkedList.h"

List::~List() // деструктор
{
    while (head)
    {
        tail = head->next;
        delete head;
        head = tail;
    }
}

void List::PushBack(int x) { // вставка в конец списка
    Node* temp = new Node;
    temp->next = NULL;
    temp->value = x;

    if (x > 0) {
        if (head != NULL)
        {
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }
        else
        {
            temp->prev = NULL;
            head = tail = temp;
        }
    }
    else {
        temp->prev = NULL;
        if (head != NULL) {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        else {
            head = tail = temp;
        }
    }
    this->count++;
}

void List::PushFront(int x) { // вставка в начало списка
    Node* temp = new Node;
    temp->next = NULL;
    temp->value = x;
    temp->prev = NULL;

    if (head != NULL) {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    else {
        head = tail = temp;
    }
    this->count++;
}

bool List::ShowFromBegin() // вывод с начала списка
{
    Node* temp = new Node;
    temp = head;
    if (!temp) {
        return 0;
    }
    else {
        for (; temp != NULL;) {
            cout << temp->value << " | ";
            temp = temp->next;
        }
        return 1;
    }
}

bool List::ShowFromEnd() // вывод списка наоборот
{
    Node* temp = new Node;
    temp = tail;
    if (!temp) {
        return 0;
    }
    else {
        for (; temp != NULL;) {
            cout << temp->value << " | ";
            temp = temp->prev;
        }
        return 1;
    }
}

bool List::Remove(int index) { // удалить элемент по индексу
    Node* temp = head;

    for (int i = 0; i < index; i++)
        temp = temp->next;

    if (temp == head) {
        temp->prev;
        if (head) {
            head->prev = NULL;
        }
        else {
            tail = NULL;
        }
        delete temp;
    }
    if (temp == tail) {
        tail = tail->prev;
        if (tail) {
            tail->next = NULL;
        }
        delete temp;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
    return 1;
}

void List::Insert(int index, int value) {
    Node* temp = new Node;
    Node* current = head;
    Node* newnode = new Node;
    Node* after;
    newnode->value = value;

    int counter = 0;
    if (index == 0)
    {
        PushFront(value);


    }
    else if (index > count - 1)
    {
        PushBack(value);
    }
    else
    {
        while (counter != index)
        {
            counter++;
            if (counter == index)
            {
                newnode->next = current->next;
                after = newnode->next;
                after->prev = newnode;
                current->next = newnode;
                newnode->prev = current;
                this->count++;
            }
            else
            {
                current = current->next;
            }

        }
    }
}
int List::GetCount() { // кол-во элементов в списке
    return this->count;
}