#include"Node.h"
#include<iostream>
using namespace std;

class LinkedList
{
protected:
   Node* head;
   Node* tail;
public:
    LinkedList();
    virtual void insertAtTail(int)=0;
    virtual void insertAtHead(int)=0;
    virtual void display()=0;
    virtual int deleteFromTail()=0;
};

LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
}
