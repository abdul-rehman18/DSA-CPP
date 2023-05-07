#include "myLinkedList.h"

int main()
{
    int val;
	myLinkedList obj;

	obj.insertAtHead(50);
	obj.insertAtHead(2);
	obj.insertAtHead(0);
	obj.insertAtTail(7);
	obj.insertAtTail(-2);

	//cout << "Delete From Tail: " << obj.deleteFromTail() << endl;

	obj.insertSorted(1462);

	//cout << obj.deleteValue(1462) << endl;
	
	cout << "Original List: "<<endl;

	obj.display();
	
	cout << "Enter a value for deletion : ";
    cin >> val;
	
    cout << "List after deleting nodes greater than "<<val <<": "<<endl;
    
    obj.deleteNode(val);
    
    obj.display();
    
    cout << endl;
    
    
	return 0;
}