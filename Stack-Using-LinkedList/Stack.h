#include"MyLinkedList.h"

#include <iostream>
using namespace std;

class Stack
{
protected:
	int* arr;
	int maxSize;
	int currentSize;
public:
	virtual void push(int) = 0; 	//add Value
	virtual int pop() = 0;		//remove Value
	virtual int top() = 0;
	virtual bool isEmpty() = 0;
	Stack(int);
};

Stack<T>::Stack(int s)
{
	arr = new T[s];
	maxSize = s;
	currentSize = 0;
}