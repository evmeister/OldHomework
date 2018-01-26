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
struct tree *deletemin(void);
void bitcode(struct tree *lea);	
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



	for(i=0; i<257; i++) //Puts all trees in heap
	{
		if(leaves[i]!=NULL)
		{
			heap[n]=leaves[i];
			n++;
		}
	}
		


	while(n!=1) //organizes heap until there is only one tree by using deletemin to remove the two trees with minimum values and inserting a new tree with a combined value from the two and the two trees as left and right children. 
	{		
		min1=deletemin();
		min2=deletemin();
		struct tree *new=createTree(getData(min1)+getData(min2), min1, min2);
		heap[n]=new;
		n++;
	}




	for(i=0; i<257; i++) //This loop prints the characters and their bit encodings. It calls isprint to check if the ascii value can be printed as a character.
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
	pack(argv[1], argv[2], leaves); //This is the compression function.
	return 0;
}



//This O(n) function searches for the minimum in heap. It traverses the unsorted array called heap, then removes and returns the tree with the min value 
struct tree
*deletemin(void)
{
	int i;
	int place=0;
	struct tree *min1; 
	int min=getData(heap[0]);
	min1=heap[0];
	for(i=0; i<n; i++)
	{
		if((getData(heap[i]))<min)
		{
			min=getData(heap[i]);
			min1=heap[i];
			place=i;
		}
	}		
	heap[place]=heap[n-1];
	heap[n-1]=NULL;
	n--;
	return min1; 
}



//This recursive function O(n) prints the bit encoding of a leaf
//If a leaf is it the right child of its parent, it prints 1, else it prints 0
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
