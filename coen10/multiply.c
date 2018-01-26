#include <stdio.h>
int main (void)
{
	int count;
	int i;
	count=0;
	srand((int) time(NULL));
	for(i=0; i<10; i++)
	{	
		int rand1=rand()%13;
		int rand2=rand()%13;
		int a;
		printf("%d * %d = \n", rand1, rand2);
		scanf("%d", &a);
		if(rand1*rand2==a)
		{
			count++;
		}
	}
	printf("You got %d0%% correct \n", count);

return 0;
}
