//Evan Eberhardt Lab 5
//rgen: random string generator

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define MB 1048576

int main(){
	//init random number generator and buffer
	int i;
	time_t t;
	srand((unsigned) time(&t));
	unsigned char buffer [MB];
	
	//fill buffer
	for(i=0; i<MB-1; i++){
		buffer[i] = rand() %255;
		printf("%c", buffer[i]);
	}
	buffer[MB-1] = EOF;
	printf("%c", buffer[MB-1]);
	return 0;
}

