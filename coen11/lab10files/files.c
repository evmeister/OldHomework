#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "header.h"
void quit(char*);
void read_file(char *file);
void write_file(char *file);
void
quit(char* file)
{
//	printf("Placeholder\n");
	write_file(file);
	if(group[0].head==NULL && group[1].head==NULL && group[2].head==NULL && group[3].head==NULL)
	{
		return;
	}
	NODE *p;
	int i;
	for(i=0; i<4; i++)
	{
		p=group[i].head;
		while(p!=NULL)
		{
			group[i].head=p->next;
			free(p);
			p=group[i].head;
		}
	}
	return;
}
void
read_file(char *file)
{
	FILE *fp;
	fp=fopen(file, "r");
	if(fp==NULL)
	{
		printf("File error.\n");
		return;
	}
	fseek(fp, 28, SEEK_SET);
	char name[20];
	int m;
	while(fscanf(fp, "%s\t%d\n", name, &m)==2)
	{
		insert(name, m);
	}
	fclose(fp);
	return;
}
void
write_file(char* file)
{
	FILE *fp;
	fp=fopen(file, "w");
	if(fp==NULL)
	{
		printf("File error.\n");
		return;
	}
	fprintf(fp, "Name\t\tSize\n----------------\n");
	NODE *p;
	int i;
	for(i=0; i<4; i++)
	{
		p=group[i].head;
		while(p!=NULL)
		{
			fprintf(fp, "%s\t%d\n", p->name, p->size);
			p=p->next;
		}
	}
	fclose(fp);
	return;
}
