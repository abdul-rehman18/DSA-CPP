#include "Stack.h"
#include<string>

template <class T>
class myStack :public Stack<T>
{
public:
	void push(T);
	T pop();
	T top();
	myStack(int ss);
	bool isEmpty();
	bool isFull();
	int check_pre(char);
	void post(char*);
	void display();
};

template <class T>
bool myStack<T>::isFull()
{
	if (Stack<T>::maxSize == Stack<T>::currentSize)
		return true;

	return false;
}

template <class T>
bool myStack<T>::isEmpty()
{
	if (Stack<T>::currentSize == 0)
		return true;

	return false;
}

template <class T>
void myStack<T>::display()
{
	for (int i = 0; i < Stack<T>::currentSize; i++)
		cout << i << ". " << Stack<T>::arr[i] << endl;
}


template <class T>
myStack<T>::myStack(int ss):Stack<T>(ss)
{

}

template <class T>
void myStack<T>::push(T value)
{
	if (!isFull())
	{
		Stack<T>::arr[Stack<T>::currentSize] = value;
		Stack<T>::currentSize++;
	}

	else
		cout << "Stack is already FULL" << endl;
}


template <class T>
T myStack<T>::pop()
{
	if (isEmpty())
	{
		cout << "Stack is Empty, returning ZERO" << endl;
		return 0;
	}

	Stack<T>::currentSize--;
	return Stack<T>::arr[Stack<T>::currentSize];
}


template <class T>
T myStack<T>::top()
{
	if (isEmpty())
	{
		cout << "Stack is Empty, returning ZERO" << endl;
		return 0;
	}

	return Stack<T>::arr[Stack<T>::currentSize-1];
}

template<class T>
int myStack<T>::check_pre(char op)
{
	if (op == '/' || op == '*')
	{
		return 1;
	}
	else if (op == '+' || op == '-')
	{
		return 2;
	}
	else
		return 0;
}

template <class T>
void myStack<T>::post(char* value)
{
	//Wrote this code on VS Code that's why add std:: before string
	std::string n;
	cout<<"Expression to Evaluate is : "<<endl;
	for(int i=0;value[i]!='\0';i++)
	{
		cout<<value[i];
	}
	cout<<endl;
	for(int i=0;value[i]!='\0';i++)
	{
		if ((value[i]>='0'&&value[i]<='9')||(value[i]>='a'&&value[i]<='z')||(value[i]>='A'&&value[i]<='Z'))
		{
			n += value[i];
			//push(value[i]);
			
		}
		else if(value[i]=='(')
			push(value[i]);
		else if (value[i] == ')')
		{ 
			n += ' ';
			while (!isEmpty() && top() != '(')
			{
				n += top();
				pop();
			}
			if (!isEmpty())
			{
				pop();
			}
		}
		else if (value[i] == '+' || value[i] == '-' || value[i] == '*' || value[i] == '/' )
		{
			n += ' ';
			while (!isEmpty() && check_pre(top()) > check_pre(value[i]))
			{
				// cout<<top()<<endl;
				n += top();
				pop();
			}
			//if(value[i]!=' ')
			push(value[i]);
		}
		
	}
	while (!isEmpty())
	{
		n += ' ';
		n += top();
		pop();
	}
	cout<<endl;
	cout << "Result: " << n << endl;
	
}