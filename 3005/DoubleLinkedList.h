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
    List() :head(NULL), tail(NULL), count(NULL) {}; //���������� ����������

    ~List(); //����������
    void PushBack(int x); // ������� � ����� ������
    void PushFront(int x); // ������� � ������ ������
    bool ShowFromBegin(); // ����� � ������ ������
    bool ShowFromEnd(); // ����� ������ ��������
    bool Remove(int index); // ������� ������� �� �������
    void Insert(int index, int value); // �������� ������� ��� ������
    int GetCount(); // ���-�� ��������� � ������
};


