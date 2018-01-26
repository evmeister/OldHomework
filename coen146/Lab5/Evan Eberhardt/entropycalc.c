//Evan Eberhardt Lab 5
//ecalc: entropy calculator

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MB 1048576

int main(){
	//init
	int i;
	double prob, entropy;
	int count =0;
	unsigned char buffer [MB];
	unsigned int freqarr[256];
	for(i=0; i<256; i++)
		freqarr[i] =0;

	//read in string
	while(fgets(buffer, MB, stdin)){
		//bin values
		for(i=0; i<strlen(buffer); i++){
			freqarr[buffer[i]]++;
			count++;
		}
	}

	//calculate entropy
	for(i=0; i<256; i++){
		//ignore empty bins
		if(freqarr[i]){
			prob = (double)freqarr[i] / (double)count;
			entropy += prob * log2(1/prob);
		}
	}
	printf("Entropy:  %f\n", entropy);
	return 0;
}

