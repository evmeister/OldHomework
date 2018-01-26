#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int division(int, int);
int
main(void)
{
	int counter=0;
	srand((int) time(NULL));
	int divisor, quotient;
	int i;
	for(i=0; i<10; i++)
	{
		divisor = rand()%12+1;
		quotient = rand()%13;
		if(division(divisor, quotient)==1)
		{
			counter++;
		}
	}
	printf("You got %d of 10 correct. Did you honor your family?\n", counter);
	return 0;
}
int
division(divisor, quotient)
{
	int number=divisor*quotient;
	int answer;
	printf("What is %d divided by %d?\n", number, divisor);
	scanf("%d", &answer);
	if(answer==quotient)
	{
		printf("Good job, grasshopper!\n");
		return 1;
	}
	else
	{
		printf("Wrong, fool! The answer is %d.\n", quotient);
		return 0;
	}
}
