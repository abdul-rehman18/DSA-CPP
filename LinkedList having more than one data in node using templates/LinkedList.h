#include"Node.h"
#include"Record.h"
#include<iostream>
using namespace std;

template<class T>
class Linkedlist
{
protected:
	Node<T>* head;
public:
	Linkedlist();
	virtual bool isEmpty() = 0;
	virtual void insertAtTail(T) = 0;
	virtual void insertAtHead(T) = 0;
	virtual void deletebyID(int) = 0;
	virtual T deleteFromHead() = 0;
	virtual void display() = 0;
	//virtual void insertSorted(T, bool) = 0;
	virtual void sortbyID() = 0;
	virtual void sortbyName() = 0;

};

template<class T>
Linkedlist<T>::Linkedlist()
{
	head = nullptr;
}
