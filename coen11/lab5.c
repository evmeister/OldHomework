#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define NODE struct node
struct node
{
	char name[20];
	int size;
	NODE *next;
};
NODE *head=NULL;
NODE *tail=NULL;
void insert(void);
void delete(void);
void show(void);
void quit(void);
int
main(void)
{
	int inp;
	while(1)
	{
		printf("To add to the list, press 1.\nTo delete from the list, press 2.\nTo show the list, press 3.\nTo quit, press any other number.\n");
		scanf("%d", &inp);
		switch (inp)
		{
			case 1:
				{
					insert();
					break;
				}
			case 2:
				{
					delete();
					break;
				}
			case 3:
				{
					show();
					break;
				}
			default:
				{
					quit();
					return 0;
				}
		}
	}
}
void
insert(void)
{
//	printf("Placeholder\n");
	NODE *temp, *p;
	temp=p=head;
	temp=(NODE*)malloc(sizeof(NODE));
	if(temp==NULL)
	{
		printf("Memory error.\n");
		return;
	}
	printf("Enter name:\n");
	scanf("%s", temp->name);
	while(p!=NULL)
	{
		if(strcmp(temp->name, p->name)==0)
		{
			printf("Name already in use.\n");
			free(temp);
			return;
		}
		p=p->next;
	}
	printf("Enter party size:\n");
	scanf("%d", &temp->size);
	temp->next=NULL;
	if(head==NULL)
	{
		head=temp;
		tail=temp;
	}
	else
	{
		tail->next=temp;
		tail=temp;
	}
	printf("Reserved.\n");
	return;
}
void
delete(void)
{
//	printf("Placeholder\n");
	NODE *p, *q;
	p=q=head;
	if(head==NULL)
	{
		printf("Waitlist Empty.\n");
		return;
	}
	printf("Enter table size:\n");
	int n;
	scanf("%d", &n);
	while(p!=NULL)
	{
		if(p->size<=n)
			break;
		q=p;
		p=p->next;
	}
	if(p==NULL)
	{
		printf("Not found.\n");
		return;
	}
	if(p==head)
		head=head->next;
	else if(p==tail)
	{
		tail=q;
		tail->next=NULL;
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
	if(head==NULL)
	{
		printf("Waitlist Empty.\n");
		return;
	}
	NODE *p;
	p=head;
	while(p!=NULL)
	{
		printf("%s party of %d\n", p->name, p->size);
		p=p->next;
	}
	return;
}
void
quit(void)
{
//	printf("Placeholder\n");
	if(head==NULL)
	{
		return;
	}
	NODE *p;
	p=head;
	while(p!=NULL)
	{
		head=p->next;
		free(p);
		p=head;
	}
	return;
}
