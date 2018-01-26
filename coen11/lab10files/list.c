#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "header.h"
void
insert(char *inname, int n)
{
//	printf("Placeholder\n");
	NODE *temp, *p;
	temp=(NODE*)malloc(sizeof(NODE));
	if(temp==NULL)
	{
		printf("Memory error.\n");
		return;
	}
	int i;
	for(i=0; i<4; i++)
	{
		p=group[i].head;
		while(p!=NULL)
		{
			if(strcmp(inname, p->name)==0)
			{
				printf("Name already in use.\n");
				free(temp);
				return;
			}
			p=p->next;
		}
	}
	strcpy(temp->name, inname);
	temp->size=n;
	int f;
	if(temp->size==1 || temp->size==2)
		f=0;
	else if(temp->size==3 || temp->size==4)
		f=1;
	else if(temp->size==5 || temp->size==6)
		f=2;
	else
		f=3;
	temp->next=NULL;
    //Inserting
	if(group[f].head==NULL)
	{
		group[f].head=temp;
		group[f].tail=temp;
	}
	else
	{
		group[f].tail->next=temp;
		group[f].tail=temp;
	}
	printf("Reserved.\n");
	return;
}
void
delete(void)
{
//	printf("Placeholder\n");
	NODE *p, *q;
	if(group[0].head==NULL && group[1].head==NULL && group[2].head==NULL && group[3].head==NULL)
	{
		printf("Waitlist Empty.\n");
		return;
	}
	printf("Enter table size:\n");
	int n, f;
	scanf("%d", &n);
	if(n==1 || n==2)
	{
		f=0;
	}
	else if(n==3 ||n==4)
	{
		f=1;
	}
	else if(n==5 || n==6)
	{
		f=2;
	}
	else
	{
		f=3;
	}
	p=group[f].head;
	while(f>=0)
	{
		if(p!=NULL && p->size<=n)
			break;
		if(p!=NULL)
		{
			q=p;
			p=p->next;
		}
		if(p==NULL)
		{
			f-=1;
			p=group[f].head;
		}
	}
	if(f<0)
	{
		printf("Not found.\n");
		return;
	}
	if(p==group[f].head)
		group[f].head=group[f].head->next;
	else if(p==group[f].tail)
	{
		group[f].tail=q;
		group[f].tail->next=NULL;
	}
	else
		q->next=p->next;
	free(p);
	printf("Seated.\n");
	return;
}
void
show(void)
{
//	printf("Placeholder\n");
	if(group[0].head==NULL && group[1].head==NULL && group[2].head==NULL && group[3].head==NULL)
	{
		printf("Waitlist Empty.\n");
		return;
	}
	NODE *p;
	int i;
	for(i=0; i<4; i++)
	{
		printf("Group %d:\n", i);
		p=group[i].head;
		while(p!=NULL)
		{
			printf("%s party of %d\n", p->name, p->size);
			p=p->next;
		}
	}
	return;
}
