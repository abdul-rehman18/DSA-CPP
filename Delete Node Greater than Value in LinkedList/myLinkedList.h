#include"LinkedList.h"

class myLinkedList:public LinkedList
{
public:
    void insertAtTail(int);
    void insertAtHead(int);
    void insertSorted(int);
    void display();
    int deleteFromTail();
    int deleteFromHead();
    bool deleteValue(int);
    void deleteNode(int);
};

void myLinkedList::insertAtTail(int value)
{
    Node* newNode;
    newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if(head == nullptr)
    {
        head = newNode;
    }

    else
    {
        Node* t = head;
        while(1)
        {
            if (t->next == nullptr)
                break;
            t = t->next;
        }
        t->next = newNode;
    }
}

void myLinkedList::insertAtHead(int value)
{
    Node* newNode;
    newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if(head == nullptr)
    {
        head = newNode;
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
    if(head == nullptr)
    {
        cout << "LinkedList is empty...." << endl;
        return 0;
    }
    else if(head->next == nullptr)
    {
        int rv = head->data;
        delete head;
        head =  nullptr;
        return rv;
    }
    else
    {
        Node* temp = head;
        while (1)
        {
            if(temp->next->next == nullptr)
                break;
            temp = temp->next;
        }
        int rv = temp->next->data;
        delete temp->next;
        temp->next = nullptr;
        return rv;
    }
}

int myLinkedList::deleteFromHead()
{
    if (head == nullptr)
    {
        cout << "LinkedList is empty...." << endl;
        return 0;
    }
    else if (head->next == nullptr)
    {
        int rv = head->data;
        delete head;
        head = nullptr;
        return rv;
    }
    else
    {
        int rv = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        temp = nullptr;
        return rv;
    }
}

bool myLinkedList::deleteValue(int value)
{
    if (head == nullptr)
    {
        cout << "LinkedList is empty...." << endl;
        return false;
    }
    else if (head->next == nullptr)
    {
        if(value == head->data)
        {
            delete head;
            head = nullptr;
            return true;
        }
        return false;
    }
    else
    {
        if(value == head->data)
        {
            deleteFromHead();
            return true;
        }
        else
        {
            Node* t1 = head;
            while(1)
            {
                if(value == t1->next->data)
                    break;
                else
                    t1 = t1->next;
                if (t1->next == nullptr)
                    return false;
            }
            Node* t2 = t1->next;
            t1->next = t1->next->next;
            //or
            //t1->next = t2->next;
            delete t2;
            t2 = nullptr;
            return true;
        }
    }
}

void myLinkedList::insertSorted(int value)
{
    if(head == nullptr)
    {
        Node* newNode;
        newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        head = newNode;
    }
    else if(value <= head->data)
        insertAtHead(value);
    else
    {
        Node* newNode;
        newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        Node* t1 = head;
        while (1)
        {
            if(value > t1->data && value <= t1->next->data)
            {
                newNode->next = t1->next;
                t1->next = newNode;
                break;
            }
            else
                t1 = t1->next;
            if (t1->next == nullptr)
            {
                t1->next = newNode;
                break;
            }
        }
           
    }
}

void myLinkedList::deleteNode(int value)
{
    Node* curr= head;
    Node* prev=nullptr;
    while(curr != nullptr)
    {
        if(curr->data > value)
        {
            if(prev==nullptr)
            {
                head = curr->next;
                delete curr;
                curr = head;
            }
            else
            {
                prev->next = curr->next;
                Node *temp = curr->next;
                delete curr;
                curr = temp;
            }
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
}