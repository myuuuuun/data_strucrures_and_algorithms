/*
Linked list library

2018 @myuuuuun

To do: write methods of the BiDirectionalLinkedList class
*/

#include <iostream>
#include "LinkedList.hpp"


/*
(Single Directional) Linked List
*/

template <typename T>
LinkedList<T>::LinkedList()
{
	LinkedListNode<T> *new_node;

	// head_node node
	new_node = new LinkedListNode<T>;
	new_node->next = NULL;
	head_node = new_node;

	size = 0;
};


template <typename T>
LinkedList<T>::LinkedList(int inital_size, const T values[])
{
	LinkedListNode<T> *node;
	
	size = inital_size;

	// head node
	head_node = new LinkedListNode<T>;
	node = head_node;

	for (int i=0; i<size; ++i)
	{
		node->next = new LinkedListNode<T>;
		node->next->value = values[i];
		node = node->next;
	}

	// last node
	node->next = NULL;
};


template <typename T>
LinkedList<T>::~LinkedList()
{
	clear();
	delete head_node;
};


// clear all nodes except head_node
template <typename T>
void LinkedList<T>::clear()
{
	LinkedListNode<T> *node;
	LinkedListNode<T> *next;

	node = head_node->next;
	while (node) 
	{
		next = node->next;
		delete node;
		node = next;
	};

	size = 0;
	head_node->next = NULL;
};


template <typename T>
T LinkedList<T>::head()
{
	return get(0);
};


template <typename T>
T LinkedList<T>::get(int index)
{
	LinkedListNode<T> *node;

	if (index < 0 || index >= size) {
		throw std::invalid_argument("`index` must be 0 <= index < size");
	};

	int i = 0;
	for (node=head_node; node; node=node->next) 
	{
		if (i == index) 
		{
			break;
		};

		++i;
	};

	return node->next->value;
};


template <typename T>
void LinkedList<T>::set(int index, T value)
{
	LinkedListNode<T> *node;

	if (index < 0 || index >= size) {
		throw std::invalid_argument("`index` must be 0 <= index < size");
	};

	int i = 0;
	for (node=head_node; node; node=node->next) 
	{
		if (i == index) 
		{
			node->next->value = value;
			break;
		};

		++i;
	};
};


template <typename T>
void LinkedList<T>::append(T v)
{
	insert(size, v);
};


template <typename T>
void LinkedList<T>::insert(T v)
{
	insert(size, v);
};


template <typename T>
void LinkedList<T>::insert(int index, T v)
{
	LinkedListNode<T> *node;
	LinkedListNode<T> *new_node;

	if (index < 0 || index > size) {
		throw std::invalid_argument("`index` must be 0 <= index <= size");
	}

	// new node
	new_node = new LinkedListNode<T>;
	new_node->value = v;

	int i = 0;
	for (node=head_node; node; node=node->next) 
	{
		if (i == index) 
		{
			new_node->next = node->next;
			node->next = new_node;
			break;
		};

		++i;
	};

	++size;
};


template <typename T>
void LinkedList<T>::remove()
{
	pop(size-1);
};


template <typename T>
void LinkedList<T>::remove(int index)
{
	pop(index);
};


template <typename T>
T LinkedList<T>::pop()
{
	return pop(size-1);
};


template <typename T>
T LinkedList<T>::pop(int index)
{
	LinkedListNode<T> *node;
	LinkedListNode<T> *next_node;
	T value;

	if (index < 0 || index >= size) {
		throw std::invalid_argument("`index` must be 0 <= index < size");
	}

	int i = 0;
	for (node=head_node; node; node=node->next) 
	{
		if (i == index) 
		{
			value = node->next->value;
			next_node = node->next->next;
			delete node->next;
			node->next = next_node;
			break;
		};

		++i;
	};

	--size;
	return value;
};


template <typename T>
void LinkedList<T>::traverse() const
{
	LinkedListNode<T> *node;

	for (node=head_node->next; node; node=node->next) 
	{
		std::cout << node->value << std::endl;
	};
};


template <typename T>
int LinkedList<T>::length() const
{
	return this->size;
};


template <typename T>
bool LinkedList<T>::search(T value) const
{
	return get_index(value) != -1;
};


template <typename T>
int LinkedList<T>::get_index(T value) const
{
	LinkedListNode<T> *node;

	int i = 0;
	for (node=head_node->next; node; node=node->next) 
	{
		if (node->value == value) 
		{
			return i;
		};

		++i;
	};

	// return -1 if not found
	return -1;
};


/*
Bi-directional Linked List
*/

template <typename T>
BiDirectionalLinkedList<T>::BiDirectionalLinkedList()
{
	BiDirectionalLinkedListNode<T> *new_node;

	// head_node node
	new_node = new BiDirectionalLinkedListNode<T>;
	new_node->prev = NULL;
	new_node->next = NULL;
	head_node = new_node;
	tail_node = new_node;

	size = 0;
};


template <typename T>
BiDirectionalLinkedList<T>::BiDirectionalLinkedList(int inital_size, const T values[])
{
	BiDirectionalLinkedListNode<T> *node;
	
	size = inital_size;

	// head node
	head_node = new BiDirectionalLinkedListNode<T>;
	head_node->prev = NULL;
	node = head_node;

	for (int i=0; i<size; ++i)
	{
		node->next = new BiDirectionalLinkedListNode<T>;
		node->next->prev = node;
		node->next->value = values[i];
		node = node->next;
	}

	// last node
	node->next = NULL;
	tail_node = node;
};


template <typename T>
BiDirectionalLinkedList<T>::~BiDirectionalLinkedList()
{
	clear();
	delete head_node;
};


// clear all nodes except head_node
template <typename T>
void BiDirectionalLinkedList<T>::clear()
{
	BiDirectionalLinkedListNode<T> *node;
	BiDirectionalLinkedListNode<T> *next;

	node = head_node->next;
	while (node) 
	{
		next = node->next;
		delete node;
		node = next;
	};

	size = 0;
	head_node->next = NULL;
	tail_node = NULL;
};


template <typename T>
void BiDirectionalLinkedList<T>::traverse() const
{
	BiDirectionalLinkedListNode<T> *node;

	for (node=head_node->next; node; node=node->next) 
	{
		std::cout << node->value << std::endl;
	};
};


template <typename T>
int BiDirectionalLinkedList<T>::length() const
{
	return this->size;
};


int main()
{	
	int max_n = 10000;
	

	/* Linked List */
	std::cout << "Linked list test:" << std::endl;
	LinkedList<double> ll;

	ll.append(1);
	ll.append(3);
	ll.append(4);
	ll.insert(0, 0);
	ll.insert(4, 5);
	ll.insert(2, 2);
	ll.traverse(); // 0 1 2 3 4 5
	std::cout << "head: " << ll.head() << std::endl; // 0
	ll.set(0, -1);
	std::cout << "head: " << ll.head() << std::endl; // -1
	std::cout << "size: " << ll.length() << std::endl; // size: 6

	std::cout << "" << std::endl;
	ll.remove();
	ll.traverse(); // 0 1 2 3 4

	std::cout << "" << std::endl;
	ll.remove(0);
	ll.traverse(); // 1 2 3 4

	std::cout << "" << std::endl;
	ll.remove(3);
	ll.traverse(); // 1 2 3
	std::cout << "size: " << ll.length() << std::endl; // size: 3

	std::cout << "" << std::endl;
	std::cout << "pop: " << ll.pop() << std::endl; // pop: 3
	std::cout << "pop: " << ll.pop(0) << std::endl; // pop: 1
	std::cout << "pop: " << ll.pop(0) << std::endl; // pop: 2

	std::cout << "" << std::endl;
	for(int i=0; i<max_n; ++i)
	{
		ll.insert(i, max_n-1-i);
	};

	std::cout << "search " << max_n << ": " << ll.search(max_n) << std::endl; // search max_n: 0
	std::cout << "search " << max_n-1 << ": " << ll.search(max_n-1) << std::endl; // search max_n-1: 1
	std::cout << "index " << max_n << ": " << ll.get_index(max_n) << std::endl; // index max_n: -1
	std::cout << "index " << max_n-1 << ": " << ll.get_index(max_n-1) << std::endl; // index max_n-1: 0

	for(int i=0; i<max_n-2; ++i)
	{
		ll.remove(max_n-1-i);
	};

	ll.traverse(); // max_n - 1, max_n - 2
	std::cout << "size: " << ll.length() << std::endl; // size: 2
	ll.clear();
	std::cout << "size: " << ll.length() << std::endl; // size: 0

	std::cout << "" << std::endl;
	double elems[max_n];
	for (int i=0; i<max_n; ++i)
	{
		elems[i] = max_n - i - 1;
	};
	LinkedList<double> ll2(max_n, elems);
	std::cout << "size: " << ll2.length() << std::endl; // size: max_n

	for(int i=0; i<max_n-2; ++i)
	{
		ll2.remove(max_n-3-i);
	};
	ll2.traverse(); // 1 0
	std::cout << "size: " << ll2.length() << std::endl; // size: 3

	ll2.clear();
	std::cout << "size: " << ll2.length() << std::endl; // size: 0
	

	/* Bi-directional Linked List */
	std::cout << std::endl;
	std::cout << "Bi-directional linked list test:" << std::endl;
	max_n = 10;
	double elems2[max_n];
	for (int i=0; i<max_n; ++i)
	{
		elems2[i] = max_n - i - 1;
	};
	BiDirectionalLinkedList<double> bl(max_n, elems2);
	bl.traverse(); // 1 2 ... 9
	std::cout << "size: " << bl.length() << std::endl; // size: max_n

    return 0;
}
