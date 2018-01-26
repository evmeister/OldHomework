#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "header.h"
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
