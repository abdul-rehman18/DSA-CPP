#include "Queue.h"

template <class T>
class myQueue :public Queue<T>
{
    int rear;
	int front;
public:
	void enqueue(T);
	T dequeue();
	myQueue(int ss);
	bool isEmpty();
	bool isFull();
	void display();
};

template <class T>
bool myQueue<T>::isFull() 
{
	if (Queue<T>::maxSize == Queue<T>::currentSize)
		return true;

	return false;
}

template<class T>
bool myQueue<T>::isEmpty()
{
    if(Queue<T>::currentSize == 0)
        return true;
    return false;
}

template <class T>
void myQueue<T>::display()
{
	cout << "Maximum Size: " << Queue<T>::maxSize << endl;
	cout << "Current Size: " << Queue<T>::currentSize << endl;
    cout << "Front: " << front << endl;
    cout << "Rear: " << rear << endl;


	for (int i = front; i < rear; i++)
		cout << i%Queue<T>::maxSize << ". " << Queue<T>::arr[i] << endl;
}

template <class T>
myQueue<T>::myQueue(int ss):Queue<T>(ss)
{

}

