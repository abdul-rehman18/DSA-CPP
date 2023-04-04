#include "MyArray.h"
#include <string>
int main()
{
	MyArray<int> two(4);
	cout << two.removeValue() << endl;
	two.addValue(235);
	two.addValue(10);
	two.addValue(-3);
	two.addValue(17);
	two.addValue(88);
	two.display();
	cout << endl;

	MyArray<char> three(3);
	three.addValue('A');
	three.addValue('z');
	three.display();

	cout << endl;
	MyArray<string> four(50);
	four.addValue("ucp");
	four.addValue("mohsin");
	four.addValue("abbas");
	four.display();

	return 0;
}


/*
	myArray one(5);
	one.addValue(235);
	one.addValue(10);
	one.addValue(-3);
	cout << one.removeValue() << endl;

	one.display();*/