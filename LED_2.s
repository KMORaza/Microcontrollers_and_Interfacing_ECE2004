#include <stdio.h> 
#include "LPC17xx.H" 
void delay (unsigned int x); 
int main (void) { 
LPC_GPI01->FIODIR | = 0xB0000000; 
LPC_GPIO2->FIODIR |= 0x0000007C; 
while (1){ 
delay (5000); 
LPC_GPIO1->FIOPIN&=~ ((1<<28) | (1<<31)); 
LPC_GPIO2->FIOPIN&=~ ((1<<3)| (1<<5)); 
LPC_GPI02->FIOPIN] =(1<<2)| (1<<4)| (1<<6); 
LPC_GPI01->FIOPIN|=(1<<29); 
delay(5000); 
} 
} 
LPC_GPI01->FIOPIN] =(1<<28) | (1<<31); 
LPC_GPIO2->FIOPIN] =(1<<3)| (1<<5); 
LPC_GPIO2->FIOPIN&=~ ((1<<2)| (1<<4)| (1<<6)); 
LPC_GPIO1->FIOPIN&=~(1<<29); 
void delay(unsigned int x){ 
int i=0; 
for (;x>0;x--) 
for (i=0; i<1000;i++); 
} 
