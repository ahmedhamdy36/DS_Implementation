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
	Node<T>* prev;

	Node();
	Node(T value);
};

template <class T>
Node<T>::Node()
{
	data = 0;
	next = NULL;
	prev = NULL;
}

template <class T>
Node<T>::Node(T value)
{
	data = value;
	next = NULL;
	prev = NULL;
}

////////////////// List implementation //////////////////
/////////////////////////////////////////////////////////
template <class T>
class d_linkedList
{
private:
	Node<T>* head;
	Node<T>* tail;
	int size;

public:
	d_linkedList();
	int Length();
	T listHead();
	T listTail();
	T At(int pos);
	void append(T val);
	void deletAt(int pos);
	void insert(T val, int pos);
	void clear();
	bool empty();
};

template<class T>
d_linkedList<T>::d_linkedList()
{
	head = tail = NULL;
	size = 0;
}

template<class T>
int d_linkedList<T>::Length()
{
	return size;
}

template<class T>
T d_linkedList<T>::listHead()
{
	if (size == 0)
	{
		cout << "list is empty" << endl;
		return NULL;
	}
	else
		return T(head->data);
}

template<class T>
T d_linkedList<T>::listTail()
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
T d_linkedList<T>::At(int pos)
{
	assert(pos < size);

	if (pos >= (size / 2))
	{
		Node<T>* temp = tail;

		int counter = size;
		while (counter > pos + 1)
		{
			temp = temp->prev;
			counter--;
		}

		return (temp->data);
	}
	else
	{
		Node<T>* temp = head;

		int counter = 0;
		while (counter < pos)
		{
			temp = temp->next;
			counter++;
		}

		return (temp->data);
	}
}

template<class T>
void d_linkedList<T>::append(T val)
{
	Node<T>* temp = new Node<T>(val);

	if (size == 0)
		head = tail = temp;
	else
	{
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}
	size++;
}

template<class T>
void d_linkedList<T>::deletAt(int pos)
{
	assert(pos < size);

	if (pos >= (size / 2))
	{
		Node<T>* deletedNode = tail;
		if (pos == size - 1)
		{
			deletedNode->prev->next = NULL;
			tail = deletedNode->prev;
		}
		else
		{
			int counter = size;
			while (counter > pos + 1)
			{
				deletedNode = deletedNode->prev;
				counter--;
			}

			deletedNode->prev->next = deletedNode->next;
			deletedNode->next->prev = deletedNode->prev;
		}
		delete deletedNode;
	}
	else
	{
		Node<T>* deletedNode = head;
		if (pos == 0)
		{
			head = head->next;
			head->prev = NULL;
		}
		else
		{
			int counter = 0;
			while (counter < pos)
			{
				deletedNode = deletedNode->next;
				counter++;
			}

			deletedNode->next->prev = deletedNode->prev;
			deletedNode->prev->next = deletedNode->next;
		}
		delete deletedNode;
	}

	size--;
}

template<class T>
void d_linkedList<T>::insert(T val, int pos)
{
	assert(pos < size + 1);
	Node<T>* newNode = new Node<T>(val);

	if (pos > size / 2)
	{
		Node<T>* temp = tail;
		if (pos == size)
		{
			append(val);
			delete newNode;
		}
		else
		{
			int counter = size;
			while (counter > pos + 1)
			{
				temp = temp->prev;
				counter--;
			}


			newNode->prev = temp->prev;
			temp->prev->next = newNode;
			newNode->next = temp;
			temp->prev = newNode;
		}
	}
	else
	{
		Node<T>* temp = head;
		if (pos == 0)
		{
			if (size == 0)
				append(val);
			else
			{
				temp->prev = newNode;
				newNode->next = temp;
				head = newNode;
			}
		}
		else
		{
			int counter = 0;
			while (counter < pos - 1)
			{
				temp = temp->next;
				counter++;
			}

			newNode->next = temp->next;
			temp->next->prev = newNode;
			newNode->prev = temp;
			temp->next = newNode;
		}
	}
	
	size++;
}

template<class T>
void d_linkedList<T>::clear()
{
	while (size > 0)
		deletAt(0);
}

template<class T>
bool d_linkedList<T>::empty()
{
	return (size == 0);
}

////////////////// Main  //////////////////
///////////////////////////////////////////
int main()
{
	d_linkedList<int> test;
	test.append(1);
	test.append(2);
	test.append(3);
	test.append(4);
	test.append(5);

	//test.deletAt(2);
	
	test.insert(9,3);

	int counter = 0;
	while (counter < test.Length())
	{
		cout << test.At(counter) << endl;
		counter++;
	}

	return 0;
}