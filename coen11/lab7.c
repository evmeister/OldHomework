#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define NODE struct node
#define LIST struct list
struct node
{
	char name[20];
	int size;
	NODE *next;
};
struct list
{
	NODE *head;
	NODE *tail;
};
LIST group[4];
void insert(char*, int);
void delete(void);
void show(void);
void quit(char*);
void read_file(char *file);
void write_file(char *file);
int
//main(void)
main(int argc, char *argv[])
{
// begin io
	if(argc<2)
	{
		printf("Filename not found.\n");
		return 0;
	}
// end io	
	int i;
	for(i=0; i<4;i++)
	{
		group[i].head=NULL;
		group[i].tail=NULL;
	}
	read_file(argv[1]);
	int inp;
	while(1)
	{
		printf("To add to the list, press 1.\nTo delete from the list, press 2.\nTo show the list, press 3.\nTo quit, press any other number.\n");
		scanf("%d", &inp);
		switch (inp)
		{
			case 1:
				{
					int n;
					char name[20];
					printf("Enter name:\n");
					scanf("%s", name);
					printf("Enter party size:\n");
					scanf("%d", &n);
					insert(name, n);
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
					quit(argv[1]);
					return 0;
				}
		}
	}
}
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
