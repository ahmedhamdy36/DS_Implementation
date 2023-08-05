#include<iostream>
#include<assert.h>
#include<vector>
using namespace std;

////////////////// Min-Heap implementation //////////////////
/////////////////////////////////////////////////////////
class minHeap
{
private:
	vector<int> heap;
	int size;
	int left(int pos);
	int right(int pos);
	int parent(int pos);
	void reHeapUp(int pos);
	void reHeapDown(int pos);

public:
	minHeap();
	int top();
	void push(int val);
	void pop();
	void print();
	int Heapsize();
};

minHeap::minHeap()
{
	size = 0;
}

int minHeap::left(int pos)
{
	int p = (2 * pos) + 1;

	if (p >= heap.size())
		return -1;
	else
		return p;
}

int minHeap::right(int pos)
{
	int p = (2 * pos) + 2;

	if (p >= heap.size())
		return -1;
	else
		return p;
}

int minHeap::parent(int pos)
{
	if (pos == 0)
		return -1;
	else
		return ((pos - 1) / 2);
}

void minHeap::reHeapUp(int pos)
{
	if (pos == 0 || heap[parent(pos)] < heap[pos])
		return;
	
	int temp = heap[pos];
	heap[pos] = heap[parent(pos)];
	heap[parent(pos)] = temp;

	reHeapUp(parent(pos));	
}

void minHeap::reHeapDown(int pos)
{
	int tempChild = left(pos);

	if (tempChild == -1)
		return;

	int rightChild = right(pos);

	if (rightChild != -1 && heap[rightChild] < heap[tempChild])
		tempChild = rightChild;

	if (heap[pos] > heap[tempChild])
	{
		int temp = heap[pos];
		heap[pos] = heap[tempChild];
		heap[tempChild] = temp;

		reHeapDown(tempChild);
	}
}

int minHeap::top()
{
	if (Heapsize() == 0)
		assert(false);
	return heap.front();
}

void minHeap::push(int val)
{
	heap.push_back(val);
	size++;
	reHeapUp((heap.size()) - 1);
}

void minHeap::pop()
{
	if (size != 0)
	{
		heap[0] = heap.back();
		heap.pop_back();
		reHeapDown(0);
	}
	size--;
}

void minHeap::print()
{
	for (int i = 0; i < Heapsize(); i++)
	{
		cout << heap[i] << ", ";
	}
}

int minHeap::Heapsize()
{
	return size;
}


int main()
{
	minHeap test;
	test.push(1);
	test.push(12);
	test.push(15);
	test.push(5);
	test.push(17);
	test.push(0);
	test.push(3);
	test.push(27);

	test.pop();

	cout << test.top() << endl;
	cout << test.Heapsize() << endl;

	test.print();

	return 0;
}