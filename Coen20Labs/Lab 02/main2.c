//Evan Eberhardt
//Coen20 Lab 2
#include <stdio.h>
void decToBin(unsigned int decimal, int binary[8]);
void printBin(int binary[8]);
int main()
{
    unsigned int x;
    int b[8];
    printf("Enter a decimal integer: ");
    scanf("%d", &x);
    int l=-128;
    int u=127;
    if((int)x<l || (int)x>u){printf("OVERFLOW");return 0;}
    decToBin(x,b);
    printf("The 8 binary bits are: ");
    printBin(b);
    printf("\n press a number to close\n");
    scanf("%d", &x);
    return 0;
}
void decToBin(unsigned int decimal, int *binary){
    int i;
    for(i=7; i>=0; i--){
             int r=decimal%2;
             binary[i]=r;
             decimal/=2;
             }
}
void printBin(int binary[8]){
     int i;
     for(i=0; i<8; i++){
              printf("%d",binary[i]);
              }
}


