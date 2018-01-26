//Evan Eberhardt Lab 6
//Execute Diffie-Hellman algorithm

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

//This function will return True if int is prime
bool isPrime(int);

int main(){
	//Initializations.
	// p is modulus. r is base. B and A are Bob's and Alice's private
	// keys respectively. Bp and Ap are Bob's and Alice's public keys
	// respectively. Bk and Ak will be the calculated shared private keys
	unsigned long long  B, A, Bp, Ap, Bk, Ak;
	int p ,r;

	//Main while loop
	while(1){
		//multiple while loops at each input step allows for error checking
		while(1){
			printf("Enter prime number as modulus:\n");
			scanf("%d", &p);
			if(!isPrime(p))
				printf("%d is not prime.\n", p);
			else break;
		}
		while(1){
			printf("Enter a prime number as base, smaller than modulus:\n");
			scanf("%d", &r);
			if(!isPrime(r))
				printf("%d is not prime.\n", r);
			else if(p <= r)
				printf("%d is not smaller than modulus %d\n", r,p);
			else break;
		}
		printf("Enter Bob's private key:\n");
		scanf("%lld", &B);
		printf("Enter Alice's private key:\n");
		scanf("%lld", &A);

		//Calculate public keys.These are assumed to be swapped between 
		//Bob and Alice
		Bp = ((unsigned long long)pow(r, B) % p);//Bob
		Ap = ((unsigned long long)pow(r, A) % p);//Alice

		//Calculate shared private keys
		Bk = ((unsigned long long)pow(Ap, B) % p);
		Ak = ((unsigned long long)pow(Bp, A) % p);

		//Check if equal
		if(Bk == Ak)
			printf("Bob's key %d is equal to Alice's key %d\n", Bk, Ak);
		else
			printf("Bob's key %d is unequal to Alice's key %d\n", Bk, Ak);

		//Restart function
		printf("Enter '0' to quit, any other number to restart\n");
		int i;
		scanf("%d", &i);
		if(i==0) return 0;
	}
}

//function returns True if int is prime
bool isPrime(int N){
	long long  s = floor(sqrt(N));
	int i,j;
	for( i=2; i < s; i++){
		j =N % i;
		if(j==0)
			return false;
	}
	return true;
}
