/* Evan Eberhardt
 * Project 2
 * This code creates and destroys unsorted sets, and counts, adds,
 * and removes elements from the sets. */
#include<stdbool.h>
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"set.h"
struct set{
	int count;
	int length;
	char **elts;
};
/* This function will create a set.
 * It is O(n) */
SET *createSet(int maxElts)
{
	SET *sp;
	sp=malloc(sizeof(SET));
	assert(sp!=NULL);
	sp->count=0;
	sp->length=maxElts;
	sp->elts=malloc(sizeof(char*)*maxElts);
	assert(sp->elts!=NULL);
	return sp;
}
/*This function returns how many elements are in the file.
 * It is O(1) */
int numElements(SET *sp)
{
	assert(sp!=NULL);
	return sp->count;
}
/* This function will destroy a set. It is O(n) */
void destroySet(SET *sp)
{
	int i;
	assert(sp!=NULL);
	for(i=0; i<sp->count; i++)
		free(sp->elts[i]);
	free(sp->elts);
	free(sp);
	return;
}
/* This function will find the index of an element that is searched for.
 * It is a sequential search, so it is O(n)
 * It will be called by other functions. */
int findElement(SET *sp, char* elt, bool *found)
{
	int i=0;
	for(i=0; i<sp->count; i++)
	{
		if(strcmp(elt, sp->elts[i])==0)
		{
			*found=true;
			return i;
		}
	}
	*found=false;
	return -1;
}
/* This funtion will return true if the searched for element is found.
 * It is O(n)
 * It will call findElement. */
bool hasElement(SET *sp, char *elt)
{
	bool found;
	assert(sp!=NULL && elt!=NULL);
	findElement(sp, elt, &found);
	return found;
}
/* This function will add an element to a set.
 * It is O(n)
 * It calls findElement. */
bool addElement(SET *sp, char *elt)
{
	bool found;
	assert(sp!=NULL);
	if(sp->count==sp->length)
		return false;
	if(findElement(sp, elt, &found)==-1)
	{
		sp->elts[sp->count]=strdup(elt);
		sp->count++;
		return true;
	}
	return false;
}
/* This function will remove an element from a set.
 * It is O(n)
 * It calls findElement. */
bool removeElement(SET *sp, char *elt)
{
	int i;
	bool found;
	assert(sp!=NULL);
	if(sp->count==0)
		return false;
	i=findElement(sp, elt, &found);
	if(i!=-1)
	{
		free(sp->elts[i]);
		sp->elts[i]=strdup(sp->elts[sp->count-1]);
		sp->count--;
		return true;
	}
	return false;
}
