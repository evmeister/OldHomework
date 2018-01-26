#include <stdio.h>
int main(void)
{
	const int SIZE=10;
	int i;
	int rooms[SIZE];
	for(i=0; i<SIZE; i++)
	{
		rooms[i]=0;
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
				int full=0;
				for(j=0; j<SIZE; j++)
				{
					switch(rooms[j])
					{
						case 0:
						{
							r=j+1;
							rooms[j]=counter;
							printf("Room %d reserved. Room ID %d.\n", r, counter);
							counter++;
							j=SIZE;
							full++;
							break;
						}
						default:
						{
							full++;
						}
					}
				}
				if(full==10)
				{
					printf("The hotel is full.\n");						
				}	
				break;
			}
			case 1:
			{
				int l;
				int empty=0;
				int check;
				for(l=0; l<SIZE; l++)
				{
					if(rooms[l]==0)
					{
						empty++;
					}
				}
				if(empty==10)
				{
					printf("The hotel is empty.\n");
				}
				else
				{
					printf("Enter the room ID of the reservation you want to cancel.\n");
					scanf("%d", &check);
					int t;
					int flag=0;
					for(t=0; t<SIZE; t++)
					{
						if(check==rooms[t])
						{
							rooms[t]=0;
							printf("Canceled.\n");
							break;
						}
						else
						{
							flag++;
						}
					}
					if(flag==10)
					{
						printf("Room ID invalid.\n");
					}
				}				
				break;
			}
			case 2:
			{
				int k;
				int r;
				int empty=0;
				for(k=0; k<SIZE; k++)
				{
					if(rooms[k]==0)
					{
						empty++;
					}
					else
					{
						r=k+1;
						printf("Room %d is reserved. Room ID %d.\n", r, rooms[k]);
					}
				}
				if(empty==10)
				{
					printf("The hotel is empty.\n");
				}					
				break;
			}
			default:
			{	
				return(0);
			}
		}
	}
}
