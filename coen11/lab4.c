#include<stdio.h>
#include<string.h>
typedef union
{
	char school[20];
	float salary;
	int years;
}status;
typedef struct
{
	char name[20];
	int age;
	status info;
}person;
person array[10];
int counter=0;
void write();
void delete();
void show();
int
main(void)
{
	int i;
	for(i=0; i<10; i++)
	{
		array[i].name[0]='\0';
		array[i].age=0;
	}
	while(1)
	{
		int input;
		printf("To write data, press 1.\nTo delete data, press 2.\nTo list data, press 3.\nPress any other number to quit.\n");
		scanf("%d", &input);
		switch(input)
		{
			case 1:
				{
					write();
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
					return(0);
				}
		}
	}
}
void
write(void)
{
	if(counter==10)
	{
		printf("The list is full.\n");
		return;
	}
	printf("Input name:\n");
	scanf("%s", array[counter].name);
	printf("Input age:\n");
	scanf("%d", &array[counter].age);
	if(array[counter].age<=21)
	{
		printf("Input school:\n");
		scanf("%s", array[counter].info.school);
	}
	else if(array[counter].age>=65)
	{
		printf("Input years retired:\n");
		scanf("%d", &array[counter].info.years);
	}
	else
	{
		printf("Input Salary:\n");
		scanf("%f", &array[counter].info.salary);
	}
	counter++;
//	printf("Placeholder\n");
	return;
}
void
delete(void)
{
	if(counter==0)
	{
		printf("The list is empty.\n");
		return;
	}
	printf("Input name to delete:\n");
	char find[20];
	scanf("%s", find);
	int i;
	for(i=0; i<counter; i++)
	{
		if(strcmp(array[i].name, find)==0)
		{
			array[i]=array[counter-1];
			counter--;
			printf("Deleted.\n");
		}
	}
//	printf("Placeholder\n");
	return;
}
void
show(void)
{
	if(counter==0)
	{
		printf("The list is empty.\n");
		return;
	}
	int i;
	for(i=0; i<counter; i++)
	{
		if(array[i].age<=21)
		{
			printf("%s\t%d\t%s\n", array[i].name, array[i].age, array[i].info.school);
		}
		else if(array[i].age>=65)
		{
			printf("%s\t%d\t%d\n", array[i].name, array[i].age, array[i].info.years);
		}
		else
		{
			printf("%s\t%d\t%f\n", array[i].name, array[i].age, array[i].info.salary);
		}
	}		
//	printf("Placeholder\n");
	return;
}
