#include "MyStack.h"
int main()
{
	myStack two(4);
	cout << two.pop() << endl;
	two.push(235);
	two.push(10);
	two.push(-3);
	two.push(17);
	two.push(88);
	two.display();
	cout << endl;

	return 0;
}