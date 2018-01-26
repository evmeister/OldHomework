//Evan Eberhardt
//Lab section: Th 2:15
//This program counts the words in a file
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//maximum word length constant
#define MAX_WORD_LENGTH 30
int
main(int argc, char *argv[])
{
	//Declare variables
	int counter=0;
	FILE *fp;
	char buffer[MAX_WORD_LENGTH];
	//File IO
	if(argc!=2)
	{
		printf("File not found.\n");
		return 0;
	}
	fp=fopen(argv[1], "r");
	if(fp==NULL)
	{
		printf("File read error.\n");
		return 0;
	}
	//File opened. While loop used to count.
	while((fscanf(fp, "%s", buffer))>0)
		counter++;
	//Close file
	fclose(fp);
	printf("%d total words.\n", counter);
	return 0;
}
