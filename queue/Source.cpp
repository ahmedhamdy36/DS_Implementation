#include<iostream>
#include<assert.h>
using namespace std;

///////////////// Queue implementation //////////////////
/////////////////////////////////////////////////////////
template<class T>
class MyQueue
{
private:
	int elements;
	int capacity;
	int front;
	int back;
	T* Arr;

public:
	MyQueue(int sizeOfQ);
	void Enqueue(T val);
	void Dequeue();
	bool isFull();
	bool isEmpty();
	T Front();
	~MyQueue();
};

template<class T>
MyQueue<T>::MyQueue(int sizeOfQ)
{
	elements = 0;
	capacity = sizeOfQ;
	front = back = -1;
	Arr = new T[capacity];
}

template<class T>
void MyQueue<T>::Enqueue(T val)
{
	assert(!isFull());
	if (elements == 0)
		front++;

	back = (back + 1) % capacity;
	Arr[back] = val;
	elements++;
}

template<class T>
void MyQueue<T>::Dequeue()
{
	assert(!isEmpty());
	if (elements == 1)
		front = back = -1;
	else
		front = (front + 1) % capacity;
	elements--;
}

template<class T>
bool MyQueue<T>::isFull()
{
	return ((elements == capacity) != 0);
}

template<class T>
bool MyQueue<T>::isEmpty()
{
	return (front == -1);
}

template<class T>
T MyQueue<T>::Front()
{
	assert(!isEmpty());
	return T(Arr[front]);
}

template<class T>
MyQueue<T>::~MyQueue()
{
	delete [] Arr;
}

/////////////////// Main //////////////////
///////////////////////////////////////////
int main()
{
	MyQueue<int> test(3);

	cout << test.isEmpty() << endl;

	test.Enqueue(1);
	test.Enqueue(2);
	test.Enqueue(3);

	cout << test.isFull() << endl;

	test.Dequeue();
	cout << test.Front() << endl;
}