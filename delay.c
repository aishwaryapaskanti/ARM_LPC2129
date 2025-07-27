//delay.c
#include "types.h"
void delay_us(u32 dly)
{
	dly=dly*12;
	while(dly--);
}
void delay_ms(u32 dly)
{
	dly=dly*12000;
	while(dly--);
}
void delay_s(u32 dly)
{
	dly=dly*12000000;
	while(dly--);
}
