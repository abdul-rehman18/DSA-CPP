#include "Queue.h"

class myQueue :public Queue
{
private:
    myLinkedList que;
public:
	void enqueue(int);
	int dequeue();
	myQueue(int ss);
	bool isEmpty();
	void display();
};

bool myQueue::isEmpty()
{
    if(Queue::currentSize == 0)
        return true;
    return false;
}

void myQueue::display()
{
	cout << "Maximum Size: " << Queue::maxSize << endl;
	cout << "Current Size: " << Queue::currentSize << endl;

	for (int i = 0; i < Queue::currentSize; i++)
		cout << i << ". " << Queue::arr[i] << endl;
}

myQueue::myQueue(int ss):Queue(ss)
{

}

void myQueue:: enqueue(int value)
{
    que.insertAtTail(value);
}

int myQueue:: dequeue()
{
    if(isEmpty())
    {
        cout << "Queue is Empty, returning ZERO" << endl;
		return 0;
    }
    que.deleteFromHead();
    //incase of delete from tail, there will be insert at head in enqueue function
}