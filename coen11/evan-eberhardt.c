#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NODE struct node 
struct node
{
	char task[200];
	NODE *next;
};
NODE *head=NULL;
void add(void);
void delete(void);
void show(void);
void count(void);
void save(char *file);
int
main(int argc, char *argv[])
{
	if(argc!=2)
	{
		printf("File not found");
		return 0;
	}
	int input;
	while(1)
	{
		printf("To add a task, press 1.\nTo delete a task, press 2.\nTo show the list of tasks, press 3.\nTo count urgent tasks, press 4.\nPress any other number to save and quit.\n");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
				{
					add();
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
			case 4:
				{
					count();
					break;
				}
			default:
				{
					save(argv[1]);
					return 0;
				}
		}
	}
}
void
add(void)
{
//	printf("Placeholder\n");
	NODE *temp;
	temp=(NODE*)malloc(sizeof(NODE));
	if(temp==NULL)
	{
		printf("Malloc error\n");
		return;
	}
	char input[200];
	printf("Enter new task:\n");
	scanf("%s", input);
//	printf("%s\n", input);
//	printf("bug1\n");
	strcpy(temp->task, input);
//	printf("bug2\n");
	if(head!=NULL);
		temp->next=head;
//	printf("bug3\n");
	head=temp;	
	printf("Task added\n");
	return;
}
void
delete(void)
{
//	printf("Placeholder\n");
	NODE *p, *q;
	char input[200];
	if(head==NULL)
	{
		printf("List empty\n");
		return;
	}
	printf("Enter completed task:\n");
	scanf("%s", input);
	p=head;
	while(p!=NULL)
	{
		if(strcmp(input, p->task)==0)
		{
			q->next=p->next;
			free(p);
			printf("Task removed\n");
			return;
		}
		q=p;
		p=p->next;
	}
	printf("Task not found\n");
	return;
}
void
show(void)
{
//	printf("Placeholder\n");
	NODE *temp;
	temp=head;
	if(temp==NULL)
	{
		printf("List empty\n");
		return;
	}
	while(temp!=NULL)
	{
		printf("%s\n", temp->task);
		temp=temp->next;
	}
	return;
}
void
count(void)
{
//	printf("Placeholder\n");
	int counter=0;
	int i;
	NODE *p;
	char find[7];
	if(head==NULL)
	{
		printf("List empty\n");
		return;
	}
	p=head;
	while(p!=NULL)
	{
		if(strncmp(p->task, "urgent", 6)==0)
			counter++;
		p=p->next;
	}
	printf("%d urgent tasks\n", counter);
	return;
}
void
save(char *file)
{
	FILE *fp;
	NODE *p;
	fp=fopen(file, "w");
//	printf("Placeholder\n");
	p=head;
	if(p==NULL)
	{
		fprintf(fp, " ");
		return;
	}
	while(p!=NULL)
	{
		fprintf(fp, "%s\n", p->task);
		p=p->next;
	}
	fclose(fp);
	return;
}
