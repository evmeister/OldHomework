// Evan Eberhardt
// 4 May 15
// Monday 5:10 Lab
// Lab 6

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int16_t Multiply(int8_t multiplier, int8_t multiplicand);

int main()
{
  printf("Enter the multiplier: ");
  int mltplr, mltplcnd;
  scanf("%d", &mltplr);
  (int8_t)mltplr;
  printf("Enter the multiplicand: ");
  scanf("%d", &mltplcnd);
  (int8_t)mltplcnd;
  int16_t prdct=Multiply(mltplr, mltplcnd);
  printf("The correspnonding product is: %d\n", prdct);
  system("PAUSE");	
  return 0;
}

int16_t Multiply(int8_t multiplier, int8_t multiplicand){
        int i;
        uint16_t product=0;
        for(i=0; i<8; i++){
                 if(((uint8_t)multiplier>>i)&0x1==1){
                          product+=((uint8_t)multiplicand<<i);
                 }
        }
        if(multiplier<0)
                        product-=((uint8_t)multiplicand<<8);
        if(multiplicand<0)
                        product-=((uint8_t)multiplier<<8);
        return product;
}
