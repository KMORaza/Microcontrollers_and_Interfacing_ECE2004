#include <stdio.h> 
#include "LPC17xx.H" 
void delay (unsigned int x); 
int main (void) { 
LPC_GPI01->FIODIR 1= 0xB0000000; 
LPC_GPI02->FIODIR |= 0x0000007C 
while (1) 
LPC_GPIO1->FIOPIN | =(1<<28) | (1<<29) | (1<<31); 
LPC_GPIO2->FIOPIN|=(1<<2); 
LPC_GPIO2->FIOPING=((1<<3)| (1<<4)| (1<<5)| (1<<6)); 
delay(5000); 
LPC_GPIO2->FIOPIN] =(1<<3)| (1<<4)| (1<<5) | (1<<6); 
LPC_GPI01->FIOPIN&=((1<<28) | (1<<29) | (1<<31)); LPC GPIO2->FIOPIN&~ (1<<2); 
delay(5000); 
} 
} 
void delay (unsigned int x){ 
int i=0; 
for (;x>0;x--) 
for (i=0; i<1000; i++); 
} 
