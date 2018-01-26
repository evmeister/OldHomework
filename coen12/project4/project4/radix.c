//Evan Eberhardt
//Project 4
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include"deque.h"
#define r 10
//This function performs a radix sort on a list of numbers the user inputs.
int main()
{
	int max=0;
	int input, digits, binno;
	int i, j;
	int divisor=1; //This variable will be used when finding a particular digit of an item
	DEQUE *main;
	DEQUE *charliebucket[r];
	main=createDeque(); // This creates the main deque
	for(i=0; i<r; i++) // This loop creates the array of deques
		charliebucket[i]=createDeque();
	while(scanf("%d", &input)==1) //This loop scans in the list of numbers
	{	
		assert(input>=0); //Makes sure no negativ number is input
		if(input>max) //Keeps track of the maximum input
			max=input;
		addLast(main, input);
	}
	printf("sorting...\n");
	digits=ceil(log(max+1)/log(r)); //Finds out how many digits the max has. This is how many iterations will be performed
	for(i=0; i<digits; i++) //This is the main sorting loop
	{
		while(numItems(main)!=0) //This loop takes items from the main deque and puts them in bins corresponding to the lowest significant digit
		{
			input=removeFirst(main);
			binno=(input/divisor)%10; //This will find the nth digit of a number, where n is the current iteration. First iteration finds the ones digit, second finds the tens digit...
			addLast(charliebucket[binno], input);
		}
		for(j=0; j<r; j++) //This loop places each item from each bin in order into the main deque
		{
			while(numItems(charliebucket[j])!=0)
			{
				input=removeFirst(charliebucket[j]);
				addLast(main, input);
				if(i==digits-1) //This statement checks if the last iteration is performed and prints items as they are places in the correct order in the main deque
					printf("%d\n", getLast(main));
			}
		}
		divisor*=10; //After each iteration, the divisor will increase by a factor of ten so that the next iteration will use the next digit
	}
	return 0;
}
