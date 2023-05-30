#include"LinkedList.h"

class myLinkedList :public LinkedList
{
protected:
	int count=0;
public:
	void insertAtTail(int);
	void insertAtHead(int);
	void insertSorted(int);
	void display();
	int deleteFromTail();
	int deleteFromHead();
	bool deleteValue(int);
	int findkthToLast(int);
};

void myLinkedList::insertAtTail(int value)
{
	Node* newNode;
	newNode = new Node;
	newNode->data = value;
	newNode->next = nullptr;

	if (tail == nullptr)
	{
		tail = newNode;
		tail->next = tail;
	}

	else
	{
		newNode->next = tail->next;
		tail->next = newNode;
		tail = newNode;
	}
}

void myLinkedList::insertAtHead(int value)
{
	Node* newNode;
	newNode = new Node;
	newNode->data = value;
	newNode->next = nullptr;

	if (tail == nullptr)
	{
		tail = newNode;
		tail->next = tail;
	}
	else
	{
		newNode->next = tail->next;
		tail->next = newNode;
	}
}

void myLinkedList::display()
{
	if (tail == nullptr)
		cout << "LL is empty" << endl;
	else
	{
		Node* temp = tail->next;
		while (1)
		{
			cout << temp->data << endl;
			temp = temp->next;
			if (temp == tail->next)
				break;
		}
	}

}

int myLinkedList::deleteFromTail()
{
	if (tail == nullptr)
	{
		cout << "LinkedList is empty...." << endl;
		return NULL;
	}
	else if (tail->next == tail)
	{
		int rv = tail->data;
		delete tail;
		tail = nullptr;
		return rv;
	}
	else
	{
		Node* temp = tail->next;
		while (1)
		{
			if (temp->next == tail)
				break;
			temp = temp->next;
		}
		int rv = tail->data;
		temp->next = tail->next;
		delete tail;
		tail = temp;
		return rv;
	}
}

int myLinkedList::deleteFromHead()
{
	if (tail == nullptr)
	{
		cout << "LinkedList is empty...." << endl;
		return NULL;
	}
	else if (tail->next == tail)
	{
		int rv = tail->data;
		delete tail;
		tail = nullptr;
		return rv;
	}
	else
	{
		int rv = tail->next->data;
		Node* temp = tail->next;
		tail->next = tail->next->next;
		delete temp;
		temp = nullptr;
		return rv;
	}
}

bool myLinkedList::deleteValue(int value)
{
	if (tail == nullptr)
	{
		cout << "LinkedList is empty...." << endl;
		return false;
	}
	else if (tail->next == tail)
	{
		if (value == tail->next->data)
		{
			delete tail;
			tail = nullptr;
			return true;
		}
		return false;
	}
	else
	{
		if (value == tail->next->data)
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
			Node* t1 = tail->next;
			while (1)
			{
				if (value == t1->next->data)
					break;
				else
					t1 = t1->next;
				if (t1 == tail)
					return false;
			}
			Node* t2 = t1->next;
			t1->next = t1->next->next;
			//or
			//t1->next = t2->next;
			delete t2;
			t2 = nullptr;
			return true;
		}
	}
}

void myLinkedList::insertSorted(int value)
{
	if (tail == nullptr)
	{
		Node* newNode;
		newNode = new Node;
		newNode->data = value;
		newNode->next = nullptr;
		tail = newNode;
		tail->next = tail;
	}
	else if (value <= tail->next->data)
		insertAtHead(value);

	else if (value >= tail->data)
		insertAtTail(value);
	else
	{
		Node* newNode;
		newNode = new Node;
		newNode->data = value;
		newNode->next = nullptr;
		Node* t1 = tail->next;
		while (1)
		{
			if (value > t1->data && value <= t1->next->data)
			{
				newNode->next = t1->next;
				t1->next = newNode;
				break;
			}
			else
				t1 = t1->next;
		}

	}
}

int myLinkedList::findkthToLast(int k)
{
	int count = 0;
	Node* temp = tail->next;
	while (1)
	{
		temp = temp->next;
		count++;
		if (temp == tail->next)
			break;
	}
	if (k >= count)
		return -1;
	else
	{
		Node* temp = tail->next;
		int nc = count - k;
		for (int i = 1; i < count; i++)
		{
			if (i == nc)
				return temp->data;
			temp = temp->next;
		}
	}
	
}