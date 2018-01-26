#include <stdio.h>
#include <stdlib.h>
int recur(char*, char*);
int
main(int argc, char *argv[])
{
	if(argc<3)
	{
		printf("Files not found.\n");
		return 0;
	}
	FILE *fp;
	fp=fopen(argv[1], "r");
	if(fp==NULL)
	{
		printf("File1 could not open.\n");
		return 0;
	}
	FILE *fq;
	fq=(fopen(argv[2], "w"));
	if(fq==NULL)
	{
		printf("File2 could not open.\n");
		return 0;
	}
	char str1[20];
	char str2[20];
	char *p=str1;
	char *q=str2;
	while((fgets(str1, 20, fp))!=NULL)
	{
		int g;
		g=recur(p, q);
		str2[g]='\0';
		fprintf(fq, "%s\n", str2);
	}
	fclose(fp);
	fclose(fq);
}
int
recur(char *p, char *q)
{
	if(*p=='\0' || *p=='\n')
		return 0;
	else
	{
		int i=recur(p+1, q);
		q[i]=*p;
		return i+1;
	}
}
