#include<iostream>
#include<assert.h>
using namespace std;


///////////////// Stack Node //////////////////
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

////////////////// Stack implementation //////////////////
/////////////////////////////////////////////////////////
template <class T>
class linkedStack
{
private:
	Node<T>* top;
	int size;

public:
	linkedStack();
	bool isEmpty();
	void push(T val);
	T pop();
	T Top();
	void clear();
	~linkedStack();
};

template<class T>
linkedStack<T>::linkedStack()
{
	top = NULL;
	size = 0;
}

template<class T>
bool linkedStack<T>::isEmpty()
{
	return (size == 0);
}

template<class T>
void linkedStack<T>::push(T val)
{
	Node<T>* newNode = new Node<T>(val);
	newNode->next = top;
	top = newNode;
	size++;
}

template<class T>
T linkedStack<T>::pop()
{
	if (isEmpty())
	{
		cout << "Stack is Empty!" << endl; 
		return 0;
	}
	Node<T>* temp = top;
	top = top->next;
	T val = temp->data;
	delete temp;
	size--;
	return val;
}

template<class T>
T linkedStack<T>::Top()
{
	return T(top->data);
}

template<class T>
void linkedStack<T>::clear()
{
	while (!isEmpty())
		pop();
}

template<class T>
linkedStack<T>::~linkedStack()
{
	clear();
}

/////////////////// Main //////////////////
///////////////////////////////////////////
int main()
{
	linkedStack <int> s;
	s.push(5);
	s.push(8);
	s.pop();
	s.pop();
	if (s.isEmpty()) {
		cout << "The LinkedStack is now empty!\n";
		s.push(35);
	}
	cout << s.Top() << endl;

	return 0;
}