//kpm.c
#include <LPC21xx.h>
#include "types.h"
#include "defines.h"
#include "kpm_defines.h"
#include "lcd.h"
#include "lcd_defines.h"
u32 kpmLUT[4][4]=
{
	{1,2,3,4},
	{5,6,7,8},
	{9,10,11,12},
	{13,14,15,16}
};

u32 ColScan(void)
{
	return (((IOPIN1 >> COL0)&0x0F)<15) ? 0 : 1;
}

u32 RowCheck(void)
{
	u32 r;
	for(r=0;r<4;r++)
	{
		//starting from 0th row ground only one row
		//keeping other rows high
		IOPIN1 = (IOPIN1 & ~(0x0F << ROW0)) | (~(1 << r) << ROW0);

		//check whether cols other than all 1s
		if(ColScan()==0)
			break;
	}
	//re-initialize all rows
	IOCLR1 = 15 << ROW0;
	return r;
}

u32 ColCheck(void)
{
	u32 c;
	for(c=0;c<=3;c++)
	{
		if (((IOPIN1 >> (COL0 + c)) & 1) == 0)
			break;
	}
	return c;
}	

u32 KeyScan(void)
{
	u32 r,c,keyV;
	//wait to detect any key press
	while(ColScan());
	//identify row in which key was pressed
	r=RowCheck();
	//identify col in which key was pressed
	c=ColCheck();
	//extract/map key value for key pressed
	keyV=kpmLUT[r][c];
	return keyV;
}

void InitKPM(void)
{
	//cfg row lines as gpio output
	IODIR1 |= (0x0F << ROW0);
	//hence all rows are grounded
	//default all col lines are gpio input
}

char GetKey(void) {
    // Simulated key press handling
    return '1';  // Default return value for testing
}

int GetNumber(void) {
    return 5;  // Default return value for testing
}
u32 KPM_Read_Data(void)
{
                u32 key,sum=0;
        s32 pos=0;
        while(1)
        {
                key=KeyScan();
                if(key==' ')
                {
                        pos--;
                        if(pos>=0)
                        {
                          CmdLCD(GOTO_LINE2_POS0 + pos);
                          CharLCD(' ');
                          CmdLCD(GOTO_LINE2_POS0 + pos);
                          sum=sum/10;
                        }
                        else
                        {
                                pos=0;
                        }
                        while(ColScan()==0);

                }
                else if(key>=48 && key<=57)
                {


                         CmdLCD(GOTO_LINE2_POS0 + pos);
                         CharLCD(key);
                         CmdLCD(GOTO_LINE2_POS0 + pos);

                        sum=sum*10 + (key-48);
                        while(ColScan()==0);
                        pos++;
                }
                else
                {
                        break;
                }
        }
return sum;
}
