#include"myLinkedList.h"
//#include"myStack.h"
//#include"myQueue.h"

int main()
{
	myLinkedList<int> obj;
	while (1)
	{
		cout << "1. Add a value to the linked list" << endl;
		cout << "2. Delete duplicate values from the linked list " << endl;
		cout << "3. Display the linked list" << endl;
		cout << "4. Exit" << endl;
		cout << "Enter your choice : ";
		cin >> ch;
		if (ch == 1)
		{
			cout << "Enter a value to add to LL : ";
			cin >> num;
			cout << "Press 1 to insert at Head and 2 to insert at Tail!!: ";
			cin >> n;
			if (n == 1)
				obj.insertAtHead(num);
			else
				obj.insertAtTail(num);
		}
		else if (ch == 2)
		{
			obj.removeDuplicates();
		}
		else if (ch == 3)
		{
			obj.display();
		}
		else if (ch == 4)
		{
			exit(0);
		}
		cout << endl;
		cout << "Do you want to continue? (Y/N): ";
		cin >> c;
		if (c != 'Y' && c != 'y')
			break;
	}
	return 0;
}