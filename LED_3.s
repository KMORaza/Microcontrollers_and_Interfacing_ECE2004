#include <stdio.h> 
#include "LPC17xx.H" 
void delay(unsigned int x); 
int main (void) { 
LPC_GPIO1->FIODIR |= 0xB0000000; 
LPC_GPIO2->FIODIR |= 0x0000007C; 
while(1){ 
LPC_GPIO1->FIOPIN|=(1<<28); 
LPC_GPIO2->FIOPIN&=~((1<<2)|(1<<4)|(1<<6)|(1<<3)|(1<<5)); 
LPC_GPIO1->FIOPIN&=~((1<<29)|(1<<31)); 
delay(5000); 
LPC_GPIO1->FIOPIN|=((1<<28)|(1<<29)); 
LPC_GPIO2->FIOPIN&=~((1<<2)|(1<<4)|(1<<6)|(1<<3)|(1<<5)); 
LPC_GPIO1->FIOPIN&=~(1<<31); 
delay(5000); 
LPC_GPIO1->FIOPIN|=((1<<28)|(1<<29)|(1<<31)); 
LPC_GPIO2->FIOPIN&=~((1<<2)|(1<<4)|(1<<6)|(1<<3)|(1<<5)); 
delay(5000); 
LPC_GPIO1->FIOPIN|=((1<<28)|(1<<29)|(1<<31)); 
LPC_GPIO2->FIOPIN|=(1<<2); 
LPC_GPIO2->FIOPIN&=~((1<<4)|(1<<6)|(1<<3)|(1<<5)); 
delay(5000); 
LPC_GPIO1->FIOPIN|=((1<<28)|(1<<29)|(1<<31)); 
LPC_GPIO2->FIOPIN|=((1<<2)|(1<<3)); 
LPC_GPIO2->FIOPIN&=~((1<<4)|(1<<6)|(1<<5)); 
delay(5000); 
LPC_GPIO1->FIOPIN|=((1<<28)|(1<<29)|(1<<31)); 
LPC_GPIO2->FIOPIN|=((1<<2)|(1<<3)|(1<<4)); 
LPC_GPIO2->FIOPIN&=~((1<<6)|(1<<5)); 
delay(5000); 
LPC_GPIO1->FIOPIN|=((1<<28)|(1<<29)|(1<<31)); 
LPC_GPIO2->FIOPIN|=((1<<2)|(1<<3)|(1<<4)|(1<<5)); 
LPC_GPIO2->FIOPIN&=~(1<<6); 
delay(5000); 
LPC_GPIO1->FIOPIN|=((1<<28)|(1<<29)|(1<<31)); 
LPC_GPIO2->FIOPIN|=((1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)); 
delay(5000); 
LPC_GPIO1->FIOPIN|=((1<<29)|(1<<31)); 
LPC_GPIO2->FIOPIN|=((1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)); 
LPC_GPIO1->FIOPIN&=~(1<<28); 
delay(10000); 
LPC_GPIO1->FIOPIN|=(1<<31); 
LPC_GPIO2->FIOPIN|=((1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)); 
LPC_GPIO1->FIOPIN&=~((1<<28)|(1<<29)); 
delay(5000); 
LPC_GPIO2->FIOPIN|=((1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)); 
LPC_GPIO1->FIOPIN&=~((1<<28)|(1<<29)|(1<<31)); 
delay(5000); 
LPC_GPIO2->FIOPIN|=((1<<3)|(1<<4)|(1<<5)|(1<<6)); 
LPC_GPIO1->FIOPIN&=~((1<<28)|(1<<29)|(1<<31)); 
LPC_GPIO2->FIOPIN&=~(1<<2); 
delay(5000); 
LPC_GPIO2->FIOPIN|=((1<<4)|(1<<5)|(1<<6)); 
LPC_GPIO1->FIOPIN&=~((1<<28)|(1<<29)|(1<<31)); 
LPC_GPIO2->FIOPIN&=~((1<<2)|(1<<3)); 
delay(5000); 
LPC_GPIO2->FIOPIN|=((1<<5)|(1<<6)); 
LPC_GPIO1->FIOPIN&=~((1<<28)|(1<<29)|(1<<31)); 
LPC_GPIO2->FIOPIN&=~((1<<2)|(1<<3)|(1<<4)); 
delay(5000); 
LPC_GPIO2->FIOPIN|=((1<<6)); 
LPC_GPIO1->FIOPIN&=~((1<<28)|(1<<29)|(1<<31)); 
LPC_GPIO2->FIOPIN&=~((1<<2)|(1<<3)|(1<<4)|(1<<5)); 
delay(5000); 
LPC_GPIO1->FIOPIN&=~((1<<28)|(1<<29)|(1<<31)); 
LPC_GPIO2->FIOPIN&=~((1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)); 
delay(5000); 
} 
} 
void delay(unsigned int x) { 
int i=0; 
for(;x>0;x--) 
for(i=0;i<1000;i++); 
} 
