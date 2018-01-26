#include <stdio.h>
#include <string.h>
int main(void)
{
	const int SIZE=10;
	int i;
	char rooms[SIZE][20];
	for(i=0; i<SIZE; i++)
	{
		rooms[i][0]='\0';
	}
	int counter=1;
	int user;
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
							strcpy(rooms[j], input);
							printf("Room %d reserved.\n", r);
							counter++;
							j=SIZE;
							break;
						}
					}
				}	
				break;
			}
			case 1:
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
				break;
			}
			case 2:
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
				break;
			}
			default:
			{	
				return 0;
			}
		}
	}
}
