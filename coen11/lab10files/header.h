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
void read_file(char *);
void write_file(char *);
