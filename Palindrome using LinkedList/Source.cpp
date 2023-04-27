#include"myLinkedList.h"


int main()
{
	myLinkedList<string> obj;
	obj.insertSorted("ABBA");
	obj.insertSorted("BCCB");
	obj.insertSorted("CDS");
	obj.insertSorted("DAA");
	obj.insertSorted("EES");
	obj.display();

	cout << endl;
	obj.palindrome();
	obj.display();
	return 0;
}