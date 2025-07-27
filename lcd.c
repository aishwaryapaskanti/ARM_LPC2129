//lcd.c
#include "types.h"
#include "delay.h"
#include <LPC21xx.h>
#include "lcd_defines.h"

void WriteLCD(u8 Dat)
{
	//write on data pins
	IOPIN0=((IOPIN0&~(0xFF<<LCD_DATA))|
	        (Dat<<LCD_DATA));
	//activate write operation
	IOCLR0=1<<LCD_RW;
	//latch into cmd/data register
	IOSET0=1<<LCD_EN;
	delay_us(1);
	IOCLR0=1<<LCD_EN;
	//internal operation upper bound time
	delay_ms(2);
}

void CmdLCD(u8 cmd)
{
	//select cmd reg
	IOCLR0=1<<LCD_RS;
	//write to cmd reg
	WriteLCD(cmd);
}

void CharLCD(u8 ascii)
{
	//select data reg
	IOSET0=1<<LCD_RS;
	//Write to DDRAM/Display via data reg
	WriteLCD(ascii);
}

void InitLCD(void)
{
	//cfg data&control pins as gpio out
	IODIR0|=0xFF<<LCD_DATA|1<<LCD_RS|1<<LCD_RW|
	        1<<LCD_EN;
	//implement initialization algorithm
	delay_ms(15);
	CmdLCD(0x30);
	delay_ms(2);
	delay_us(100);
	CmdLCD(0x30);
	delay_us(100);
	CmdLCD(0x30);
	CmdLCD(MODE_8BIT_2LINE);
	CmdLCD(DSP_ON_CUR_OFF);
  CmdLCD(CLEAR_LCD);
  CmdLCD(SHIFT_CUR_RIGHT);
}
	

void StrLCD(s8 *str)
{
	while(*str)
		CharLCD(*str++);
}

void U32LCD(u32 num)
{
	s8 a[10];
	s32 i=0;
	if(num==0)
		CharLCD('0');
	else
	{
		while(num>0)
		{
			a[i]=(num%10)+48;
			i++;
			num/=10;
		}
		for(--i;i>=0;i--)
		  CharLCD(a[i]);
	}	
}

void S32LCD(s32 num)
{
	if(num<0)
	{
		CharLCD('-');
		num=-num;
	}
	U32LCD(num);
}

void F32LCD(f32 fNum,u32 nDP)
{
	u32 num,i;
	if(fNum<0.0)
	{
		CharLCD('-');
		fNum=-fNum;
	}
	num=fNum;
  U32LCD(num);
  CharLCD('.');	
	for(i=0;i<nDP;i++)
	{
		fNum=(fNum-num)*10;
		num=fNum;
		CharLCD(num+48);		
	}
}

void HexLCD(u32 num)
{
	s8 a[8],t;
	s32 i=0;
	if(num==0)
		CharLCD('0');
	else
	{
		while(num>0)
		{
			t=(num%16);
			t=(t>9)?('A'+(t-10)):(t+48);
			a[i]=t;
			i++;
			num/=16;
		}
		for(--i;i>=0;i--)
		  CharLCD(a[i]);
	}
}
void OctLCD(u32 num)
{
	s8 a[11];
	s32 i=0;
	if(num==0)
		CharLCD('0');
	else
	{
		while(num>0)
		{
			a[i]=(num%8)+48;
			i++;
			num/=8;
		}
		for(--i;i>=0;i--)
		  CharLCD(a[i]);
	}
}

void BinLCD(u32 num, u32 nBD)
{
	s32 i;
	for(i=(nBD-1);i>=0;i--)
	{
		CharLCD(((num>>i)&1)+48);
	}
}

void BuildCGRAM(u8 *p,u8 nBytes)
{
	u32 i;
	//position cursor to cgram start;
	CmdLCD(GOTO_CGRAM_START);
	//write into cgram via data reg
	for(i=0;i<nBytes;i++)
	{
		CharLCD(p[i]);
	}
	//reposition cursor back to ddram
	CmdLCD(GOTO_LINE1_POS0);
}
