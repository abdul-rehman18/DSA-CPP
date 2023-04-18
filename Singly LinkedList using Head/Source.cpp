#include "myLinkedList.h"

int main()
{
	myLinkedList obj;

	obj.insertAtHead(50);
	obj.insertAtHead(2);
	obj.insertAtHead(0);
	obj.insertAtTail(787);
	obj.insertAtTail(-2);

	cout << "Delete From Tail: " << obj.deleteFromTail() << endl;

	obj.insertSorted(1462);

	cout << obj.deleteValue(1462) << endl << " Display:" << endl;

	obj.display();
	return 0;
}