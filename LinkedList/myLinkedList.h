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

void myLinkedList::insertAtTail(int value)
{
    Node* newNode;
    newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if(head == nullptr && tail == nullptr)
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

void myLinkedList::insertAtHead(int value)
{
    Node* newNode;
    newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if(head == nullptr && tail == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

void myLinkedList::display()
{
    Node* temp = head;
    while (1)
    {
        if(temp == nullptr)
            break;
        cout<< temp->data <<endl;
        temp = temp->next;
    }
    
}

int myLinkedList::deleteFromTail()
{
    if(head == nullptr && tail == nullptr)
    {
        cout << "LinkedList is empty...." << endl;
        return NULL;
    }
    else if(head==tail)
    {
        int rv = head->data;
        delete head;
        //or
        //delete tail;
        head =  nullptr;
        tail = nullptr;
        return rv;
    }
    else
    {
        Node* temp = head;
        while (1)
        {
            if(temp->next == tail)
                break;
            temp = temp->next;
        }
        int rv = tail->data;
        delete tail;
        tail = temp;
        temp->next = nullptr;
        //or
        //tail->next = nullptr;
        return rv;
    }
}

int myLinkedList::deleteFromHead()
{
    if (head == nullptr && tail == nullptr)
    {
        cout << "LinkedList is empty...." << endl;
        return NULL;
    }
    else if (head == tail)
    {
        int rv = head->data;
        delete head;
        head = nullptr;
        tail = nullptr;
        return rv;
    }
    else
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        temp = nullptr;
        return rv;
    }
}