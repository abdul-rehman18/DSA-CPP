#include"LinkedList.h"


template<class T>
class myLinkedList :public Linkedlist<T>
{
public:
	bool isEmpty();
	void insertAtTail(T);
	void insertAtHead(T);
	void deletebyID(int);
	T deleteFromHead();
	void display();
	//void insertSorted(T,bool);
	void sortbyID();
	void sortbyName();
};

template <class T>
bool myLinkedList<T>::isEmpty()
{
	if (head == nullptr)
		return true;
	return false;
}

template<class T>
void myLinkedList<T>::insertAtHead(T value)
{
	Node<T>* newNode = new Node<T>;
	newNode->data.ID = value.ID;
	newNode->data.name = value.name;
	//newNode->ID = value.ID;
	//newNode->name = value.name;
	newNode->next = nullptr;
	if (head == nullptr)
	{
		head = newNode;
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
	newNode->data.ID = value.ID;
	newNode->data.name = value.name;
	//newNode->ID = value.ID;
	//newNode->name = value.name;
	newNode->next = nullptr;
	if (head == nullptr)
	{
		head = newNode;
	}
	else
	{
		Node<T>* t = head;
		while (1)
		{
			if (t->next == nullptr)
				break;
			t = t->next;
		}
		t->next = newNode;
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
		cout << temp->data.ID << endl;
		cout << temp->data.name << endl;
		temp = temp->next;
	}
}

/*template<class T>
void myLinkedList<T>::insertSorted(T value,bool flag)
{
	if (head == nullptr)
	{
		insertAtHead(value);
	}
	else if (value.ID <= head->data.ID&& flag)
		insertAtHead(value);
	else if (value.name <= head->data.name&& !flag)
		insertAtHead(value);
	else
	{
		Node<T>* newNode = new Node<T>;
		newNode->data.ID = value.ID;
		newNode->data.name = value.name;
		//newNode->ID = value.ID;
		//newNode->name = value.name;
		newNode->next = nullptr;
		Node<T>* t1 = head;
		while (1)
		{
			if (value.ID > t1->data.ID &&value.ID <= t1->next->data.ID && flag)
			{
				newNode->next = t1->next;
				t1->next = newNode;
				break;
			}
			if (value.name > t1->data.name &&value.name <= t1->next->data.name && !flag)
			{
				newNode->next = t1->next;
				t1->next = newNode;
				break;
			}
			else
				t1 = t1->next;
			if (t1->next == nullptr)
			{
				t1->next = newNode;
				break;
			}
		}
		//cout << "Data Sorted by ID" << endl;
	}
}
*/
template<class T>
T myLinkedList<T>::deleteFromHead()
{
	if (head == nullptr )
	{
		T r;
		cout << "LL is empty!!" << endl;
		return r;
	}
	else if (head->next == nullptr )
	{
		T r;
		r.ID = head->data.ID;
		r.name = head->data.name;
		delete head;
		head = nullptr;
		return r;
	}
	else
	{
		T r;
		r.ID = head->data.ID;
		r.name = head->data.name;
		Node<T>* temp = head;
		head = head->next;
		delete temp;
		temp = nullptr;
		return r;
	}
}

template<class T>
void myLinkedList<T>::deletebyID(int value)
{
	if (head == nullptr)
	{
		cout << "LL is empty!!" << endl;
	}
	else if (head->next == nullptr)
	{
		if (head->data.ID == value)
		{
			delete head;
			head = nullptr;
			cout << "Value Found and deleted!!" << endl;
		}
		else
		{
			cout << "Value Doesnot exist" << endl;
		}
	}
	else
	{
		Node<T>* temp = head;
		while (1)
		{
			if (value == temp->next->data.ID)
				break;
			else
				temp = temp->next;
			if (temp == nullptr)
				cout << "Value not Found" << endl;
		}
		Node<T>* t1 = temp->next;
		temp->next = t1->next;
		delete t1;
		t1 = nullptr;
		cout << "Value Found and deleted!!" << endl;
	}
}

template<class T>
void myLinkedList<T>::sortbyID()
{
	if (head == nullptr)
		return;
	while (1)
	{
		Node<T>* t1 = head;
		while (t1->next != nullptr)
		{
			if (t1->data.ID > t1->next->data.ID)
			{
				T temp = t1->data;
				t1->data = t1->next->data;
				t1->next->data = temp;
			}
			t1 = t1->next;
		}
		
		if (t1->next == nullptr)
			break;
	}
}

template<class T>
void myLinkedList<T>::sortbyName()
{
	if (head == nullptr)
		return;
	while (1)
	{
		Node<T>* t1 = head;
		while (t1->next != nullptr)
		{
			if (t1->data.name > t1->next->data.name)
			{
				T temp = t1->data;
				t1->data = t1->next->data;
				t1->next->data = temp;
			}
			t1 = t1->next;
		}
		
		if (t1->next == nullptr)
			break;
	}
}


