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

template<class T>
bool myQueue<T>::isEmpty()
{
    if(Queue<T>currentSize == 0)
        return true;
    return false;
}

template <class T>
void myQueue<T>::display()
{
	cout << "Maximum Size: " << Queue<T>::maxSize << endl;
	cout << "Current Size: " << Queue<T>::currentSize << endl;

	for (int i = 0; i < Queue<T>::currentSize; i++)
		cout << i << ". " << Queue<T>::arr[i] << endl;
}

template <class T>
myQueue<T>::myQueue(int ss):Queue<T>(ss)
{

}

template <class T>
void myQueue<T>:: enqueue(T value)
{
    if(!isFull())
    {
        Queue<T>::arr[Queue<T>::currentSize] = value;
        Queue<T>::currentSize++;
    }
    else
        cout<<"Queue is already Full!!"<<endl;
}

template <class T>
T myQueue<T>:: dequeue()
{
    if(isEmpty())
    {
        
    }
}