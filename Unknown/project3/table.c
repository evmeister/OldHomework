/* Evan Eberhardt
 * Project 3
 * This code creates and destroys unsorted sets, and counts, adds,
 * and removes elements from the sets. */
#include<stdbool.h>
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"set.h"
#define EMPTY 0
#define FILLED 1
#define DELETED 2
struct set{
	int count;
	int length;
	char **elts;
	char *flags;
};
unsigned hashString(char *s);
/* This function will create a set.
 * It declares and initiallizes elts and flags and sets flags to empty.
 * It is O(n) */
SET *createSet(int maxElts)
{
	int i;
	SET *sp;
	sp=malloc(sizeof(SET));
	assert(sp!=NULL);
	sp->count=0;
	sp->length=maxElts;
	sp->elts=malloc(sizeof(char*)*maxElts);
	assert(sp->elts!=NULL);
	sp->flags=malloc(sizeof(char)*maxElts);
	assert(sp->flags!=NULL);
	for(i=0; i<maxElts; i++)
		sp->flags[i]=EMPTY;
	return sp;
}
/*This function returns how many elements are in the file by returning count
 * It is O(1) */
int numElements(SET *sp)
{
	assert(sp!=NULL);
	return sp->count;
}
/* This function will destroy a set by freeing all filled elts, the array,
 * and the pointer.
 * It is O(n) */
void destroySet(SET *sp)
{
	int i;
	assert(sp!=NULL);
	for(i=0; i<sp->count; i++)
		if(sp->flags[i]==FILLED)
			free(sp->elts[i]);
	free(sp->elts);
	free(sp);
	return;
}
/* This function will find the index of an element that is searched for.
 * In a for loop, it checks the hash location of a value and if it is filled
 * it compares the data. It also remembers the first deleted slot and if the
 * value was found (bool *found) and returns the location.
 * Best case, this is O(1). Worst case this is O(n).
 * It will be called by other functions. */
int findElement(SET *sp, char* elt, bool *found)
{
	unsigned j;
	int flag=0;
	int x=-1;
	int i=0;
	for(i=0; i<sp->length; i++)
	{
		j=((hashString(elt)+i)%sp->length);
		if(sp->flags[j]==FILLED)
		{	
			if(strcmp(elt, sp->elts[j])==0)
			{
				*found=true;
				return j;
			}
		}
		else if(sp->flags[j]==EMPTY)
		{
			if(flag==0)
				x=j;
			break;
		}
		else
		{
			if(flag==0)
			{
				x=j;
				flag++;
			}
		}
	}
	*found=false;
	return x;
}
/* This funtion will return true if the searched for element is found.
 * Best case it is O(1). Worst case it is O(n).
 * It does this by calling findElement. */
bool hasElement(SET *sp, char *elt)
{
	bool found;
	assert(sp!=NULL && elt!=NULL);
	findElement(sp, elt, &found);
	return found;
}
/* This function will add an element to a set.
 * It uses strdup to assign the value to elts[locn], increments the counter
 * and sets the flag to filled.
 * Best case this is O(1). Worst case this is O(n).
 * It calls findElement. */
bool addElement(SET *sp, char *elt)
{
	int locn;
	bool found;
	assert(sp!=NULL);
	if(sp->count==sp->length)
		return false;
	locn=findElement(sp, elt, &found);
	if(found==false)
	{
		sp->elts[locn]=strdup(elt);
		sp->count++;
		sp->flags[locn]=FILLED;
		return true;
	}
	return false;
}
/* This function will remove an element from a set.
 * It calls findElement, frees elts[i], decrements the counter, and sets the
 * flag to deleted.
 * Best case, this is O(1). Worst case this is O(n).
 * It calls findElement. */
bool removeElement(SET *sp, char *elt)
{
	int i;
	bool found;
	assert(sp!=NULL);
	if(sp->count==0)
		return false;
	i=findElement(sp, elt, &found);
	if(found==true)
	{
		free(sp->elts[i]);
		sp->count--;
		sp->flags[i]=DELETED;
		return true;
	}
	return false;
}
/* This is the hash function. Lo and behold, it hashes.
 * It uses a while loop to create a hash value from the given key.
 * It is O(n).*/
unsigned hashString(char *s)
{
	unsigned hash=0;
	while(*s!='\0')
		hash = 31 * hash + *s ++;
	return hash;
}
