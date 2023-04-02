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

template<class T>
bool myQueue<T>::isFull()
{
    if(Queue<T>::maxSize == Queue<T>currentSize)
        return true;
    return false;
}

