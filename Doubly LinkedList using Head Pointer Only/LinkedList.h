#include"Node.h"
#include<iostream>
using namespace std;
class LinkedList{
protected:
  Node* head;
  
public:
  LinkedList();
  virtual void insertAtTail(int)=0;
  virtual void insertAtHead(int)=0;
  virtual int deleteFromHead()=0;
  virtual int deleteFromTail()=0;
  virtual bool search(int)=0;
  virtual void display()=0;
  ~LinkedList();
};
LinkedList::LinkedList(){
        head=nullptr;
}
LinkedList::~LinkedList(){
    delete head;
}