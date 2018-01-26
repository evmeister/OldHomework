# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
# include "deque.h"


struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct deque {
    int count;
    struct node *head;
};


struct deque *createDeque(void)
{
    struct deque *dp;


    dp = malloc(sizeof(struct deque));
    assert(dp != NULL);

    dp->count = 0;
    dp->head = malloc(sizeof(struct node));
    assert(dp->head != NULL);

    dp->head->next = dp->head;
    dp->head->prev = dp->head;

    return dp;
}


void destroyDeque(struct deque *dp)
{
    struct node *np, *next;


    assert(dp != NULL);
    np = dp->head;

    do {
	next = np->next;
	free(np);
	np = next;
    } while (np != dp->head);

    free(dp);
}


void addFirst(struct deque *dp, int x)
{
    struct node *np, *sentinel;


    assert(dp != NULL);
    np = malloc(sizeof(struct node));
    assert(np != NULL);
    np->data = x;

    dp->count ++;
    sentinel = dp->head;

    np->prev = sentinel;
    np->next = sentinel->next;

    sentinel->next->prev = np;
    sentinel->next = np;
}


void addLast(struct deque *dp, int x)
{
    struct node *np, *sentinel;


    assert(dp != NULL);
    np = malloc(sizeof(struct node));
    assert(np != NULL);
    np->data = x;

    sentinel = dp->head;
    dp->count ++;

    np->prev = sentinel->prev;
    np->next = sentinel;

    sentinel->prev->next = np;
    sentinel->prev = np;
}


int removeFirst(struct deque *dp)
{
    int x;
    struct node *np, *sentinel;


    assert(dp != NULL && dp->count > 0);
    sentinel = dp->head;
    dp->count --;

    np = sentinel->next;
    sentinel->next = np->next;
    np->next->prev = sentinel;

    x = np->data;
    free(np);
    return x;
}


int removeLast(struct deque *dp)
{
    int x;
    struct node *np, *sentinel;


    assert(dp != NULL && dp->count > 0);
    sentinel = dp->head;
    dp->count --;

    np = sentinel->prev;
    sentinel->prev = np->prev;
    np->prev->next = sentinel;

    x = np->data;
    free(np);
    return x;
}


int getFirst(struct deque *dp)
{
    assert(dp != NULL && dp->count > 0);
    return dp->head->next->data;
}


int getLast(struct deque *dp)
{
    assert(dp != NULL && dp->count > 0);
    return dp->head->prev->data;
}


int numItems(struct deque *dp)
{
    return dp->count;
}
