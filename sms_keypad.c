//sms_keypad.c
#include <LPC21xx.h>
#include "kpm_defines.h"
#include "types.h"
#include "kpm.h"

const u8 kpmLUT[4][4][4] =
{
    {
        {'7', '8', '9', '%'},
        {'4', '5', '6', '*'},
        {'1', '2', '3', '-'},
        {' ', '0', ' ', '+'}
    },
    {
        {'a', 'd', 'g', ' '},
        {'j', 'm', 'p', ' '},
        {'s', 'v', 'y', ' '},
        {' ', ' ', ' ', ' '}
    },
    {
        {'b', 'e', 'h', ' '},
        {'k', 'n', 'q', ' '},
        {'t', 'w', 'z', ' '},
        {' ', ' ', ' ', ' '}
    },
    {
        {'c', 'f', 'i', ' '},
        {'l', 'o', 'r', ' '},
        {' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' '} 
    }
};
s32 presskey, khcount;

u32 ColScan(void)
{
    return (((IOPIN1 >> COL0) & 0xF) < 0xF) ? 0 : 1;
}

u32 RowCheck(void)
{
    u32 r;
    for (r = 0; r < 4; r++)
    {
        IOPIN1 = ((IOPIN1 & ~(0xF << ROW0)) | ((~(1 << r)) << ROW0));
        if (ColScan() == 0)
            break;
    }
		IOCLR1=15<<ROW0;
    return r;
}

u32 ColCheck(void)
{
    u32 c;
    for (c = 0; c < 4; c++)
    {
        if (((IOPIN1 >> (COL0 + c)) & 1) == 0)
            break;
    }
    return c;
}

u32 KeyScan(void)
{
    u32 r, c;
    static u32 posr = 0, posc = 0;

    // Wait to detect any key pressed
    while (ColScan());

    // Identify row in which key was pressed
    r = RowCheck();

    // Identify col in which key was pressed
    c = ColCheck();

    if (r != posr)
    {
        khcount = 0;
        posr = r;
    }

    if (c != posc)
    {
			khcount = 0;
        posc = c;
    }

    return kpmLUT[khcount][r][c];
}
void InitKPM(void)
{
	//cfg row lines as gpio output
	IODIR1 |= (0x0F << ROW0);
	//hence all rows are grounded
	//default all col lines are gpio input
}
