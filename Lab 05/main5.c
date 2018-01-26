// Evan Eberhardt
// 27 Apr 15
// Monday 5:10 Lab
// Lab 5

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void ascToBin(char *string, int binary[8]);
void printBin(int binary[8]);
int addBinary(int first[8], int second [8], int result[8]);
int subBinary(int first[8], int second[8], int result[8]);

int main()
{
  printf("Enter the 1st binary number: ");
  char str[9];
  gets(str);
  int frst[8];
  ascToBin(str, frst);
  printf("Enter 2nd binary number: ");
  char str2[9]; 
  gets(str2);
  int scnd[8];
  ascToBin(str2, scnd);
  int sum[8];
  int cout;
  cout = addBinary(frst, scnd, sum);
  printf("The 1st plus the 2nd is: ");
  printBin(sum);
  printf("\nThe carry out is: %d\n", cout);
  int diff[8];
  int bout;
  printf("The 1st less the 2nd is: ");
  bout = subBinary(frst, scnd, diff);
  printBin(diff);
  printf("\nThe borrow out is: %d\n", bout);
  system("PAUSE");	
  return 0;
}
void printBin(int binary[8]){
     int i;
     for(i=7; i>=0; i--){
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
int addBinary(int first[8], int second [8], int result[8]){
    int cout=0;
    int i;
    for(i=0; i<8; i++){
             if(cout==0 && first[i]==0 && second[i]==0){
                        cout=0;
                        result[i]=0;
             }
             else if(cout==1 && first[i]==1 && second[i]==1){
                  cout=1;
                  result[i]=1;
             }
             else if((cout==0 && first[i]!=second[i]) || (cout==1 && first[i]==0 && second[i]==0)){
                  cout=0;
                  result[i]=1;
             }
             else if((cout==1 && first[i]!=second[i]) || (cout==0 && first[i]==1 && second[i]==1)){
                  cout=1;
                  result[i]=0;
             }
    }
    return cout;
}
int subBinary(int first[8], int second[8], int result[8]){
    int bout=0;
    int i;
    for(i=0; i<8; i++){
             if(bout==0 && first[i]==1 && second[i]==0){
                        bout=0;
                        result[i]=1;
             }
             else if(bout==1 && first[i]==0 && second[i]==1){
                  bout=1;
                  result[i]=0;
             }
             else if((bout==0 && first[i]==second[i]) || (bout==1 && first[i]==1 && second[i]==0)){
                  bout=0;
                  result[i]=0;
             }
             else if((bout==1 && first[i]==second[i]) || (bout==0 && first[i]==0 && second[i]==1)){
                  bout=1;
                  result[i]=1;
             }
    }
    return bout;
}
