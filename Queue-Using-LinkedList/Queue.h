#include <iostream>
using namespace std;

class Queue
{
protected:
	int* arr;
	int maxSize;
	int currentSize;
public:
	virtual void enqueue(int) = 0;
	virtual int dequeue() = 0;
	virtual bool isEmpty() = 0;
	Queue(int);
};

Queue::Queue(int s)
{
	arr = new T[s];
	maxSize = s;
	currentSize = 0;
}