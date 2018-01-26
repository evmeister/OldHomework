/* Evan Eberhardt
 * Project 4
 * deque.c
 * This code creates and destroys deques, and counts, adds, removes, and gets elements */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include "deque.h"
struct deque{
	int count;
	struct node *head;
};
struct node{
	int data;
	struct node *next;
	struct node *prev;
};
/* createDeque
 * This function allocates and sets data within a deque and creates a dummy node.
 * This function is O(1) */
DEQUE *createDeque(void)
{
	DEQUE *dp;
	dp=malloc(sizeof(DEQUE));
	assert(dp!=NULL);
	dp->count=0;
	dp->head=malloc(sizeof(struct node));
	assert(dp->head!=NULL);
	dp->head->next=dp->head;
	dp->head->prev=dp->head;
	return dp;
}
/* numItems
 * This function returns the number of items in the deque
 * This function is O(1) */
int numItems(DEQUE *dp)
{
	assert(dp!=NULL);
	return dp->count;
}
/* destroyDeque
 * This function frees every node using a loop and two node pointers, then frees the deque
 * It is O(n) */
void destroyDeque(DEQUE *dp)
{
	assert(dp!=NULL);
	struct node *p, *q;
	struct node *temp=dp->head;
	p=dp->head->next;
	q=p->next;
	while(p!=dp->head)
	{
		free(p);
		p=q;
		q=p->next;
	}
	free(temp);
	free(dp);
	return;
}
/* addFirst
 * This function allocates a node, sets data, increments count, and sets next and prev pointers
 * It results in a new node at the first location in the deque
 * This funciton is O(1) */
void addFirst(DEQUE *dp, int x)
{
	assert(dp!=NULL);
	struct node *new;
	new=malloc(sizeof(struct node));
	assert(new!=NULL);
	new->data=x;
	dp->count++;
	new->next=dp->head->next;
	new->prev=dp->head;
	dp->head->next->prev=new;
	dp->head->next=new;
	return;
}
/* removeFirst
 * This function sets pointers, decrements count, frees the pointer to the first node, and returns data.
 * This function is O(1) */
int removeFirst(DEQUE *dp)
{
	assert(dp!=NULL);
	struct node *temp=dp->head;
	int x;
	dp->count--;
	struct node *p=temp->next;
	temp->next=p->next;
	p->next->prev=temp;
	x=p->data;
	free(p);
	return x;
}
/* getFirst
 * This function returns the data at the first location
 * This function is O(1) */
int getFirst(DEQUE *dp)
{
	assert(dp!=NULL && dp->count!=0);
	return dp->head->next->data;
}
/* getLast
 * This function returns that data at the last location
 * This function is O(1) */
int getLast(DEQUE *dp)
{
	assert(dp!=NULL && dp->count!=0);
	return dp->head->prev->data;
}
/* addLast
 * This function allocates a node, sets data, increments count, and sets next and prev pointers
 * It results in a new node at the last location in the deque
 * This funcition is O(1) */
void addLast(DEQUE *dp, int x)
{
	assert(dp!=NULL);
	struct node *new;
	new=malloc(sizeof(struct node));
	assert(new!=NULL);
	new->data=x;
	dp->count++;
	new->next=dp->head;
	new->prev=dp->head->prev;
	dp->head->prev->next=new;
	dp->head->prev=new;
	return;
}
/* removeLast
 * This function sets pointers, decrements count, frees the pointer th the last node, and returns data
 * This function is O(1) */
int removeLast(DEQUE *dp)
{
	assert(dp!=NULL);
	struct node *temp=dp->head;
	int x;
	dp->count--;
	struct node *p=temp->prev;
	temp->prev=p->prev;
	p->prev->next=temp;
	x=p->data;
	free(p);
	return x;
}
