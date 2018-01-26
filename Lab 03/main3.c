//Evan Eberhardt
//Monday 5:10 Lab

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void ascToBin(char *string, int binary[8]);
int binToUnsigned(int binary[8]);
int binToSigned(int binary[8]);

int main()
{
  printf("Enter binary string: ");
  char str[9];
  gets(str);
  int bin[8];
  ascToBin(str, bin);
  //test
  int a;
  for(a=0; a<8; a++){
           printf("%d", bin[a]);
  }
  printf("\n");
  //
  int U=binToUnsigned(bin);
  printf("The unsigned decimal integer is: %d\n", U);
  int S=binToSigned(bin);
  printf("The 2's complement integer is: %d\n", S);
  system("PAUSE");	
  return 0;
}
void ascToBin(char *string, int binary[8]){
     int i=0;
     int k=strlen(string);
     int j=k;
     printf("String uses %d bits\n", k);
     while(k>0){
                if(string[k-1]=='1'){
                     binary[i]=1;
                }    
                else {
                     binary[i]=0;
                }
                k--;
                i++;
     }
     if(j<8){
             for(i; i<8; i++)
                    binary[i]=0;
     }
     return;
}
int binToUnsigned(int binary[8]){
    int a=0;
    int i;
    for(i=0; i<8; i++){
             a+=((pow(2,i))*(binary[i]));
    }
    return a;
}
int binToSigned(int binary[8]){
    int a=0;
    int i;
    for(i=0; i<7; i++){
             a+=((pow(2,i))*(binary[i]));
    }
    a-=((pow(2,7))*(binary[7]));
    return a;
}
