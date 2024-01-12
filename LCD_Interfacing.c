#include<LPC17xx.h>
#include<stdio.h>
void delay(unsigned int x);
void LCD_CmdWrite(char cmd);
void LCD_DataWrite(char data);
void sendByte(char byte);
int main(void)
{ 
// char i, a[]={“Hello World!"};
SystemInit(); // Clock and PLL configuration
LPC_GPIO2->FIODIR |= 0x000000FF; 
LPC_GPIO1->FIODIR |= 0x00000007;
Lcd_CmdWrite(0x38);
Lcd_CmdWrite(0x01); 
Lcd_CmdWrite(0x0E); 
Lcd_CmdWrite(0x80); 
Lcd_DataWrite('H');
Lcd_DataWrite('e');
Lcd_DataWrite('l');
Lcd_DataWrite('l');
Lcd_DataWrite('o');
Lcd_DataWrite(' ');
Lcd_DataWrite('w');
Lcd_DataWrite('o');
Lcd_DataWrite('r');
Lcd_DataWrite('l');
Lcd_DataWrite('d');
}
void Lcd_CmdWrite(char cmd)
{ 
sendByte(cmd); //Send the command
LPC_GPIO1->FIOPIN &= ~(1<<0); 
LPC_GPIO1->FIOPIN &= ~(1<<1); 
LPC_GPIO1->FIOPIN |= (1<<2);
delay(1000);
LPC_GPIO1->FIOPIN &= ~(1<<2);
delay(10000); 
}
void Lcd_DataWrite(char dat)
{ 
sendByte(dat); //Send the command
LPC_GPIO1->FIOPIN |= (1<<0);
LPC_GPIO1->FIOPIN &= ~(1<<1); 
LPC_GPIO1->FIOPIN |= (1<<2); 
delay(1000);
LPC_GPIO1->FIOPIN &= ~(1<<2);
delay(10000); 
}
void sendByte(char byte)
{ 
LPC_GPIO2->FIOPIN &= ~(0xFF);
LPC_GPIO2->FIOPIN |= (((byte >>0x00) & 0x01) << 0);
LPC_GPIO2->FIOPIN |= (((byte >>0x01) & 0x01) << 1);
LPC_GPIO2->FIOPIN |= (((byte >>0x02) & 0x01) << 2);
LPC_GPIO2->FIOPIN |= (((byte >>0x03) & 0x01) << 3);
LPC_GPIO2->FIOPIN |= (((byte >>0x04) & 0x01) << 4);
LPC_GPIO2->FIOPIN |= (((byte >>0x05) & 0x01) << 5);
LPC_GPIO2->FIOPIN |= (((byte >>0x06) & 0x01) << 6);
LPC_GPIO2->FIOPIN |= (((byte >>0x07) & 0x01) << 7); 
}
void delay(unsigned int ms)
{
unsigned int i, j;
for(i=0; i<ms; i++)
for(j=0; j<20000; j++);
}
