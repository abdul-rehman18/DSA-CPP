#include "myQueue.h"
int main()
{
	myQueue<int> q(5);
	q.enqueue(88);
	q.enqueue(-3);
	q.enqueue(420);

	cout << "Dequeued Value: " << q.dequeue() << endl;

	q.display();
	

	return 0;
}

