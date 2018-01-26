/* Evan Eberhardt
 * Project 6
 * deque.cpp
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deque.h"
class Node{
public:
	int data;
	Node *next;
	Node *prev;
};

//Deque() is a constructor that sets the pointers of a new deque. It is O(1).
Deque::Deque()
{
	count = 0;
	head = new Node;
	head->next = head;
	head->prev = head;
}

//~Deque() is a destructor that deletes every node using a do while loop and two node pointers, then deletes the deque. It is O(n).
Deque::~Deque()
{
	Node *np, *next;

	np = head;

	do{
		next = np->next;
		delete np;
		np = next;
	}while(np != head);

}

//size() returns count, the number of items in the deque. it is O(1).
int Deque::size()
{
	return count;
}

//addFirst(int x) sets data and pointers in a new node in the deque, increments count, and places the node at the first location in the deque. It is O(1).
void Deque::addFirst(int x)
{
	Node *np, *dummy;
	np =new Node;

	np->data = x;
	count++;
	dummy = head;
	np->prev = dummy;
	np->next = dummy->next;
	dummy->next->prev = np;
	dummy->next = np;
}

//addLast(int x) sets data and pointers in a new vode in the deque, increments count, and places the node at the last location in the deque. It is O(1).
void Deque::addLast(int x)
{
	Node *np, *dummy;
	np = new Node;

	np->data = x;
	dummy = head;
	count++;
	np->prev = dummy->prev;
	np->next = dummy;
	dummy->prev->next = np;
	dummy->prev = np;
}

//removeFirst() sets pointers and decrements count in order to delete the node at the first loction. It then returns data. It does this only if the deque is not empty. It is O(1).
int Deque::removeFirst()
{
	int x;
	Node *np, *dummy;

	assert(count > 0);

	dummy = head;
	count--;
	np = dummy->next;
	dummy->next = np->next;
	np->next->prev = dummy;
	x = np->data;
	delete np;
	return x;
}

//removeLast() sets pointers and decrements count in order to delete the node at the last loction. It then returns data. It does this only if the deque is not empty.  It is O(1).
int Deque::removeLast()
{
	int x;
	Node *np, *dummy;

	assert(count > 0);

	dummy = head;
	count--;
	np = dummy->prev;
	dummy->prev = np->prev;
	np->prev->next = dummy;
	x = np->data;
	delete np;
	return x;
}

//getFirst() returns data from the node in the first location as long as it is not empty. It is O(1)
int Deque::getFirst()
{
	assert(count > 0);
	return head->next->data;
}

//getLast() returns data from the node in the last location as long as it is not empty. It is O(1)
int Deque::getLast()
{
	assert(count > 0);
	return head->prev->data;
}
