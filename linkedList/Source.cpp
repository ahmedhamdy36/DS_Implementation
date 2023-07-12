#include<iostream>
#include<assert.h>
using namespace std;


////////////////// List Node //////////////////
///////////////////////////////////////////////
template <class T>
class Node
{
public:
	T data;
	Node<T>* next;

	Node();
	Node(T value);
};

template <class T>
Node<T>::Node()
{
	data = 0;
	next = NULL;
}

template <class T>
Node<T>::Node(T value)
{
	data = value;
	next = NULL;
}


////////////////// List implementation //////////////////
/////////////////////////////////////////////////////////
template <class T>
class linkedList
{
private:
	Node<T>* head;
	Node<T>* tail;
	int size;

public:
	linkedList();
	int Length();
	T listHead();
	T listTail();
	T At(int pos);
	void append(T val);
	void deletAt(int pos);
	void insert(T val, int pos);
};

template <class T>
linkedList<T>::linkedList()
{
	head = tail = NULL;
	size = 0;
}

template<class T>
int linkedList<T>::Length()
{
	return size;
}

template<class T>
T linkedList<T>::listHead()
{
	if (size==0)
	{
		cout << "list is empty" << endl;
		return NULL;
	}
	else
		return T(head->data);
}

template<class T>
T linkedList<T>::listTail()
{
	if (size == 0)
	{
		cout << "list is empty" << endl;
		return NULL;
	}
	else
		return (tail->data);
}

template<class T>
T linkedList<T>::At(int pos)
{
	assert(pos < size);
	Node<T> temp = head;

	int counter = 0;
	while (counter < pos)
	{
		temp = temp->next;
		counter++;
	}

	return (temp->data);
}

template<class T>
void linkedList<T>::append(T val)
{
	Node<T>* temp = new Node<T>(val);

	if (size==0)
		head = tail = temp;
	else
	{
		tail->next = temp;
		tail = temp;
	}
	size++;
}

template<class T>
void linkedList<T>::deletAt(int pos)
{
	assert(pos < size);
	Node<T>* temp = head;
	int counter = 0;

	if (pos == 0)
	{
		head = head->next;
		delete temp;
	}
	else
	{
		while (counter < pos - 1)
		{
			temp = temp->next;
			counter++;
		}

		Node<T>* deletedNode = temp->next;
		if (deletedNode->next == NULL)
			tail = tmp;
		else
			temp->next = deletedNode->next;
		delete deletedNode;
	}

	size--;
}

template<class T>
void linkedList<T>::insert(T val, int pos)
{
	assert(pos < size);
	Node<T>* newNode = new Node<T>(val);
	Node<T>* temp = head;
	int counter = 0;

	if (pos == 0)
	{
		newNode->next = head;
		head = newNode;
		delete temp;
	}
	else
	{
		while (counter < pos - 1)
		{
			temp = temp->next;
			counter++;
		}

		if (temp->next == NULL)
		{
			temp->next = newNode;
			tail = newNode;
		}
		else 
		{
			newNode->next = temp->next;
			temp->next = newNode;
		}
	}

	size++;
}


////////////////// Main  //////////////////
///////////////////////////////////////////
int main()
{
	linkedList<int> test;
	test.append(1);
	test.append(2);
	test.append(3);
	cout << "list size = " << test.Length() << endl;
	cout << "head of list = " << test.listHead() << endl;
	cout << "tial of list = " << test.listTail() << endl;

	return 0;
}