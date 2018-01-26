/* Evan Eberhardt
 * Project 2
 * This code creates and destroys sorted sets, and counts, adds, and removes elements
 * in the set. */
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
/* This function will create a set. It is O(n) */
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
/*This function returns how many elements are in the file. It is O(1) */
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
 * It is a binary search, so it is O(logn)
 * It will be called by other functons. */
int findElement(SET *sp, char *elt, bool *found)
{
	int lo, mid, hi, diff;
	lo=0;
	hi=sp->count-1;
	while(lo<=hi)
	{
		mid=(lo+hi)/2;
		diff=strcmp(elt,sp->elts[mid]);
		if(diff<0)
			hi=mid-1;
		else if(diff>0)
			lo=mid+1;
		else
		{
			*found=true;
			return mid;
		}
	}
	*found=false;
	return lo;
}
/* This function will return true if the searched for element is found.
 * it is O(logn)
 * It calls findElement. */
bool hasElement(SET *sp, char *elt)
{
	bool found;
	assert(sp!=NULL && elt!=NULL);
	findElement(sp, elt, &found);
	return found;
}
/* This function will add an element to the set.
 * It is O(logn)+O(n)=O(n)
 * It calls findElement. */
bool addElement(SET *sp, char *elt)
{
	bool found;
	int i,j;
	assert(sp!=NULL);
	if(sp->count==sp->length)
		return false;
	i=findElement(sp, elt, &found);
	if(found==false)
	{
		j=sp->count;
		while(j>i)
		{
			sp->elts[j]=sp->elts[j-1];
			j--;
		}
		sp->elts[i]=strdup(elt);
		sp->count++;
		return true;
	}
	return false;
}
/* This function will remove an element from the set.
 * It is O(logn)+O(n)=O(n)
 * It calls findElemet. */
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
		i++;
		while(i<sp->count)
		{
			sp->elts[i-1]=sp->elts[i];
			i++;
		}
		sp->count--;
		return true;
	}
	return false;
}
