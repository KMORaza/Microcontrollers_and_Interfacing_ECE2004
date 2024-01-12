#include <LPC17xx.H> 
static unsigned char Dir=0x00; 
void delay(unsigned int x); 
void Direction(void); 
/* Main starts here */ 
int main(){ 
LPC_SC->PCONP |= (1 << 15); /* enable power to GPIO & IOCON */ 
LPC_GPIO0->FIODIR |= 0x78000000; /* Configure P0.27,P0.28,P0.29,P0.30 as Output*/ 
LPC_GPIO1->FIODIR |= 0x01000000; 
LPC_GPIO2->FIODIR &= ~(1<<10); /* Configure P2.10 as Input */ 
while(1){ 
if(Dir) /* Clockwise Direction */ 
{ 
LPC_GPIO0->FIOPIN = (LPC_GPIO0->FIOPIN & 0x87FFFFFF) | 0x88000000; 
delay(50000); 
LPC_GPIO0->FIOPIN = (LPC_GPIO0->FIOPIN & 0x87FFFFFF) | 0x44000000; 
delay(50000); 
LPC_GPIO0->FIOPIN = (LPC_GPIO0->FIOPIN & 0x87FFFFFF) | 0x22000000; 
delay(50000); 
LPC_GPIO0->FIOPIN = (LPC_GPIO0->FIOPIN & 0x87FFFFFF) | 0x11000000; 
delay(50000); 
} 
else /* AntiClockwise Direction */ 
{ 
LPC_GPIO0->FIOPIN = (LPC_GPIO0->FIOPIN & 0x87FFFFFF) | 0x11000000; 
delay(50000); 
LPC_GPIO0->FIOPIN = (LPC_GPIO0->FIOPIN & 0x87FFFFFF) | 0x22000000; 
delay(50000); 
LPC_GPIO0->FIOPIN = (LPC_GPIO0->FIOPIN & 0x87FFFFFF) | 0x44000000; 
delay(50000); 
LPC_GPIO0->FIOPIN = (LPC_GPIO0->FIOPIN & 0x87FFFFFF) | 0x88000000; 
delay(50000); 
} 
if(!(LPC_GPIO2->FIOPIN & (1 << 10))) /* Is Button INT0 Pressed ? */ 
{ 
while(!(LPC_GPIO2->FIOPIN & (1 << 10))); /* Wait untill released */ 
Direction(); /* Call Direction Function */ 
} 
} 
} 
/* Delay Routine */ 
void delay(unsigned int x){ 
for(;x>0;x--); 
} 
/* Direction Function for stepper motor*/ 
void Direction(void){ 
Dir = ~Dir; /* Complement the Direction */ 
delay(50000); 
} 
