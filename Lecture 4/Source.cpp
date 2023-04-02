#include "myQueue.h"
int main()
{
	myQueue<int> q(5);
	
	q.enqueue(88);
	q.enqueue(-3);
	q.enqueue(42);
	q.enqueue(10);
	q.enqueue(99);
	cout << "Dequeue = " << q.dequeue() << endl;
	q.enqueue(77);
	cout << "Dequeue = " << q.dequeue() << endl;
	cout << "Dequeue = " << q.dequeue() << endl;
	cout << "Dequeue = " << q.dequeue() << endl;
	cout << "Dequeue = " << q.dequeue() << endl;
	cout << "Dequeue = " << q.dequeue() << endl;
	q.enqueue(-85);

	cout << "Pyara sa endl" << endl;

	q.display();

	return 0;
}

