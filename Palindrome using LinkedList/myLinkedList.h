#include"LinkedList.h"

template<class T>
class myLinkedList :public Linkedlist<T>
{
public:
	bool isEmpty();
	void insertAtTail(T);
	void insertAtHead(T);
	void insertSorted(T);
	void display();
	bool deleteFromTail();
	bool deleteFromHead();
	bool deleteValue(T);
	bool search(T);
	void palindrome();
};

template <class T>
bool myLinkedList<T>::isEmpty()
{
	if (head == nullptr && tail == nullptr)
		return true;
	return false;
}

template<class T>
void myLinkedList<T>::insertAtHead(T value)
{
	Node<T>* newNode = new Node<T>;
	newNode->data = value;
	newNode->next = nullptr;
	if (head == nullptr&& tail == nullptr)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		newNode->next = head;
		head = newNode;
	}
}

template<class T>
void myLinkedList<T>::insertAtTail(T value)
{
	Node<T>* newNode = new Node<T>;
	newNode->data = value;
	newNode->next = nullptr;
	if (head == nullptr && tail == nullptr)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->next = newNode;
		tail = newNode;
	}
}

template<class T>
void myLinkedList<T>::insertSorted(T value)
{
	if (head == nullptr&&tail == nullptr)
	{
		Node<T>* newNode = new Node<T>;
		newNode->data = value;
		newNode->next = nullptr;
		head = newNode;
		tail = newNode;
	}
	else if (value <= head->data)
		insertAtHead(value);
	else if (value >= tail->data)
		insertAtTail(value);
	else
	{
		Node<T>* newNode = new Node<T>;
		newNode->data = value;
		newNode->next = nullptr;
		Node<T>* t1 = head;
		if (value > t1->data && value <= t1->data)
		{
			newNode->next = t1->next;
			t1->next = newNode;
		}
		else
			t1 = t1->next;
	}
}

template<class T>
void myLinkedList<T>::display()
{
	Node<T>*temp = head;
	while (1)
	{
		if (temp == nullptr)
			break;
		cout << temp->data << endl;
		temp = temp->next;
	}
}

template<class T>
bool myLinkedList<T>::deleteFromHead()
{
	if (head == nullptr && tail == nullptr)
	{
		cout << "LL is empty!!" << endl;
		return NULL;
	}
	else if (head == tail)
	{
		//T rv = head->data;
		delete head;
		head = nullptr;
		tail = nullptr;
		return true;
	}
	else
	{
		//int rv = head->data;
		Node<T>* temp = head;
		head = head->next;
		delete temp;
		temp = nullptr;
		return true;
	}
}

template<class T>
bool myLinkedList<T>::deleteFromTail()
{
	if (head == nullptr&&tail == nullptr)
	{
		cout << "LL is empty!!" << endl;
		return NULL;
	}
	else if (head == tail)
	{
		//int rv = head->data;
		delete tail;
		head = nullptr;
		tail = nullptr;
		return true;
	}
	else
	{
		Node<T>* temp = head;
		while (1)
		{
			if (temp->next == tail)
				break;
			temp = temp->next;
		}
		//int rv = tail->data;
		delete tail;
		tail = temp;
		tail->next = nullptr;
		return true;
	}
}

template<class T>
bool myLinkedList<T>::deleteValue(T value)
{
	if (head == nullptr&&tail == nullptr)
	{
		cout << "LL is empty!!" << endl;
		return false;
	}
	else if (head == tail)
	{
		if (value == head->data)
		{
			delete head;
			head = nullptr;
			tail = nullptr;
			return true;
		}
		return false;
	}
	else
	{
		if (value == head->data)
		{
			deleteFromHead();
			return true;
		}
		else if (value == tail->data)
		{
			deleteFromTail();
			return true;
		}
		else
		{
			Node<T>* t1 = head;
			while (1)
			{
				if (value == t1->next->data)
					break;
				t1 = t1->next;
				if (t1 == tail)
				{
					cout << "No such value!!" << endl;
					return false;
				}
			}
			Node<T>* t2 = t1->next;
			t1->next = t2->next;
			delete t2;
			t2 = nullptr;
			return true;
		}
	}
}

template<class T>
bool myLinkedList<T>::search(T value)
{
	if (head == nullptr && tail == nullptr)
	{
		cout << "LL is empty!!" << endl;
		return false;
	}
	else if (head == tail)
	{
		if (value == head->data)
			return true;
		return false;
	}
	else
	{
		Node<T>* t1 = head;
		while (1)
		{
			if (value == t1->next->data)
				return true;
			t1 = t1->next;
			if (t1 == tail)
			{
				cout << "No such value" << endl;
				return false;
			}
		}
	}
}

template<class T>
void myLinkedList<T>::palindrome()
{
	
	if (head == nullptr && tail == nullptr)
	{
		cout << "LL is empty!!" << endl;
	}
	else
	{
		int a = 0;
		Node<T>* t1 = head;
		Node<T>* t2 =t1;
		while (1)
		{
			a = 0;
			T temp = t1->data;
			for (int i = 0; i < temp.length() / 2 ; i++)
			{
				if (temp[i] == temp[temp.length() - i - 1])
					a++;
			}
			if (a == temp.length() / 2)
			{
				cout << "It is a palindrome" << endl;
				t2 = t1;
			}
			else
			{
				deleteValue(temp);
				// t2->next = t1->next;
				// delete t1;
				// t1 = t2 ;
				// cout << "It is not a palindrome" << endl;
			}
			t1 = t1->next;
			if (t1 == nullptr)
			{
				break;
			}
		}
	}
}