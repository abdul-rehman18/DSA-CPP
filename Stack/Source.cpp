#include "MyStack.h"
#include <string>
int main()
{
	myStack<int> two(4);
	cout << two.pop() << endl;
	two.push(235);
	two.push(10);
	two.push(-3);
	two.push(17);
	two.push(88);
	two.display();
	cout << endl;

	myStack<char> three(3);
	three.push('A');
	three.push('z');
	three.display();

	cout << endl;
	myStack<string> four(50);
	four.push("ucp");
	four.push("mohsin");
	four.push("abbas");
	four.display();

	return 0;
}


/*
	myStack one(5);
	one.push(235);
	one.push(10);
	one.push(-3);
	cout << one.pop() << endl;

	one.display();*/