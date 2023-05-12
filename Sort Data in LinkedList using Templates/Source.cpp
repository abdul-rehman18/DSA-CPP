#include"myLinkedList.h"
#include<string>

int main()
{
	cout << "----------------------------Welcome--------------------------" << endl;
	int ch, id = 0, n = 0;
	string nm;
	char c;
	myLinkedList<Record> obj;
	while (1)
	{
		cout << "1. Add a new data record to the linked list" << endl;
		cout << "2. Delete a data record from the linked list by ID " << endl;
		cout << "3. Sort the linked list by ID" << endl;
		cout << "4. Sort the linked list by name" << endl;
		cout << "5. Display the linked list" << endl;
		cout << "6. Exit" << endl;
		cout << "Enter your choice : ";
		cin >> ch;
		if (ch == 1)
		{
			cout << "Enter a new data record to add to LL : " << endl;
			cout << "Enter ID : ";
			cin >> id;
			cout << "Enter Name : ";
			cin >> nm;
			Record r(id, nm);
			cout << "Press 1 to insert at Head and 2 to insert at Tail!!: ";
			cin >> n;
			if (n == 1)
				obj.insertAtHead(r);
			else
				obj.insertAtTail(r);
		}
		else if (ch == 2)
		{
			cout << "Enter an ID to delete : ";
			cin >> id;
			obj.deletebyID(id);
		}
		else if (ch == 3)
		{
			obj.sortbyID();
		}
		else if (ch == 4)
		{
			obj.sortbyName();
		}
		else if (ch == 5)
		{
			obj.display();
		}
		else if (ch == 6)
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