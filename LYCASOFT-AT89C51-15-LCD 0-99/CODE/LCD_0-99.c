#include<reg51.h>
#include "8051_delay.h"
#include "LCD_4_BIT_HEADER_FILE.h"

int Count,i;

void divider(int x)
{
	int Temp,Dig1,Dig2;
	
	Temp = x;

	Dig1 = Temp/10;
	Lcd_Data(Dig1+48);

	Dig2 = Temp%10;
	Lcd_Data(Dig2+48);
}

void main()
{
	P1=0X00;

	Lcd_Intialization();

	Lcd_Command(0x80);
	Lcd_String("LYCO SOFT");
	
	while(1)
	{
		for(i=0;i<100;i++)
		{
			Lcd_Command(0xc0);
			divider(i);
			delay(500);
		}
	}
}