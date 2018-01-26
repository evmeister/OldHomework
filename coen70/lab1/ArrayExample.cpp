/* ArrayExample.cpp */
#include <iostream>
using namespace std;

int main()
{
	int score[10];
	for (int i=0; i < 10; ++i)
	{
		score [i]=3*i;
		cout << score[i];
	}
	return 0;
}
