#include<iostream>
#include<assert.h>
using namespace std;

///////////////// Stack implementation //////////////////
/////////////////////////////////////////////////////////
template<class T>
class MyStack
{
private:
	int capacity;
	int elements;
	T* arr;
public:
	MyStack(int sizeOfStack);
	void push(T val);
	T pop();
	void expand();
	bool isEmpty();
	~MyStack();
};

template<class T>
MyStack<T>::MyStack(int sizeOfStack)
{
	elements = 0;
	capacity = sizeOfStack;
	arr = new T[capacity];
}

template<class T>
void MyStack<T>::push(T val)
{
	if (capacity == elements)
		expand();
	arr[elements] = val;
	elements++;
}

template<class T>
T MyStack<T>::pop()
{
	assert(!isEmpty());
	elements--;
	return T(arr[elements]);
}

template<class T>
void MyStack<T>::expand()
{
	T* newArr = new T[capacity * 2];
	for (int i = 0; i < capacity; i++)
		newArr[i] = arr[i];
	
	capacity *= 2;
	delete[] arr;
	arr = newArr;
}

template<class T>
bool MyStack<T>::isEmpty()
{
	return (elements == 0);
}

template<class T>
MyStack<T>::~MyStack()
{
	delete[] arr;
}


/////////////////// Main //////////////////
///////////////////////////////////////////
int main()
{
	MyStack<int> test(3);

	cout << test.isEmpty() << endl;

	test.push(1);
	test.push(2);
	test.push(3);
	test.push(4);
	test.push(5);
	test.push(6);
	cout << test.isEmpty() << endl;

	cout << test.pop()<<endl;;
}