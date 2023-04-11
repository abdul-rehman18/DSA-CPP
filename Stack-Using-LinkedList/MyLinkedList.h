#include"LinkedList.h"

class myLinkedList:public LinkedList
{
public:
    void insertAtTail(int);
    void insertAtHead(int);
    void display();
    int deleteFromTail();
    int deleteFromHead();
};

void myLinkedList::insertAtTail(int)
{
    Node* newNode;
    newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if ( head == nullptr && tail == nullptr)
    {
        head = newNode;
        tail = newNode;
    }

    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

void myLinkedList::insertAtHead(int)
{
    Node* newNode;
    newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if ( head == nullptr && tail == nullptr)
    {
        head = newNode;
        tail = newNode;
    }

    else
    {
        newNode->next = head;
        tail = newNode;
    }
}

void myLinkedList::display()
{
    
}