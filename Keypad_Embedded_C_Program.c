/* Assumptions:
   1. 7-segment display(a, b, c, d, e, f, g, h) is connected to P0.7 to P0.0 respectively.
   2. R1(P1), R2(P2), R3(P3), R4(P4) are connected to P2.6, P2.5, P2.4, P2.3 respectively.
   3. C1(P5), C2(P6), C3(P7) are connected to P2.2, P2.1, P2.0 respectively.
   4. Pressing “*” button in keypad will display only “.”
   5. Pressing “#” button in keypad will display only “8.”
*/
#include “LPC17XX.H”
void Delay(unsigned int x);
int main(){
int seg[10]= { , , , ………}// array of 7-segment Hex values(0 to 9).
LPC_GPIO0→FIODIR| = 0x000000FF;
LPC_GPIO2→FIODIR| = (1<<2)|(1<<1)|(1<<0);
LPC_GPIO2→FIODIR& = ~ ((1<<6)|(1<<5)|(1<<4)|(1<<3));
while(1){
LPC_GPIO2→FIOPIN& = ~ ((1<<2)|(1<<1)|(1<<0));//C1=C2=C3=0
if(!((LPC_GPIO2→FIOPIN)&(1<<6)))//if(R1=0){
LPC_GPIO2→FIOPIN& = ~(1<<2);//C1=0;
LPC_GPIO2→FIOPIN| = (1<<1)|(1<<0);// C2=C3=1;
if(!((LPC_GPIO2→FIOPIN)&(1<<6)))//if(R1=0){
LPC_GPIO0→FIOPIN|=seg[1];//Display 1 on 7-segment display
}
else{
LPC_GPIO2→FIOPIN& = ~(1<<1);//C2=0;
LPC_GPIO2→FIOPIN| = (1<<2)|(1<<0);// C1=C3=1;
if(!((LPC_GPIO2→FIOPIN)&(1<<6)))//if(R1=0){
LPC_GPIO0→FIOPIN|=seg[2]; //Display 2 on 7-segment display
}
else{
LPC_GPIO2→FIOPIN& = ~(1<<2);//C3=0;
LPC_GPIO2→FIOPIN| = (1<<1)|(1<<0);// C2=C1=1;
if(!((LPC_GPIO2→FIOPIN)&(1<<6)))//if(R1=0)
{
LPC_GPIO0→FIOPIN|=seg[3]; //Display 3 on 7-segment display
}
}
}
} // this ends for R1
if(!((LPC_GPIO2→FIOPIN)&(1<<5)))//if(R2=0)
{
LPC_GPIO2→FIOPIN& = ~(1<<2);//C1=0;
LPC_GPIO2→FIOPIN| = (1<<1)|(1<<0);// C2=C3=1;
if(!((LPC_GPIO2→FIOPIN)&(1<<5)))//if(R2=0)
{
LPC_GPIO0→FIOPIN|=seg[4]; //Display 4 on 7-segment display
}
else{
LPC_GPIO2→FIOPIN& = ~(1<<1);//C2=0;
LPC_GPIO2→FIOPIN| = (1<<2)|(1<<0);// C1=C3=1;
if(!((LPC_GPIO2→FIOPIN)&(1<<5)))//if(R2=0)
{
LPC_GPIO0→FIOPIN|=seg[5]; //Display 5 on 7-segment display
}
else{
LPC_GPIO2→FIOPIN& = ~(1<<2);//C3=0;
LPC_GPIO2→FIOPIN| = (1<<1)|(1<<0);// C2=C1=1;
if(!((LPC_GPIO2→FIOPIN)&(1<<5)))//if(R2=0)
{
LPC_GPIO0→FIOPIN|=seg[6]; //Display 6 on 7-segment display
}
}
}
} // this ends for R2
if(!((LPC_GPIO2→FIOPIN)&(1<<4)))//if(R3=0)
{
LPC_GPIO2→FIOPIN& = ~(1<<2);//C1=0;
LPC_GPIO2→FIOPIN| = (1<<1)|(1<<0);// C2=C3=1;
if(!((LPC_GPIO2→FIOPIN)&(1<<4)))//if(R3=0)
{
LPC_GPIO0→FIOPIN|=seg[7]; //Display 7 on 7-segment display
}
else{
LPC_GPIO2→FIOPIN& = ~(1<<1);//C2=0;
LPC_GPIO2→FIOPIN| = (1<<2)|(1<<0);// C1=C3=1;
if(!((LPC_GPIO2→FIOPIN)&(1<<4)))//if(R3=0)
{
LPC_GPIO0→FIOPIN|=seg[8]; //Display 8 on 7-segment display
}
else{
LPC_GPIO2→FIOPIN& = ~(1<<2);//C3=0;
LPC_GPIO2→FIOPIN| = (1<<1)|(1<<0);// C2=C1=1;
if(!((LPC_GPIO2→FIOPIN)&(1<<4)))//if(R3=0)
{
LPC_GPIO0→FIOPIN|=seg[9]; //Display 9 on 7-segment display
}
}
}
} // this ends for R3
if(!((LPC_GPIO2→FIOPIN)&(1<<3)))//if(R4=0)
{
LPC_GPIO2→FIOPIN& = ~(1<<2);//C1=0;
LPC_GPIO2→FIOPIN| = (1<<1)|(1<<0);// C2=C3=1;
if(!((LPC_GPIO2→FIOPIN)&(1<<3)))//if(R4=0)
{
LPC_GPIO0→FIOPIN|=0x00000001; //Display “.”on 7-segment display
}
else{
LPC_GPIO2→FIOPIN& = ~(1<<1);//C2=0;
LPC_GPIO2→FIOPIN| = (1<<2)|(1<<0);// C1=C3=1;
if(!((LPC_GPIO2→FIOPIN)&(1<<3)))//if(R4=0)
{
LPC_GPIO0→FIOPIN|=seg[0]; //Display 0 on 7-segment display
}
else{
LPC_GPIO2→FIOPIN& = ~(1<<2);//C3=0;
LPC_GPIO2→FIOPIN| = (1<<1)|(1<<0);// C2=C1=1;
if(!((LPC_GPIO2→FIOPIN)&(1<<3)))//if(R4=0)
{
LPC_GPIO0→FIOPIN|=0x000000FF; //Display “8.” on 7-segment display
}
}
}
} // this ends for R4
}// end for while loop
}// end for main loop
void delay(unsigned int x)
{
int i,j;
for(i=0;i<x;i++)
for(j=0;j<20000;j++);
}
