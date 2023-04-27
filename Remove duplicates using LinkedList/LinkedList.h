#include"Node.h"
#include<iostream>
using namespace std;

template<class T>
class Linkedlist
{
protected:
	Node<T>* head;
	Node<T>* tail;
public:
	Linkedlist();
	virtual bool isEmpty() = 0;
	virtual void insertAtTail(T) = 0;
	virtual void insertAtHead(T) = 0;
	virtual void insertSorted(T) = 0;
	virtual void display() = 0;
	virtual bool deleteFromTail() = 0;
	virtual bool deleteFromHead() = 0;
	virtual bool deleteValue(T) = 0;
	virtual bool search(T) = 0;
	virtual void removeDuplicates() = 0;
};

template<class T>
Linkedlist<T>::Linkedlist()
{
	head = nullptr;
	tail = nullptr;
}
