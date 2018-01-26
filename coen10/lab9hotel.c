#include <stdio.h>
#include <string.h>
#define SIZE 10
char rooms[SIZE][20];
int counter=1;
void reserve();
void cancel();
void list();
int main(void)
{
	int user;
	int i;
	for(i=0; i<SIZE; i++)
	{
		rooms[i][0]='\0';
	}
	while(1)
	{
		printf("To reserve a room, press 0.\n");
		printf("To cancel a reservation, press 1.\n");
		printf("To list all reservations, press 2.\n");
		printf("Press any other number to quit.\n");
		scanf("%d", &user);
		switch(user)
		{
			case 0:
			{
				reserve();
				break;
			}
			case 1:
			{
				cancel();
				break;
			}
			case 2:
			{
				list();
				break;
			}
			default:
				return 0;
		}
	}
}
void reserve()
{
	char *p=rooms[0];
    if(counter==11)
    {
    	printf("The hotel is full.\n");
		return;
    }
    char name[20];
	int number;
    printf("Type in the name of the reservation:\n");
	scanf("%s",name);
	int i;
	for(i=0;i<SIZE;i++);
	{
		if(strcmp(p,name)==0)
		{	
			printf("This name is already in use.\n");
			return;
		}
		p+=20;
	}
	printf("Enter how many rooms you want to reserve:\n");
    scanf("%d",&number);
	p=rooms[0];
	int avail=11-counter;
	if(number>avail)
	{
		printf("System could only reserve %d of %d rooms requested.\n", avail, number);
		number=avail;
	}
	int j=0;
	while(j<number)
	{
		if(p[0]=='\0')
		{
			strcpy(p,name);
			counter++;
			j++;
		}
		p+=20;
	}
	printf("Room(s) reserved.\n");
	return;
}
void cancel()
{
	char *p=rooms[0];
	char check[20];
    if(counter==1)
    {
       	printf("The hotel is empty.\n");
		return;
    }
    printf("Enter the name of the reservation you want to cancel.\n");
    scanf("%s", check);
    int i;
    int flag=0;
    for(i=0; i<SIZE; i++)
    {
		int value=strcmp(p,check);
		if(value==0)
        {
            p[0]='\0';
            counter--;
        }
        else
        {
          	flag++;
        }
		p+=20;
	}
    if(flag==10)
    {
       	printf("Name invalid.\n");
    }
	else
	{
			printf("Canceled.\n");
	}
	return;
}
void list()
{
	int k;
    if(counter==1)
    {
     	printf("The hotel is empty.\n");
    	return;
	}
	char *p=rooms[0];
    for(k=0; k<SIZE; k++)
    {
      	if(p[0]!='\0')
        {
           	printf("Room %d is reserved under %s.\n", k+1, p);
        }
		p+=20;
    }
	return;
}
