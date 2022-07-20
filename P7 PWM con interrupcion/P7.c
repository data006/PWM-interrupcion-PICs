#include<16F887.h>
#device ADC=8
#fuses INTRC, NOBROWNOUT,NOPROTECT,NOLVP
#use delay(clock=4000000)
#use rs232(baud=9600,xmit=PIN_C6, rcv=PIN_C7)
#include <stdlib.h>
unsigned int16 low,high,x;
void main(){ 
     enable_interrupts(Global);
     enable_interrupts(int_rda);
     high=313;
     low=312;
     while(true){
        output_high(pin_C2);
        delay_us(high);
        output_low(pin_C2);
        delay_us(low);
     }
}
#int_rda
void serial(){
   scanf("%li", &x);
   high=x*625/100;
   low=(625)-high;
   if(x==0){
      high = 0;
      low = 625;
   }
   printf("Alto: %li\n",high);
   printf("Bajo: %li\n",low);
      
}

