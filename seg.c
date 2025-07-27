//seg.c
#include <LPC21xx.h>
#include "types.h"
#include "delay.h"
#include "seg_defines.h"

u8 ca7seg_lut[10]=
{
	0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90
};
void Init7Segs()
{
	//cfg a to dp of mux segs as gpio out
	//cfg comms of 2 mux segs as gpio out
	IODIR0|=(0xFF<<CA7SEG_2_MUX)|
	        (1<<DSEL1)|(1<<DSEL2);
}	

void disp_2_mux_segs(u8 num)
{	
			IOPIN0=((IOPIN0&~(0xFF<<CA7SEG_2_MUX))|
			       (ca7seg_lut[num/10]<<CA7SEG_2_MUX));
			IOSET0=1<<DSEL1;
			delay_ms(1);
			IOCLR0=1<<DSEL1;
			
			IOPIN0=((IOPIN0&~(0xFF<<CA7SEG_2_MUX))|
			       (ca7seg_lut[num%10]<<CA7SEG_2_MUX));
			IOSET0=1<<DSEL2;
			delay_ms(1);
			IOCLR0=1<<DSEL2;					
}

void init_4_mux_segs()
{
	//cfg a to dp of mux segs as gpio out
	//cfg comms of 2 mux segs as gpio out
	IODIR0|=(0xFF<<CA7SEG_4_MUX)|
	        (1<<DSEL1)|(1<<DSEL2)|
	        (1<<DSEL3)|(1<<DSEL4);
}	

/*
void disp_time(u32 t1,u32 t2)
{
	IOPIN0=((IOPIN0&~(0xFF<<CA7SEG_4_MUX))|
			   (ca7seg_lut[t1/10]<<CA7SEG_4_MUX));
	IOSET0=1<<DSEL1;
	delay_ms(1);
	IOCLR0=1<<DSEL1;
			
	IOPIN0=((IOPIN0&~(0xFF<<CA7SEG_4_MUX))|
			    (ca7seg_lut[t1%10]<<CA7SEG_4_MUX));
	IOSET0=1<<DSEL2;
	delay_ms(1);
	IOCLR0=1<<DSEL2;		

	IOPIN0=((IOPIN0&~(0xFF<<CA7SEG_4_MUX))|
			   (ca7seg_lut[t2/10]<<CA7SEG_4_MUX));
	IOSET0=1<<DSEL3;
	delay_ms(1);
	IOCLR0=1<<DSEL3;
			
	IOPIN0=((IOPIN0&~(0xFF<<CA7SEG_4_MUX))|
			    (ca7seg_lut[t2%10]<<CA7SEG_4_MUX));
	IOSET0=1<<DSEL4;
	delay_ms(1);
	IOCLR0=1<<DSEL4;		
}
*/


void disp_time(u32 t1,u32 t2)
{
	IOPIN0=((IOPIN0&~(0xFF<<CA7SEG_4_MUX))|
			   (ca7seg_lut[t1]<<CA7SEG_4_MUX));
	IOSET0=1<<DSEL1;
	delay_ms(1);
	IOCLR0=1<<DSEL1;
			
	IOPIN0=((IOPIN0&~(0xFF<<CA7SEG_4_MUX))|
			    (ca7seg_lut[t2/100]<<CA7SEG_4_MUX));
	IOSET0=1<<DSEL2;
	delay_ms(1);
	IOCLR0=1<<DSEL2;		

	IOPIN0=((IOPIN0&~(0xFF<<CA7SEG_4_MUX))|
			   (ca7seg_lut[(t2/10)%10]<<CA7SEG_4_MUX));
	IOSET0=1<<DSEL3;
	delay_ms(1);
	IOCLR0=1<<DSEL3;
			
	IOPIN0=((IOPIN0&~(0xFF<<CA7SEG_4_MUX))|
			    (ca7seg_lut[t2%10]<<CA7SEG_4_MUX));
	IOSET0=1<<DSEL4;
	delay_ms(1);
	IOCLR0=1<<DSEL4;		
}
