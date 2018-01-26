/* Evan Eberahrdt
 * Project 5
 * Huffman.c */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<ctype.h>
#include"tree.h"
#include"pack.h"
#define p(i) ((i-1)/2)
#define lc(i) ((2*i)+1)
#define rc(i) ((2*i)+2)
void insert(struct tree *leaf);
struct tree *deletemin(void);
void bitcode(struct tree *leaf);	
void pack(char *infile, char *outfile, struct tree *leaves[257]);
int count[257]; //Number of occurrences of a char
struct tree *leaves[257]; //Tree for each character with count>0
struct tree *heap[257]; //Leaves organized as a heap
int n; //counter for trees in heap
int
main(int argc, char *argv[])
{
	//Declarations
	int i, c;
	n=0;
	for(i=0; i<257; i++)
	{
		count[i]=0;
		leaves[i]=NULL;
		heap[i]=NULL;
	}
	FILE *infp, *outfp;
	struct tree *min1, *min2;


	
	if(argc!=3) //File IO
	{
		printf("Files missing\n");
		return 0;
	}
	infp=fopen(argv[1], "r");
	assert(infp!=NULL);
	while((c=getc(infp))!=EOF) //Gets ascii values for each character
		count[c]++;
	fclose(infp);


	
	for(i=0; i<257; i++) //makes trees for each character
	{
		if(count[i]>0)
			leaves[i]=createTree(count[i], NULL, NULL);
	}
	struct tree *eof=createTree(0, NULL, NULL);
	leaves[256]=eof;



	for(i=0; i<257; i++) //Puts all trees in heap calling the insert function
	{
		if(leaves[i]!=NULL)
		{
		   	insert(leaves[i]);
		}
	}


	
	while(n!=1) //organizes heap until there is only one tree. Takes the two smallest values from the heap, makes a tree whose value is the sum of the minimums and whose children are the minimums, then inserts the new tree into the heap with the insert function.
	{		
		min1=deletemin();
		min2=deletemin();
		struct tree *new=createTree(getData(min1)+getData(min2), min1, min2);
		getData(new);
		insert(new);
	}




	for(i=0; i<257; i++) //This loop prints the characters and their bit encodings. It uses isprint to see if the ascii value can be printed as a character or octal code. calls bitcode.
	{
		if(leaves[i]!=NULL)
		{
			if((isprint(i))==0)
			{	
				printf("\n%o:\t%d\t", i, count[i]);
				bitcode(leaves[i]);
			}
			else
			{
				printf("\n%c:\t%d\t", i, count[i]);
				bitcode(leaves[i]);
			}

		}
	}
	printf("\n");
	pack(argv[1], argv[2], leaves);
	return 0;
}



//This O(n) function searches for the minimum in heap. it takes min to be the first value in the heap, then fixes the order of hte heap. It checks which child of heap[i] has the least value, then if then if the last value is less than this child, and inserts it at i if it is.  
struct tree
*deletemin(void)
{
	int i, child;
	struct tree *min, *x;
	x=heap[n-1];
	min =heap[0];
	i=0;
	while(lc(i)<n)
	{
		child=lc(i);
		if(rc(i)<n && getData(heap[lc(i)])>getData(heap[rc(i)]))
		{
			child=rc(i);
		}
		if(getData(x)>getData(heap[child]))
		{
			heap[i]=heap[child];
			i=child;
		}
		else
			break;
	}
	heap[i]=x;
	n--;
	return min;
}



//This recursive function O(n) prints the bit encoding of a leaf
//If a leaf is the right child of its parent, it prints 1, else it prints 0
void
bitcode(struct tree *leaf)
{
	if(getParent(leaf)==NULL)
		return;
	bitcode(getParent(leaf));
	if(leaf==getRight(getParent(leaf)))
	{
		printf("1");
	}
	else
	{
		printf("0");
	}
	return;
}	



//This function inserts the leaves into a binary min heap. It is O(1)
//if the would be parent's value is greater than the leaf, the parent is shifed down the tree until the leaf can be inserted in the proper place.
void
insert(struct tree *leaf)
{
	int i;
	i=n;
	n++;
	while(i>0 &&  getData(heap[p(i)])>getData(leaf))
	{
		heap[i]=heap[p(i)];
		i=p(i);	
	}
	heap[i]=leaf;
}
