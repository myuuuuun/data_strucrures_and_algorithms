/*
Linked list library

2018 @myuuuuun
*/

#ifndef __LinkedList
#define __LinkedList


template <typename T> 
struct LinkedListNode
{
	T value;
	LinkedListNode<T> *next;
};


template <typename T> 
struct BiDirectionalLinkedListNode
{
	T value;
	BiDirectionalLinkedListNode<T> *prev;
	BiDirectionalLinkedListNode<T> *next;
};


template <typename T> 
class LinkedList
{
	private:
		LinkedListNode<T> *head_node;
		int size;

	public:
		LinkedList<T>();
		LinkedList<T>(int, const T[]);
		~LinkedList<T>();
		void clear();
		T head();
		T get(int);
		void set(int, T);
		void append(T);
		void insert(T);
		void insert(int, T);
		void remove();
		void remove(int);
		T pop();
		T pop(int);
		void traverse() const;
		int length() const;
		bool search(T) const;
		int get_index(T) const;
};


template <typename T> 
class BiDirectionalLinkedList
{
	private:
		BiDirectionalLinkedListNode<T> *head_node;
		BiDirectionalLinkedListNode<T> *tail_node;
		int size;

	public:
		BiDirectionalLinkedList<T>();
		BiDirectionalLinkedList<T>(int, const T[]);
		~BiDirectionalLinkedList<T>();
		void clear();
		void traverse() const;
		int length() const;
};


#endif
