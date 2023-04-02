#include "Queue.h"

template <class T>
class myQueue :public Queue<T>
{
public:
	void enqueue(T);
	T dequeue();
	myQueue(int ss);
	bool isEmpty();
	bool isFull();
	void display();
};