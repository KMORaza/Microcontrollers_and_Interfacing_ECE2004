// Write an embedded C program to operate Tollgate barrier with stepper motor and DIP switch & to operate dc fan for operator. 
// Assume stepper motor is connected to P2.3 to P2.0(3rd to 0th pole), DC fan is connected to P2.10(-ve), P2.11(+ve), toll gate barrier switch is connected to P2.17 and dc fan is connected to P2.26
#include<LPC17XX.H>
#include<stdio.h>
void delay(unsigned int x);
int main(void)
{ 
int i; 
LPC_GPIO2->FIODIR &= ~((1<<26)|(1<<17)); 
LPC_GPIO2->FIODIR |= (1<<11)|(1<<10); 
LPC_GPIO2->FIODIR |= (1<<3)|(1<<2)|(1<<1)|(1<<0); 
while(1) 
{ 
if (((LPC_GPIO2->FIOPIN)>>26) & 0x01) 
{
LPC_GPIO2->FIOPIN &= ~(1<<10);
LPC_GPIO2->FIOPIN |= (1<<11); 
}
else
{ 
LPC_GPIO2->FIOPIN &= ~((1<<10)|(1<<11)); 
}
if (((LPC_GPIO2->FIOPIN)>>17) & 0x01) 
{
LPC_GPIO2->FIOPIN &= ~((1<<1)|(1<<2)|(1<<3));
LPC_GPIO2->FIOPIN |= (1<<0);
delay(10000); 
}
else
{ 
LPC_GPIO2->FIOPIN &= ~((1<<0)|(1<<2)|(1<<3));
LPC_GPIO2->FIOPIN |= (1<<1); 
}
}
}
void delay_ms(unsigned int ms)
{
unsigned int i, j;
for(i=0; i<ms; i++)
for(j=0; j<20000; j++);
}
