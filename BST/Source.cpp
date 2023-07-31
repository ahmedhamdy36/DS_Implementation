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
	Node<T>* right;
	Node<T>* left;

	Node(T);
};

template <class T>
Node<T>::Node(T value)
{
	data = value;
	right = NULL;
	left = NULL;
}


////////////////// BST implementation //////////////////
/////////////////////////////////////////////////////////
template <class T>
class BST
{
private:
	Node<T>* root;
	int size;

public:
	BST();
	void insert(T val);
	bool find(T val);
	int getLevel(T val);
	Node<T>* getRoot();
	void traverse(Node<T>* node);
	void deleteNode(T val);
};

template<class T>
BST<T>::BST()
{
	root = NULL;
	size = 0;
}

template<class T>
void BST<T>::insert(T val)
{
	if (root==NULL)
	{
		root = new Node<T>(val);
		size++;
		return;
	}

	Node<T>* temp = root;
	Node<T>* parentTemp = root;
	while (temp != NULL)
	{
		if (val > temp->data)
		{
			parentTemp = temp;
			temp = temp->right;
		}
		else if (val < temp->data)
		{
			parentTemp = temp;
			temp = temp->left;
		}
		else
		{
			cout << "This number already exists !" << endl;
			return;
		}
	}

	temp = new Node<T>(val);
	if (val > parentTemp->data)
		parentTemp->right = temp;
	else
		parentTemp->left = temp;

	size++;
}

template<class T>
bool BST<T>::find(T val)
{
	Node<T>* temp = root;
	while (temp != NULL)
	{
		if (val > temp->data)
			temp = temp->right;
		else if (val < temp->data)
			temp = temp->left;
		else
			return true;
	}
	return false;
}

template<class T>
int BST<T>::getLevel(T val)
{
	int count = 0;
	Node<T>* temp = root;
	while (temp != NULL)
	{
		if (val > temp->data)
			temp = temp->right;
		else if (val < temp->data)
			temp = temp->left;
		else
			return count;
		count++;
	}
	cout << "Not found!";
	return -1;
}

template<class T>
Node<T>* BST<T>::getRoot()
{
	return root;
}

//In-order traversal
template<class T>
void BST<T>::traverse(Node<T>* node)
{
	if (node == NULL)
		return;

	traverse(node->left);
	cout << node->data << ", ";

	traverse(node->right);
}

template<class T>
void BST<T>::deleteNode(T val)
{
	if (root == NULL)
	{
		cout << "Tree is Empty!" << endl;
		return;
	}

	Node<T>* temp = root;
	Node<T>* parentTemp = NULL;
	bool found = false;
	bool direction = false; // false -> left , true -> right
	while (temp != NULL)
	{
		if (val > temp->data)
		{
			parentTemp = temp;
			temp = temp->right;
			direction = true;
		}
		else if (val < temp->data)
		{
			parentTemp = temp;
			temp = temp->left;
			direction = false;
		}
		else
		{
			found = true;
			break;
		}
	}

	if (found)
	{
		if (temp->left == NULL && temp->right == NULL)
		{
			if (direction)
				parentTemp->right = NULL;
			else
				parentTemp->left = NULL;
			delete temp;
		}
		else if (temp->left != NULL && temp->right == NULL)
		{
			parentTemp->left = temp->left;
			delete temp;
		}
		else if (temp->left == NULL && temp->right != NULL)
		{
			parentTemp->right = temp->right;
			delete temp;
		}
		else
		{
			//if the node has 2 subtree we will replace it with the minimum value in the right subtree.
			return;
		}

		size--;
	}
	else
	{
		cout << "This value not found!" << endl;
	}
}


/////////////////// Main //////////////////
///////////////////////////////////////////
int main()
{
	BST<int> test;
	test.insert(20);
	test.insert(30);
	test.insert(10);
	test.insert(5);
	test.insert(15);
	test.insert(25);
	test.insert(35);
	test.insert(3);
	test.insert(17);

	test.deleteNode(20);

	cout << test.find(2) << endl;
	cout << test.find(10) << endl;

	cout << test.getLevel(20) << endl;
	cout << test.getLevel(10) << endl;
	cout << test.getLevel(15) << endl;
	cout << test.getLevel(2) << endl;
	cout << test.getLevel(40) << endl;

	test.traverse(test.getRoot());

	return 0;
}