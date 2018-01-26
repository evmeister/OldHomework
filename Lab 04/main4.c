// Evan Eberhardt
// 20 Apr 15
// Monday 5:10 Lab
// Lab 4

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void ascToBin(char *string, int binary[8]);
void twosComp(int binary[8]);
void printBin(int binary[8]);

int main()
{
  printf("Enter binary string: ");
  char str[9];
  gets(str);
  int bin[8];
  ascToBin(str, bin);
  printf("The 2's complement:  ");
  twosComp(bin);
  printBin(bin);
  printf("\n");
  system("PAUSE");	
  return 0;
}
void printBin(int binary[8]){
     int i;
     for(i=0; i<8; i++){
              printf("%d",binary[i]);
     }
     return;
}
void ascToBin(char *string, int binary[8]){
     int i=0;
     int k=strlen(string);
     int j=k;
     //printf("String uses %d bits\n", k); //test value
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
void twosComp(int binary[8]){
     int i=0;
     int comp[8];
     while(i<8){
                if(binary[i]==0){ 
                                  comp[i]=0;
                                  i++;
                }
                else if(binary[i]==1){
                     comp[i]=1;
                     i++;
                     break;
                }
     }
     for(i; i<8; i++){
            if(binary[i]==0){ comp[i]=1;}
            else if(binary[i]==1){ comp[i]=0;}
     }
     int j=0;
     for(i=7, j; i>=0, j<8; i--, j++){
              binary[j]=comp[i];
     }
     return;
}
