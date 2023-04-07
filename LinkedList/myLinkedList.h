#include"LinkedList.h"

class myLinkedList:public LinkedList
{
public:
    void insertAtTail(int);
    void insertAtHead(int);
    void display();
    int deleteFromTail();
};


