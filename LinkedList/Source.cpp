#include"myLinkedList.h"

int main()
{
    myLinkedList obj;
    obj.insertAtTail(100);
    obj.insertAtTail(23);
    obj.insertAtTail(44);
    obj.insertAtHead(92);
    obj.display();
    return 0;
}