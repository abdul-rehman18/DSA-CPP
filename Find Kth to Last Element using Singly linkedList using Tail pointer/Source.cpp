#include "myLinkedList.h"

int main()
{
	int k = 0;
	myLinkedList obj;

	obj.insertAtHead(1);
	obj.insertAtHead(10);
	obj.insertAtHead(9);
	obj.insertAtHead(8);
	obj.insertAtHead(7);
	obj.insertAtHead(6);
	obj.insertAtHead(5);
	obj.insertAtHead(4);
	obj.insertAtHead(3);
	obj.insertAtHead(2);
	obj.insertAtHead(1);


	cout << " Display:" << endl;

	obj.display();

	cout << "Enter K: ";
	cin >> k;

	cout << obj.findkthToLast(k) << endl;
	return 0;
}