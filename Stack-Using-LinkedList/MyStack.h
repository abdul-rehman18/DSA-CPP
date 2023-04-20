#include "Stack.h"


class myStack :public Stack
{
private:
    myLinkedList stk;
public:
	void push(int);
	int pop();
	int top();
	myStack(int ss);
	bool isEmpty();
	void display();
};


bool myStack::isEmpty()
{
	if (stk.head == nullptr && stk.tail == nullptr)
        return true;
	return false;
}


void myStack::display()
{
	cout << "Maximum Size: " << Stack::maxSize << endl;
	cout << "Current Size: " << Stack::currentSize << endl;

	stk.display();
}



myStack::myStack(int ss):Stack(ss)
{

}


void myStack::push(int value)
{
    stk.insertAtTail(value);
}



int myStack::pop()
{
	if (isEmpty())
	{
		cout << "Stack is Empty, returning ZERO" << endl;
		return 0;
	}
    stk.deleteFromTail();
}



int myStack::top()
{
    if (isEmpty())
	{
		cout << "Stack is Empty, returning ZERO" << endl;
		return 0;
	}
	return Stack::arr[Stack::currentSize-1];
}