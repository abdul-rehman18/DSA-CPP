#include"LinkedList.h"

class myLinkedList:public LinkedList
{
public:
   myLinkedList();
   void insertAtTail(int);
   void insertAtHead(int);
   int deleteFromHead();
   int deleteFromTail();
   void display();
};

void myLinkedList::display(){
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}

void myLinkedList::insertAtHead(int value){
    Node* newNode=new Node;
    newNode->data=value;
    newNode->next=nullptr;
    newNode->prev=nullptr;
    if(head==nullptr){
        head=newNode;
       
    }
    else{
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
    }
}

int myLinkedList::deleteFromHead(){
       if(head==nullptr){
           cout<<" LL is empty !"<<endl;
           return NULL;
       }
       else if(head->next==nullptr){
           int rv=head->data;
           delete head;
           head=nullptr;
           return rv;
       }
       else{
           int rv=head->data;
           Node* temp=head;
           head=head->next;
           head->prev=nullptr;
           delete temp;
           temp=nullptr;
           return rv;
       }   
}

int myLinkedList::deleteFromTail(){
        if(head==nullptr){
           cout<<" LL is empty !"<<endl;
           return NULL;
       }
        else if(head->next==nullptr){
           int rv=head->data;
           delete head;
           head=nullptr;
           return rv;
       }
       else{
            Node* temp=head;
            while(temp->next!=nullptr){
                temp=temp->next;
            }
            int rv=temp->data;
            temp->prev->next=nullptr;
            delete temp;
            temp=nullptr;
            return rv;
       }
        
}
 

void myLinkedList::insertAtTail(int value){
    Node* newNode=new Node;
    newNode->data=value;
    newNode->next=nullptr;
    newNode->prev=nullptr;
    if(head==nullptr){
        head=newNode;
       
    }
    else
    {
        Node* temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;       
    }
}

