#include <stdio.h>
#include <string.h>
#define SIZE 10
int user;
char rooms[SIZE][20];
int counter=1;
void reserve();
void cancel();
void list();
int main(void)
{
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
void
reserve()
{
	int r;
        int j;
        if(counter==11)
        {
        	printf("The hotel is full.\n");
        }
        else
        {
        	for(j=0; j<SIZE; j++)
        		{
                        	if(rooms[j][0]=='\0')
                                	{
                                        	r=j+1;
                                                char input [20];
                                                printf("Type in the name of the reservation: ");
                                                scanf("%s", input);
						int i;
						int flag=0;
						for(i=0; i<SIZE; i++)
						{
							if(strcmp(input, rooms[i])==0)
							{	
								flag++;
							}
						}
						if(flag==0)	
                                                {	strcpy(rooms[j], input);
                                                	printf("Room %d reserved.\n", r);
                                               		counter++;
						}
						else
						{
						printf("This name already exists.\n");
						}
                                                j=SIZE;
                                                break;
                                        }
                        }
	}
return;
}
void
cancel()
{
	char check[20];
        if(counter==1)
        {
        	printf("The hotel is empty.\n");
        }
        else
        {
        	printf("Enter the name of the reservation you want to cancel.\n");
                scanf("%s", check);
                int t;
                int flag=0;
                for(t=0; t<SIZE; t++)
                {
                	int value=strcmp(rooms[t], check);
                        if(value==0)
                        {
                        	rooms[t][0]='\0';
                                printf("Canceled.\n");
                                counter--;
                                t=SIZE;
                                break;
                        }
                        else
                        {
                        	flag++;
                        }
                  }
                  if(flag==10)
                  {
                  	printf("Name invalid.\n");
                  }
	}
return;
}
void
list()
{
	int k;
        int r;
        if(counter==1)
        {
        	printf("The hotel is empty.\n");
        }
        for(k=0; k<SIZE; k++)
        {
        	if(rooms[k][0]!='\0')
                {
                	printf("Room %d is reserved under %s.\n", r=k+1, rooms[k]);
                }
        }
return;
}
